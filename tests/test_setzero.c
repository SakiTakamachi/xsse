#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <stdbool.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_setzero_si128(void **state)
{
	(void) state;

	__m128i result = _mm_setzero_si128();

	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_undefined_si128(void **state)
{
	(void) state;

#ifndef _MSC_VER
	__m128i result = _mm_undefined_si128();
	assert_true(sizeof(result) == 16);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_setzero_si128),
		cmocka_unit_test(test_mm_undefined_si128)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}