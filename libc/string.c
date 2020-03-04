#include "string.h"
#include "stdint.h"
#include "stdio.h"
#include "stddef.h"

char *strcpy(char *destination, const char *source) {
    if (destination == NULL) return NULL;

    char *ptr = destination;

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    return ptr;
}

char strcat(const char *str1, const char *str2, char *destination) {
    uint8_t len1 = strlen(str1);
    uint8_t len2 = strlen(str2);
    char *ptr = destination;

    for (uint8_t i = 0; i < len1; i++) {
        *destination = *str1;
        str1++;
        destination++;
    }

    for (uint8_t i = len1; i < (len1+len2); i++) {
        *destination = *str2;
        str2++;
        destination++;
    }

    return *ptr;
}