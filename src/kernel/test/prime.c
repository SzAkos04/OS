#include "../screen.h"
#include "./prime.h"

#include <cstdbool.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_screen(void) {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            if (is_prime(y * SCREEN_WIDTH + x)) {
                draw_pixel(point_new(x, y), WHITE);
            }
        }
    }
}
