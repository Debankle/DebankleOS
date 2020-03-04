#include "gdt.h"

#define SEGMENT_BASE    0
#define SEGMENT_LIMIT   0xFFFFFFFF

#define CODE_RX_TYPE    0xA
#define DATA_RW_TYPE    0x2


#define GDT_NUM_ENTRIES 3

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_mid;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__ ((packed));
typedef struct gdt_entry gdt_entry_t;

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__ ((packed));
typedef struct gdt_ptr gdt_ptr_t;

gdt_entry_t gdt[GDT_NUM_ENTRIES];


void load_gdt(uint32_t);
void gdt_create_descriptor(uint8_t n, uint32_t limit, uint8_t pl, uint8_t type);

void gdt_init() {
    gdt_ptr_t _gp;
    _gp.limit = (sizeof(gdt_entry_t)*5)-1;
    _gp.base = (uint32_t)&gdt;

    gdt_create_descriptor(0, 0, 0, 0);
    gdt_create_descriptor(1, SEGMENT_LIMIT, PL0, CODE_RX_TYPE);
    gdt_create_descriptor(2, SEGMENT_LIMIT, PL0, DATA_RW_TYPE);
    gdt_create_descriptor(3, SEGMENT_LIMIT, PL3, CODE_RX_TYPE);
    gdt_create_descriptor(4, SEGMENT_LIMIT, PL3, DATA_RW_TYPE);

    load_gdt((uint32_t)&_gp);
}

void gdt_create_descriptor(uint8_t n, uint32_t limit, uint8_t pl, uint8_t type) {
    gdt[n].base_low = (SEGMENT_BASE & 0xFFFF);
    gdt[n].base_mid = (SEGMENT_BASE >> 16) & 0xFF;
    gdt[n].base_high = (SEGMENT_BASE >> 24) & 0xFF;
    gdt[n].limit_low = (limit & 0xFFFF);
    gdt[n].granularity = (0x01 << 7) | (0x01 << 6) | 0x0F;
    gdt[n].access = (0x01 << 7) | ((pl & 0x03) << 5) | (0x01 << 4) | (type & 0x0F);
}