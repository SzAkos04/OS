#pragma once

#include <cstdint.h>

struct Registers {
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t ds, es, fs, gs;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
};

void isr_install(size_t i, void (*handler)(struct Registers *));
void isr_init(void);
