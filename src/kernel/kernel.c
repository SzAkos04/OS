#include "screen.h"

#include "utils.h"

void _main_c() {
    screen_init();
    clear_screen();

    // draw a cube
    /* draw_rect(50, 50, 100, 100, WHITE); */
    /* draw_line(50, 50, 75, 75, GREEN); */
    /* draw_line(50, 100, 75, 125, GREEN); */
    /* draw_line(100, 50, 125, 75, YELLOW); */
    /* draw_line(100, 100, 125, 125, YELLOW); */
    /* draw_rect(75, 75, 125, 125, RED); */

    // print out all the printable characters
    /* for (int i = 33; i < 75; i++) { */
    /*     int x = (i - 33) * 8; */
    /*     print_string((char[]){i, '\0'}, x, 0, WHITE); */
    /* } */
    /* for (int i = 76; i < 118; i++) { */
    /*     int x = (i - 76) * 8; */
    /*     print_string((char[]){i, '\0'}, x, 8, WHITE); */
    /* } */
    /* for (int i = 119; i < 127; i++) { */
    /*     int x = (i - 119) * 8; */
    /*     print_string((char[]){i, '\0'}, x, 16, WHITE); */
    /* } */

    for (int i = 0; i < 255; i++) {
        draw_line(0, i, SCREEN_WIDTH, i, i);
    }
}
