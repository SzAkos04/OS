[org 0x7c00]

global _start

_start:
    mov [BOOT_DRIVE], dl

    mov bp, 0x8000
    mov sp, bp

    mov bx, 0x9000
    mov dh, 5
    mov dl, [BOOT_DRIVE]
    call disk_load

    jmp $

%include "src/io.asm"
%include "src/disk.asm"

BOOT_DRIVE db 0

times 510-($-$$) db 0
dw 0xaa55
