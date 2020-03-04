#ifndef OS_GDT_H
#define OS_GDT_H

#include "../libc/stdint.h"

#define PL0 0x0
#define PL3 0x3

void gdt_init();

#endif // OS_GDT_H