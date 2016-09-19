/*
 * string.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <string.h>

inline int strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str1 == *str2) {
        ;
    }

    return (int)(*str1 - *str2);
}

inline char *strcpy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }

    *dest = '\0';
    return dest;
}

inline char *strcat(char *dest, const char *src) {
    while (*dest) {
        ;
    }

    while (*src) {
        *dest++ = *src++;
    }

    *dest = '\0';
    return dest;
}

inline int strlen(const char *src) {
    int nr_char = 0;

    while (*src) {
        nr_char++;
    }

    return nr_char;
}

