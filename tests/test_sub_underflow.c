#include "xsse_test.h"

static void test_mm_sub_epi8_underflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi8(INT8_MIN);
	__m128i b = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	__m128i result = _mm_sub_epi8(a, b);

	int8_t expected[16] = {
		INT8_MIN, INT8_MAX, INT8_MAX - 1, INT8_MAX - 2, INT8_MAX - 3, INT8_MAX - 4, INT8_MAX - 5, INT8_MAX - 6,
		INT8_MAX - 7, INT8_MAX - 8, INT8_MAX - 9, INT8_MAX - 10, INT8_MAX - 11, INT8_MAX - 12, INT8_MAX - 13, INT8_MAX - 14
	};
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_sub_epi16_underflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi16(INT16_MIN);
	__m128i b = _mm_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7);

	__m128i result = _mm_sub_epi16(a, b);

	int16_t expected[8] = { INT16_MIN, INT16_MAX, INT16_MAX - 1, INT16_MAX - 2, INT16_MAX - 3, INT16_MAX - 4, INT16_MAX - 5, INT16_MAX - 6 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_sub_epi32_underflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi32(INT32_MIN);
	__m128i b = _mm_setr_epi32(0, 1, 2, 3);

	__m128i result = _mm_sub_epi32(a, b);

	int32_t expected[4] = { INT32_MIN, INT32_MAX, INT32_MAX - 1, INT32_MAX - 2 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_sub_epi64_underflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi64x(INT64_MIN);
	__m128i b = _mm_set_epi64x(1, 0);

	__m128i result = _mm_sub_epi64(a, b);

	int64_t expected[2] = { INT64_MIN, INT64_MAX };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_sub_epi8_underflow),
		cmocka_unit_test(test_mm_sub_epi16_underflow),
		cmocka_unit_test(test_mm_sub_epi32_underflow),
		cmocka_unit_test(test_mm_sub_epi64_underflow)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
