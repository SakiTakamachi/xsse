#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_subs_epi8_basic(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -7);
	__m128i b = _mm_setr_epi8(1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1);

	__m128i result = _mm_subs_epi8(a, b);

	int8_t expected[16] = { -1, 0, 1, 2, 5, 6, 7, 8, -1, -2, -3, -4, -3, -4, -5, -6 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_subs_epi16_basic(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0, 1, 2, 3, -4, -5, -6, -7);
	__m128i b = _mm_setr_epi16(1, 1, -1, -1, 1, 1, -1, -1);

	__m128i result = _mm_subs_epi16(a, b);

	int16_t expected[8] = { -1, 0, 3, 4, -5, -6, -5, -6 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_subs_epu8_basic(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	__m128i b = _mm_set1_epi8(1);

	__m128i result = _mm_subs_epu8(a, b);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_subs_epu16_basic(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(1, 2, 3, 4, 5, 6, 7, 8);
	__m128i b = _mm_set1_epi16(1);

	__m128i result = _mm_subs_epu16(a, b);

	int16_t expected[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_subs_epi8_basic),
		cmocka_unit_test(test_mm_subs_epi16_basic),
		cmocka_unit_test(test_mm_subs_epu8_basic),
		cmocka_unit_test(test_mm_subs_epu16_basic)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
