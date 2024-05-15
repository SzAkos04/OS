#include "screen.h"

#include "utils.h"

void _main_c() {
    screen_init();
    clear_screen();

    while (1) {
        clear_buffer();

        draw_rect(50, 50, 100, 100, RED);

        draw_line(50, 50, 75, 75, BLUE);
        draw_line(50, 100, 75, 125, GREEN);
        draw_line(100, 50, 125, 75, BLUE);
        draw_line(100, 100, 125, 125, GREEN);

        draw_rect(75, 75, 125, 125, RED);

        print_string("CUB", 65, 30, WHITE);

        swap_buffers();
    }
}
