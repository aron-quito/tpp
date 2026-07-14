#include "semantic.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int ambito_actual = 0;
static int errores_semanticos = 0;

static void reportar_error(const char *mensaje, const char *detalle) {
    fprintf(stderr, "Error semántico: %s '%s'\n", mensaje, detalle ? detalle : "");
    errores_semanticos++;
}

static int obtener_tipo_expresion(NodoAST *nodo) {
    if (!nodo) return 0;

    switch (nodo->tipo) {
        case N_ENTERO: return TIPO_ENTERO;
        case N_DECIMAL: return TIPO_DECIMAL;
        case N_VARIABLE: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym && sym->categoria == SYM_VAR) {
                nodo->val_entero = sym->direccion_memoria;
                return sym->tipo;
            } else if (!sym) {
                reportar_error("Variable no declarada:", nodo->nombre_var);
            } else {
                reportar_error("El identificador no es una variable:", nodo->nombre_var);
            }
            return 0; // Error / Desconocido
        }
        case N_ACCESO_ARREGLO: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym && sym->categoria == SYM_VAR) {
                nodo->val_entero = sym->direccion_memoria;
                int tipo_indice = obtener_tipo_expresion(nodo->izq);
                if (tipo_indice != TIPO_ENTERO) {
                    reportar_error("El índice del arreglo debe ser entero:", nodo->nombre_var);
                }
                return sym->tipo;
            } else if (!sym) {
                reportar_error("Arreglo no declarado:", nodo->nombre_var);
            } else {
                reportar_error("El identificador no es un arreglo:", nodo->nombre_var);
            }
            return 0;
        }
        case N_OPERACION: {
            int tipo_izq = obtener_tipo_expresion(nodo->izq);
            int tipo_der = obtener_tipo_expresion(nodo->der);
            
            // Reglas de tipo muy simples:
            // Si alguno es desconocido, el resultado es desconocido para no lanzar errores en cascada.
            if (tipo_izq == 0 || tipo_der == 0) return 0;

            if (nodo->operador == MAS || nodo->operador == MENOS || nodo->operador == MULT || nodo->operador == DIV) {
                if (tipo_izq == TIPO_DECIMAL || tipo_der == TIPO_DECIMAL) return TIPO_DECIMAL;
                return TIPO_ENTERO;
            }
            // Operadores relacionales
            if (nodo->operador == IGUAL || nodo->operador == DIFERENTE || nodo->operador == MENOR || 
                nodo->operador == MAYOR || nodo->operador == MENOR_IGUAL || nodo->operador == MAYOR_IGUAL) {
                return TIPO_ENTERO; // Como booleano
            }
            return tipo_izq;
        }
        case N_LLAMADA_FUNCION: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym && sym->categoria == SYM_FUN) {
                return sym->tipo; // tipo de retorno
            } else if (!sym) {
                reportar_error("Función no declarada:", nodo->nombre_var);
            } else {
                reportar_error("El identificador no es una función:", nodo->nombre_var);
            }
            return 0;
        }
        default:
            return 0;
    }
}

static void visitar_nodo(NodoAST *nodo);

static void procesar_declaracion_var(NodoAST *nodo, int tipo_var) {
    if (!nodo) return;
    if (nodo->tipo == N_LISTA_ELEMENTOS || nodo->tipo == N_LISTA_IDS) {
        procesar_declaracion_var(nodo->izq, tipo_var);
        procesar_declaracion_var(nodo->der, tipo_var);
        // En caso de que se siga usando N_LISTA_IDS original (cuyo valor está en nombre_var):
        if (nodo->tipo == N_LISTA_IDS && nodo->nombre_var) {
            insertar_simbolo(nodo->nombre_var, SYM_VAR, tipo_var, ambito_actual, 1);
        }
    } else if (nodo->tipo == N_VARIABLE) {
        insertar_simbolo(nodo->nombre_var, SYM_VAR, tipo_var, ambito_actual, 1);
    } else if (nodo->tipo == N_ASIGNACION) {
        insertar_simbolo(nodo->nombre_var, SYM_VAR, tipo_var, ambito_actual, 1);
        
        // Verificación de tipos para la inicialización
        int tipo_expr = obtener_tipo_expresion(nodo->izq);
        if (tipo_expr != 0 && tipo_expr != tipo_var) {
            if (tipo_var == TIPO_ENTERO && tipo_expr == TIPO_DECIMAL) {
                fprintf(stderr, "Advertencia semántica: Asignación de decimal a entero '%s', posible pérdida de precisión.\n", nodo->nombre_var);
            }
        }
        
        visitar_nodo(nodo->izq); // Visitar la expresión asignada
    } else if (nodo->tipo == N_DECLARACION_ARREGLO) {
        insertar_simbolo(nodo->nombre_var, SYM_VAR, tipo_var, ambito_actual, nodo->val_entero);
    }
}

static void visitar_nodo(NodoAST *nodo) {
    if (!nodo) return;

    switch (nodo->tipo) {
        case N_PROGRAMA:
            inicializar_symtab();
            visitar_nodo(nodo->izq);
            // No llamamos a liberar_symtab() aquí porque codegen.c lo necesita
            break;

        case N_LISTA_ELEMENTOS:
        case N_LISTA_PARAMETROS:
        case N_LISTA_ARGUMENTOS:
        case N_LISTA_CASOS:
            visitar_nodo(nodo->izq);
            visitar_nodo(nodo->der);
            break;

        case N_DECLARACION_VAR: {
            // nodo->operador tiene el tipo (TIPO_ENTERO, etc.)
            procesar_declaracion_var(nodo->izq, nodo->operador);
            break;
        }

        case N_DECLARACION_FUN: {
            insertar_simbolo(nodo->nombre_var, SYM_FUN, nodo->operador, 0, 1); // Funciones son globales
            
            // Asignar memoria para guardar ra (Return Address)
            char ra_var_name[256];
            sprintf(ra_var_name, ".ra_%s", nodo->nombre_var);
            Simbolo *ra_sym = insertar_simbolo(ra_var_name, SYM_VAR, TIPO_ENTERO, 0, 1);
            if (ra_sym) {
                nodo->val_entero = ra_sym->direccion_memoria;
            }

            ambito_actual++; // Nuevo ambito para la funcion
            visitar_nodo(nodo->izq); // Parametros
            visitar_nodo(nodo->der); // Cuerpo
            
            // Al salir de la función, las variables locales ya no son válidas
            eliminar_ambito(ambito_actual);
            ambito_actual--;
            break;
        }

        case N_PARAMETRO: {
            Simbolo *sym = insertar_simbolo(nodo->nombre_var, SYM_VAR, nodo->operador, ambito_actual, 1);
            if (sym) {
                nodo->val_entero = sym->direccion_memoria;
            }
            break;
        }

        case N_ASIGNACION: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (!sym || sym->categoria != SYM_VAR) {
                reportar_error("Asignación a variable no declarada:", nodo->nombre_var);
            } else {
                nodo->val_entero = sym->direccion_memoria;
                int tipo_expr = obtener_tipo_expresion(nodo->izq);
                if (tipo_expr != 0 && tipo_expr != sym->tipo) {
                    // Advertencia simple (o error estricto, dependiendo del lenguaje)
                    if (sym->tipo == TIPO_ENTERO && tipo_expr == TIPO_DECIMAL) {
                        fprintf(stderr, "Advertencia semántica: Asignación de decimal a entero '%s', posible pérdida de precisión.\n", nodo->nombre_var);
                    }
                }
            }
            visitar_nodo(nodo->izq);
            break;
        }

        case N_ASIGNACION_ARREGLO: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (!sym || sym->categoria != SYM_VAR) {
                reportar_error("Asignación a arreglo no declarado:", nodo->nombre_var);
            } else {
                nodo->val_entero = sym->direccion_memoria;
                int tipo_indice = obtener_tipo_expresion(nodo->izq);
                if (tipo_indice != TIPO_ENTERO) {
                    reportar_error("El índice del arreglo debe ser entero:", nodo->nombre_var);
                }
                int tipo_expr = obtener_tipo_expresion(nodo->der);
                if (tipo_expr != 0 && tipo_expr != sym->tipo) {
                    if (sym->tipo == TIPO_ENTERO && tipo_expr == TIPO_DECIMAL) {
                        fprintf(stderr, "Advertencia semántica: Asignación de decimal a arreglo entero '%s', posible pérdida de precisión.\n", nodo->nombre_var);
                    }
                }
            }
            visitar_nodo(nodo->izq); // Indice
            visitar_nodo(nodo->der); // Expresion
            break;
        }

        case N_OPERACION:
            obtener_tipo_expresion(nodo); // Verifica tipos y variables dentro de la expresión
            visitar_nodo(nodo->izq);
            visitar_nodo(nodo->der);
            break;

        case N_LLAMADA_FUNCION:
            obtener_tipo_expresion(nodo); // Verifica que la función existe
            visitar_nodo(nodo->izq); // Argumentos
            break;

        case N_VARIABLE: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (!sym || sym->categoria != SYM_VAR) {
                reportar_error("Uso de variable no declarada:", nodo->nombre_var);
            } else {
                nodo->val_entero = sym->direccion_memoria;
            }
            break;
        }

        case N_LEER: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (!sym || sym->categoria != SYM_VAR) {
                reportar_error("Instrucción LEER requiere una variable declarada:", nodo->nombre_var);
            } else {
                nodo->val_entero = sym->direccion_memoria;
            }
            break;
        }

        case N_SI:
        case N_MIENTRAS:
            obtener_tipo_expresion(nodo->izq); // Condicion
            visitar_nodo(nodo->izq);
            
            ambito_actual++;
            visitar_nodo(nodo->der); // Bloque
            eliminar_ambito(ambito_actual);
            ambito_actual--;

            if (nodo->centro) { // SINO
                ambito_actual++;
                visitar_nodo(nodo->centro);
                eliminar_ambito(ambito_actual);
                ambito_actual--;
            }
            break;

        case N_PARA:
            ambito_actual++; // El for tiene su propio ambito
            visitar_nodo(nodo->izq); // init (suele ser declaracion de variable)
            obtener_tipo_expresion(nodo->der); // condicion
            visitar_nodo(nodo->der);
            visitar_nodo(nodo->centro); // paso
            visitar_nodo(nodo->adicional); // cuerpo
            eliminar_ambito(ambito_actual);
            ambito_actual--;
            break;

        case N_RETORNAR:
        case N_IMPRIMIR:
            visitar_nodo(nodo->izq); // Verifica las expresiones
            break;

        case N_DEPENDE:
            obtener_tipo_expresion(nodo->izq);
            visitar_nodo(nodo->izq);
            visitar_nodo(nodo->der);
            break;

        case N_CASO:
            if (nodo->izq) visitar_nodo(nodo->izq);
            ambito_actual++;
            visitar_nodo(nodo->der);
            eliminar_ambito(ambito_actual);
            ambito_actual--;
            break;

        default:
            // Nodos hoja sin nada extra: N_ENTERO, N_DECIMAL, N_CADENA, etc.
            break;
    }
}

int analizar_semantica(NodoAST *raiz) {
    errores_semanticos = 0;
    ambito_actual = 0;
    
    printf("\n==================== ANALISIS SEMANTICO ====================\n");
    visitar_nodo(raiz);
    
    imprimir_symtab();
    
    if (errores_semanticos > 0) {
        printf("Analisis completado con %d error(es) semantico(s).\n", errores_semanticos);
        return 0; // Fallo
    } else {
        printf("Análisis semántico exitoso. No se detectaron errores.\n");
        return 1; // Éxito
    }
}
