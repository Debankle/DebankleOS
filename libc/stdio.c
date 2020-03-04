#include "stdio.h"
#include "string.h"

void printf(void *s) {
    char *printString;
    char buffer[33];

    switch (_Generic(s, char*: 1, int: 2, bool: 3, default: 0)) {
        case 1:
            printString = s;
            break;
        case 2:
            printString = itoa((int)&s, buffer);
            break;
        case 0:
            printString = s;
            break;
        default:
            printString = s;
    }

    kprint(printString);
}

uint8_t strlen(const char *s) {
    int l;
    for (l = 0; s[l] != '\0'; l++);
    return l;
}