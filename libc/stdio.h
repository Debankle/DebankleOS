#ifndef OS_STD
#define OS_STD

#include "stdint.h"
#include "../drivers/display.h"

void printf(void *s);
uint8_t strlen(const char *s);

#endif // OS_STD