#ifndef SANCUS_SUPPORT_CAN_INTERRUPT_H
#define SANCUS_SUPPORT_CAN_INTERRUPT_H

#include <msp430.h>
#include <stdint.h>

#define CAN_IRQ_VECTOR    4
#define ISR_STACK_SIZE (4096)

uint16_t __isr_stack[ISR_STACK_SIZE];
extern void* __isr_sp;

#define CAN_ISR_ENTRY(fct)                                        \
__attribute__((naked)) __attribute__((interrupt(CAN_IRQ_VECTOR))) \
void can_isr_entry(void)                                         \
{                                                                   \
    __asm__ __volatile__(                                           \
            "cmp #0x0, r1\n\t"                                      \
            "jne 1f\n\t"                                            \
            "mov &__isr_sp, r1\n\t"                                 \
            "push r15\n\t"                                          \
            "push r2\n\t"                                           \
            "1: push r15\n\t"                                       \
            "push r14\n\t"                                          \
            "push r13\n\t"                                          \
            "push r12\n\t"                                          \
            "push r11\n\t"                                          \
            "push r10\n\t"                                          \
            "push r9\n\t"                                           \
            "push r8\n\t"                                           \
            "push r7\n\t"                                           \
            "push r6\n\t"                                           \
            "push r5\n\t"                                           \
            "push r4\n\t"                                           \
            "push r3\n\t"                                           \
            "call #" #fct "\n\t"                                    \
            "pop r3\n\t"                                            \
            "pop r4\n\t"                                            \
            "pop r5\n\t"                                            \
            "pop r6\n\t"                                            \
            "pop r7\n\t"                                            \
            "pop r8\n\t"                                            \
	    "pop r9\n\t"                                            \
            "pop r10\n\t"                                           \
            "pop r11\n\t"                                           \
            "pop r12\n\t"                                           \
            "pop r13\n\t"                                           \
            "pop r14\n\t"                                           \
            "pop r15\n\t"                                           \
            "reti\n\t"                                              \
            :::);                                                   \
}

#endif
