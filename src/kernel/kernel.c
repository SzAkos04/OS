#include "screen.h"

// TODO: unnecessary includes
#include "./test/color.h"
#include "./test/mixed.h"
#include "./test/prime.h"
#include "./test/text.h"

void _main_c() {
    screen_init();

    while (1) {
        clear_buffer();

        // color_screen();

        // text_screen();

        mixed_screen();

        // prime_screen();

        swap_buffers();
    }
}
