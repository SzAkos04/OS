#include "./color.h"

#include "../screen.h"

void color_screen(void) {
    static int offset = 0;
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        int draw_y = (y + offset) % SCREEN_HEIGHT;
        draw_line(point_new(0, draw_y), point_new(SCREEN_WIDTH, draw_y),
                  y % 256);
    }
    offset = (offset + 1) % SCREEN_HEIGHT;
}
