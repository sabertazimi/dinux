/*
 * entry.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <defs.h>

#define BUFFER_SCREEN_WIDTH 80

#define KERN_DEBUG

#ifdef KERN_DEBUG
    #define VGA_INPUT(handle, character, color)     \
        do {                                        \
            *handle++ = character;              \
            *handle++ = color;                  \
        } while (0)
#endif

int kern_entry(void) {
    int nr_char = 0;

    uint8_t *input = (uint8_t *)0xb8000;
    uint8_t color = (0 << 4) | (15 & 0x0f);

    VGA_INPUT(input, 'H', color); nr_char++;
    VGA_INPUT(input, 'e', color); nr_char++;
    VGA_INPUT(input, 'l', color); nr_char++;
    VGA_INPUT(input, 'l', color); nr_char++;
    VGA_INPUT(input, 'o', color); nr_char++;
    VGA_INPUT(input, ',', color); nr_char++;
    VGA_INPUT(input, ' ', color); nr_char++;
    VGA_INPUT(input, 'D', color); nr_char++;
    VGA_INPUT(input, 'i', color); nr_char++;
    VGA_INPUT(input, 'n', color); nr_char++;
    VGA_INPUT(input, 'u', color); nr_char++;
    VGA_INPUT(input, 'x', color); nr_char++;
    VGA_INPUT(input, '!', color); nr_char++;

    while (nr_char < BUFFER_SCREEN_WIDTH) {
        VGA_INPUT(input, ' ', color); nr_char++;
    }

    return 0;
}
