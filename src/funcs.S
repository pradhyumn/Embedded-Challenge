
.syntax unified

.global add_asm

.global summation1
.global summation2
.global summation3



add_asm:
    add r0, r0, r1
    bx lr

summation1:
    mov r4, #0
    add_loop1:
        
        ldrb r2, [r0], #1
        add r4, r4, r2
        subs r1, r1, #1
        bne add_loop1
    mov r0, r4
    bx lr


summation2:
    mov r4, #0
    add r1, r1, #1
    add_loop2:
        subs r1, r1, #1
        ldrb r2, [r0], #1
        IT NE
        addne r4, r4, r2
        bne add_loop2
    mov r0, r4
    bx lr

summation3:
    mov r4, #0
    add r1, r1, #1
    add_loop3:
        subs r1, r1, #1
        ITT NE
        ldrbne r2, [r0], #1
        addne r4, r4, r2
        bne add_loop2
    mov r0, r4
    bx lr

