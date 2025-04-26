#include "idt.h"
#include "irq.h"
#include "isr.h"
#include "screen.h"
#include "timer.h"

// TODO: unnecessary includes
#include "./test/color.h"
#include "./test/mixed.h"
#include "./test/prime.h"
#include "./test/text.h"

void panic(const char *msg) {
    clear_buffer();

    print_string(msg, point_new(0, 0), RED);

    swap_buffers();

    for (;;) {
    }
}

void render(void) {
    clear_buffer();

    // color_screen();

    // text_screen();

    mixed_screen();

    // prime_screen();

    swap_buffers();
}

void _main_c(void) {
    idt_init();
    isr_init();
    irq_init();
    screen_init();
    timer_init();

    while (1) {
        render();
    }
}
