#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <inttypes.h>

#include "../src/xsse.h"

static void test_mm_insert_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi16(10, 20, 30, 40, 50, 60, 70, 80);
    int val = -50;

    __m128i result = _mm_insert_epi16(x, val, 2);

	int16_t expected[8] = { 10, 20, -50, 40, 50, 60, 70, 80 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_insert_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}