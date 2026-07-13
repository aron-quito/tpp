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
                return sym->tipo;
            } else if (!sym) {
                reportar_error("Variable no declarada:", nodo->nombre_var);
            } else {
                reportar_error("El identificador no es una variable:", nodo->nombre_var);
            }
            return 0; // Error / Desconocido
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

static void visitar_nodo(NodoAST *nodo) {
    if (!nodo) return;

    switch (nodo->tipo) {
        case N_PROGRAMA:
            inicializar_symtab();
            visitar_nodo(nodo->izq);
            break;

        case N_LISTA_ELEMENTOS:
        case N_LISTA_PARAMETROS:
        case N_LISTA_ARGUMENTOS:
        case N_LISTA_CASOS:
            visitar_nodo(nodo->izq);
            visitar_nodo(nodo->der);
            break;

        case N_DECLARACION_VAR: {
            int tipo_var = nodo->operador; // TIPO_ENTERO, TIPO_DECIMAL, etc.
            NodoAST *lista_ids = nodo->izq;
            while (lista_ids) {
                if (lista_ids->tipo == N_LISTA_IDS) {
                    insertar_simbolo(lista_ids->nombre_var, SYM_VAR, tipo_var, ambito_actual);
                    lista_ids = lista_ids->izq;
                } else if (lista_ids->tipo == N_VARIABLE) {
                    // Por si en algún caso es solo N_VARIABLE en lugar de N_LISTA_IDS
                    insertar_simbolo(lista_ids->nombre_var, SYM_VAR, tipo_var, ambito_actual);
                    break;
                } else if (lista_ids->tipo == N_ASIGNACION) {
                    // Ocurre en el bucle PARA (declaración con asignación inicial)
                    insertar_simbolo(lista_ids->nombre_var, SYM_VAR, tipo_var, ambito_actual);
                    visitar_nodo(lista_ids); // Visitar la asignación para verificar el tipo
                    break;
                } else {
                    break;
                }
            }
            break;
        }

        case N_DECLARACION_FUN: {
            // nodo->nombre_var tiene el nombre de la funcion
            // nodo->operador tiene el tipo de retorno (0 si es void/ninguno)
            insertar_simbolo(nodo->nombre_var, SYM_FUN, nodo->operador, 0); // Funciones son globales

            ambito_actual++; // Nuevo ambito para la funcion
            visitar_nodo(nodo->izq); // Parametros
            visitar_nodo(nodo->der); // Cuerpo
            
            // Eliminar variables locales
            eliminar_ambito(ambito_actual);
            ambito_actual--;
            break;
        }

        case N_PARAMETRO:
            insertar_simbolo(nodo->nombre_var, SYM_VAR, nodo->operador, ambito_actual);
            break;

        case N_ASIGNACION: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (!sym || sym->categoria != SYM_VAR) {
                reportar_error("Asignación a variable no declarada:", nodo->nombre_var);
            } else {
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
            }
            break;
        }

        case N_LEER: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (!sym || sym->categoria != SYM_VAR) {
                reportar_error("Instrucción LEER requiere una variable declarada:", nodo->nombre_var);
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
