#ifndef OS_PORTS_H
#define OS_PORTS_H

#include "../libc/stdint.h"

#define FB_COMMAND_PORT                 0x3D4
#define FB_DATA_PORT                    0x3D5

#define FB_HIGH_BYTE_COMMAND            14
#define FB_LOW_BYTE_COMMAND             15

#define SERIAL_COM1_BASE                0x3F8      /* COM1 base port */

#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

#define SERIAL_LINE_ENABLE_DLAB         0x80

void move_cursor(uint16_t pos);
void serial_configure_baud_rate(uint16_t com, uint16_t divisor);
uint32_t serial_is_transmit_fifo_empty(uint32_t com);

#endif // OS_PORTS_H