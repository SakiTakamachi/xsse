#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_sad_epu8(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	__m128i b = _mm_set1_epi8(10);

	__m128i result = _mm_sad_epu8(a, b);

	uint16_t expected[8] = { 44, 0, 0, 0, 22, 0, 0, 0 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_sad_epu8)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
