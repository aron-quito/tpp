#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include <stdio.h>

/* Genera código ensamblador RISC-V puro (RV32I) a partir del AST.
 * Escribe el resultado en el archivo proporcionado.
 * Retorna 1 si es exitoso, 0 si hay errores no recuperables.
 */
int generar_codigo(NodoAST *raiz, FILE *out);

#endif
