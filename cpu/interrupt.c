#include "interrupt.h"
#include "../libc/stdint.h"
#include "idt.h"
#include "../kernel/constants.h"
#include "../libc/stddef.h"
#include "../libc/stdio.h"

static interrupt_handler_t interrupt_handlers[IDT_NUM_ENTRIES];

uint32_t register_interrupt_handler(uint32_t interrupt,
                                    interrupt_handler_t handler)
{
    if (interrupt > 255) {
        return 1;
    }
    if (interrupt == SYSCALL_INT_IDX) {
        return 1;
    }
    if (interrupt_handlers[interrupt] != NULL) {
        return 1;
    }

    interrupt_handlers[interrupt] = handler;
    return 0;
}

void interrupt_handler(cpu_state_t state, idt_info_t info, stack_state_t exec)
{
    if (interrupt_handlers[info.idt_index] != NULL) {
        interrupt_handlers[info.idt_index](state, info, exec);
    } else {
        printf(&info.idt_index, TYPE_INT);
        printf(" - ", TYPE_CHAR);
        printf(&exec.eip, TYPE_INT);
        printf(" - ", TYPE_CHAR);
        printf(&exec.cs, TYPE_INT);
        printf(" - ", TYPE_CHAR);
        printf(&exec.eflags, TYPE_INT);
    }
}
