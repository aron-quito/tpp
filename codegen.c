#include "codegen.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static FILE *out;
static int espaciado = 0;
static int en_imprimir = 0;
static int en_for_init = 0;
static int en_for_paso = 0;

static void escribir_espaciado() {
    for (int i = 0; i < espaciado; i++) {
        fprintf(out, "    ");
    }
}

static void visitar_nodo_c(NodoAST *nodo) {
    if (!nodo) return;

    switch (nodo->tipo) {
        case N_ENTERO:
            fprintf(out, "%d", nodo->val_entero);
            break;
        case N_DECIMAL:
            fprintf(out, "%f", nodo->val_decimal);
            break;
        case N_CADENA:
            fprintf(out, "%s", nodo->val_cadena);
            break;
        case N_VARIABLE:
            fprintf(out, "%s", nodo->nombre_var);
            break;
        case N_OPERACION:
            fprintf(out, "(");
            visitar_nodo_c(nodo->izq);
            switch (nodo->operador) {
                case MAS: fprintf(out, " + "); break;
                case MENOS: fprintf(out, " - "); break;
                case MULT: fprintf(out, " * "); break;
                case DIV: fprintf(out, " / "); break;
                case MOD: fprintf(out, " %% "); break;
                case IGUAL: fprintf(out, " == "); break;
                case MENOR: fprintf(out, " < "); break;
                case MAYOR: fprintf(out, " > "); break;
                case MENOR_IGUAL: fprintf(out, " <= "); break;
                case MAYOR_IGUAL: fprintf(out, " >= "); break;
                case DIFERENTE: fprintf(out, " != "); break;
            }
            visitar_nodo_c(nodo->der);
            fprintf(out, ")");
            break;
        case N_ASIGNACION:
            if (!en_for_init && !en_for_paso) escribir_espaciado();
            fprintf(out, "%s = ", nodo->nombre_var);
            visitar_nodo_c(nodo->izq);
            if (!en_for_init && !en_for_paso) fprintf(out, ";\n");
            break;
        case N_DECLARACION_VAR: {
            if (!en_for_init) escribir_espaciado();
            int tipo_var = nodo->operador;
            if (tipo_var == TIPO_ENTERO) fprintf(out, "int ");
            else if (tipo_var == TIPO_DECIMAL) fprintf(out, "double ");
            
            NodoAST *lista_ids = nodo->izq;
            while (lista_ids) {
                if (lista_ids->tipo == N_LISTA_IDS) {
                    fprintf(out, "%s", lista_ids->nombre_var);
                    lista_ids = lista_ids->izq;
                    if (lista_ids) fprintf(out, ", ");
                } else if (lista_ids->tipo == N_ASIGNACION) {
                    // Especial: variables con asignación en la misma línea
                    fprintf(out, "%s = ", lista_ids->nombre_var);
                    visitar_nodo_c(lista_ids->izq);
                    break;
                } else if (lista_ids->tipo == N_VARIABLE) {
                    fprintf(out, "%s", lista_ids->nombre_var);
                    break;
                } else {
                    break;
                }
            }
            if (!en_for_init) fprintf(out, ";\n");
            break;
        }
        case N_IMPRIMIR:
            escribir_espaciado();
            fprintf(out, "std::cout << ");
            en_imprimir = 1;
            visitar_nodo_c(nodo->izq);
            en_imprimir = 0;
            fprintf(out, ";\n");
            break;
        case N_LISTA_ARGUMENTOS:
            if (nodo->izq) {
                visitar_nodo_c(nodo->izq);
                if (en_imprimir) fprintf(out, " << ");
                else fprintf(out, ", ");
            }
            if (nodo->der) {
                visitar_nodo_c(nodo->der);
            }
            break;
        case N_LEER:
            escribir_espaciado();
            fprintf(out, "std::cin >> %s;\n", nodo->nombre_var);
            break;
        case N_RETORNAR:
            escribir_espaciado();
            fprintf(out, "return ");
            visitar_nodo_c(nodo->izq);
            fprintf(out, ";\n");
            break;
        case N_SI:
            escribir_espaciado();
            fprintf(out, "if (");
            visitar_nodo_c(nodo->izq);
            fprintf(out, ") {\n");
            espaciado++;
            visitar_nodo_c(nodo->der);
            espaciado--;
            escribir_espaciado();
            fprintf(out, "}\n");
            if (nodo->centro) {
                escribir_espaciado();
                fprintf(out, "else {\n");
                espaciado++;
                visitar_nodo_c(nodo->centro);
                espaciado--;
                escribir_espaciado();
                fprintf(out, "}\n");
            }
            break;
        case N_MIENTRAS:
            escribir_espaciado();
            fprintf(out, "while (");
            visitar_nodo_c(nodo->izq);
            fprintf(out, ") {\n");
            espaciado++;
            visitar_nodo_c(nodo->der);
            espaciado--;
            escribir_espaciado();
            fprintf(out, "}\n");
            break;
        case N_PARA:
            escribir_espaciado();
            fprintf(out, "for (");
            en_for_init = 1;
            visitar_nodo_c(nodo->izq); // init
            en_for_init = 0;
            fprintf(out, "; ");
            visitar_nodo_c(nodo->der); // condicion
            fprintf(out, "; ");
            en_for_paso = 1;
            visitar_nodo_c(nodo->centro); // paso
            en_for_paso = 0;
            fprintf(out, ") {\n");
            espaciado++;
            visitar_nodo_c(nodo->adicional); // cuerpo
            espaciado--;
            escribir_espaciado();
            fprintf(out, "}\n");
            break;
        case N_DEPENDE:
            escribir_espaciado();
            fprintf(out, "switch (");
            visitar_nodo_c(nodo->izq);
            fprintf(out, ") {\n");
            espaciado++;
            visitar_nodo_c(nodo->der);
            espaciado--;
            escribir_espaciado();
            fprintf(out, "}\n");
            break;
        case N_CASO:
            escribir_espaciado();
            if (nodo->izq) {
                fprintf(out, "case ");
                visitar_nodo_c(nodo->izq);
                fprintf(out, ":\n");
            } else {
                fprintf(out, "default:\n");
            }
            espaciado++;
            visitar_nodo_c(nodo->der);
            escribir_espaciado();
            fprintf(out, "break;\n");
            espaciado--;
            break;
        case N_LLAMADA_FUNCION:
            fprintf(out, "%s(", nodo->nombre_var);
            visitar_nodo_c(nodo->izq);
            fprintf(out, ")");
            break;
        case N_DECLARACION_FUN:
            escribir_espaciado();
            if (nodo->operador == TIPO_ENTERO) fprintf(out, "int ");
            else if (nodo->operador == TIPO_DECIMAL) fprintf(out, "double ");
            else fprintf(out, "void ");
            
            fprintf(out, "%s(", nodo->nombre_var);
            visitar_nodo_c(nodo->izq); // Parametros
            fprintf(out, ") {\n");
            espaciado++;
            visitar_nodo_c(nodo->der); // Cuerpo
            espaciado--;
            fprintf(out, "}\n\n");
            break;
        case N_PARAMETRO:
            if (nodo->operador == TIPO_ENTERO) fprintf(out, "int ");
            else if (nodo->operador == TIPO_DECIMAL) fprintf(out, "double ");
            fprintf(out, "%s", nodo->nombre_var);
            break;
        case N_LISTA_PARAMETROS:
            if (nodo->izq) {
                visitar_nodo_c(nodo->izq);
                fprintf(out, ", ");
            }
            if (nodo->der) {
                visitar_nodo_c(nodo->der);
            }
            break;
        case N_LISTA_ELEMENTOS:
        case N_LISTA_CASOS:
            visitar_nodo_c(nodo->izq);
            visitar_nodo_c(nodo->der);
            break;
        default:
            break;
    }
}

static void visitar_funciones(NodoAST *nodo) {
    if (!nodo) return;
    if (nodo->tipo == N_LISTA_ELEMENTOS) {
        visitar_funciones(nodo->izq);
        visitar_funciones(nodo->der);
    } else if (nodo->tipo == N_DECLARACION_FUN) {
        visitar_nodo_c(nodo);
    }
}

static void visitar_instrucciones(NodoAST *nodo) {
    if (!nodo) return;
    if (nodo->tipo == N_LISTA_ELEMENTOS) {
        visitar_instrucciones(nodo->izq);
        visitar_instrucciones(nodo->der);
    } else if (nodo->tipo != N_DECLARACION_FUN) {
        visitar_nodo_c(nodo);
    }
}

void generar_codigo_c(NodoAST *raiz, const char *nombre_archivo_salida, const char *nombre_ejecutable) {
    out = fopen(nombre_archivo_salida, "w");
    if (!out) {
        fprintf(stderr, "Error: No se pudo crear el archivo de salida %s\n", nombre_archivo_salida);
        return;
    }
    
    printf("Generando codigo C++ en '%s'...\n", nombre_archivo_salida);
    
    // Incluir cabeceras necesarias
    fprintf(out, "#include <iostream>\n");
    fprintf(out, "#include <string>\n\n");
    
    // Primero, declarar/definir las funciones globales
    visitar_funciones(raiz->izq);
    
    // Luego, crear la función main para el resto de instrucciones
    fprintf(out, "int main() {\n");
    espaciado++;
    
    visitar_instrucciones(raiz->izq);
    
    escribir_espaciado();
    fprintf(out, "return 0;\n");
    espaciado--;
    fprintf(out, "}\n");
    
    fclose(out);
    
    printf("Generacion exitosa. Compilando ejecutable final...\n");
    
    // Llamar al compilador g++ del sistema
    char comando[256];
    snprintf(comando, sizeof(comando), "g++ %s -o %s", nombre_archivo_salida, nombre_ejecutable);
    int res = system(comando);
    if (res == 0) {
        printf("¡Compilacion final exitosa! Puedes ejecutar tu programa con: ./%s\n\n", nombre_ejecutable);
    } else {
        printf("Hubo un error al compilar el archivo generado.\n");
    }
}
