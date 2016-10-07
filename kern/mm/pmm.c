/*
 * pmm.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <x86.h>
#include <stdlib.h>
#include <pmm.h>

static uint32_t pmm_stack[PAGE_MAX_SIZE+1];

void show_memory_map(void) {
    uint32_t mmap_addr = glb_mboot_ptr->mmap_addr;
    uint32_t mmap_length = glb_mboot_ptr->mmap_length;

    printk("Memory map:\n");

    for (mmap_entry_t *mmap = (mmap_entry_t *)mmap_addr;
            (uint32_t)mmap < mmap_addr + mmap_length; mmap++) {
        printk("base_addr = 0x%X%08X, length = 0x%X%08X, type = 0x%X\n",
            (uint32_t)mmap->base_addr_high, (uint32_t)mmap->base_addr_low,
            (uint32_t)mmap->length_high, (uint32_t)mmap->length_low,
            (uint32_t)mmap->type);
    }
}

void pmm_init(void) {

}

uint32_t pmm_alloc_page(void) {
    return 0;
}

void pmm_free_page(uint32_t addr) {

}


