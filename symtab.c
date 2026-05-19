#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Simbolo *tabla_simbolos = NULL;

void inicializar_symtab() {
    tabla_simbolos = NULL;
}

Simbolo* insertar_simbolo(char *nombre, CategoriaSimbolo cat, int tipo, int ambito) {
    if (buscar_simbolo(nombre) != NULL && cat == SYM_VAR) { // Simplificacion para el ambito global/local
        Simbolo *existente = tabla_simbolos;
        while(existente) {
            if (strcmp(existente->nombre, nombre) == 0 && existente->ambito == ambito) {
                fprintf(stderr, "Error semántico: Redefinición del símbolo '%s' en el mismo ámbito.\n", nombre);
                return NULL;
            }
            existente = existente->sig;
        }
    }
    
    Simbolo *nuevo = (Simbolo*)malloc(sizeof(Simbolo));
    nuevo->nombre = strdup(nombre);
    nuevo->categoria = cat;
    nuevo->tipo = tipo;
    nuevo->num_params = 0;
    nuevo->tipos_params = NULL;
    nuevo->ambito = ambito;
    
    nuevo->sig = tabla_simbolos;
    tabla_simbolos = nuevo;
    
    return nuevo;
}

Simbolo* buscar_simbolo(char *nombre) {
    Simbolo *actual = tabla_simbolos;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return actual;
        }
        actual = actual->sig;
    }
    return NULL;
}

void eliminar_ambito(int ambito) {
    Simbolo *actual = tabla_simbolos;
    Simbolo *prev = NULL;
    
    while (actual != NULL) {
        if (actual->ambito == ambito) {
            Simbolo *eliminar = actual;
            if (prev == NULL) {
                tabla_simbolos = actual->sig;
                actual = tabla_simbolos;
            } else {
                prev->sig = actual->sig;
                actual = prev->sig;
            }
            free(eliminar->nombre);
            if (eliminar->tipos_params != NULL) free(eliminar->tipos_params);
            free(eliminar);
        } else {
            prev = actual;
            actual = actual->sig;
        }
    }
}

void imprimir_symtab() {
    printf("==================== TABLA DE SIMBOLOS ====================\n");
    printf("%-20s %-10s %-10s %-10s\n", "Nombre", "Categoria", "Tipo", "Ambito");
    printf("-----------------------------------------------------------\n");
    Simbolo *actual = tabla_simbolos;
    while (actual != NULL) {
        printf("%-20s %-10s %-10d %-10d\n", actual->nombre, 
               (actual->categoria == SYM_VAR ? "Variable" : "Funcion"), 
               actual->tipo, actual->ambito);
        actual = actual->sig;
    }
    printf("===========================================================\n");
}

void liberar_symtab() {
    Simbolo *actual = tabla_simbolos;
    while (actual != NULL) {
        Simbolo *siguiente = actual->sig;
        free(actual->nombre);
        if (actual->tipos_params != NULL) free(actual->tipos_params);
        free(actual);
        actual = siguiente;
    }
    tabla_simbolos = NULL;
}
