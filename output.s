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
    addi sp, sp, -1136
    sw ra, 1132(sp)
    li t0, 0
    li t1, 0
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 1
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 2
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 3
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 4
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 5
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 6
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 7
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 23
    li t1, 8
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 9
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 10
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 7
    li t1, 11
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 12
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 13
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 14
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 15
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 16
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 17
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 25
    li t1, 18
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 13
    li t1, 19
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 20
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 21
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 22
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 23
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 14
    li t1, 24
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 25
    slli t1, t1, 2
    li t2, 0
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 0
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 1
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 2
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 3
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 4
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 5
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 6
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 7
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 8
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 25
    li t1, 9
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 13
    li t1, 10
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 11
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 14
    li t1, 12
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 13
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 14
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 7
    li t1, 15
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 23
    li t1, 16
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 17
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 18
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 19
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    li t1, 20
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 21
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 22
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 23
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 24
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 25
    slli t1, t1, 2
    li t2, 104
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 0
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 1
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 2
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 7
    li t1, 3
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 4
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 5
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 6
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 7
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 8
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 9
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 23
    li t1, 10
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 11
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 25
    li t1, 12
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 13
    li t1, 13
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 14
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 15
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 16
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 17
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 18
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    li t1, 19
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 20
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 21
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 22
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 23
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 24
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 14
    li t1, 25
    slli t1, t1, 2
    li t2, 208
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    li t1, 0
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 1
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 2
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 3
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 25
    li t1, 4
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 5
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 6
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 7
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 8
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 9
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 10
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 11
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 14
    li t1, 12
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 13
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 14
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 15
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 16
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 17
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 18
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 13
    li t1, 19
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 7
    li t1, 20
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 23
    li t1, 21
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 22
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 23
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 24
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 25
    slli t1, t1, 2
    li t2, 312
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 0
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 1
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 2
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 3
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    li t1, 4
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 5
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 6
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 7
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 8
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 25
    li t1, 9
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 10
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 11
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 12
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 13
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 14
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 15
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 7
    li t1, 16
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 23
    li t1, 17
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 18
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 19
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 20
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 21
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 13
    li t1, 22
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 23
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 14
    li t1, 24
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 25
    slli t1, t1, 2
    li t2, 416
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 0
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    li t1, 1
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 2
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 3
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 4
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 5
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 6
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 7
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 8
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 9
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 10
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 11
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 12
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 13
    li t1, 13
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 25
    li t1, 14
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 7
    li t1, 15
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 16
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 17
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 23
    li t1, 18
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 19
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 20
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 21
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 22
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 23
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 14
    li t1, 24
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 25
    slli t1, t1, 2
    li t2, 520
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 0
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 1
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 2
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 7
    li t1, 3
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 4
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 5
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 6
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 7
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 8
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 23
    li t1, 9
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 13
    li t1, 10
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 11
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 14
    li t1, 12
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 13
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 14
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 15
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 16
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 17
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 18
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 25
    li t1, 19
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 20
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 21
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 22
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 23
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    li t1, 24
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 25
    slli t1, t1, 2
    li t2, 624
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    li t1, 0
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 1
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 2
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 3
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 4
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 5
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 7
    li t1, 6
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 7
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 8
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 4
    li t1, 9
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 10
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 11
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 12
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 13
    li t1, 13
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 14
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 23
    li t1, 15
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 16
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 2
    li t1, 17
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 14
    li t1, 18
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 19
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 25
    li t1, 20
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 21
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 22
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 23
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 24
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 25
    slli t1, t1, 2
    li t2, 728
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 0
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    li t1, 1
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 2
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 3
    li t1, 3
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 4
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 5
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 6
    li t1, 6
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 7
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 10
    li t1, 8
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 19
    li t1, 9
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 1
    li t1, 10
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 11
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 12
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 13
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 20
    li t1, 14
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 15
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 24
    li t1, 16
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 17
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 18
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 12
    li t1, 19
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 5
    li t1, 20
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 9
    li t1, 21
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 8
    li t1, 22
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 22
    li t1, 23
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 15
    li t1, 24
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 16
    li t1, 25
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 17
    li t1, 26
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 18
    li t1, 27
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 11
    li t1, 28
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 21
    li t1, 29
    slli t1, t1, 2
    li t2, 832
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    li t0, 0
    sw t0, 1072(sp)
    li t0, 16
    sw t0, 1108(sp)
    li t0, 21
    sw t0, 1112(sp)
    li t0, 0
    sw t0, 1076(sp)
.L1:
    lw t0, 1076(sp)
    li t1, 26
    slt t0, t0, t1
    beqz t0, .L2
    li t0, 0
    sw t0, 1080(sp)
.L3:
    lw t0, 1080(sp)
    li t1, 26
    slt t0, t0, t1
    beqz t0, .L4
    li t0, 0
    sw t0, 1084(sp)
.L5:
    lw t0, 1084(sp)
    li t1, 26
    slt t0, t0, t1
    beqz t0, .L6
    lw t0, 1076(sp)
    sw t0, 1088(sp)
    lw t0, 1080(sp)
    sw t0, 1092(sp)
    lw t0, 1084(sp)
    sw t0, 1096(sp)
    li t0, 0
    sw t0, 1100(sp)
.L7:
    lw t0, 1100(sp)
    li t1, 30
    slt t0, t0, t1
    beqz t0, .L8
    li t0, 0
    sw t0, 1116(sp)
    li t0, 0
    sw t0, 1120(sp)
    lw t0, 1092(sp)
    lw t1, 1108(sp)
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L9
    li t0, 1
    sw t0, 1120(sp)
    j .L10
.L9:
.L10:
    lw t0, 1096(sp)
    lw t1, 1112(sp)
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L11
    li t0, 1
    sw t0, 1116(sp)
    j .L12
.L11:
.L12:
    lw t0, 1120(sp)
    li t1, 1
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L13
    lw t0, 1092(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1092(sp)
    lw t0, 1092(sp)
    li t1, 26
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L15
    li t0, 0
    sw t0, 1092(sp)
    j .L16
.L15:
.L16:
    lw t0, 1088(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1088(sp)
    lw t0, 1088(sp)
    li t1, 26
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L17
    li t0, 0
    sw t0, 1088(sp)
    j .L18
.L17:
.L18:
    j .L14
.L13:
    lw t0, 1116(sp)
    li t1, 1
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L19
    lw t0, 1092(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1092(sp)
    lw t0, 1092(sp)
    li t1, 26
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L21
    li t0, 0
    sw t0, 1092(sp)
    j .L22
.L21:
.L22:
    lw t0, 1088(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1088(sp)
    lw t0, 1088(sp)
    li t1, 26
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L23
    li t0, 0
    sw t0, 1088(sp)
    j .L24
.L23:
.L24:
    j .L20
.L19:
.L20:
.L14:
    lw t0, 1096(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1096(sp)
    lw t0, 1096(sp)
    li t1, 26
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L25
    li t0, 0
    sw t0, 1096(sp)
    j .L26
.L25:
.L26:
    lw t0, 1100(sp)
    slli t0, t0, 2
    li t1, 832
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 728
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1096(sp)
    add t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 26
    slt t0, t0, t1
    xori t0, t0, 1
    beqz t0, .L27
    lw t0, 1104(sp)
    li t1, 26
    sub t0, t0, t1
    sw t0, 1104(sp)
    j .L28
.L27:
.L28:
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 208
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1096(sp)
    sub t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 0
    slt t0, t0, t1
    beqz t0, .L29
    lw t0, 1104(sp)
    li t1, 26
    add t0, t0, t1
    sw t0, 1104(sp)
    j .L30
.L29:
.L30:
    lw t0, 1104(sp)
    lw t1, 1092(sp)
    add t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 26
    slt t0, t0, t1
    xori t0, t0, 1
    beqz t0, .L31
    lw t0, 1104(sp)
    li t1, 26
    sub t0, t0, t1
    sw t0, 1104(sp)
    j .L32
.L31:
.L32:
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 104
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1092(sp)
    sub t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 0
    slt t0, t0, t1
    beqz t0, .L33
    lw t0, 1104(sp)
    li t1, 26
    add t0, t0, t1
    sw t0, 1104(sp)
    j .L34
.L33:
.L34:
    lw t0, 1104(sp)
    lw t1, 1088(sp)
    add t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 26
    slt t0, t0, t1
    xori t0, t0, 1
    beqz t0, .L35
    lw t0, 1104(sp)
    li t1, 26
    sub t0, t0, t1
    sw t0, 1104(sp)
    j .L36
.L35:
.L36:
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 0
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1088(sp)
    sub t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 0
    slt t0, t0, t1
    beqz t0, .L37
    lw t0, 1104(sp)
    li t1, 26
    add t0, t0, t1
    sw t0, 1104(sp)
    j .L38
.L37:
.L38:
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 624
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1088(sp)
    add t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 26
    slt t0, t0, t1
    xori t0, t0, 1
    beqz t0, .L39
    lw t0, 1104(sp)
    li t1, 26
    sub t0, t0, t1
    sw t0, 1104(sp)
    j .L40
.L39:
.L40:
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 312
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1088(sp)
    sub t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 0
    slt t0, t0, t1
    beqz t0, .L41
    lw t0, 1104(sp)
    li t1, 26
    add t0, t0, t1
    sw t0, 1104(sp)
    j .L42
.L41:
.L42:
    lw t0, 1104(sp)
    lw t1, 1092(sp)
    add t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 26
    slt t0, t0, t1
    xori t0, t0, 1
    beqz t0, .L43
    lw t0, 1104(sp)
    li t1, 26
    sub t0, t0, t1
    sw t0, 1104(sp)
    j .L44
.L43:
.L44:
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 416
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1092(sp)
    sub t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 0
    slt t0, t0, t1
    beqz t0, .L45
    lw t0, 1104(sp)
    li t1, 26
    add t0, t0, t1
    sw t0, 1104(sp)
    j .L46
.L45:
.L46:
    lw t0, 1104(sp)
    lw t1, 1096(sp)
    add t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 26
    slt t0, t0, t1
    xori t0, t0, 1
    beqz t0, .L47
    lw t0, 1104(sp)
    li t1, 26
    sub t0, t0, t1
    sw t0, 1104(sp)
    j .L48
.L47:
.L48:
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 520
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1096(sp)
    sub t0, t0, t1
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    li t1, 0
    slt t0, t0, t1
    beqz t0, .L49
    lw t0, 1104(sp)
    li t1, 26
    add t0, t0, t1
    sw t0, 1104(sp)
    j .L50
.L49:
.L50:
    lw t0, 1104(sp)
    slli t0, t0, 2
    li t1, 728
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    sw t0, 1104(sp)
    lw t0, 1104(sp)
    lw t1, 1100(sp)
    slli t1, t1, 2
    li t2, 952
    add t1, t1, t2
    add t1, t1, sp
    sw t0, 0(t1)
    lw t0, 1100(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1100(sp)
    j .L7
.L8:
    li t0, 1
    sw t0, 1124(sp)
    li t0, 19
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 7
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L51
    li t0, 0
    sw t0, 1124(sp)
    j .L52
.L51:
.L52:
    li t0, 20
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 4
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L53
    li t0, 0
    sw t0, 1124(sp)
    j .L54
.L53:
.L54:
    li t0, 21
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 8
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L55
    li t0, 0
    sw t0, 1124(sp)
    j .L56
.L55:
.L56:
    li t0, 22
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 11
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L57
    li t0, 0
    sw t0, 1124(sp)
    j .L58
.L57:
.L58:
    li t0, 23
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 23
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L59
    li t0, 0
    sw t0, 1124(sp)
    j .L60
.L59:
.L60:
    li t0, 24
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 7
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L61
    li t0, 0
    sw t0, 1124(sp)
    j .L62
.L61:
.L62:
    li t0, 25
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 8
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L63
    li t0, 0
    sw t0, 1124(sp)
    j .L64
.L63:
.L64:
    li t0, 26
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 19
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L65
    li t0, 0
    sw t0, 1124(sp)
    j .L66
.L65:
.L66:
    li t0, 27
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 11
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L67
    li t0, 0
    sw t0, 1124(sp)
    j .L68
.L67:
.L68:
    li t0, 28
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 4
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L69
    li t0, 0
    sw t0, 1124(sp)
    j .L70
.L69:
.L70:
    li t0, 29
    slli t0, t0, 2
    li t1, 952
    add t0, t0, t1
    add t0, t0, sp
    lw t0, 0(t0)
    li t1, 17
    sub t0, t0, t1
    snez t0, t0
    beqz t0, .L71
    li t0, 0
    sw t0, 1124(sp)
    j .L72
.L71:
.L72:
    lw t0, 1124(sp)
    li t1, 1
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L73
    .section .data
.LSTR75: .string "¡LA MAQUINA BOMBE HA ROTO LA CLAVE DE ENIGMA!"
    .section .text
    lui a0, %hi(.LSTR75)
    addi a0, a0, %lo(.LSTR75)
    call __print_str
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    .section .data
.LSTR76: .string "Rotacion Inicial Encontrada: "
    .section .text
    lui a0, %hi(.LSTR76)
    addi a0, a0, %lo(.LSTR76)
    call __print_str
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    lw t0, 1076(sp)
    mv a0, t0
    call __print_num
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    lw t0, 1080(sp)
    mv a0, t0
    call __print_num
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    lw t0, 1084(sp)
    mv a0, t0
    call __print_num
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    li t0, 1
    sw t0, 1072(sp)
    li t0, 26
    sw t0, 1076(sp)
    li t0, 26
    sw t0, 1080(sp)
    li t0, 26
    sw t0, 1084(sp)
    j .L74
.L73:
.L74:
    lw t0, 1084(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1084(sp)
    j .L5
.L6:
    lw t0, 1080(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1080(sp)
    j .L3
.L4:
    lw t0, 1076(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 1076(sp)
    j .L1
.L2:
    lw t0, 1072(sp)
    li t1, 0
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L77
    .section .data
.LSTR79: .string "FALLO CRITICO: No se encontro el mensaje."
    .section .text
    lui a0, %hi(.LSTR79)
    addi a0, a0, %lo(.LSTR79)
    call __print_str
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    j .L78
.L77:
.L78:

    lw ra, 1132(sp)
    addi sp, sp, 1136
.halt_loop:
    j .halt_loop

