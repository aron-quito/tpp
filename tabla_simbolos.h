#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

/* Tipos de datos que soporta nuestro lenguaje */
typedef enum {
    T_ENTERO,
    T_DECIMAL,
    T_CADENA,
    T_FUNCION
} TipoDato;

/* La estructura para cada símbolo (variable o función) */
typedef struct Simbolo {
    char *nombre;          // Nombre de la variable/función (ej. "promedio")
    TipoDato tipo;         // Tipo de dato (T_ENTERO, T_DECIMAL, etc.)
    int es_funcion;        // 1 si es función, 0 si es variable
    int alcance;           // Ámbito/Scope (0 para global, 1, 2... para locales)
    struct Simbolo *sig;   // Puntero al siguiente símbolo (Lista enlazada)
} Simbolo;

/* Prototipos de las funciones de la tabla */
void insertar_simbolo(char *nombre, TipoDato tipo, int es_funcion, int alcance);
Simbolo* buscar_simbolo_con_ambito(char *nombre, int alcance_actual);
void imprimir_tabla();
void liberar_tabla();

#endif