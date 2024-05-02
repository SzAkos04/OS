bits 16

global print_char
global _start

extern main

section .text
_start:
    mov ax, 0x07C0
    mov ds, ax
    mov es, ax

    mov bp, 0x8000
    mov sp, bp

    call main

    jmp $

print_char:
    pusha
    mov ah, 0x0e
    mov al, [bp+4]
    int 0x10
    popa
    ret

times 510-($-$$) db 0
dw 0xaa55
