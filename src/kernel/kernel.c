#include "screen.h"

#include "font.h"

void _main_c() {
    screen_init();
    clear_screen();

    while (1) {
        clear_buffer();

        draw_rect(25, 50, 75, 100, MAGENTA);
        draw_line(25, 50, 50, 75, BLUE);
        draw_line(25, 100, 50, 125, GREEN);
        draw_line(75, 50, 100, 75, BLUE);
        draw_line(75, 100, 100, 125, GREEN);
        draw_rect(50, 75, 100, 125, RED);
        print_string("Koczka", 75 - FONT_WIDTH("Koczka") / 2, 135, WHITE);

        fill_rect(SCREEN_WIDTH - 75, 75, SCREEN_WIDTH - 25, 125, BLUE);
        print_string("Negyzet", SCREEN_WIDTH - 50 - FONT_WIDTH("Negyzet") / 2,
                     135, WHITE);

        print_string("VERI KUL OS",
                     SCREEN_WIDTH / 2 - FONT_WIDTH("VERI KUL OS") / 2,
                     SCREEN_HEIGHT / 2 - FONT_SIZE / 2, WHITE);

        swap_buffers();
    }
}
