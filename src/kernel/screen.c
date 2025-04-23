#include "screen.h"

#include "font.h"
#include "utils.h"

#include <cctype.h>
#include <cmath.h>
#include <cstdbool.h>
#include <cstdint.h>

#define VIDEO_ADDRESS 0xa0000

// VGA control port addresses
#define PALETTE_MASK 0x3C6
#define PALETTE_READ 0x3C7
#define PALETTE_WRITE 0x3C8
#define PALETTE_DATA 0x3C9

#define DAC_MAX 63

point_t point_new(int x, int y) { return (point_t){x, y}; }

uint8_t back_buf[SCREEN_HEIGHT][SCREEN_WIDTH];

static inline bool in_bound(point_t p) {
    return p.x >= 0 && p.x < SCREEN_WIDTH && p.y >= 0 && p.y < SCREEN_HEIGHT;
}

void screen_init() {
    outportb(PALETTE_MASK, 0xFF);
    outportb(PALETTE_WRITE, 0);

    for (uint8_t i = 0; i < 255; i++) {
        uint8_t r =
            (((i >> RED_SHIFT) & RED_MASK) * (DAC_MAX + 1)) / (1 << RED_BITS);
        uint8_t g = (((i >> GREEN_SHIFT) & GREEN_MASK) * (DAC_MAX + 1)) /
                    (1 << GREEN_BITS);
        uint8_t b = (((i >> BLUE_SHIFT) & BLUE_MASK) * (DAC_MAX + 1)) /
                    (1 << BLUE_BITS);

        outportb(PALETTE_DATA, r);
        outportb(PALETTE_DATA, g);
        outportb(PALETTE_DATA, b);
    }

    // Set color 255 to white
    outportb(PALETTE_DATA, DAC_MAX);
    outportb(PALETTE_DATA, DAC_MAX);
    outportb(PALETTE_DATA, DAC_MAX);
}

static inline void putpixel(point_t p, uint8_t VGA_COLOR) {
    if (!in_bound(p)) {
        return;
    }
    uint8_t *location = (uint8_t *)VIDEO_ADDRESS + SCREEN_WIDTH * p.y + p.x;
    *location = VGA_COLOR;
}

void draw_pixel(point_t p, uint8_t VGA_COLOR) {
    if (!in_bound(p)) {
        return;
    }
    back_buf[p.y][p.x] = VGA_COLOR;
}

void fill_screen(uint8_t VGA_COLOR) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            draw_pixel(point_new(x, y), VGA_COLOR);
        }
    }
}

void draw_line(point_t p1, point_t p2, uint8_t VGA_COLOR) {
    int dx = abs(p2.x - p1.x), sx = p1.x < p2.x ? 1 : -1;
    int dy = -abs(p2.y - p1.y), sy = p1.y < p2.y ? 1 : -1;
    int err = dx + dy;

    while (1) {
        draw_pixel(p1, VGA_COLOR);
        if (p1.x == p2.x && p1.y == p2.y) {
            break;
        }
        int e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            p1.x += sx;
        }
        if (e2 <= dx) {
            err += dx;
            p1.y += sy;
        }
    }
}

void draw_rect(point_t p1, point_t p2, uint8_t VGA_COLOR) {
    int min_x = p1.x < p2.x ? p1.x : p2.x;
    int max_x = p1.x > p2.x ? p1.x : p2.x;
    int min_y = p1.y < p2.y ? p1.y : p2.y;
    int max_y = p1.y > p2.y ? p1.y : p2.y;

    draw_line(point_new(min_x, min_y), point_new(max_x, min_y), VGA_COLOR);
    draw_line(point_new(min_x, max_y), point_new(max_x, max_y), VGA_COLOR);
    draw_line(point_new(min_x, min_y), point_new(min_x, max_y), VGA_COLOR);
    draw_line(point_new(max_x, min_y), point_new(max_x, max_y), VGA_COLOR);
}

void fill_rect(point_t p1, point_t p2, uint8_t VGA_COLOR) {
    int min_x = p1.x < p2.x ? p1.x : p2.x;
    int max_x = p1.x > p2.x ? p1.x : p2.x;
    int min_y = p1.y < p2.y ? p1.y : p2.y;
    int max_y = p1.y > p2.y ? p1.y : p2.y;

    for (int y = min_y; y <= max_y; y++) {
        draw_line(point_new(min_x, y), point_new(max_x, y), VGA_COLOR);
    }
}

void draw_char(char ch, point_t p, uint8_t VGA_COLOR) {
    if (!isprint(ch)) {
        return;
    }

    for (int i = 0; i < FONT_SIZE; i++) {
        for (int j = 0; j < FONT_SIZE; j++) {
            if (font[(unsigned char)ch][i] & (1 << j)) {
                draw_pixel(point_new(p.x + j, p.y + i), VGA_COLOR);
            }
        }
    }
}

void print_string(const char *str, point_t p, uint8_t VGA_COLOR) {
    int offset = 0;
    while (*str) {
        char ch = *str++;
        if (ch == '\n') {
            p.y += FONT_SIZE;
            offset = 0;
        } else {
            draw_char(ch, point_new(p.x + offset, p.y), VGA_COLOR);
            offset += FONT_SIZE;
        }
    }
}

void clear_buffer(void) { fill_screen(BLACK); }

void swap_buffers(void) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            putpixel(point_new(x, y), back_buf[y][x]);
        }
    }
}
