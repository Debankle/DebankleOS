#include "string.h"
#include "stdint.h"
#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"
#include "../drivers/display.h"


void swap(char *x, char *y) {
    char t = *x;
    *x = *y;
    *y = t;
}

char *reverse(char *buffer, int i, int j) {
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }

    return buffer;
}

char *itoa(int value, char *buffer) {
    int n = abs(value);

    int i = 0;
    while (n) {
        int r = n % 10;
        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        } else {
            buffer[i++] = 48 + r;
        }

        n /= 10;
    }

    if (i == 0) {
        buffer[i++] = '0';
    }

    if (value < 0) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0';

    return reverse(buffer, 0, i-1);
}

int atoi(char *str) {
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    for (; str[i] != '\0'; i++) {
        res = res * 10 + str[i] - '0';
    }

    return sign * res;
}

void strcpy(char *destination, const char *source) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}