#include "cctype.h"

int isalpha(int c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); }

int isdigit(int c) { return (c >= '0' && c <= '9'); }

int isalnum(int c) { return isalpha(c) || isdigit(c); }

int iscntrl(int c) { return (c >= 0 && c <= 0x1F) || (c == 0x7F); }

int isgraph(int c) { return (c >= 0x21 && c <= 0x7E); }

int islower(int c) { return (c >= 'a' && c <= 'z'); }

int isupper(int c) { return (c >= 'A' && c <= 'Z'); }

int isprint(int c) { return (c >= 0x20 && c <= 0x7E); }

int ispunct(int c) { return isgraph(c) && !isalnum(c); }

int isspace(int c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
            c == '\r');
}

int isxdigit(int c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
           (c >= 'A' && c <= 'F');
}

int isblank(int c) { return (c == ' ' || c == '\t'); }

int tolower(int c) {
    if (isupper(c)) {
        return c + ('a' - 'A');
    }
    return c;
}

int toupper(int c) {
    if (islower(c)) {
        return c - ('a' - 'A');
    }
    return c;
}
