#include "screen.h"
#include "utils.h"

#define VIDEO_ADDRESS 0xa0000
#define SCREEN_WIDTH 320
#define SCREEN_SIZE 200

void _main_c() { putpixel(50, 50, 0x0f); }
