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
    addi sp, sp, -208
    sw ra, 204(sp)

    lw ra, 204(sp)
    addi sp, sp, 208
.halt_loop:
    j .halt_loop


    .globl modulo
modulo:
    sw ra, 0(sp)
    sw a0, 4(sp)
.L1:
    lw t0, 4(sp)
    li t1, 0
    slt t0, t0, t1
    beqz t0, .L2
    lw t0, 4(sp)
    li t1, 26
    add t0, t0, t1
    sw t0, 4(sp)
    j .L1
.L2:
    lw t0, 4(sp)
    li t1, 26
    mv a0, t0
    j .L_end_modulo
.L_end_modulo:
    lw ra, 0(sp)
    ret

    .globl clavijas
clavijas:
    sw ra, 8(sp)
    sw a0, 12(sp)
.L_end_clavijas:
    lw ra, 8(sp)
    ret

    .globl reflectorB
reflectorB:
    sw ra, 16(sp)
    sw a0, 20(sp)
.L_end_reflectorB:
    lw ra, 16(sp)
    ret

    .globl rotorUnoFwd
rotorUnoFwd:
    sw ra, 24(sp)
    sw a0, 28(sp)
.L_end_rotorUnoFwd:
    lw ra, 24(sp)
    ret

    .globl rotorUnoRev
rotorUnoRev:
    sw ra, 32(sp)
    sw a0, 36(sp)
.L_end_rotorUnoRev:
    lw ra, 32(sp)
    ret

    .globl rotorDosFwd
rotorDosFwd:
    sw ra, 40(sp)
    sw a0, 44(sp)
.L_end_rotorDosFwd:
    lw ra, 40(sp)
    ret

    .globl rotorDosRev
rotorDosRev:
    sw ra, 48(sp)
    sw a0, 52(sp)
.L_end_rotorDosRev:
    lw ra, 48(sp)
    ret

    .globl rotorTresFwd
rotorTresFwd:
    sw ra, 56(sp)
    sw a0, 60(sp)
.L_end_rotorTresFwd:
    lw ra, 56(sp)
    ret

    .globl rotorTresRev
rotorTresRev:
    sw ra, 64(sp)
    sw a0, 68(sp)
.L_end_rotorTresRev:
    lw ra, 64(sp)
    ret

    .globl pasarRotor
pasarRotor:
    sw ra, 72(sp)
    sw a0, 76(sp)
    sw a1, 80(sp)
    sw a2, 84(sp)
    sw a3, 88(sp)
    sw a4, 92(sp)
    lw t0, 80(sp)
    lw t1, 84(sp)
    sub t0, t0, t1
    mv a0, t0
    call modulo
    mv t0, a0
    sw t0, 96(sp)
    lw t0, 76(sp)
    lw t1, 96(sp)
    add t0, t0, t1
    mv a0, t0
    call modulo
    mv t0, a0
    sw t0, 100(sp)
    li t0, 0
    sw t0, 104(sp)
    lw t0, 88(sp)
    li t1, 1
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L3
    lw t0, 92(sp)
    li t1, 0
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L5
    lw t0, 100(sp)
    mv a0, t0
    call rotorUnoFwd
    mv t0, a0
    sw t0, 104(sp)
    j .L6
.L5:
    lw t0, 100(sp)
    mv a0, t0
    call rotorUnoRev
    mv t0, a0
    sw t0, 104(sp)
.L6:
    j .L4
.L3:
.L4:
    lw t0, 88(sp)
    li t1, 2
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L7
    lw t0, 92(sp)
    li t1, 0
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L9
    lw t0, 100(sp)
    mv a0, t0
    call rotorDosFwd
    mv t0, a0
    sw t0, 104(sp)
    j .L10
.L9:
    lw t0, 100(sp)
    mv a0, t0
    call rotorDosRev
    mv t0, a0
    sw t0, 104(sp)
.L10:
    j .L8
.L7:
.L8:
    lw t0, 88(sp)
    li t1, 3
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L11
    lw t0, 92(sp)
    li t1, 0
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L13
    lw t0, 100(sp)
    mv a0, t0
    call rotorTresFwd
    mv t0, a0
    sw t0, 104(sp)
    j .L14
.L13:
    lw t0, 100(sp)
    mv a0, t0
    call rotorTresRev
    mv t0, a0
    sw t0, 104(sp)
.L14:
    j .L12
.L11:
.L12:
    lw t0, 104(sp)
    lw t1, 96(sp)
    sub t0, t0, t1
    mv a0, t0
    call modulo
    mv t0, a0
    mv a0, t0
    j .L_end_pasarRotor
.L_end_pasarRotor:
    lw ra, 72(sp)
    ret

    .globl obtenerMensaje
obtenerMensaje:
    sw ra, 108(sp)
    sw a0, 112(sp)
.L_end_obtenerMensaje:
    lw ra, 108(sp)
    ret

    .globl chequearCrib
chequearCrib:
    sw ra, 116(sp)
    sw a0, 120(sp)
    sw a1, 124(sp)
.L_end_chequearCrib:
    lw ra, 116(sp)
    ret

    .globl iniciarCrack
iniciarCrack:
    sw ra, 128(sp)
    li t0, 27
    sw t0, 180(sp)
    li t0, 0
    sw t0, 144(sp)
    li t0, 0
    sw t0, 148(sp)
    li t0, 0
    sw t0, 152(sp)
    li t0, 0
    sw t0, 184(sp)
.L15:
    lw t0, 184(sp)
    li t1, 26
    slt t0, t0, t1
    beqz t0, .L16
    li t0, 0
    sw t0, 188(sp)
.L17:
    lw t0, 188(sp)
    li t1, 26
    slt t0, t0, t1
    beqz t0, .L18
    li t0, 0
    sw t0, 192(sp)
.L19:
    lw t0, 192(sp)
    li t1, 26
    slt t0, t0, t1
    beqz t0, .L20
    lw t0, 184(sp)
    sw t0, 132(sp)
    lw t0, 188(sp)
    sw t0, 136(sp)
    lw t0, 192(sp)
    sw t0, 140(sp)
    li t0, 0
    sw t0, 176(sp)
    li t0, 0
    sw t0, 196(sp)
.L21:
    lw t0, 196(sp)
    lw t1, 180(sp)
    slt t0, t0, t1
    beqz t0, .L22
    lw t0, 196(sp)
    mv a0, t0
    call obtenerMensaje
    mv t0, a0
    sw t0, 168(sp)
    li t0, 0
    sw t0, 156(sp)
    li t0, 0
    sw t0, 160(sp)
    lw t0, 136(sp)
    li t1, 16
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L23
    li t0, 1
    sw t0, 156(sp)
    j .L24
.L23:
.L24:
    lw t0, 140(sp)
    li t1, 21
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L25
    li t0, 1
    sw t0, 160(sp)
    j .L26
.L25:
.L26:
    lw t0, 160(sp)
    li t1, 1
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L27
    lw t0, 136(sp)
    li t1, 1
    add t0, t0, t1
    mv a0, t0
    call modulo
    mv t0, a0
    sw t0, 136(sp)
    lw t0, 132(sp)
    li t1, 1
    add t0, t0, t1
    mv a0, t0
    call modulo
    mv t0, a0
    sw t0, 132(sp)
    j .L28
.L27:
    lw t0, 156(sp)
    li t1, 1
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L29
    lw t0, 136(sp)
    li t1, 1
    add t0, t0, t1
    mv a0, t0
    call modulo
    mv t0, a0
    sw t0, 136(sp)
    lw t0, 132(sp)
    li t1, 1
    add t0, t0, t1
    mv a0, t0
    call modulo
    mv t0, a0
    sw t0, 132(sp)
    j .L30
.L29:
.L30:
.L28:
    lw t0, 140(sp)
    li t1, 1
    add t0, t0, t1
    mv a0, t0
    call modulo
    mv t0, a0
    sw t0, 140(sp)
    lw t0, 168(sp)
    mv a0, t0
    call clavijas
    mv t0, a0
    sw t0, 164(sp)
    lw t0, 164(sp)
    mv a0, t0
    lw t0, 140(sp)
    mv a1, t0
    lw t0, 152(sp)
    mv a2, t0
    li t0, 3
    mv a3, t0
    li t0, 0
    mv a4, t0
    call pasarRotor
    mv t0, a0
    sw t0, 164(sp)
    lw t0, 164(sp)
    mv a0, t0
    lw t0, 136(sp)
    mv a1, t0
    lw t0, 148(sp)
    mv a2, t0
    li t0, 1
    mv a3, t0
    li t0, 0
    mv a4, t0
    call pasarRotor
    mv t0, a0
    sw t0, 164(sp)
    lw t0, 164(sp)
    mv a0, t0
    lw t0, 132(sp)
    mv a1, t0
    lw t0, 144(sp)
    mv a2, t0
    li t0, 2
    mv a3, t0
    li t0, 0
    mv a4, t0
    call pasarRotor
    mv t0, a0
    sw t0, 164(sp)
    lw t0, 164(sp)
    mv a0, t0
    call reflectorB
    mv t0, a0
    sw t0, 164(sp)
    lw t0, 164(sp)
    mv a0, t0
    lw t0, 132(sp)
    mv a1, t0
    lw t0, 144(sp)
    mv a2, t0
    li t0, 2
    mv a3, t0
    li t0, 1
    mv a4, t0
    call pasarRotor
    mv t0, a0
    sw t0, 164(sp)
    lw t0, 164(sp)
    mv a0, t0
    lw t0, 136(sp)
    mv a1, t0
    lw t0, 148(sp)
    mv a2, t0
    li t0, 1
    mv a3, t0
    li t0, 1
    mv a4, t0
    call pasarRotor
    mv t0, a0
    sw t0, 164(sp)
    lw t0, 164(sp)
    mv a0, t0
    lw t0, 140(sp)
    mv a1, t0
    lw t0, 152(sp)
    mv a2, t0
    li t0, 3
    mv a3, t0
    li t0, 1
    mv a4, t0
    call pasarRotor
    mv t0, a0
    sw t0, 164(sp)
    lw t0, 164(sp)
    mv a0, t0
    call clavijas
    mv t0, a0
    sw t0, 172(sp)
    lw t0, 172(sp)
    mv a0, t0
    lw t0, 176(sp)
    mv a1, t0
    call chequearCrib
    mv t0, a0
    sw t0, 176(sp)
    lw t0, 176(sp)
    li t1, 11
    sub t0, t0, t1
    seqz t0, t0
    beqz t0, .L31
    lw t0, 184(sp)
    mv a0, t0
    call __print_num
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    lw t0, 188(sp)
    mv a0, t0
    call __print_num
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    lw t0, 192(sp)
    mv a0, t0
    call __print_num
    # Imprimir salto de linea (\n = ASCII 10)
    li t0, 10
    add zero, zero, t0
    li t1, 0xff000004
    sw t0, 0(t1)
    li t0, 1
    mv a0, t0
    j .L_end_iniciarCrack
    j .L32
.L31:
.L32:
    lw t0, 196(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 196(sp)
    j .L21
.L22:
    lw t0, 192(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 192(sp)
    j .L19
.L20:
    lw t0, 188(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 188(sp)
    j .L17
.L18:
    lw t0, 184(sp)
    li t1, 1
    add t0, t0, t1
    sw t0, 184(sp)
    j .L15
.L16:
    li t0, 0
    mv a0, t0
    j .L_end_iniciarCrack
.L_end_iniciarCrack:
    lw ra, 128(sp)
    ret
