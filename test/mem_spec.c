/*
 * mem.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>
#include <console.h>

int mem_spec(void) {
    console_write_color(">>>>\tmem_spec passed!\n", RC_BLACK, RC_GREEN);
    return 0;
}
