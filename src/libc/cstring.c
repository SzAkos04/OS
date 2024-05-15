#include "cstring.h"

size_t strlen(const char *str) {
    int l = 0;
    while (*str++) {
        l++;
    }
    return l;
}
