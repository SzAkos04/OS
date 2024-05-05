#pragma once

#include "utils.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

#define BLACK 0x00
#define BLUE 0x01
#define GREEN 0x02
#define CYAN 0x03
#define RED 0x04
#define MAGENTA 0x05
#define BROWN 0x06
#define LIGHT_GREY 0x07
#define GREY 0x08
#define LIGHT_BLUE 0x09
#define LIGHT_GREEN 0x0a
#define LIGHT_CYAN 0x0b
#define LIGHT_RED 0x0c
#define LIGHT_MAGENTA 0x0d
#define YELLOW 0x0e
#define WHITE 0x0f

void screen_init(void);

void putpixel(int pos_x, int pos_y, u8 VGA_COLOR);

void fill_screen(u8 VGA_COLOR);

void clear_screen(void);

void draw_line(int x1, int y1, int x2, int y2, u8 VGA_COLOR);

void draw_rect(int x1, int y1, int x2, int y2, u8 VGA_COLOR);
void fill_rect(int x1, int y1, int x2, int y2, u8 VGA_COLOR);

void print_string(const char *str, int x, int y, u8 VGA_COLOR);
