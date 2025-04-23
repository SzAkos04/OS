	[BITS 32]

	extern isr_handler

	global _isr0
	global _isr1
	global _isr2
	global _isr3
	global _isr4
	global _isr5
	global _isr6
	global _isr7
	global _isr8
	global _isr9
	global _isr10
	global _isr11
	global _isr12
	global _isr13
	global _isr14
	global _isr15
	global _isr16
	global _isr17
	global _isr18
	global _isr19
	global _isr20
	global _isr21
	global _isr22
	global _isr23
	global _isr24
	global _isr25
	global _isr26
	global _isr27
	global _isr28
	global _isr29
	global _isr30
	global _isr31
	global _isr32
	global _isr33
	global _isr34
	global _isr35
	global _isr36
	global _isr37
	global _isr38
	global _isr39
	global _isr40
	global _isr41
	global _isr42
	global _isr43
	global _isr44
	global _isr45
	global _isr46
	global _isr47

	; Macros are unfolded manually

_isr0:
	cli
	push dword 0
	push dword 0
	jmp  isr_common

_isr1:
	cli
	push dword 0
	push dword 1
	jmp  isr_common

_isr2:
	cli
	push dword 0
	push dword 2
	jmp  isr_common

_isr3:
	cli
	push dword 0
	push dword 3
	jmp  isr_common

_isr4:
	cli
	push dword 0
	push dword 4
	jmp  isr_common

_isr5:
	cli
	push dword 0
	push dword 5
	jmp  isr_common

_isr6:
	cli
	push dword 0
	push dword 6
	jmp  isr_common

_isr7:
	cli
	push dword 0
	push dword 7
	jmp  isr_common

_isr8:
	cli
	push dword 8
	jmp  isr_common

_isr9:
	cli
	push dword 0
	push dword 9
	jmp  isr_common

_isr10:
	cli
	push dword 10
	jmp  isr_common

_isr11:
	cli
	push dword 11
	jmp  isr_common

_isr12:
	cli
	push dword 12
	jmp  isr_common

_isr13:
	cli
	push dword 13
	jmp  isr_common

_isr14:
	cli
	push dword 14
	jmp  isr_common

_isr15:
	cli
	push dword 0
	push dword 15
	jmp  isr_common

_isr16:
	cli
	push dword 0
	push dword 16
	jmp  isr_common

_isr17:
	cli
	push dword 0
	push dword 17
	jmp  isr_common

_isr18:
	cli
	push dword 0
	push dword 18
	jmp  isr_common

_isr19:
	cli
	push dword 0
	push dword 19
	jmp  isr_common

_isr20:
	cli
	push dword 0
	push dword 20
	jmp  isr_common

_isr21:
	cli
	push dword 0
	push dword 21
	jmp  isr_common

_isr22:
	cli
	push dword 0
	push dword 22
	jmp  isr_common

_isr23:
	cli
	push dword 0
	push dword 23
	jmp  isr_common

_isr24:
	cli
	push dword 0
	push dword 24
	jmp  isr_common

_isr25:
	cli
	push dword 0
	push dword 25
	jmp  isr_common

_isr26:
	cli
	push dword 0
	push dword 26
	jmp  isr_common

_isr27:
	cli
	push dword 0
	push dword 27
	jmp  isr_common

_isr28:
	cli
	push dword 0
	push dword 28
	jmp  isr_common

_isr29:
	cli
	push dword 0
	push dword 29
	jmp  isr_common

_isr30:
	cli
	push dword 0
	push dword 30
	jmp  isr_common

_isr31:
	cli
	push dword 0
	push dword 31
	jmp  isr_common

_isr32:
	cli
	push dword 0
	push dword 32
	jmp  isr_common

_isr33:
	cli
	push dword 0
	push dword 33
	jmp  isr_common

_isr34:
	cli
	push dword 0
	push dword 34
	jmp  isr_common

_isr35:
	cli
	push dword 0
	push dword 35
	jmp  isr_common

_isr36:
	cli
	push dword 0
	push dword 36
	jmp  isr_common

_isr37:
	cli
	push dword 0
	push dword 37
	jmp  isr_common

_isr38:
	cli
	push dword 0
	push dword 38
	jmp  isr_common

_isr39:
	cli
	push dword 0
	push dword 39
	jmp  isr_common

_isr40:
	cli
	push dword 0
	push dword 40
	jmp  isr_common

_isr41:
	cli
	push dword 0
	push dword 41
	jmp  isr_common

_isr42:
	cli
	push dword 0
	push dword 42
	jmp  isr_common

_isr43:
	cli
	push dword 0
	push dword 43
	jmp  isr_common

_isr44:
	cli
	push dword 0
	push dword 44
	jmp  isr_common

_isr45:
	cli
	push dword 0
	push dword 45
	jmp  isr_common

_isr46:
	cli
	push dword 0
	push dword 46
	jmp  isr_common

_isr47:
	cli
	push dword 0
	push dword 47
	jmp  isr_common

	; The common handler

isr_common:
	pusha
	push ds
	push es
	push fs
	push gs

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	cld

	push esp
	call isr_handler
	add  esp, 4

	pop gs
	pop fs
	pop es
	pop ds
	popa

	add esp, 8; remove pushed error code + interrupt number
	iretd
