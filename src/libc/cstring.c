#include "cstring.h"

size_t strlen(const char *str) {
    int l = 0;
    while (*str++) {
        l++;
    }
    return l;
}

void memset(void *dst, uint8_t value, size_t n) {
    uint8_t *d = dst;

    while (n-- > 0) {
        *d++ = value;
    }
}
