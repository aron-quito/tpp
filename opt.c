#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opt.h"

void optimizar_ast(NodoAST *nodo) {
    if (!nodo) return;

    // Optimizar los hijos primero
    optimizar_ast(nodo->izq);
    optimizar_ast(nodo->der);

    // Constant Folding: Si es una operacion y ambos hijos son enteros
    if (nodo->tipo == N_OPERACION && nodo->izq && nodo->der) {
        if (nodo->izq->tipo == N_ENTERO && nodo->der->tipo == N_ENTERO) {
            int val_izq = nodo->izq->val_entero;
            int val_der = nodo->der->val_entero;
            int res = 0;
            int valido = 1;

            const char* op = obtener_nombre_operador(nodo->operador);
            if (strcmp(op, "+") == 0) { res = val_izq + val_der; }
            else if (strcmp(op, "-") == 0) { res = val_izq - val_der; }
            else if (strcmp(op, "*") == 0) { res = val_izq * val_der; }
            else if (strcmp(op, "/") == 0) { 
                if (val_der != 0) res = val_izq / val_der;
                else valido = 0; 
            }
            else if (strcmp(op, ">") == 0) { res = val_izq > val_der; }
            else if (strcmp(op, "<") == 0) { res = val_izq < val_der; }
            else if (strcmp(op, "==") == 0) { res = val_izq == val_der; }
            else if (strcmp(op, "!=") == 0) { res = val_izq != val_der; }
            else { valido = 0; }

            if (valido) {
                // Transformar el nodo operacion en un nodo entero
                nodo->tipo = N_ENTERO;
                nodo->val_entero = res;
                // Liberar los hijos
                free(nodo->izq->val_cadena);
                free(nodo->der->val_cadena);
                free(nodo->izq);
                free(nodo->der);
                nodo->izq = NULL;
                nodo->der = NULL;
            }
        }
    }
}
