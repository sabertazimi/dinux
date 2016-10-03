/*
 * entry.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <gdt.h>
#include <idt.h>
#include <stdlib.h>

#ifdef KERN_DEBUG
#include <spec.h>
#endif

int kern_entry(void) {

    console_clear();

#ifdef KERN_DEBUG
    if (mem_spec()) {
        printk_color(RC_BLACK, RC_GREEN, "mem_spec        >>>>>>>>>> [OK]\n") ;
    } else {
        printk_color(RC_BLACK, RC_RED, "mem_spec        >>>>>>>>>> [ER]\n") ;
    }

    if (string_spec()) {
        printk_color(RC_BLACK, RC_GREEN, "string_spec     >>>>>>>>>> [OK]\n") ;
    } else {
        printk_color(RC_BLACK, RC_RED, "string_spec     >>>>>>>>>> [ER]\n") ;
    }
#endif

#ifdef KERN_DEBUG
    debug_init();
    // panic("panic test");
#endif

    gdt_init();
    idt_init();

    printk("\nAuthor: sabertazimi\n");
    printk("Email: sabertazimi@gmail.com\n");
    printk("Hello, Dinux!\n");
    printk("@time 2016.9.21\n");

#ifdef KERN_DEBUG
    print_regs();
    printk("\n");
    asm volatile("int $0xe");
#endif

    return 0;
}
