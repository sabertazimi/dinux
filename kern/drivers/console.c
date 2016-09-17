/*
 * console.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <console.h>
#include <x86.h>

// VGA display buffer: 25*80 array own 2 bytes element
static uint16_t *video_memory = (uint16_t *)0xb8000;

// virtual cursor position
static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;

static void move_cursor(void) {
    uint16_t cursor_location = cursor_y * VGA_BUFFER_WIDTH + cursor_x;
    outb(0x3d4, 14);                    // 0x3d4 端口中内部 14 号端口
    outb(0x3d5, cursor_location >> 8);  // higher 8 bits of cursor position
    outb(0x3d4, 15);                    // 0x3d4 端口中内部 15 号端口
    outb(0x3d5, cursor_location);       // lower 8 bits of cursor position
}

static void scroll(void) {
    real_color_t back = RC_BLACK,
                 fore = RC_WHITE;
    uint16_t blank = VGA_CHAR(' ', back, fore);

    if (cursor_y >= VGA_BUFFER_HEIGHT) {
        for (int i = 0 * VGA_BUFFER_WIDTH; i < (VGA_BUFFER_HEIGHT-1) * VGA_BUFFER_WIDTH; i++) {
            video_memory[i] = video_memory[i + VGA_BUFFER_WIDTH];
        }

        for (int i = (VGA_BUFFER_HEIGHT-1) * VGA_BUFFER_WIDTH; i < VGA_BUFFER_HEIGHT * VGA_BUFFER_WIDTH; i++) {
            video_memory[i] = blank;
        }

        cursor_y = 24;
    }
}

void console_clear(void) {
    real_color_t back = RC_BLACK,
                 fore = RC_WHITE;
    uint16_t blank = VGA_CHAR(' ', back, fore);

    for (int i = 0; i < VGA_BUFFER_WIDTH * VGA_BUFFER_HEIGHT; i++) {
        video_memory[i] = blank;
    }

    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

void console_putc_color(char c, real_color_t back, real_color_t fore) {
    uint16_t character = VGA_CHAR(c, back, fore);

    if (c == 0x8 && cursor_x) {
        // backspace
        cursor_x--;
    } else if (c == 0x9) {
        // tab
        cursor_x = (cursor_x + 8) & ~(8 - 1);
    } else if (c == '\r') {
        cursor_x = 0;
    } else if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else if (c >=' ') {
        video_memory[cursor_y * VGA_BUFFER_WIDTH + cursor_x] = character;
        cursor_x++;
    }

    if (cursor_x >= VGA_BUFFER_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }

    scroll();
    move_cursor();
}

void console_write(char *str) {
    while (*str) {
        console_putc_color(*str++, RC_BLACK, RC_WHITE);
    }
}

void console_write_color(char *str, real_color_t back, real_color_t fore) {
    while (*str) {
        console_putc_color(*str++, back, fore);
    }
}

