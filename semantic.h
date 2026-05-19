#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"
#include "symtab.h"

// Realiza el analisis semantico del AST (construye tabla de simbolos, verifica tipos)
// Devuelve 1 si hay exito, 0 si hay errores semanticos
int analizar_semantica(NodoAST *raiz);

#endif
