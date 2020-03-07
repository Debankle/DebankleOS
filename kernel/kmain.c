#include "../cpu/gdt.h"
#include "../cpu/idt.h"
#include "../drivers/display.h"
#include "../libc/string.h"
#include "../libc/stdint.h"
#include "../libc/stdio.h"

extern void test_int(void);

void kinit() {
    gdt_init();
    idt_init();
    display_init();
}

void kmain() {
    kinit();

    char *a = "Hello World!\n";
    printf(a, TYPE_CHAR);
    char b[strlen(a)];
    strcpy(b, a);
    printf(b, TYPE_CHAR);

    int x = 33;
    printf(&x, TYPE_INT);

    kprint("\n");

    test_int();
}