#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_sub_epi8_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi8(INT8_MAX);
	__m128i b = _mm_setr_epi8(0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15);

	__m128i result = _mm_sub_epi8(a, b);

	int8_t expected[16] = {
        INT8_MAX, INT8_MIN, INT8_MIN + 1, INT8_MIN + 2, INT8_MIN + 3, INT8_MIN + 4, INT8_MIN + 5, INT8_MIN + 6,
        INT8_MIN + 7, INT8_MIN + 8, INT8_MIN + 9, INT8_MIN + 10, INT8_MIN + 11, INT8_MIN + 12, INT8_MIN + 13, INT8_MIN + 14
    };
	int8_t actual[16];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_sub_epi16_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi16(INT16_MAX);
	__m128i b = _mm_setr_epi16(0, -1, -2, -3, -4, -5, -6, -7);

	__m128i result = _mm_sub_epi16(a, b);

	int16_t expected[8] = { INT16_MAX, INT16_MIN, INT16_MIN + 1, INT16_MIN + 2, INT16_MIN + 3, INT16_MIN + 4, INT16_MIN + 5, INT16_MIN + 6 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_sub_epi32_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi32(INT32_MAX);
	__m128i b = _mm_setr_epi32(0, -1, -2, -3);

	__m128i result = _mm_sub_epi32(a, b);

	int32_t expected[4] = { INT32_MAX, INT32_MIN, INT32_MIN + 1, INT32_MIN + 2 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_sub_epi64_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi64x(INT64_MAX);
	__m128i b = _mm_set_epi64x(-1, 0);

	__m128i result = _mm_sub_epi64(a, b);

	int64_t expected[2] = { INT64_MAX, INT64_MIN };
	int64_t actual[2];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_sub_epi8_overflow),
		cmocka_unit_test(test_mm_sub_epi16_overflow),
		cmocka_unit_test(test_mm_sub_epi32_overflow),
		cmocka_unit_test(test_mm_sub_epi64_overflow)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
