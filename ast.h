#ifndef AST_H
#define AST_H

/* Definimos una lista con todos los tipos de nodos posibles que puede tener el árbol */
typedef enum {
    N_ENTERO,
    N_DECIMAL,
    N_CADENA,
    N_VARIABLE,
    N_OPERACION,
    N_ASIGNACION,
    N_DECLARACION_VAR,
    N_LISTA_IDS,
    N_IMPRIMIR,
    N_LEER,
    N_RETORNAR,
    N_SI,
    N_MIENTRAS,
    N_PARA,
    N_DEPENDE,
    N_CASO,
    N_LISTA_CASOS,
    N_LLAMADA_FUNCION,
    N_LISTA_ARGUMENTOS,
    N_DECLARACION_FUN,
    N_PARAMETRO,
    N_LISTA_PARAMETROS,
    N_LISTA_ELEMENTOS,
    N_PROGRAMA
} TipoNodo;

/* La estructura fundamental de nuestro Árbol Sintáctico Abstracto */
typedef struct NodoAST {
    TipoNodo tipo;
    
    /* Ramas: Útiles para nodos de operación y estructuras complejas */
    struct NodoAST *izq;
    struct NodoAST *der;
    struct NodoAST *centro;      /* Para condicionales (SINO) o bucles (PARA) */
    struct NodoAST *adicional;   /* Para el cuerpo de estructuras complejas (PARA) o más ramas */
    
    int operador; /* Guardará el token de la operación (MAS, MENOS, MULT...) o tipo */
    
    /* Hojas: Útiles si el nodo es un valor final y no tiene ramas */
    int val_entero;
    double val_decimal;
    char* nombre_var;
    char* val_cadena;
} NodoAST;

/* Prototipos de las funciones que "construirán" los nodos en memoria */
NodoAST* nuevo_nodo_entero(int valor);
NodoAST* nuevo_nodo_decimal(double valor);
NodoAST* nuevo_nodo_variable(char* nombre);
NodoAST* nuevo_nodo_cadena(char* cadena);
NodoAST* nuevo_nodo_operacion(int operador, NodoAST* izq, NodoAST* der);
NodoAST* nuevo_nodo_asignacion(char* nombre_var, NodoAST* expresion);
NodoAST* nuevo_nodo_declaracion_var(int tipo, NodoAST* lista_ids);
NodoAST* nuevo_nodo_lista_ids(NodoAST* lista, char* id);
NodoAST* nuevo_nodo_imprimir(NodoAST* lista_impresion);
NodoAST* nuevo_nodo_leer(char* nombre_var);
NodoAST* nuevo_nodo_retornar(NodoAST* expresion);
NodoAST* nuevo_nodo_si(NodoAST* condicion, NodoAST* bloque_si, NodoAST* bloque_sino);
NodoAST* nuevo_nodo_mientras(NodoAST* condicion, NodoAST* bloque);
NodoAST* nuevo_nodo_para(NodoAST* init, NodoAST* condicion, NodoAST* paso, NodoAST* bloque);
NodoAST* nuevo_nodo_depende(NodoAST* expresion, NodoAST* lista_casos);
NodoAST* nuevo_nodo_caso(NodoAST* valor, NodoAST* bloque);
NodoAST* nuevo_nodo_lista_casos(NodoAST* lista, NodoAST* caso);
NodoAST* nuevo_nodo_llamada_funcion(char* nombre_fun, NodoAST* argumentos);
NodoAST* nuevo_nodo_lista_argumentos(NodoAST* lista, NodoAST* argumento);
NodoAST* nuevo_nodo_declaracion_fun(char* nombre_fun, int tipo_retorno, NodoAST* parametros, NodoAST* bloque);
NodoAST* nuevo_nodo_parametro(int tipo, char* nombre);
NodoAST* nuevo_nodo_lista_parametros(NodoAST* lista, NodoAST* parametro);
NodoAST* nuevo_nodo_lista_elementos(NodoAST* lista, NodoAST* elemento);
NodoAST* nuevo_nodo_programa(NodoAST* lista_elementos);

/* Función para imprimir y visualizar el AST de forma jerárquica */
void imprimir_ast(NodoAST* nodo, int esp);

/* Función para liberar la memoria ocupada por el AST recursivamente */
void liberar_ast(NodoAST* nodo);

#endif