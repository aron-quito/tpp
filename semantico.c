#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"
#include "ast.h"

#define T_ENTERO_BISON 268  
#define T_DECIMAL_BISON 269 

int ambito_actual = 0;
int errores_semanticos = 0;

/* Mapea los tokens numéricos devueltos por Bison a los tipos internos del enum de la tabla */
TipoDato convertir_tipo(int tipo_bison) {
    if (tipo_bison == 0) return T_ENTERO; 
    return (tipo_bison == T_ENTERO_BISON) ? T_ENTERO : T_DECIMAL;
}

/* Recorre de manera recursiva los nodos del AST para aplicar las reglas de validación */
void analizar_semantico(NodoAST *nodo) {
    if (nodo == NULL) return;

    switch (nodo->tipo) {
        
        case N_PROGRAMA:
            /* Deriva el análisis hacia el nodo hijo izquierdo que arranca la lista de elementos */
            analizar_semantico(nodo->izq);
            break;

        case N_LISTA_ELEMENTOS:
            /* Ejecuta el análisis en cascada: izquierdo para elementos previos, derecho para el actual */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->der);
            break;

        case N_DECLARACION_FUN: {
            /* Evalúa si el operador define tipo de retorno; si es cero, se asume entero por defecto */
            TipoDato tipo_ret = (nodo->operador == 0) ? T_ENTERO : convertir_tipo(nodo->operador);
            
            /* Inserta el identificador de la función en el ámbito global (alcance 0) antes de procesar su bloque */
            insertar_simbolo(nodo->nombre_var, tipo_ret, 1, 0);
            
            /* Incrementa el contador para aislar las variables locales que se declaren dentro de esta función */
            ambito_actual++;
            
            /* Analiza el nodo central (parámetros) y el nodo derecho (bloque de instrucciones interno) */
            analizar_semantico(nodo->centro); 
            analizar_semantico(nodo->der);
            
            /* Reduce el ámbito al salir de la función para invalidar el acceso a sus variables locales */
            ambito_actual--;
            break;
        }

        case N_LISTA_PARAMETROS:
            /* Navega por la secuencia recursiva de parámetros de la función */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->der);
            break;

        case N_PARAMETRO: {
            /* Extrae el tipo del parámetro del campo operador e inserta su nombre en el ámbito de la función */
            TipoDato t_param = convertir_tipo(nodo->operador);
            insertar_simbolo(nodo->nombre_var, t_param, 0, ambito_actual);
            break;
        }

        case N_DECLARACION_VAR:
            if (nodo->izq) {
                NodoAST *lista = nodo->izq;
                TipoDato t_var = convertir_tipo(nodo->operador);
                
                /* Itera por la lista de variables compartidas bajo un mismo tipo base */
                while (lista != NULL && lista->tipo == N_LISTA_IDS) {
                    /* Registra la variable si es un identificador simple */
                    if (lista->nombre_var) {
                        insertar_simbolo(lista->nombre_var, t_var, 0, ambito_actual);
                    }
                    /* Si la variable incluye una asignación inicial, la registra y analiza su expresión */
                    if (lista->der && lista->der->tipo == N_ASIGNACION) {
                        insertar_simbolo(lista->der->nombre_var, t_var, 0, ambito_actual);
                        analizar_semantico(lista->der->izq); 
                    }
                    lista = lista->izq; 
                }
            }
            break;

        case N_ASIGNACION: {
            /* Busca si la variable destino ya existe en la tabla de símbolos */
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym == NULL) {
                fprintf(stderr, "Error Semántico: Intento de asignación a la variable '%s' no declarada.\n", nodo->nombre_var);
                errores_semanticos++;
            }
            /* Analiza el nodo izquierdo que contiene el valor o expresión a asignar */
            analizar_semantico(nodo->izq);
            break;
        }

        case N_VARIABLE: {
            /* Comprueba que la variable utilizada en una expresión matemática/lógica exista en el ámbito actual */
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym == NULL) {
                fprintf(stderr, "Error Semántico: La variable '%s' se está usando pero no ha sido declarada.\n", nodo->nombre_var);
                errores_semanticos++;
            }
            break;
        }

        case N_LEER: {
            /* Valida que la variable pasada a la instrucción Leer() haya sido declarada previamente */
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym == NULL) {
                fprintf(stderr, "Error Semántico: La función Leer() intenta escribir en '%s', la cual no ha sido declarada.\n", nodo->nombre_var);
                errores_semanticos++;
            }
            break;
        }

        case N_LLAMADA_FUNCION: {
            /* Recupera los datos del identificador de la función que se pretende invocar */
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym == NULL) {
                fprintf(stderr, "Error Semántico: La función '%s' no ha sido declarada en el sistema.\n", nodo->nombre_var);
                errores_semanticos++;
            } else if (sym->es_funcion == 0) {
                /* Detecta errores si el usuario intenta invocar una variable como si fuera función */
                fprintf(stderr, "Error Semántico: El identificador '%s' no es una función, es una variable.\n", nodo->nombre_var);
                errores_semanticos++;
            }
            /* Evalúa de forma recursiva los argumentos pasados en la llamada */
            analizar_semantico(nodo->izq);
            break;
        }

        case N_LISTA_ARGUMENTOS:
            /* Analiza recursivamente la secuencia de expresiones enviadas como argumentos */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->der);
            break;

        case N_OPERACION:
            /* Verifica que tanto el miembro izquierdo como el derecho de la operación sean válidos */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->der);
            break;

        case N_SI:
            /* Valida la expresión condicional (izq), el cuerpo afirmativo (centro) y el bloque alternativo (der) */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->centro);
            analizar_semantico(nodo->der);
            break;

        case N_MIENTRAS:
            /* Analiza la condición de parada del bucle (izq) y el bloque de instrucciones interior (der) */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->der);
            break;

        case N_PARA:
            /* Valida secuencialmente: inicialización (izq), condición (centro), incremento (der) y cuerpo (adicional) */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->centro);
            analizar_semantico(nodo->der);
            analizar_semantico(nodo->adicional);
            break;

        case N_DEPENDE:
            /* Analiza la variable bajo evaluación del switch (izq) y salta a la lista de casos estructurados (der) */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->der);
            break;

        case N_LISTA_CASOS:
            /* Recorre la cadena jerárquica de bloques "caso" asociados al depende */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->der);
            break;

        case N_CASO:
            /* Valida el valor constante de comparación (izq) y las sentencias asignadas a dicho caso (der) */
            analizar_semantico(nodo->izq);
            analizar_semantico(nodo->der);
            break;

        case N_RETORNAR:
        case N_IMPRIMIR:
            /* Analiza las expresiones vinculadas al retorno o a la salida estándar por pantalla */
            analizar_semantico(nodo->izq);
            break;

        default:
            /* Las hojas puras (enteros, decimales, cadenas constantes) no contienen identificadores a validar */
            break;
    }
}

/* Inicia el recorrido general del árbol e inicializa los contadores globales de control */
int ejecutar_analisis_semantico(NodoAST *raiz) {
    printf("\n=== EJECUTANDO ANÁLISIS SEMÁNTICO ===\n");
    ambito_actual = 0;
    errores_semanticos = 0;

    analizar_semantico(raiz);

    if (errores_semanticos == 0) {
        printf("Análisis semántico completado con éxito. Todo en orden.\n");
        return 1;
    } else {
        printf("Análisis semántico finalizado. Se detectaron %d error(es) lógico(s).\n", errores_semanticos);
        return 0;
    }
}