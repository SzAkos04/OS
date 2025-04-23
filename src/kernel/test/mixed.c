#include "./mixed.h"

#include "../font.h"
#include "../screen.h"

void mixed_screen(void) {
    draw_rect(point_new(25, 50), point_new(75, 100), MAGENTA);
    draw_line(point_new(25, 50), point_new(50, 75), BLUE);
    draw_line(point_new(25, 100), point_new(50, 125), GREEN);
    draw_line(point_new(75, 50), point_new(100, 75), BLUE);
    draw_line(point_new(75, 100), point_new(100, 125), GREEN);
    draw_rect(point_new(50, 75), point_new(100, 125), RED);
    const char *cube = "Koczka";
    print_string(cube, point_new(75 - TEXT_WIDTH(cube) / 2, 135), WHITE);

    fill_rect(point_new(SCREEN_WIDTH - 75, 75),
              point_new(SCREEN_WIDTH - 25, 125), BLUE);
    const char *square = "Negyzet";
    print_string(square,
                 point_new(SCREEN_WIDTH - 50 - TEXT_WIDTH(square) / 2, 135),
                 WHITE);

    const char *cool = "VERI KUL OS";
    print_string(cool,
                 point_new(SCREEN_WIDTH / 2 - TEXT_WIDTH(cool) / 2,
                           SCREEN_HEIGHT / 2 - FONT_SIZE / 2),
                 WHITE);
}
