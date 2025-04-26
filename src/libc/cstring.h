#pragma once

#include <cstdint.h>

size_t strlen(const char *str);
void memset(void *dst, uint8_t value, size_t n);
char *utoa(uint32_t value, char *buffer);
