#include "keyboard.h"

#include "kernel.h"

#include "irq.h"

static void keyboard_handler(struct Registers *regs) {
    panic("keyboard works");
}

void keyboard_init() { irq_install(1, keyboard_handler); }
