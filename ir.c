#include <stdio.h>
#include <stdlib.h>
#include "ir.h"

static int temp_counter = 0;
static int label_counter = 0;

static int new_temp() {
    return temp_counter++;
}

static int new_label() {
    return ++label_counter;
}

// Devuelve el id del temporal o -1
static int generar_ir(NodoAST *nodo) {
    if (!nodo) return -1;

    switch(nodo->tipo) {
        case N_PROGRAMA:
            generar_ir(nodo->izq);
            break;

        case N_LISTA_ELEMENTOS:
        case N_LISTA_PARAMETROS:
        case N_LISTA_CASOS:
            generar_ir(nodo->izq);
            generar_ir(nodo->der);
            break;

        case N_DECLARACION_VAR:
            generar_ir(nodo->izq); // El nodo asignación
            break;

        case N_ENTERO: {
            int t = new_temp();
            printf("    t%d = %d\n", t, nodo->val_entero);
            return t;
        }

        case N_VARIABLE: {
            int t = new_temp();
            printf("    t%d = %s\n", t, nodo->nombre_var);
            return t;
        }

        case N_ACCESO_ARREGLO: {
            int idx_t = generar_ir(nodo->izq);
            int res_t = new_temp();
            printf("    t%d = %s[t%d]\n", res_t, nodo->nombre_var, idx_t);
            return res_t;
        }

        case N_OPERACION: {
            int t1 = generar_ir(nodo->izq);
            int t2 = generar_ir(nodo->der);
            int res = new_temp();
            printf("    t%d = t%d %s t%d\n", res, t1, obtener_nombre_operador(nodo->operador), t2);
            return res;
        }

        case N_ASIGNACION: {
            int t1 = generar_ir(nodo->izq);
            printf("    %s = t%d\n", nodo->nombre_var, t1);
            break;
        }

        case N_ASIGNACION_ARREGLO: {
            int t1 = generar_ir(nodo->der); // valor
            int t2 = generar_ir(nodo->izq); // indice
            printf("    %s[t%d] = t%d\n", nodo->nombre_var, t2, t1);
            break;
        }

        case N_SI: {
            int lbl_else = new_label();
            int lbl_end = new_label();
            
            int cond = generar_ir(nodo->izq);
            printf("    ifFalse t%d goto L%d\n", cond, lbl_else);
            
            generar_ir(nodo->der); // Cuerpo if
            printf("    goto L%d\n", lbl_end);
            
            printf("L%d:\n", lbl_else);
            if (nodo->centro) {
                generar_ir(nodo->centro); // Cuerpo else
            }
            printf("L%d:\n", lbl_end);
            break;
        }

        case N_MIENTRAS: {
            int lbl_start = new_label();
            int lbl_end = new_label();
            
            printf("L%d:\n", lbl_start);
            int cond = generar_ir(nodo->izq);
            printf("    ifFalse t%d goto L%d\n", cond, lbl_end);
            
            generar_ir(nodo->der); // Cuerpo
            printf("    goto L%d\n", lbl_start);
            printf("L%d:\n", lbl_end);
            break;
        }

        case N_IMPRIMIR:
            // Simplificado: imprimimos cada parametro
            if (nodo->izq) {
                NodoAST *param = nodo->izq;
                while (param && param->tipo == N_LISTA_PARAMETROS) {
                    if (param->izq->tipo == N_CADENA) {
                        printf("    print %s\n", param->izq->val_cadena);
                    } else {
                        int t = generar_ir(param->izq);
                        printf("    print t%d\n", t);
                    }
                    param = param->der;
                }
                if (param) {
                    if (param->tipo == N_CADENA) {
                        printf("    print %s\n", param->val_cadena);
                    } else {
                        int t = generar_ir(param);
                        printf("    print t%d\n", t);
                    }
                }
            }
            break;

        default:
            generar_ir(nodo->izq);
            generar_ir(nodo->der);
            break;
    }
    return -1;
}

void generar_codigo_intermedio(NodoAST *nodo) {
    temp_counter = 0;
    label_counter = 0;
    generar_ir(nodo);
}
