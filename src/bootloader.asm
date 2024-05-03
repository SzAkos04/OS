[org 0x7c00]

global _start

_start:
    mov bx, HELLO_MSG
    call print_str

    jmp $

%include "src/io.asm"

HELLO_MSG db "Hello, World!", 0

times 510-($-$$) db 0
dw 0xaa55
