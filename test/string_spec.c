/*
 * string.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>
#include "spec.h"

int string_spec(void) {
    assert_equal("strcmp", strcmp("Hello", "Hello W"), )
    return TRUE;
}

