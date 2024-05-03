disk_load:
    push dx

    mov ah, 0x02
    mov al, dh
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02

    int 0x13

    jc disk_error

    pop dx
    cmp dh, al
    jne disk_error
    
    mov bx, DISK_SUCCESS_MSG
    call print_str

    ret

disk_error:
    mov bx, DISK_ERR_MSG
    call print_str
    jmp $

DISK_ERR_MSG db "Disk read error!", 0x0d, 0x0a, 0
DISK_SUCCESS_MSG db "Disk read successful!", 0x0d, 0x0a, 0
