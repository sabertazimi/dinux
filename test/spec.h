/*
 * spec.h
 * Copyright (C) 2016 sabertazimi <sabertazimi@avalon>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef TEST_SPEC_H
#define TEST_SPEC_H

#include <defs.h>
#include <console.h>

#define assert_equal(function, result, expect, info)            \
    do {                                                        \
        if (result != expect) {                                 \
            console_write_color(function, RC_BLACK, RC_RED);    \
            console_write_color(": ", RC_BLACK, RC_RED);        \
            console_write_color("expect ", RC_BLACK, RC_RED);   \
            console_write_color(info, RC_BLACK, RC_RED);        \
            console_write_color("\n", RC_BLACK, RC_RED);        \
            return FALSE;                                       \
        }                                                       \
    } while (0)

#define assert_nequal(function, result, expect, info)           \
    do {                                                        \
        if (result == expect) {                                 \
            console_write_color(function, RC_BLACK, RC_RED);    \
            console_write_color(": ", RC_BLACK, RC_RED);        \
            console_write_color("expect ", RC_BLACK, RC_RED);   \
            console_write_color(info, RC_BLACK, RC_RED);        \
            console_write_color("\n", RC_BLACK, RC_RED);        \
            return FALSE;                                       \
        }                                                       \
    } while (0)

int mem_spec(void);
int string_spec(void);

#endif /* !TEST_SPEC_H */
