#pragma once

#include <cstdint.h>

#define asm __asm__
#define CLI() asm("cli")
#define STI() asm("sti")

typedef unsigned char byte;

byte inportb(uint16_t port);

void outportb(uint16_t port, uint8_t data);

uint8_t inportw(uint16_t port);

void outportw(uint16_t port, uint16_t data);
