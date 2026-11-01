MAGIC equ 0x1BADB002

section .multiboot
align 4
    dd MAGIC
    dd 0
    dd -MAGIC 

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

section .text
global _start
extern kernel_main

_start:
    mov esp, stack_top 
    call kernel_main
.hang: 
    cli
    hlt
    jmp .hang
