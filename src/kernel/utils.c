#include "utils.h"

byte inportb(u16 port) {
    byte result;
    asm("in %%dx, %%al" : "=a"(result) : "d"(port));
    return result;
}

void outportb(u16 port, u8 data) {
    asm("out %%al, %%dx" : : "a"(data), "d"(port));
}

u8 inportw(u16 port) {
    u16 result;
    asm("in %%dx, %%ax" : "=a"(result) : "d"(port));
    return result;
}

void outportw(u16 port, u16 data) {
    asm("out %%ax, %%dx" : : "a"(data), "d"(port));
}

size_t strlen(const char *str) {
    int l = 0;
    while (*str++ != 0) {
        l++;
    }
    return l;
}
