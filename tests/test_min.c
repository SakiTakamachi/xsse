#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_min_epu8(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(50, 100, 50, 100, 50, 100, 50, 200, 50, 100, 50, 100, 50, 100, 50, 200);
	__m128i b = _mm_setr_epi8(100, 50, 100, 50, 100, 50, 200, 50, 100, 50, 100, 50, 100, 50, 50, 200);

	__m128i result = _mm_min_epu8(a, b);

	uint8_t expected[16] = { 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 200 };
	uint8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

static void test_mm_min_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(50, 100, 50, 200, 50, 100, 50, 200);
	__m128i b = _mm_setr_epi16(100, 50, 100, 50, 100, 50, 50, 200);

	__m128i result = _mm_min_epi16(a, b);

	uint16_t expected[8] = { 50, 50, 50, 50, 50, 50, 50, 200 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_min_epu8),
		cmocka_unit_test(test_mm_min_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
