#ifndef AST_H
#define AST_H

/* Definimos una lista con todos los tipos de nodos posibles que puede tener el árbol */
typedef enum {
    N_ENTERO,
    N_DECIMAL,
    N_VARIABLE,
    N_OPERACION
    // Más adelante agregaremos N_SI, N_MIENTRAS, N_ASIGNACION, etc.
} TipoNodo;

/* La estructura fundamental de nuestro Árbol Sintáctico Abstracto */
typedef struct NodoAST {
    TipoNodo tipo;
    
    /* Ramas: Útiles para nodos de operación (ej: 2 + 3) */
    struct NodoAST *izq;
    struct NodoAST *der;
    int operador; /* Guardará el token de la operación (MAS, MENOS, MULT...) */
    
    /* Hojas: Útiles si el nodo es un valor final y no tiene ramas */
    int val_entero;
    double val_decimal;
    char* nombre_var;
} NodoAST;

/* Prototipos de las funciones que "construirán" los nodos en memoria */
NodoAST* nuevo_nodo_entero(int valor);
NodoAST* nuevo_nodo_decimal(double valor);
NodoAST* nuevo_nodo_variable(char* nombre);
NodoAST* nuevo_nodo_operacion(int operador, NodoAST* izq, NodoAST* der);

#endif