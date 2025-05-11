#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdbool.h>
#include <inttypes.h>
#include <string.h>
#include <cmocka.h>
#include "../src/xsse.h"

#ifndef assert_uint_equal
#define assert_uint_equal(a, b) (assert_true(a == b))
#endif
