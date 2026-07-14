#include "codegen.h"
#include "symtab.h"
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>

static int label_counter = 0;

static int new_label() {
    return ++label_counter;
}

// target_reg es el número de registro temporal (0 para t0, 1 para t1, ..., 6 para t6)
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
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym) {
                fprintf(out, "    lw t%d, %d(sp)\n", target_reg, sym->direccion_memoria);
            }
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
        case N_DECIMAL:
            // RV32I no tiene FPU. Truncamos a entero como fallback.
            fprintf(out, "    li t%d, %d # Truncado de decimal\n", target_reg, (int)nodo->val_decimal);
            break;
    }
}

static void procesar_declaracion_var_codegen(NodoAST *nodo, FILE *out) {
    if (!nodo) return;
    if (nodo->tipo == N_LISTA_ELEMENTOS || nodo->tipo == N_LISTA_IDS) {
        procesar_declaracion_var_codegen(nodo->izq, out);
        procesar_declaracion_var_codegen(nodo->der, out);
    } else if (nodo->tipo == N_ASIGNACION) {
        Simbolo *sym = buscar_simbolo(nodo->nombre_var);
        if (sym) {
            traducir_expresion(nodo->izq, out, 0); // evalúa en t0
            fprintf(out, "    sw t0, %d(sp)\n", sym->direccion_memoria);
        }
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
            
            generar_nodo(nodo->izq, out);
            
            // Epílogo
            fprintf(out, "\n    lw ra, %d(sp)\n", frame_size - 4);
            fprintf(out, "    addi sp, sp, %d\n", frame_size);
            fprintf(out, ".halt_loop:\n");
            fprintf(out, "    j .halt_loop\n\n");
            break;
        }

        case N_LISTA_ELEMENTOS:
        case N_LISTA_PARAMETROS:
        case N_LISTA_CASOS:
            generar_nodo(nodo->izq, out);
            generar_nodo(nodo->der, out);
            break;

        case N_DECLARACION_VAR:
            procesar_declaracion_var_codegen(nodo->izq, out);
            break;
            
        case N_ASIGNACION: {
            Simbolo *sym = buscar_simbolo(nodo->nombre_var);
            if (sym) {
                traducir_expresion(nodo->izq, out, 0); // evalúa en t0
                fprintf(out, "    sw t0, %d(sp)\n", sym->direccion_memoria);
            }
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
