#pragma once

#include "isr.h"
#include <cstdint.h>

void idt_init(void);
void idt_set(uint8_t index, void (*base)(struct Registers *), uint16_t selector,
             uint8_t flags);
