print_str:
    pusha
    mov ah, 0x0e
.repeat:
    mov al, [bx]
    cmp al, 0
    je .done
    int 0x10
    inc bx
    jmp .repeat
.done:
    popa
    ret
