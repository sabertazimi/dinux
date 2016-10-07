/*
 * pmm.h
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef KERN_MM_PMM_H
#define KERN_MM_PMM_H

#include <multiboot.h>

// variables defined in kernel.ld
extern uint8_t kern_start[];
extern uint8_t kern_end[];

void show_memory_map(void);

#endif /* !KERN_MM_PMM_H */
