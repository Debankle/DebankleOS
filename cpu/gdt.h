#ifndef OS_GDT_H
#define OS_GDT_H

#define PL0 0x0
#define PL3 0x3

#define SEGMENT_BASE    0
#define SEGMENT_LIMIT   0xFFFFFFFF

#define CODE_RX_TYPE    0xA
#define DATA_RW_TYPE    0x2

#define GDT_NUM_ENTRIES 3

void gdt_init();

#endif // OS_GDT_H