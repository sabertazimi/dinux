/*
 * entry.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <gdt.h>
#include <idt.h>
#include <drivers.h>
#include <mm.h>
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
    pmm_init();
    timer_init(1000);
    keyboard_init();

#ifdef KERN_DEBUG
    printk("\nAuthor: sabertazimi\n");
    printk("Email: sabertazimi@gmail.com\n");
    printk("Hello, Dinux!\n");
    printk("@time 2016.9.21\n\n");

    print_regs();
    printk("\n");

    printk("kernel in memory start: 0x%08X\n", kern_start);
    printk("kernel in memory end  : 0x%08X\n", kern_end);
    printk("kernel in memory used : %d KB\n\n", (kern_end - kern_start + 1023)/1024);

    show_memory_map();
#endif

#ifdef KERN_DEBUG
    uint32_t alloc_addr = NULL;

    printk_color(RC_BLACK, RC_GREEN, "\nThe count of physical memory page is: %u\n\n", phy_page_count);
    printk_color(RC_BLACK, RC_LIGHT_BROWN, "Test physical memory alloc: \n");
    alloc_addr = pmm_alloc_page();
    printk_color(RC_BLACK, RC_LIGHT_BROWN, "Alloc physical addr: 0x%08X\n", alloc_addr);
    alloc_addr = pmm_alloc_page();
    printk_color(RC_BLACK, RC_LIGHT_BROWN, "Alloc physical addr: 0x%08X\n", alloc_addr);
    alloc_addr = pmm_alloc_page();
    printk_color(RC_BLACK, RC_LIGHT_BROWN, "Alloc physical addr: 0x%08X\n", alloc_addr);
    alloc_addr = pmm_alloc_page();
    printk_color(RC_BLACK, RC_LIGHT_BROWN, "Alloc physical addr: 0x%08X\n", alloc_addr);
#endif

    asm volatile("sti");

    return 0;
}
