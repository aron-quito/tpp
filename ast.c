#include <stdlib.h>
#include <string.h>
#include "ast.h"

// Crea un nodo hoja para un número entero (no tiene ramas)
NodoAST* nuevo_nodo_entero(int valor) {
    NodoAST* nodo = (NodoAST*)malloc(sizeof(NodoAST));
    nodo->tipo = N_ENTERO;
    nodo->val_entero = valor;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

// Crea un nodo hoja para un número decimal
NodoAST* nuevo_nodo_decimal(double valor) {
    NodoAST* nodo = (NodoAST*)malloc(sizeof(NodoAST));
    nodo->tipo = N_DECIMAL;
    nodo->val_decimal = valor;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

// Crea un nodo hoja para una variable
NodoAST* nuevo_nodo_variable(char* nombre) {
    NodoAST* nodo = (NodoAST*)malloc(sizeof(NodoAST));
    nodo->tipo = N_VARIABLE;
    // Usamos strdup para copiar el string y no perder la referencia
    nodo->nombre_var = strdup(nombre); 
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

// Crea un nodo padre que une dos ramas mediante una operación (+, -, *, /)
NodoAST* nuevo_nodo_operacion(int operador, NodoAST* izq, NodoAST* der) {
    NodoAST* nodo = (NodoAST*)malloc(sizeof(NodoAST));
    nodo->tipo = N_OPERACION;
    nodo->operador = operador;
    nodo->izq = izq; // Rama izquierda
    nodo->der = der; // Rama derecha
    return nodo;
}