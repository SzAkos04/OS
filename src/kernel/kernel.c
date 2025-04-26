#include "cstring.h"
#include "idt.h"
#include "irq.h"
#include "isr.h"
#include "screen.h"
#include "timer.h"

#include "utils.h"

// TODO: unnecessary includes
#include "./test/color.h"
#include "./test/mixed.h"
#include "./test/prime.h"
#include "./test/text.h"

#define FPS 30

void panic(const char *msg) {
    clear_buffer();

    print_string(msg, point_new(0, 0), RED);

    swap_buffers();

    for (;;) {
    }
}

void render(void) {
    clear_buffer();

    color_screen();

    // text_screen();

    // mixed_screen();

    // prime_screen();

    char buf[32];
    utoa(timer_get(), buf);
    print_string(buf, point_new(0, 0), WHITE);

    swap_buffers();
}

void _main_c(void) {
    idt_init();
    isr_init();
    irq_init();
    screen_init();
    timer_init();

    uint32_t last_frame = 0, last = 0;

    while (1) {
        // const uint32_t now = (uint32_t)timer_get();

        // if (now != last) {
        //     last = now;
        // }

        // if ((now - last_frame) > (TIMER_FREQ / FPS)) {
        //     last_frame = now;
        render();
        // }
    }
}
