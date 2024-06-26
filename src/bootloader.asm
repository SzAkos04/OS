[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl

mov bp, 0x9000
mov sp, bp

mov  bx, MSG_REAL_MODE
call print_str

call load_kernel

call switch_to_pm

	jmp $

%include "src/print_str.asm"
%include "src/disk.asm"
%include "src/gdt.asm"
%include "src/print_str_pm.asm"
%include "src/switch_to_pm.asm"

[bits 16]

load_kernel:
	mov  bx, MSG_LOAD_KERNEL
	call print_str

	mov  bx, KERNEL_OFFSET
	mov  dh, 31
	mov  dl, [BOOT_DRIVE]
	call disk_load

	;   change to vga mode 0x13
	mov ah, 0x00
	mov al, 0x13
	int 0x10

	ret

[bits 32]

BEGIN_PM:
	mov  ebx, MSG_PROT_MODE
	call print_str_pm

	call KERNEL_OFFSET

	jmp $

BOOT_DRIVE db 0
MSG_REAL_MODE db "Started in 16-bit Real Mode", 0x0d, 0x0a, 0
MSG_PROT_MODE db "Successfully landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL db "Loading kernel into memory", 0x0d, 0x0a, 0

times 510-($-$$) db 0
dw    0xaa55
