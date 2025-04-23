#include "./color.h"

#include "../screen.h"

void color_screen(void) {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        draw_line(point_new(0, y), point_new(SCREEN_WIDTH, y), y % 256);
    }
}
