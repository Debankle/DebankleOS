#ifndef OS_INTERRUPT_H
#define OS_INTERRUPT_H

#include "../libc/stdint.h"

struct idt_info {
	uint32_t idt_index;
	uint32_t error_code;
} __attribute__((packed));
typedef struct idt_info idt_info_t;

struct cpu_state {
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
	uint32_t edx;
	uint32_t ecx;
	uint32_t ebx;
	uint32_t eax;
	uint32_t esp;
} __attribute__((packed));
typedef struct cpu_state cpu_state_t;

struct stack_state {
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
    uint32_t user_esp;
    uint32_t user_ss;
} __attribute__((packed));
typedef struct stack_state stack_state_t;

typedef void (*interrupt_handler_t)(cpu_state_t state,
                                    idt_info_t info,
                                    stack_state_t exec);

uint32_t register_interrupt_handler(uint32_t interrupt,
                                    interrupt_handler_t handler);

void enable_interrupts(void);
void disable_interrupts(void);

#endif // OS_INTERRUPT_H