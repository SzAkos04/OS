#include "utils.h"

#define VIDEO_ADDRESS 0xa0000
#define SCREEN_WIDTH 320
#define SCREEN_SIZE 200

void putpixel(int pos_x, int pos_y, u8 VGA_COLOR) {
    u8 *location = (u8 *)VIDEO_ADDRESS + SCREEN_WIDTH * pos_y + pos_x;
    *location = VGA_COLOR;
}
