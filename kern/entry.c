/*
 * entry.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>

#define KERN_DEBUG

#ifdef KERN_DEBUG

#include <spec.h>

#endif

int kern_entry(void) {

    console_clear();

#ifdef KERN_DEBUG
    if (mem_spec()) {
        printk_color(RC_BLACK, RC_GREEN, ">>>>\tmem_spec passed\n") ;
    } else {
        printk_color(RC_BLACK, RC_RED, ">>>>\tmem_spec failed\n") ;
    }

    if (string_spec()) {
        printk_color(RC_BLACK, RC_GREEN, ">>>>\tstring_spec passed\n") ;
    } else {
        printk_color(RC_BLACK, RC_RED, ">>>>\tstring_spec failed\n") ;
    }
#endif

    printk("\nAuthor: sabertazimi\n");
    printk("Email: sabertazimi@gmail.com\n");
    printk("Hello, Dinux!\n");
    printk("@time 2016.9.21\n");

#ifdef KERN_DEBUG
    debug_init();
    print_regs();
    panic("panic test");
#endif

    return 0;
}
