#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Simbolo *tabla_simbolos = NULL;

static unsigned int mem_disponible = 0;

void inicializar_symtab() {
    tabla_simbolos = NULL;
    mem_disponible = 0;
}

Simbolo* insertar_simbolo(char *nombre, CategoriaSimbolo cat, int tipo, int ambito, int tamanio) {
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
    nuevo->tamanio = tamanio;
    
    if (cat == SYM_VAR) {
        nuevo->direccion_memoria = mem_disponible;
        mem_disponible += 4 * tamanio;
    } else {
        nuevo->direccion_memoria = 0;
    }
    
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

static const char* nombre_tipo(int tipo) {
    switch(tipo) {
        case 268: return "entero";
        case 269: return "decimal";
        case 0:   return "ninguno";
        default:  return "?";
    }
}

void imprimir_symtab() {
    printf("==================== TABLA DE SIMBOLOS ====================\n");
    printf("%-20s %-10s %-10s %-8s %-8s %-10s\n", 
           "Nombre", "Categoria", "Tipo", "Ambito", "Tam", "Memoria");
    printf("----------------------------------------------------------------------\n");
    
    Simbolo *actual = tabla_simbolos;
    int count = 0;
    while (actual != NULL) {
        char tam_str[16];
        if (actual->categoria == SYM_VAR && actual->tamanio > 1) {
            sprintf(tam_str, "[%d]", actual->tamanio);
        } else if (actual->categoria == SYM_VAR) {
            sprintf(tam_str, "1");
        } else {
            sprintf(tam_str, "-");
        }
        
        printf("%-20s %-10s %-10s %-8d %-8s 0x%08X\n", 
               actual->nombre, 
               (actual->categoria == SYM_VAR ? "Variable" : "Funcion"), 
               nombre_tipo(actual->tipo),
               actual->ambito,
               tam_str,
               actual->direccion_memoria);
        actual = actual->sig;
        count++;
    }
    printf("----------------------------------------------------------------------\n");
    printf("Total: %d simbolos | Memoria usada: %u bytes (%u words)\n", 
           count, mem_disponible, mem_disponible / 4);
    printf("======================================================================\n");
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

unsigned int obtener_mem_disponible() {
    return mem_disponible;
}
