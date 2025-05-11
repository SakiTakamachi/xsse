#include "xsse_test.h"

static void test_mm_unpackhi_epi8(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	__m128i b = _mm_set_epi8(10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15);

	__m128i result = _mm_unpackhi_epi8(a, b);

	int8_t expected[16] = { 7, -7, 6, -6, 5, -5, 4, -4, 3, -3, 2, -2, 1, -1, 0, 10 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_unpackhi_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi16(0, 1, 2, 3, 4, 5, 6, 7);
	__m128i b = _mm_set_epi16(10, -1, -2, -3, -4, -5, -6, -7);

	__m128i result = _mm_unpackhi_epi16(a, b);

	int16_t expected[8] = { 3, -3, 2, -2, 1, -1, 0, 10 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_unpackhi_epi32(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi32(0, 1, 2, 3);
	__m128i b = _mm_set_epi32(10, -1, -2, -3);

	__m128i result = _mm_unpackhi_epi32(a, b);

	int32_t expected[4] = { 1, -1, 0, 10 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_unpackhi_epi64(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi64x(0, 1);
	__m128i b = _mm_set_epi64x(10, -1);

	__m128i result = _mm_unpackhi_epi64(a, b);

	int64_t expected[2] = { 0, 10 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_unpacklo_epi8(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	__m128i b = _mm_set_epi8(10, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15);

	__m128i result = _mm_unpacklo_epi8(a, b);

	int8_t expected[16] = { 15, -15, 14, -14, 13, -13, 12, -12, 11, -11, 10, -10, 9, -9, 8, -8 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_unpacklo_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi16(0, 1, 2, 3, 4, 5, 6, 7);
	__m128i b = _mm_set_epi16(10, -1, -2, -3, -4, -5, -6, -7);

	__m128i result = _mm_unpacklo_epi16(a, b);

	int16_t expected[8] = { 7, -7, 6, -6, 5, -5, 4, -4 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_unpacklo_epi32(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi32(0, 1, 2, 3);
	__m128i b = _mm_set_epi32(10, -1, -2, -3);

	__m128i result = _mm_unpacklo_epi32(a, b);

	int32_t expected[4] = { 3, -3, 2, -2 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_unpacklo_epi64(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi64x(0, 1);
	__m128i b = _mm_set_epi64x(10, -1);

	__m128i result = _mm_unpacklo_epi64(a, b);

	int64_t expected[2] = { 1, -1 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_unpackhi_epi8),
		cmocka_unit_test(test_mm_unpackhi_epi16),
		cmocka_unit_test(test_mm_unpackhi_epi32),
		cmocka_unit_test(test_mm_unpackhi_epi64),
		cmocka_unit_test(test_mm_unpacklo_epi8),
		cmocka_unit_test(test_mm_unpacklo_epi16),
		cmocka_unit_test(test_mm_unpacklo_epi32),
		cmocka_unit_test(test_mm_unpacklo_epi64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
