#pragma once

#include "isr.h"
#include <cstdint.h>

void irq_install(size_t i, void (*handler)(struct Registers *));
void irq_init(void);
