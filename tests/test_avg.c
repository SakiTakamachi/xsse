#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_avg_epu8(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150);
	__m128i b = _mm_setr_epi8(0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60);

	__m128i result = _mm_avg_epu8(a, b);

	uint8_t expected[16] = { 0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105 };
	uint8_t actual[16];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

static void test_mm_avg_epu16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0, 10, 20, 30, 40, 50, 60, 70);
	__m128i b = _mm_setr_epi16(0, 4, 8, 12, 16, 20, 24, 28);

	__m128i result = _mm_avg_epu16(a, b);

	uint16_t expected[8] = { 0, 7, 14, 21, 28, 35, 42, 49 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_avg_epu8),
        cmocka_unit_test(test_mm_avg_epu16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
