#include "string.h"
#include "stdint.h"
#include "stdio.h"
#include "stddef.h"
#include "../drivers/display.h"

void strcpy(char *destination, const char *source) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}