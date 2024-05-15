#include "screen.h"

#include "utils.h"

void _main_c() {
    screen_init();
    clear_screen();

    draw_rect(50, 50, 100, 100, COLOR(7, 0, 0));

    draw_line(50, 50, 75, 75, COLOR(7, 0, 0));
    draw_line(50, 100, 75, 125, COLOR(7, 0, 0));
    draw_line(100, 50, 125, 75, COLOR(7, 0, 0));
    draw_line(100, 100, 125, 125, COLOR(7, 0, 0));

    draw_rect(75, 75, 125, 125, COLOR(7, 0, 0));

    print_string("CUB", 65, 30, COLOR(7, 0, 0));
}
