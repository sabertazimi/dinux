/*
 * string.c
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>
#include "spec.h"

int string_spec(void) {
    assert_equal("strcmp", strcmp("Hello", "Hello W"), -1, "Hello < Hello W");
    assert_equal("strcmp", strcmp("Hello", "Hello "), -1, "Hello < Hello ");
    assert_equal("strcmp", strcmp("Hello", "Helloo"), -1, "Hello < Helloo");
    assert_equal("strcmp", strcmp("Hello", "Hello"), 0, "Hello == Hello");
    assert_equal("strcmp", strcmp("Hello\n", "Hello\n"), 0, "Hello == Hello");
    assert_equal("strcmp", strcmp("Hellooo", "Helloo"), 1, "Hellooo > Helloo");
    assert_equal("strcmp", strcmp("a", "b"), -1, "a < b");
    assert_equal("strcmp", strcmp("", "a"), -1, "epsilon < a");
    assert_equal("strcmp", strcmp("", ""), 0, "epsilon == epsilon");
    assert_equal("strcmp", strcmp("b", ""), 1, "b > epsilon");

    return TRUE;
}

