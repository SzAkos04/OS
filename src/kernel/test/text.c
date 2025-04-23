#include "./text.h"

#include "../font.h"
#include "../screen.h"

void text_screen(void) {
    int x = 0;
    int y = 0;
    for (int i = 32; i <= 126; ++i) {
        char str[2] = {i, '\0'};
        print_string(str, x, y, WHITE);

        x += TEXT_WIDTH(str);
        if (x + TEXT_WIDTH(str) > SCREEN_WIDTH) {
            x = 0;
            y += FONT_SIZE;
            if (y + FONT_SIZE > SCREEN_HEIGHT) {
                break;
            }
        }
    }
}
