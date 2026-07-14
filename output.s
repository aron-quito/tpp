    .section .text

# ---- RUTINA: print_str (Escribe en TTY Logisim 0xff000004) ----
__print_str:
    li t1, 0xff000004
.print_loop:
    lb t0, 0(a0)
    beqz t0, .print_end
    add zero, zero, t0 # FIX: Estabilizar rs2 para Logisim TTY
    sw t0, 0(t1)
    addi a0, a0, 1
    j .print_loop
.print_end:
    ret

# ---- RUTINA: soft_mul (Multiplicador de software) ----
__soft_mul:
    li t0, 0
    li t1, 0
.mul_loop:
    beq t1, a1, .mul_end
    add t0, t0, a0
    addi t1, t1, 1
    j .mul_loop
.mul_end:
    mv a0, t0
    ret

# ---- RUTINA: print_num (Imprime un entero a ASCII en TTY) ----
__print_num:
    addi sp, sp, -32
    sw ra, 28(sp)
    sw s0, 24(sp)
    sw s1, 20(sp)
    mv s0, a0
    li s1, 0xff000004
    bnez s0, .L_num_loop_prep
    li t0, 48
    add zero, zero, t0
    sw t0, 0(s1)
    j .L_num_end
.L_num_loop_prep:
    mv t3, sp
.L_num_loop:
    beqz s0, .L_num_print
    mv t1, s0
    li t2, 0
.L_div10:
    li t4, 10
    blt t1, t4, .L_div10_end
    sub t1, t1, t4
    addi t2, t2, 1
    j .L_div10
.L_div10_end:
    addi t1, t1, 48
    sb t1, 0(t3)
    addi t3, t3, 1
    mv s0, t2
    j .L_num_loop
.L_num_print:
.L_num_print_loop:
    addi t3, t3, -1
    lb t0, 0(t3)
    add zero, zero, t0
    sw t0, 0(s1)
    bne t3, sp, .L_num_print_loop
.L_num_end:
    lw ra, 28(sp)
    lw s0, 24(sp)
    lw s1, 20(sp)
    addi sp, sp, 32
    ret

    .section .text
    .globl main
main:
    addi sp, sp, -48
    sw ra, 44(sp)
    call __user_main

    lw ra, 44(sp)
    addi sp, sp, 48
.halt_loop:
    j .halt_loop


    .globl sumarArreglo
sumarArreglo:
    sw ra, 0(sp)
    sw a0, 4(sp)
    li t0, 0
    sw t0, 8(sp)
    li t0, 1
    li t1, 0
    slli t1, t1, 2
    li t2, 12
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 1
    slli t1, t1, 2
    li t2, 12
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 2
    slli t1, t1, 2
    li t2, 12
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 3
    slli t1, t1, 2
    li t2, 12
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 4
    slli t1, t1, 2
    li t2, 12
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    sw t0, 32(sp)
.L1:
    lw t0, 32(sp)
    lw t1, 4(sp)
    slt t0, t0, t1
    beqz t0, .L2
    lw t0, 8(sp)
    lw t1, 32(sp)
    slli t1, t1, 2
    li t2, 12
    add t1, t1, t2
    add t1, t1, sp
    lw t1, 0(t1)
    add t0, t0, t1
    sw t0, 8(sp)
    lw t0, 32(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 32(sp)
    j .L1
.L2:
    lw t0, 8(sp)
    mv a0, t0
    j .L_end_sumarArreglo
.L_end_sumarArreglo:
    lw ra, 0(sp)
    ret

    .globl __user_main
__user_main:
    sw ra, 36(sp)
    li t0, 5
    mv a0, t0
    call sumarArreglo
    mv t0, a0
    sw t0, 40(sp)
    .section .data
.LSTR3: .string "Suma 1..5:"
    .section .text
    lui a0, %hi(.LSTR3)
    addi a0, a0, %lo(.LSTR3)
    call __print_str
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    lw t0, 40(sp)
    mv a0, t0
    call __print_num
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
.L_end___user_main:
    lw ra, 36(sp)
    ret
