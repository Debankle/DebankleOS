#include "idt.h"
#include "gdt.h"
#include "../kernel/constants.h"
#include "../libc/stdint.h"

#define IDT_NUM_ENTRIES 256

#define CREATE_IDT_GATE(idx) create_idt_gate(idx, (uint32_t) &interrupt_handler_##idx,1, PL0);

#define DECLARE_INTERRUPT_HANDLER(i) void interrupt_handler_##i(void)


/* Protected mode exceptions interrupts */
DECLARE_INTERRUPT_HANDLER(0);
DECLARE_INTERRUPT_HANDLER(1);
DECLARE_INTERRUPT_HANDLER(2);
DECLARE_INTERRUPT_HANDLER(3);
DECLARE_INTERRUPT_HANDLER(4);
DECLARE_INTERRUPT_HANDLER(5);
DECLARE_INTERRUPT_HANDLER(6);
DECLARE_INTERRUPT_HANDLER(7);
DECLARE_INTERRUPT_HANDLER(8);
DECLARE_INTERRUPT_HANDLER(9);
DECLARE_INTERRUPT_HANDLER(10);
DECLARE_INTERRUPT_HANDLER(11);
DECLARE_INTERRUPT_HANDLER(12);
DECLARE_INTERRUPT_HANDLER(13);
DECLARE_INTERRUPT_HANDLER(14);
DECLARE_INTERRUPT_HANDLER(15);
DECLARE_INTERRUPT_HANDLER(16);
DECLARE_INTERRUPT_HANDLER(17);
DECLARE_INTERRUPT_HANDLER(18);
DECLARE_INTERRUPT_HANDLER(19);

/* IRQs */
DECLARE_INTERRUPT_HANDLER(32);
DECLARE_INTERRUPT_HANDLER(33);
DECLARE_INTERRUPT_HANDLER(34);
DECLARE_INTERRUPT_HANDLER(35);
DECLARE_INTERRUPT_HANDLER(36);
DECLARE_INTERRUPT_HANDLER(37);
DECLARE_INTERRUPT_HANDLER(38);
DECLARE_INTERRUPT_HANDLER(39);
DECLARE_INTERRUPT_HANDLER(40);
DECLARE_INTERRUPT_HANDLER(41);
DECLARE_INTERRUPT_HANDLER(42);
DECLARE_INTERRUPT_HANDLER(43);
DECLARE_INTERRUPT_HANDLER(44);
DECLARE_INTERRUPT_HANDLER(45);
DECLARE_INTERRUPT_HANDLER(46);
DECLARE_INTERRUPT_HANDLER(47);


struct idt_gate {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t flags;
    uint16_t offset_high;
} __attribute__ ((packed));
typedef struct idt_gate idt_gate_t;

struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__ ((packed));
typedef struct idt_ptr idt_ptr_t;

idt_gate_t idt[IDT_NUM_ENTRIES];

extern void load_idt(uint32_t idt_ptr);


static void create_idt_gate(uint8_t n, uint32_t handler, uint8_t type, uint8_t pl);

void idt_init() {
    idt_ptr_t idt_ptr;
    idt_ptr.base = (uint32_t) &idt;
    idt_ptr.limit = IDT_NUM_ENTRIES * sizeof(idt_gate_t) - 1;

    CREATE_IDT_GATE(1);

    load_idt((uint32_t) &idt_ptr);
}

static void create_idt_gate(uint8_t n, uint32_t handler, uint8_t type, uint8_t pl) {
    idt[n].offset_low = handler & 0x0000FFFF;
    idt[n].selector = SEGSEL_KERNEL_CS;
    idt[n].zero = 0;
    idt[n].flags = (0x01 << 7) | ((pl & 0x03) << 5) | (0x01 << 3) | (0x01 << 2) | (0x01 << 1) | type;
    idt[n].offset_high = (handler >> 16) & 0x0000FFFF;
}