#ifndef SYMTAB_H
#define SYMTAB_H

typedef enum {
    SYM_VAR,
    SYM_FUN
} CategoriaSimbolo;

typedef struct Simbolo {
    char *nombre;
    CategoriaSimbolo categoria;
    int tipo;               // Token TIPO_ENTERO, TIPO_DECIMAL, etc. (0 para void/ninguno)
    int num_params;         // Para funciones
    int *tipos_params;      // Tipos de los parámetros para funciones
    int ambito;             // 0=global, 1,2,3...=local
    struct Simbolo *sig;
} Simbolo;

void inicializar_symtab();
Simbolo* insertar_simbolo(char *nombre, CategoriaSimbolo cat, int tipo, int ambito);
Simbolo* buscar_simbolo(char *nombre);
void eliminar_ambito(int ambito);
void imprimir_symtab();
void liberar_symtab();

#endif
