#pragma once

#include "utils.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

#define COLOR(_r, _g, _b)                                                      \
    ((u8)((((_r) & 0x7) << 5) | (((_g) & 0x7) << 2) | (((_b) & 0x3) << 0)))

#define COLOR_R(_index) (((_index) >> 5) & 0x7)
#define COLOR_G(_index) (((_index) >> 2) & 0x7)
#define COLOR_B(_index) (((_index) >> 0) & 0x3)

#define COLOR_ADD(_index, _d)                                                  \
    __extension__({                                                            \
        __typeof__(_index) _c = (_index);                                      \
        __typeof__(_d) __d = (_d);                                             \
        COLOR(CLAMP(COLOR_R(_c) + __d, 0, 7), CLAMP(COLOR_G(_c) + __d, 0, 7),  \
              CLAMP(COLOR_B(_c) + __d, 0, 3));                                 \
    })

void screen_init(void);

void putpixel(int pos_x, int pos_y, u8 VGA_COLOR);

void fill_screen(u8 VGA_COLOR);

void clear_screen(void);

void draw_line(int x1, int y1, int x2, int y2, u8 VGA_COLOR);

void draw_rect(int x1, int y1, int x2, int y2, u8 VGA_COLOR);
void fill_rect(int x1, int y1, int x2, int y2, u8 VGA_COLOR);

void print_string(const char *str, int x, int y, u8 VGA_COLOR);
