#include "../cpu/gdt.h"
#include "../drivers/display.h"
#include "../libc/string.h"
#include "../libc/stdint.h"
#include "../libc/stdio.h"

void kinit() {
    gdt_init();
    display_init();
}

extern void int_test(void);

void kmain() {
    kinit();

    int_test();
}