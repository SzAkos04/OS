#include "screen.h"

#include <cmath.h>

#include "font.h"
#include "utils.h"

#define VIDEO_ADDRESS 0xa0000

// VGA control port addresses
#define PALETTE_MASK 0x3C6
#define PALETTE_READ 0x3C7
#define PALETTE_WRITE 0x3C8
#define PALETTE_DATA 0x3C9

#define RED_SHIFT 5
#define GREEN_SHIFT 2
#define BLUE_SHIFT 0

#define RED_MASK 0x7
#define GREEN_MASK 0x7
#define BLUE_MASK 0x3

u8 back_buf[SCREEN_HEIGHT][SCREEN_WIDTH];

void screen_init() {
    // configure palette with 8-bit RRRGGGBB color
    outportb(PALETTE_MASK, 0xFF);
    outportb(PALETTE_WRITE, 0);
    for (u8 i = 0; i < 255; i++) {
        outportb(PALETTE_DATA, (((i >> RED_SHIFT) & RED_MASK) * (256 / 8)) / 4);
        outportb(PALETTE_DATA,
                 (((i >> GREEN_SHIFT) & GREEN_MASK) * (256 / 8)) / 4);
        outportb(PALETTE_DATA,
                 (((i >> BLUE_SHIFT) & BLUE_MASK) * (256 / 4)) / 4);
    }

    // set color 255 = white
    outportb(PALETTE_DATA, 0x3F);
    outportb(PALETTE_DATA, 0x3F);
    outportb(PALETTE_DATA, 0x3F);
}

static inline void putpixel(int x, int y, u8 VGA_COLOR) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }
    u8 *location = (u8 *)VIDEO_ADDRESS + SCREEN_WIDTH * y + x;
    *location = VGA_COLOR;
}

void draw_pixel(int x, int y, u8 VGA_COLOR) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }
    back_buf[y][x] = VGA_COLOR;
}

void fill_screen(u8 VGA_COLOR) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            draw_pixel(x, y, VGA_COLOR);
        }
    }
}

void draw_line(int x0, int y0, int x1, int y1, u8 VGA_COLOR) {
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    while (1) {
        draw_pixel(x0, y0, VGA_COLOR);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_rect(int x1, int y1, int x2, int y2, u8 VGA_COLOR) {
    int min_x = x1 < x2 ? x1 : x2;
    int max_x = x1 > x2 ? x1 : x2;
    int min_y = y1 < y2 ? y1 : y2;
    int max_y = y1 > y2 ? y1 : y2;

    draw_line(min_x, min_y, max_x, min_y, VGA_COLOR);
    draw_line(min_x, max_y, max_x, max_y, VGA_COLOR);
    draw_line(min_x, min_y, min_x, max_y, VGA_COLOR);
    draw_line(max_x, min_y, max_x, max_y, VGA_COLOR);
}

void fill_rect(int x1, int y1, int x2, int y2, u8 VGA_COLOR) {
    int min_x = x1 < x2 ? x1 : x2;
    int max_x = x1 > x2 ? x1 : x2;
    int min_y = y1 < y2 ? y1 : y2;
    int max_y = y1 > y2 ? y1 : y2;

    for (int y = min_y; y <= max_y; y++) {
        draw_line(min_x, y, max_x, y, VGA_COLOR);
    }
}

void draw_char(char ch, int x, int y, u8 VGA_COLOR) {
    for (int i = 0; i < FONT_SIZE; i++) {
        for (int j = 0; j < FONT_SIZE; j++) {
            if (font[ch][i] & (1 << j)) {
                draw_pixel(x + j, y + i, VGA_COLOR);
            }
        }
    }
}

void print_string(const char *str, int x, int y, u8 VGA_COLOR) {
    int offset = 0;
    while (*str) {
        char ch = *str++;
        if (ch == '\n') {
            y += FONT_SIZE;
            offset = 0;
        } else {
            draw_char(ch, x + offset, y, VGA_COLOR);
            offset += FONT_SIZE;
        }
    }
}

void clear_buffer(void) { fill_screen(BLACK); }

void swap_buffers(void) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            putpixel(x, y, back_buf[y][x]);
        }
    }
}
