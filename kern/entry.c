/*
 * entry.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <defs.h>
#include <console.h>

#define KERN_DEBUG

/* #ifdef KERN_DEBUG */
/*     #define VGA_INPUT(handle, character, color)      \ */
/*         do {                                         \ */
/*             *handle++ = character;                   \ */
/*             *handle++ = color;                       \ */
/*         } while (0) */
/* #endif */

int kern_entry(void) {
    console_clear();
    console_write_color("Hello, Dinux!", RC_BLACK, RC_GREEN);

    return 0;
}
