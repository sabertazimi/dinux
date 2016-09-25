/*
 * idt.h
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef KERN_IDT_IDT_H
#define KERN_IDT_IDT_H

#include <defs.h>

typedef struct idt_entry_t {
    uint16_t    base_low;
    uint16_t    selector;      // selector of isr(interrupt service routine)/irq(interrupt request)
    uint8_t     always0;
    uint8_t     flags;
    uint16_t    base_high;
} __attribute__((packed)) idt_entry_t;

typedef struct idt_ptr_t {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_ptr_t;

typedef struct pt_regs_t {
    // last pushed
    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    // first pushed
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
} pt_regs;

typedef void (*interrupt_handler_t)(pt_regs *);

void idt_init(void);
void register_interrupt_handler(uint8_t n, interrupt_handler_t h);
void isr_handler(pt_regs *regs);

extern void idt_flush(uint32_t);

void isr0(void);    // #DE divided by zero
void isr1(void);    // #DB debug exception
void isr2(void);    // #NMI
void isr3(void);    // #BP   breakpoint
void isr4(void);    // #OF overflow
void isr5(void);    // #BR out range of array
void isr6(void);    // #UD undefine operator code
void isr7(void);    // #NM unused service
void isr8(void);    // #DF double fault
void isr9(void);    // cross segment operation
void isr10(void);   // #TS invalid tss
void isr11(void);   // #NP non segment
void isr12(void);   // #SS stack fault
void isr13(void);   // #GP general protection
void isr14(void);   // #PF page fault
void isr15(void);   // CPU reserved
void isr16(void);   // #MF float processing unit error
void isr17(void);   // #AC align check
void isr18(void);   // #MC machine check
void isr19(void);   // #XM SIMD(single instruction multiple data) float exception

// 20 ~ 31 : intel reserved
void isr20(void);
void isr21(void);
void isr22(void);
void isr23(void);
void isr24(void);
void isr25(void);
void isr26(void);
void isr27(void);
void isr28(void);
void isr29(void);
void isr30(void);
void isr31(void);

// 32 ~ 255 : user-defined exception
void isr255(void);

#endif /* !KERN_IDT_IDT_H */
