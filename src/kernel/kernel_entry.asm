[bits   32]
[global _start]
[extern _main_c]

_start:
	call _main_c
	jmp  $
