#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"

// Genera un archivo de código C/C++ a partir del AST y lo compila opcionalmente
void generar_codigo_c(NodoAST *raiz, const char *nombre_archivo_salida, const char *nombre_ejecutable);

#endif
