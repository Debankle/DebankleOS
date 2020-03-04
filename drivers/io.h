#ifndef OS_IO_H
#define OS_IO_H

#include "../libc/stdint.h"

void outb(uint16_t port, uint8_t data);
uint8_t inb(uint16_t port);

#endif // OS_IO_H