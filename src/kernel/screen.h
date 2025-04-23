#pragma once

#include "utils.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

// Bit masks and shifts for color channels in RRRGGGBB format
#define RED_SHIFT 5
#define GREEN_SHIFT 2
#define BLUE_SHIFT 0

#define RED_MASK 0x7
#define GREEN_MASK 0x7
#define BLUE_MASK 0x3

#define RED_BITS 3
#define GREEN_BITS 3
#define BLUE_BITS 2

#define COLOR_RGB(_r, _g, _b)                                                  \
    ((u8)((((_r) >> (8 - RED_BITS)) << RED_SHIFT) |                            \
          (((_g) >> (8 - GREEN_BITS)) << GREEN_SHIFT) |                        \
          (((_b) >> (8 - BLUE_BITS)) << BLUE_SHIFT)))

#define BLACK COLOR_RGB(0, 0, 0)
#define WHITE COLOR_RGB(255, 255, 255)
#define RED COLOR_RGB(255, 0, 0)
#define GREEN COLOR_RGB(0, 255, 0)
#define BLUE COLOR_RGB(0, 0, 255)

#define YELLOW COLOR_RGB(255, 255, 0)
#define MAGENTA COLOR_RGB(255, 0, 255)
#define CYAN COLOR_RGB(0, 255, 255)

extern u8 back_buf[SCREEN_HEIGHT][SCREEN_WIDTH];

void screen_init(void);

// only used to draw to the front buffer
static inline void putpixel(int x, int y, u8 VGA_COLOR);

void draw_pixel(int x, int y, u8 VGA_COLOR);

void fill_screen(u8 VGA_COLOR);

void draw_line(int x1, int y1, int x2, int y2, u8 VGA_COLOR);

void draw_rect(int x1, int y1, int x2, int y2, u8 VGA_COLOR);
void fill_rect(int x1, int y1, int x2, int y2, u8 VGA_COLOR);

void draw_char(char ch, int x, int y, u8 VGA_COLOR);
void print_string(const char *str, int x, int y, u8 VGA_COLOR);

void clear_buffer(void);
void swap_buffers(void);
