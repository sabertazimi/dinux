/*
 * entry.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <type.h>

#ifdef KERN_DEBUG
    #define VGA_INPUT(handle, character, color)     \
        do {                                        \
            *##handle##++ = character;              \
            *##handle##++ = color;                  \
        } while (0)
#endif

#define KERN_DEBUG

int kern_entry(void) {
    uint8_t *input = (uint8_t *)0xb8000;
    uint8_t color = (0 << 4) | (15 & 0x0f);

    VGA_INPUT(input, 'H', color);
    VGA_INPUT(input, 'e', color);
    VGA_INPUT(input, 'l', color);
    VGA_INPUT(input, 'l', color);
    VGA_INPUT(input, 'o', color);
    VGA_INPUT(input, ',', color);
    VGA_INPUT(input, ' ', color);
    VGA_INPUT(input, 'd', color);
    VGA_INPUT(input, 'i', color);
    VGA_INPUT(input, 'n', color);
    VGA_INPUT(input, 'u', color);
    VGA_INPUT(input, 'x', color);
    VGA_INPUT(input, '!', color);
    VGA_INPUT(input, '\n', color);

    return 0;
}
