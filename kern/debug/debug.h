/*
 * debug.h
 * Copyright (C) 2016 sabertazimi <sabertazimi@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef KERN_DEBUG_DEBUG_H
#define KERN_DEBUG_DEBUG_H

#include <defs.h>
#include <console.h>
#include <string.h>
#include <vargs.h>

int printk(const char *format, ...);
int printk_color(real_color_t back, real_color_t fore, const char *format, ...);

#endif /* !KERN_DEBUG_DEBUG_H */
