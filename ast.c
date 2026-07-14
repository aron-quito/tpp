#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función auxiliar interna para asignar memoria limpia a un nuevo nodo
static NodoAST *crear_nodo(TipoNodo tipo) {
  NodoAST *nodo = (NodoAST *)malloc(sizeof(NodoAST));
  if (!nodo) {
    fprintf(
        stderr,
        "Error fatal: No hay memoria suficiente para crear el nodo del AST.\n");
    exit(1);
  }
  nodo->tipo = tipo;
  nodo->izq = NULL;
  nodo->der = NULL;
  nodo->centro = NULL;
  nodo->adicional = NULL;
  nodo->operador = 0;
  nodo->val_entero = 0;
  nodo->val_decimal = 0.0;
  nodo->nombre_var = NULL;
  nodo->val_cadena = NULL;
  return nodo;
}

// Crea un nodo hoja para un número entero
NodoAST *nuevo_nodo_entero(int valor) {
  NodoAST *nodo = crear_nodo(N_ENTERO);
  nodo->val_entero = valor;
  return nodo;
}

// Crea un nodo hoja para un número decimal
NodoAST *nuevo_nodo_decimal(double valor) {
  NodoAST *nodo = crear_nodo(N_DECIMAL);
  nodo->val_decimal = valor;
  return nodo;
}

// Crea un nodo hoja para una variable
NodoAST *nuevo_nodo_variable(char *nombre) {
  NodoAST *nodo = crear_nodo(N_VARIABLE);
  nodo->nombre_var = strdup(nombre);
  return nodo;
}

// Crea un nodo hoja para una cadena de texto
NodoAST *nuevo_nodo_cadena(char *cadena) {
  NodoAST *nodo = crear_nodo(N_CADENA);
  nodo->val_cadena = strdup(cadena);
  return nodo;
}

// Crea un nodo padre que une dos ramas mediante una operación (+, -, *, /,
// comparaciones, etc.)
NodoAST *nuevo_nodo_operacion(int operador, NodoAST *izq, NodoAST *der) {
  NodoAST *nodo = crear_nodo(N_OPERACION);
  nodo->operador = operador;
  nodo->izq = izq;
  nodo->der = der;
  return nodo;
}

// Crea un nodo para una asignación de variable
NodoAST *nuevo_nodo_asignacion(char *nombre_var, NodoAST *expresion) {
  NodoAST *nodo = crear_nodo(N_ASIGNACION);
  nodo->nombre_var = strdup(nombre_var);
  nodo->izq = expresion;
  return nodo;
}

NodoAST *nuevo_nodo_declaracion_arreglo(char *nombre_var, int tamanio) {
  NodoAST *nodo = crear_nodo(N_DECLARACION_ARREGLO);
  nodo->nombre_var = strdup(nombre_var);
  nodo->val_entero = tamanio;
  return nodo;
}

NodoAST *nuevo_nodo_acceso_arreglo(char *nombre_var, NodoAST *indice) {
  NodoAST *nodo = crear_nodo(N_ACCESO_ARREGLO);
  nodo->nombre_var = strdup(nombre_var);
  nodo->izq = indice;
  return nodo;
}

NodoAST *nuevo_nodo_asignacion_arreglo(char *nombre_var, NodoAST *indice, NodoAST *expresion) {
  NodoAST *nodo = crear_nodo(N_ASIGNACION_ARREGLO);
  nodo->nombre_var = strdup(nombre_var);
  nodo->izq = indice;
  nodo->der = expresion;
  return nodo;
}

// Crea un nodo para una declaración de variables
NodoAST *nuevo_nodo_declaracion_var(int tipo, NodoAST *lista_ids) {
  NodoAST *nodo = crear_nodo(N_DECLARACION_VAR);
  nodo->operador = tipo;
  nodo->izq = lista_ids;
  return nodo;
}

// Crea un nodo para enlazar identificadores en una declaración múltiple
NodoAST *nuevo_nodo_lista_ids(NodoAST *lista, char *id) {
  NodoAST *nodo = crear_nodo(N_LISTA_IDS);
  nodo->izq = lista; // Puede ser otra lista o NULL
  nodo->nombre_var = strdup(id);
  return nodo;
}

// Crea un nodo para la instrucción 'imprimir'
NodoAST *nuevo_nodo_imprimir(NodoAST *lista_impresion) {
  NodoAST *nodo = crear_nodo(N_IMPRIMIR);
  nodo->izq = lista_impresion;
  return nodo;
}

// Crea un nodo para la instrucción 'leer'
NodoAST *nuevo_nodo_leer(char *nombre_var) {
  NodoAST *nodo = crear_nodo(N_LEER);
  nodo->nombre_var = strdup(nombre_var);
  return nodo;
}

// Crea un nodo para la instrucción de retorno
NodoAST *nuevo_nodo_retornar(NodoAST *expresion) {
  NodoAST *nodo = crear_nodo(N_RETORNAR);
  nodo->izq = expresion;
  return nodo;
}

// Crea un nodo para la estructura condicional SI-SINO
NodoAST *nuevo_nodo_si(NodoAST *condicion, NodoAST *bloque_si,
                       NodoAST *bloque_sino) {
  NodoAST *nodo = crear_nodo(N_SI);
  nodo->izq = condicion;
  nodo->der = bloque_si;
  nodo->centro = bloque_sino; // NULL si no hay SINO
  return nodo;
}

// Crea un nodo para el bucle MIENTRAS
NodoAST *nuevo_nodo_mientras(NodoAST *condicion, NodoAST *bloque) {
  NodoAST *nodo = crear_nodo(N_MIENTRAS);
  nodo->izq = condicion;
  nodo->der = bloque;
  return nodo;
}

// Crea un nodo para el bucle PARA
NodoAST *nuevo_nodo_para(NodoAST *init, NodoAST *condicion, NodoAST *paso,
                         NodoAST *bloque) {
  NodoAST *nodo = crear_nodo(N_PARA);
  nodo->izq = init;
  nodo->der = condicion;
  nodo->centro = paso;
  nodo->adicional = bloque;
  return nodo;
}

// Crea un nodo para la estructura de decisión DEPENDE
NodoAST *nuevo_nodo_depende(NodoAST *expresion, NodoAST *lista_casos) {
  NodoAST *nodo = crear_nodo(N_DEPENDE);
  nodo->izq = expresion;
  nodo->der = lista_casos;
  return nodo;
}

// Crea un caso particular de la estructura DEPENDE
NodoAST *nuevo_nodo_caso(NodoAST *valor, NodoAST *bloque) {
  NodoAST *nodo = crear_nodo(N_CASO);
  nodo->izq = valor; // NULL en caso de 'otros'
  nodo->der = bloque;
  return nodo;
}

// Une casos en una lista de casos
NodoAST *nuevo_nodo_lista_casos(NodoAST *lista, NodoAST *caso) {
  NodoAST *nodo = crear_nodo(N_LISTA_CASOS);
  nodo->izq = lista;
  nodo->der = caso;
  return nodo;
}

// Crea una llamada a función con sus argumentos
NodoAST *nuevo_nodo_llamada_funcion(char *nombre_fun, NodoAST *argumentos) {
  NodoAST *nodo = crear_nodo(N_LLAMADA_FUNCION);
  nodo->nombre_var = strdup(nombre_fun);
  nodo->izq = argumentos;
  return nodo;
}

// Une expresiones de argumentos en una lista
NodoAST *nuevo_nodo_lista_argumentos(NodoAST *lista, NodoAST *argumento) {
  NodoAST *nodo = crear_nodo(N_LISTA_ARGUMENTOS);
  nodo->izq = lista;
  nodo->der = argumento;
  return nodo;
}

// Crea la declaración de una nueva función
NodoAST *nuevo_nodo_declaracion_fun(char *nombre_fun, int tipo_retorno,
                                    NodoAST *parametros, NodoAST *bloque) {
  NodoAST *nodo = crear_nodo(N_DECLARACION_FUN);
  nodo->nombre_var = strdup(nombre_fun);
  nodo->operador = tipo_retorno; // Puede ser 0 o vacío
  nodo->izq = parametros;
  nodo->der = bloque;
  return nodo;
}

// Crea un parámetro con su tipo y su identificador
NodoAST *nuevo_nodo_parametro(int tipo, char *nombre) {
  NodoAST *nodo = crear_nodo(N_PARAMETRO);
  nodo->operador = tipo;
  nodo->nombre_var = strdup(nombre);
  return nodo;
}

// Une parámetros en una lista
NodoAST *nuevo_nodo_lista_parametros(NodoAST *lista, NodoAST *parametro) {
  NodoAST *nodo = crear_nodo(N_LISTA_PARAMETROS);
  nodo->izq = lista;
  nodo->der = parametro;
  return nodo;
}

// Une elementos generales (declaraciones, instrucciones)
NodoAST *nuevo_nodo_lista_elementos(NodoAST *lista, NodoAST *elemento) {
  NodoAST *nodo = crear_nodo(N_LISTA_ELEMENTOS);
  nodo->izq = lista;
  nodo->der = elemento;
  return nodo;
}

// Crea el nodo raíz del programa completo
NodoAST *nuevo_nodo_programa(NodoAST *lista_elementos) {
  NodoAST *nodo = crear_nodo(N_PROGRAMA);
  nodo->izq = lista_elementos;
  return nodo;
}

// Obtiene la representación de texto para operadores y tipos
const char *obtener_nombre_operador(int op) {
  switch (op) {
  case MAS:
    return "+";
  case MENOS:
    return "-";
  case MULT:
    return "*";
  case DIV:
    return "/";
  case MOD:
    return "%";
  case ASIG:
    return "=";
  case IGUAL:
    return "==";
  case MENOR:
    return "<";
  case MAYOR:
    return ">";
  case MENOR_IGUAL:
    return "<=";
  case MAYOR_IGUAL:
    return ">=";
  case DIFERENTE:
    return "!=";
  case TIPO_ENTERO:
    return "entero";
  case TIPO_DECIMAL:
    return "decimal";
  default:
    return "?";
  }
}

// Imprime tabulaciones según la profundidad del nodo
static void imp_espacios(int esp) {
  for (int i = 0; i < esp; i++) {
    printf("  | ");
  }
}

// Recorrido en profundidad preorden para visualizar el AST
void imprimir_ast(NodoAST *nodo, int esp) {
  if (!nodo)
    return;

  imp_espacios(esp);

  switch (nodo->tipo) {
  case N_ENTERO:
    printf("[Entero] %d\n", nodo->val_entero);
    break;
  case N_DECIMAL:
    printf("[Decimal] %f\n", nodo->val_decimal);
    break;
  case N_CADENA:
    printf("[Cadena] %s\n", nodo->val_cadena);
    break;
  case N_VARIABLE:
    printf("[Variable] %s\n", nodo->nombre_var);
    break;
  case N_OPERACION:
    printf("[Operacion] '%s'\n", obtener_nombre_operador(nodo->operador));
    imprimir_ast(nodo->izq, esp + 1);
    imprimir_ast(nodo->der, esp + 1);
    break;
  case N_ASIGNACION:
    printf("[Asignacion] a variable '%s'\n", nodo->nombre_var);
    imprimir_ast(nodo->izq, esp + 1);
    break;
  case N_DECLARACION_ARREGLO:
    printf("[Declaracion Arreglo] %s[%d]\n", nodo->nombre_var, nodo->val_entero);
    break;
  case N_ACCESO_ARREGLO:
    printf("[Acceso Arreglo] %s\n", nodo->nombre_var);
    imprimir_ast(nodo->izq, esp + 1);
    break;
  case N_ASIGNACION_ARREGLO:
    printf("[Asignacion Arreglo] %s\n", nodo->nombre_var);
    printf("  [Indice]:\n");
    imprimir_ast(nodo->izq, esp + 2);
    printf("  [Valor]:\n");
    imprimir_ast(nodo->der, esp + 2);
    break;
  case N_DECLARACION_VAR:
    printf("[Declaracion Var] Tipo: '%s'\n",
           obtener_nombre_operador(nodo->operador));
    imprimir_ast(nodo->izq, esp + 1);
    break;
  case N_LISTA_IDS:
    printf("[Lista IDs] ID: '%s'\n", nodo->nombre_var);
    if (nodo->izq) {
      imprimir_ast(nodo->izq, esp + 1);
    }
    break;
  case N_IMPRIMIR:
    printf("[Imprimir]\n");
    imprimir_ast(nodo->izq, esp + 1);
    break;
  case N_LEER:
    printf("[Leer] Variable: '%s'\n", nodo->nombre_var);
    break;
  case N_RETORNAR:
    printf("[Retornar]\n");
    imprimir_ast(nodo->izq, esp + 1);
    break;
  case N_SI:
    printf("[Si] Condicion:\n");
    imprimir_ast(nodo->izq, esp + 1);
    imp_espacios(esp);
    printf("  Entonces:\n");
    imprimir_ast(nodo->der, esp + 1);
    if (nodo->centro) {
      imp_espacios(esp);
      printf("  Sino:\n");
      imprimir_ast(nodo->centro, esp + 1);
    }
    break;
  case N_MIENTRAS:
    printf("[Mientras] Condicion:\n");
    imprimir_ast(nodo->izq, esp + 1);
    imp_espacios(esp);
    printf("  Cuerpo:\n");
    imprimir_ast(nodo->der, esp + 1);
    break;
  case N_PARA:
    printf("[Para] Inicializacion:\n");
    imprimir_ast(nodo->izq, esp + 1);
    imp_espacios(esp);
    printf("  Condicion:\n");
    imprimir_ast(nodo->der, esp + 1);
    imp_espacios(esp);
    printf("  Paso:\n");
    imprimir_ast(nodo->centro, esp + 1);
    imp_espacios(esp);
    printf("  Cuerpo:\n");
    imprimir_ast(nodo->adicional, esp + 1);
    break;
  case N_DEPENDE:
    printf("[Depende] Expresion:\n");
    imprimir_ast(nodo->izq, esp + 1);
    imp_espacios(esp);
    printf("  Casos:\n");
    imprimir_ast(nodo->der, esp + 1);
    break;
  case N_CASO:
    if (nodo->izq) {
      printf("[Caso] Valor:\n");
      imprimir_ast(nodo->izq, esp + 1);
    } else {
      printf("[Caso] Otros:\n");
    }
    imp_espacios(esp);
    printf("  Cuerpo del Caso:\n");
    imprimir_ast(nodo->der, esp + 1);
    break;
  case N_LISTA_CASOS:
    printf("[Lista Casos]\n");
    imprimir_ast(nodo->izq, esp + 1);
    imprimir_ast(nodo->der, esp + 1);
    break;
  case N_LLAMADA_FUNCION:
    printf("[Llamada Funcion] Nombre: '%s'\n", nodo->nombre_var);
    if (nodo->izq) {
      imp_espacios(esp);
      printf("  Argumentos:\n");
      imprimir_ast(nodo->izq, esp + 1);
    }
    break;
  case N_LISTA_ARGUMENTOS:
    printf("[Lista Argumentos/Expresiones]\n");
    if (nodo->izq) {
      imprimir_ast(nodo->izq, esp + 1);
    }
    if (nodo->der) {
      imprimir_ast(nodo->der, esp + 1);
    }
    break;
  case N_DECLARACION_FUN:
    printf("[Declaracion Funcion] Nombre: '%s' (Retorno: '%s')\n",
           nodo->nombre_var,
           nodo->operador ? obtener_nombre_operador(nodo->operador)
                          : "ninguno");
    if (nodo->izq) {
      imp_espacios(esp);
      printf("  Parametros:\n");
      imprimir_ast(nodo->izq, esp + 1);
    }
    imp_espacios(esp);
    printf("  Cuerpo:\n");
    imprimir_ast(nodo->der, esp + 1);
    break;
  case N_PARAMETRO:
    printf("[Parametro] Nombre: '%s' (Tipo: '%s')\n", nodo->nombre_var,
           obtener_nombre_operador(nodo->operador));
    break;
  case N_LISTA_PARAMETROS:
    printf("[Lista Parametros]\n");
    if (nodo->izq) {
      imprimir_ast(nodo->izq, esp + 1);
    }
    if (nodo->der) {
      imprimir_ast(nodo->der, esp + 1);
    }
    break;
  case N_LISTA_ELEMENTOS:
    printf("[Lista Elementos / Instrucciones]\n");
    if (nodo->izq) {
      imprimir_ast(nodo->izq, esp + 1);
    }
    if (nodo->der) {
      imprimir_ast(nodo->der, esp + 1);
    }
    break;
  case N_PROGRAMA:
    printf("[Programa / Nodo Raiz]\n");
    imprimir_ast(nodo->izq, esp + 1);
    break;
  default:
    printf("[Nodo Desconocido] tipo: %d\n", nodo->tipo);
    break;
  }
}

// Libera recursivamente toda la memoria ocupada por los nodos del AST
void liberar_ast(NodoAST *nodo) {
  if (!nodo)
    return;

  liberar_ast(nodo->izq);
  liberar_ast(nodo->der);
  liberar_ast(nodo->centro);
  liberar_ast(nodo->adicional);

  if (nodo->nombre_var) {
    free(nodo->nombre_var);
  }
  if (nodo->val_cadena) {
    free(nodo->val_cadena);
  }

  free(nodo);
}