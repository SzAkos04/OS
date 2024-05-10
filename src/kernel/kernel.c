#include "screen.h"

#include "utils.h"

void _main_c() {
    screen_init();
    clear_screen();

    for (int i = 0; i < 255; i++) {
        draw_line(0, i, SCREEN_WIDTH, i, i);
    }
}
