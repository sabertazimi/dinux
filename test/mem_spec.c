/*
 * mem.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>
#include "spec.h"

int mem_spec(void) {
    uint8_t buf[30];

    memcpy(buf, (const uint8_t *)"Hello", 6);
    assert_equal("memcpy", buf[0], 'H',"buf[0] == 'H'");
    assert_equal("memcpy", buf[1], 'e',"buf[0] == 'e'");
    assert_equal("memcpy", buf[2], 'l',"buf[0] == 'l'");
    assert_equal("memcpy", buf[3], 'l',"buf[0] == 'l'");
    assert_equal("memcpy", buf[4], 'o',"buf[0] == 'o'");
    assert_equal("memcpy", buf[5], '\0',"buf[0] == '0'");

    memset(buf, 6, 30);
    for (int i = 0; i < 30; i++) {
        assert_equal("memset", buf[i], 6, "buf == 6");
    }
    assert_nequal("memset", buf[30], 6, "buf[30] != 6");

    bzero(buf, 30);
    for (int i = 0; i < 30; i++) {
        assert_equal("bzero", buf[i], 0, "buf == 0");
    }
    assert_nequal("bzero", buf[30], 0, "buf[30] != 0");

    return TRUE;
}
