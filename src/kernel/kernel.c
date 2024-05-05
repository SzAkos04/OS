#include "screen.h"
#include "utils.h"

void _main_c() {
    clear_screen();
    draw_rect(50, 50, 100, 100, BLUE);

    draw_line(50, 50, 75, 75, GREEN);
    draw_line(50, 100, 75, 125, GREEN);
    draw_line(100, 50, 125, 75, YELLOW);
    draw_line(100, 100, 125, 125, YELLOW);

    draw_rect(75, 75, 125, 125, RED);
    print_string("CUB", 75, 30, WHITE);
}
