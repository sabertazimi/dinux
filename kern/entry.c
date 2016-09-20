/*
 * entry.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <defs.h>
#include <console.h>

#define KERN_DEBUG

#ifdef KERN_DEBUG
    #include "../test/spec.h"
#endif

/* #ifdef KERN_DEBUG */
/*     #define VGA_INPUT(handle, character, color)      \ */
/*         do {                                         \ */
/*             *handle++ = character;                   \ */
/*             *handle++ = color;                       \ */
/*         } while (0) */
/* #endif */

int kern_entry(void) {

    console_clear();

#ifdef KERN_DEBUG
    if (mem_spec()) {
        console_write_color(">>>>\tmem_spec passed\n", RC_BLACK, RC_GREEN);
    } else {
        console_write_color(">>>>\tmem_spec failed\n", RC_BLACK, RC_RED);
    }

    if (string_spec()) {
        console_write_color(">>>>\tstring_spec passed\n", RC_BLACK, RC_GREEN);
    } else {
        console_write_color(">>>>\tstring_spec failed\n", RC_BLACK, RC_RED);
    }
#endif

    console_write_color("Hello, Dinux! @time: ", RC_BLACK, RC_GREEN);
    console_write_dec(2016, RC_BLACK, RC_GREEN);
    console_write_color(".", RC_BLACK, RC_GREEN);
    console_write_hex(9, RC_BLACK, RC_GREEN);
    console_write_color(".", RC_BLACK, RC_GREEN);
    console_write_dec(17, RC_BLACK, RC_GREEN);
    console_write_color("\n", RC_BLACK, RC_GREEN);

    return 0;
}
