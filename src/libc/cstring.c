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

char *utoa(uint32_t value, char *buffer) {
    char temp[10];
    int i = 0;

    // Handle 0 explicitly
    if (value == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }

    // Extract digits
    while (value > 0) {
        temp[i++] = (value % 10) + '0';
        value /= 10;
    }

    // Reverse into buffer
    int j = 0;
    while (i > 0) {
        buffer[j++] = temp[--i];
    }

    buffer[j] = '\0';
    return buffer;
}
