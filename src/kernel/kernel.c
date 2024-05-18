#include "screen.h"

#include "font.h"

void _main_c() {
    screen_init();

    while (1) {
        clear_buffer();

#if 0
        draw_rect(25, 50, 75, 100, MAGENTA);
        draw_line(25, 50, 50, 75, BLUE);
        draw_line(25, 100, 50, 125, GREEN);
        draw_line(75, 50, 100, 75, BLUE);
        draw_line(75, 100, 100, 125, GREEN);
        draw_rect(50, 75, 100, 125, RED);
        const char *cube = "Koczka";
        print_string(cube, 75 - TEXT_WIDTH(cube) / 2, 135, WHITE);

        fill_rect(SCREEN_WIDTH - 75, 75, SCREEN_WIDTH - 25, 125, BLUE);
        const char *square = "Negyzet";
        print_string(square, SCREEN_WIDTH - 50 - TEXT_WIDTH(square) / 2, 135,
                     WHITE);

        const char *cool = "VERI KUL OS";
        print_string(cool, SCREEN_WIDTH / 2 - TEXT_WIDTH(cool) / 2,
                     SCREEN_HEIGHT / 2 - FONT_SIZE / 2, WHITE);
#endif

        int x = 0;
        int y = 0;
        for (int i = 32; i <= 126; ++i) {
            char str[2] = {i, '\0'};
            print_string(str, x, y, WHITE);

            x += TEXT_WIDTH(str);
            if (x + TEXT_WIDTH(str) > SCREEN_WIDTH) {
                x = 0;
                y += FONT_SIZE;
                if (y + FONT_SIZE > SCREEN_HEIGHT) {
                    break;
                }
            }
        }

        swap_buffers();
    }
}
