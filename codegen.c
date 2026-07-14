#include "codegen.h"
#include "symtab.h"
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>

static int label_counter = 0;
static char current_func_name[256] = "";

static int new_label() {
    return ++label_counter;
}

static void evaluar_argumentos(NodoAST *nodo, FILE *out, int *arg_idx);
static void traducir_expresion(NodoAST *nodo, FILE *out, int target_reg) {
    if (!nodo) return;
    
    if (target_reg > 6) {
        fprintf(stderr, "Error de codegen: Expresión demasiado compleja (desbordamiento de registros t0-t6).\n");
        return;
    }

    switch(nodo->tipo) {
        case N_ENTERO:
            fprintf(out, "    li t%d, %d\n", target_reg, nodo->val_entero);
            break;
        case N_VARIABLE: {
            fprintf(out, "    lw t%d, %d(sp)\n", target_reg, nodo->val_entero);
            break;
        }
        case N_ACCESO_ARREGLO: {
            traducir_expresion(nodo->izq, out, target_reg);
            fprintf(out, "    slli t%d, t%d, 2\n", target_reg, target_reg);
            fprintf(out, "    li t%d, %d\n", target_reg + 1, nodo->val_entero);
            fprintf(out, "    add t%d, t%d, t%d\n", target_reg, target_reg, target_reg + 1);
            fprintf(out, "    add t%d, t%d, sp\n", target_reg, target_reg);
            fprintf(out, "    lw t%d, 0(t%d)\n", target_reg, target_reg);
            break;
        }
        case N_OPERACION: {
            traducir_expresion(nodo->izq, out, target_reg);
            traducir_expresion(nodo->der, out, target_reg + 1);
            
            switch(nodo->operador) {
                case MAS:
                    fprintf(out, "    add t%d, t%d, t%d\n", target_reg, target_reg, target_reg + 1);
                    break;
                case MENOS:
                    fprintf(out, "    sub t%d, t%d, t%d\n", target_reg, target_reg, target_reg + 1);
                    break;
                case MULT:
                    fprintf(out, "    mv a0, t%d\n", target_reg);
                    fprintf(out, "    mv a1, t%d\n", target_reg + 1);
                    fprintf(out, "    call __soft_mul\n");
                    fprintf(out, "    mv t%d, a0\n", target_reg);
                    break;
                case IGUAL:
                    fprintf(out, "    sub t%d, t%d, t%d\n", target_reg, target_reg, target_reg + 1);
                    fprintf(out, "    seqz t%d, t%d\n", target_reg, target_reg);
                    break;
                case DIFERENTE:
                    fprintf(out, "    sub t%d, t%d, t%d\n", target_reg, target_reg, target_reg + 1);
                    fprintf(out, "    snez t%d, t%d\n", target_reg, target_reg);
                    break;
                case MENOR:
                    fprintf(out, "    slt t%d, t%d, t%d\n", target_reg, target_reg, target_reg + 1);
                    break;
                case MAYOR:
                    fprintf(out, "    slt t%d, t%d, t%d\n", target_reg, target_reg + 1, target_reg);
                    break;
                case MAYOR_IGUAL:
                    fprintf(out, "    slt t%d, t%d, t%d\n", target_reg, target_reg, target_reg + 1);
                    fprintf(out, "    xori t%d, t%d, 1\n", target_reg, target_reg);
                    break;
                case MENOR_IGUAL:
                    fprintf(out, "    slt t%d, t%d, t%d\n", target_reg, target_reg + 1, target_reg);
                    fprintf(out, "    xori t%d, t%d, 1\n", target_reg, target_reg);
                    break;
            }
            break;
        }

        case N_LLAMADA_FUNCION: {
            char *fname = nodo->nombre_var;
            if (strcmp(fname, "main") == 0) fname = "__user_main";
            int arg_idx = 0;
            evaluar_argumentos(nodo->izq, out, &arg_idx);
            fprintf(out, "    call %s\n", fname);
            if (target_reg != 10) { // a0 es registro 10 en RISC-V, pero nosotros lo simulamos como mv
                fprintf(out, "    mv t%d, a0\n", target_reg);
            }
            break;
        }
        case N_DECIMAL:
            // RV32I no tiene FPU. Truncamos a entero como fallback.
            fprintf(out, "    li t%d, %d # Truncado de decimal\n", target_reg, (int)nodo->val_decimal);
            break;
    }
}


static void evaluar_argumentos(NodoAST *nodo, FILE *out, int *arg_idx) {
    if (!nodo) return;
    if (nodo->tipo == N_LISTA_ARGUMENTOS) {
        evaluar_argumentos(nodo->izq, out, arg_idx);
        traducir_expresion(nodo->der, out, 0); // evalúa en t0
        fprintf(out, "    mv a%d, t0\n", *arg_idx);
        (*arg_idx)++;
    } else {
        traducir_expresion(nodo, out, 0); // evalúa en t0
        fprintf(out, "    mv a%d, t0\n", *arg_idx);
        (*arg_idx)++;
    }
}

static void guardar_parametros(NodoAST *nodo, FILE *out, int *arg_idx) {
    if (!nodo) return;
    if (nodo->tipo == N_LISTA_PARAMETROS) {
        guardar_parametros(nodo->izq, out, arg_idx);
        if (nodo->der && nodo->der->tipo == N_PARAMETRO) {
            fprintf(out, "    sw a%d, %d(sp)\n", *arg_idx, nodo->der->val_entero);
            (*arg_idx)++;
        }
    } else if (nodo->tipo == N_PARAMETRO) {
        fprintf(out, "    sw a%d, %d(sp)\n", *arg_idx, nodo->val_entero);
        (*arg_idx)++;
    }
}

static void procesar_declaracion_var_codegen(NodoAST *nodo, FILE *out) {
    if (!nodo) return;
    if (nodo->tipo == N_LISTA_ELEMENTOS || nodo->tipo == N_LISTA_IDS) {
        procesar_declaracion_var_codegen(nodo->izq, out);
        procesar_declaracion_var_codegen(nodo->der, out);
    } else if (nodo->tipo == N_ASIGNACION) {
        traducir_expresion(nodo->izq, out, 0); // evalúa en t0
        fprintf(out, "    sw t0, %d(sp)\n", nodo->val_entero);
    } else if (nodo->tipo == N_ASIGNACION_ARREGLO) {
        traducir_expresion(nodo->der, out, 0); // evalúa VALOR en t0
        traducir_expresion(nodo->izq, out, 1); // evalúa INDICE en t1
        fprintf(out, "    slli t1, t1, 2\n");
        fprintf(out, "    li t2, %d\n", nodo->val_entero);
        fprintf(out, "    add t1, t1, t2\n");
        fprintf(out, "    add t1, t1, sp\n");
        fprintf(out, "    sw t0, 0(t1)\n");
    }
}

static void generar_elemento_impresion(NodoAST *elem, FILE *out) {
    if (!elem) return;
    if (elem->tipo == N_CADENA) {
        int str_lbl = new_label();
        fprintf(out, "    .section .data\n");
        // elem->val_cadena ya viene con las comillas dobles, así que lo inyectamos directo
        fprintf(out, ".LSTR%d: .string %s\n", str_lbl, elem->val_cadena);
        fprintf(out, "    .section .text\n");
        fprintf(out, "    lui a0, %%hi(.LSTR%d)\n", str_lbl);
        fprintf(out, "    addi a0, a0, %%lo(.LSTR%d)\n", str_lbl);
        fprintf(out, "    call __print_str\n");
    } else {
        // Es un número. Imprimir en TTY llamando a __print_num
        traducir_expresion(elem, out, 0);
        fprintf(out, "    mv a0, t0\n");
        fprintf(out, "    call __print_num\n");
    }
}

static void procesar_lista_impresion(NodoAST *nodo, FILE *out) {
    if (!nodo) return;
    if (nodo->tipo == N_LISTA_ARGUMENTOS) {
        procesar_lista_impresion(nodo->izq, out);
        procesar_lista_impresion(nodo->der, out);
    } else {
        generar_elemento_impresion(nodo, out);
    }
}

// Forward declaration
static void generar_nodo(NodoAST *nodo, FILE *out);

// Genera todos los nodos EXCEPTO N_DECLARACION_FUN
static void generar_nodo_sin_funciones(NodoAST *nodo, FILE *out) {
    if (!nodo) return;
    if (nodo->tipo == N_DECLARACION_FUN) return; // Skip
    if (nodo->tipo == N_LISTA_ELEMENTOS || nodo->tipo == N_LISTA_PARAMETROS || nodo->tipo == N_LISTA_CASOS) {
        generar_nodo_sin_funciones(nodo->izq, out);
        generar_nodo_sin_funciones(nodo->der, out);
        return;
    }
    generar_nodo(nodo, out);
}

// Genera SOLO los nodos N_DECLARACION_FUN
static void generar_solo_funciones(NodoAST *nodo, FILE *out) {
    if (!nodo) return;
    if (nodo->tipo == N_DECLARACION_FUN) {
        generar_nodo(nodo, out);
        return;
    }
    if (nodo->tipo == N_LISTA_ELEMENTOS || nodo->tipo == N_LISTA_PARAMETROS || nodo->tipo == N_LISTA_CASOS) {
        generar_solo_funciones(nodo->izq, out);
        generar_solo_funciones(nodo->der, out);
    }
}

static void generar_nodo(NodoAST *nodo, FILE *out) {
    if (!nodo) return;

    switch(nodo->tipo) {
        case N_PROGRAMA: {
            fprintf(out, "    .section .text\n");
            fprintf(out, "    .globl main\n");
            fprintf(out, "main:\n");
            
            // Prólogo
            int frame_size = (obtener_mem_disponible() + 4 + 15) & ~15; // +4 para ra, alineado a 16 bytes
            fprintf(out, "    addi sp, sp, -%d\n", frame_size);
            fprintf(out, "    sw ra, %d(sp)\n", frame_size - 4);
            
            // Pasada 1: Generar código global (sin funciones)
            generar_nodo_sin_funciones(nodo->izq, out);
            
            Simbolo *sym_main = buscar_simbolo("main");
            if (sym_main && sym_main->categoria == SYM_FUN) {
                fprintf(out, "    call __user_main\n");
            }
            
            // Epílogo
            fprintf(out, "\n    lw ra, %d(sp)\n", frame_size - 4);
            fprintf(out, "    addi sp, sp, %d\n", frame_size);
            fprintf(out, ".halt_loop:\n");
            fprintf(out, "    j .halt_loop\n\n");
            
            // Pasada 2: Generar funciones DESPUÉS de main
            generar_solo_funciones(nodo->izq, out);
            break;
        }

        case N_LISTA_ELEMENTOS:
        case N_LISTA_PARAMETROS:
        case N_LISTA_CASOS:
            generar_nodo(nodo->izq, out);
            generar_nodo(nodo->der, out);
            break;


        case N_DECLARACION_FUN: {
            char *fname = nodo->nombre_var;
            if (strcmp(fname, "main") == 0) fname = "__user_main";
            
            // Guardar nombre actual para que N_RETORNAR sepa a dónde saltar
            strncpy(current_func_name, fname, 255);
            
            fprintf(out, "\n    .globl %s\n", fname);
            fprintf(out, "%s:\n", fname);
            
            // Prologue: Save ra
            fprintf(out, "    sw ra, %d(sp)\n", nodo->val_entero);
            
            // Move args from a0-a7 into memory
            int arg_idx = 0;
            guardar_parametros(nodo->izq, out, &arg_idx);
            
            // Body
            generar_nodo(nodo->der, out);
            
            // Epilogue
            fprintf(out, ".L_end_%s:\n", fname);
            fprintf(out, "    lw ra, %d(sp)\n", nodo->val_entero);
            fprintf(out, "    ret\n");
            break;
        }

        case N_LLAMADA_FUNCION: {
            char *fname = nodo->nombre_var;
            if (strcmp(fname, "main") == 0) fname = "__user_main";
            int arg_idx = 0;
            evaluar_argumentos(nodo->izq, out, &arg_idx);
            fprintf(out, "    call %s\n", fname);
            break;
        }

        case N_RETORNAR: {
            traducir_expresion(nodo->izq, out, 0); // result in t0
            fprintf(out, "    mv a0, t0\n");
            fprintf(out, "    j .L_end_%s\n", current_func_name);
            break;
        }

        case N_DECLARACION_VAR:
            procesar_declaracion_var_codegen(nodo->izq, out);
            break;
            
        case N_ASIGNACION: {
            traducir_expresion(nodo->izq, out, 0); // evalúa en t0
            fprintf(out, "    sw t0, %d(sp)\n", nodo->val_entero);
            break;
        }

        case N_ASIGNACION_ARREGLO: {
            // nodo->izq es el ID del indice, nodo->der es el valor (en ast.c y semantic.c)
            traducir_expresion(nodo->der, out, 0); // evalúa VALOR en t0
            traducir_expresion(nodo->izq, out, 1); // evalúa INDICE en t1
            fprintf(out, "    slli t1, t1, 2\n");
            fprintf(out, "    li t2, %d\n", nodo->val_entero);
            fprintf(out, "    add t1, t1, t2\n");
            fprintf(out, "    add t1, t1, sp\n");
            fprintf(out, "    sw t0, 0(t1)\n");
            break;
        }
        
        case N_SI: {
            int lbl_else = new_label();
            int lbl_end = new_label();
            
            traducir_expresion(nodo->izq, out, 0);
            fprintf(out, "    beqz t0, .L%d\n", lbl_else);
            
            generar_nodo(nodo->der, out); // IF bloque
            fprintf(out, "    j .L%d\n", lbl_end);
            
            fprintf(out, ".L%d:\n", lbl_else);
            if (nodo->centro) {
                generar_nodo(nodo->centro, out); // SINO bloque
            }
            fprintf(out, ".L%d:\n", lbl_end);
            break;
        }

        case N_MIENTRAS: {
            int lbl_start = new_label();
            int lbl_end = new_label();
            
            fprintf(out, ".L%d:\n", lbl_start);
            traducir_expresion(nodo->izq, out, 0);
            fprintf(out, "    beqz t0, .L%d\n", lbl_end);
            
            generar_nodo(nodo->der, out);
            
            fprintf(out, "    j .L%d\n", lbl_start);
            fprintf(out, ".L%d:\n", lbl_end);
            break;
        }
        
        case N_PARA: {
            // Un `PARA` se descompone en Init -> Loop -> Cond -> Bloque -> Paso -> Loop
            int lbl_start = new_label();
            int lbl_end = new_label();
            
            generar_nodo(nodo->izq, out); // init
            
            fprintf(out, ".L%d:\n", lbl_start);
            traducir_expresion(nodo->der, out, 0); // condicion
            fprintf(out, "    beqz t0, .L%d\n", lbl_end);
            
            generar_nodo(nodo->adicional, out); // cuerpo
            generar_nodo(nodo->centro, out);    // paso
            
            fprintf(out, "    j .L%d\n", lbl_start);
            fprintf(out, ".L%d:\n", lbl_end);
            break;
        }
        
        case N_IMPRIMIR:
            procesar_lista_impresion(nodo->izq, out);
            fprintf(out, "    # Imprimir salto de linea (\\n = ASCII 10)\n");
            fprintf(out, "    li t0, 10\n");
            fprintf(out, "    add zero, zero, t0\n");
            fprintf(out, "    li t1, 0xff000004\n");
            fprintf(out, "    sw t0, 0(t1)\n");
            break;

        default:
            break;
    }
}

int generar_codigo(NodoAST *raiz, FILE *out) {
    if (!raiz || !out) return 0;
    
    fprintf(out, "    .section .text\n");
    fprintf(out, "\n# ---- RUTINA: print_str (Escribe en TTY Logisim 0xff000004) ----\n");
    fprintf(out, "__print_str:\n");
    fprintf(out, "    li t1, 0xff000004\n");
    fprintf(out, ".print_loop:\n");
    fprintf(out, "    lb t0, 0(a0)\n");
    fprintf(out, "    beqz t0, .print_end\n");
    fprintf(out, "    add zero, zero, t0 # FIX: Estabilizar rs2 para Logisim TTY\n");
    fprintf(out, "    sw t0, 0(t1)\n");
    fprintf(out, "    addi a0, a0, 1\n");
    fprintf(out, "    j .print_loop\n");
    fprintf(out, ".print_end:\n");
    fprintf(out, "    ret\n");

    fprintf(out, "\n# ---- RUTINA: soft_mul (Multiplicador de software) ----\n");
    fprintf(out, "__soft_mul:\n");
    fprintf(out, "    li t0, 0\n");
    fprintf(out, "    li t1, 0\n");
    fprintf(out, ".mul_loop:\n");
    fprintf(out, "    beq t1, a1, .mul_end\n");
    fprintf(out, "    add t0, t0, a0\n");
    fprintf(out, "    addi t1, t1, 1\n");
    fprintf(out, "    j .mul_loop\n");
    fprintf(out, ".mul_end:\n");
    fprintf(out, "    mv a0, t0\n");
    fprintf(out, "    ret\n\n");
    
    fprintf(out, "# ---- RUTINA: print_num (Imprime un entero a ASCII en TTY) ----\n");
    fprintf(out, "__print_num:\n");
    fprintf(out, "    addi sp, sp, -32\n");
    fprintf(out, "    sw ra, 28(sp)\n");
    fprintf(out, "    sw s0, 24(sp)\n");
    fprintf(out, "    sw s1, 20(sp)\n");
    fprintf(out, "    mv s0, a0\n");
    fprintf(out, "    li s1, 0xff000004\n");
    fprintf(out, "    bnez s0, .L_num_loop_prep\n");
    fprintf(out, "    li t0, 48\n");
    fprintf(out, "    add zero, zero, t0\n");
    fprintf(out, "    sw t0, 0(s1)\n");
    fprintf(out, "    j .L_num_end\n");
    fprintf(out, ".L_num_loop_prep:\n");
    fprintf(out, "    mv t3, sp\n");
    fprintf(out, ".L_num_loop:\n");
    fprintf(out, "    beqz s0, .L_num_print\n");
    fprintf(out, "    mv t1, s0\n");
    fprintf(out, "    li t2, 0\n");
    fprintf(out, ".L_div10:\n");
    fprintf(out, "    li t4, 10\n");
    fprintf(out, "    blt t1, t4, .L_div10_end\n");
    fprintf(out, "    sub t1, t1, t4\n");
    fprintf(out, "    addi t2, t2, 1\n");
    fprintf(out, "    j .L_div10\n");
    fprintf(out, ".L_div10_end:\n");
    fprintf(out, "    addi t1, t1, 48\n");
    fprintf(out, "    sb t1, 0(t3)\n");
    fprintf(out, "    addi t3, t3, 1\n");
    fprintf(out, "    mv s0, t2\n");
    fprintf(out, "    j .L_num_loop\n");
    fprintf(out, ".L_num_print:\n");
    fprintf(out, ".L_num_print_loop:\n");
    fprintf(out, "    addi t3, t3, -1\n");
    fprintf(out, "    lb t0, 0(t3)\n");
    fprintf(out, "    add zero, zero, t0\n");
    fprintf(out, "    sw t0, 0(s1)\n");
    fprintf(out, "    bne t3, sp, .L_num_print_loop\n");
    fprintf(out, ".L_num_end:\n");
    fprintf(out, "    lw ra, 28(sp)\n");
    fprintf(out, "    lw s0, 24(sp)\n");
    fprintf(out, "    lw s1, 20(sp)\n");
    fprintf(out, "    addi sp, sp, 32\n");
    fprintf(out, "    ret\n\n");
    
    // Iniciar Generacion Principal
    generar_nodo(raiz, out);
    
    return 1;
}
