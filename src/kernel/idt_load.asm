	;      idt_load.asm
	global idt_load

	section .text

	; idt_load expects a pointer to the IDT pointer as an argument (on stack or register, depending on calling convention)

idt_load:
	;    On x86 32-bit System V ABI, the first argument is on the stack at [esp + 4]
	;    So load it into a register
	mov  eax, [esp + 4]; get the address of the IDT pointer
	lidt [eax]; load IDT
	ret  ; return to caller
