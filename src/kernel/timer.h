#pragma once

#include <cstdint.h>

#define TIMER_FREQ 363

uint32_t timer_get(void);
void timer_init(void);
