#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

/* La cabeza de nuestra lista enlazada (la tabla global) */
Simbolo *tabla = NULL;

extern int errores_semanticos;  // Contador global de errores semánticos

/* Función para insertar una variable o función en la tabla */
void insertar_simbolo(char *nombre, TipoDato tipo, int es_funcion, int alcance) {
    // Primero verificamos si ya existe en el mismo alcance (error de doble declaración)
    Simbolo *existente = buscar_simbolo(nombre);
    if (existente && existente->alcance == alcance) {
        fprintf(stderr, "Error Semantico: La variable o funcion '%s' ya fue declarada en este ambito.\n", nombre);
        errores_semanticos++;
        return;
    }

    // Creamos el nuevo símbolo en memoria
    Simbolo *nuevo = (Simbolo*)malloc(sizeof(Simbolo));
    nuevo->nombre = strdup(nombre);
    nuevo->tipo = tipo;
    nuevo->es_funcion = es_funcion;
    nuevo->alcance = alcance;
    
    // Lo insertamos al inicio de la lista
    nuevo->sig = tabla;
    tabla = nuevo;
}

/* Función para buscar si una variable ya existe */
Simbolo* buscar_simbolo(char *nombre) {
    Simbolo *actual = tabla;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return actual; // Lo encontró
        }
        actual = actual->sig;
    }
    return NULL; // No existe
}

/* Para debugear y ver qué tiene nuestra tabla */
void imprimir_tabla() {
    printf("\n=== TABLA DE SIMBOLOS ===\n");
    Simbolo *actual = tabla;
    while (actual != NULL) {
        printf("Nombre: %-15s | Tipo: %-8s | Es Fun?: %d | Ambito: %d\n",
               actual->nombre,
               (actual->tipo == T_ENTERO) ? "ENTERO" : (actual->tipo == T_DECIMAL) ? "DECIMAL" : "CADENA",
               actual->es_funcion,
               actual->alcance);
        actual = actual->sig;
    }
    printf("=========================\n");
}

/* Liberar memoria al final */
void liberar_tabla() {
    Simbolo *actual = tabla;
    while (actual != NULL) {
        Simbolo *aux = actual->sig;
        free(actual->nombre);
        free(actual);
        actual = aux;
    }
    tabla = NULL;
}