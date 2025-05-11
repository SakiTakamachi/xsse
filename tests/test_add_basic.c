#include "xsse_test.h"

static void test_mm_add_epi8_basic(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -7);
	__m128i b = _mm_setr_epi8(1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1);

	__m128i result = _mm_add_epi8(a, b);

	int8_t expected[16] = { 1, 2, 3, 4, 3, 4, 5, 6, 1, 0, -1, -2, -5, -6, -7, -8 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_add_epi16_basic(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0, 1, 2, 3, -4, -5, -6, -7);
	__m128i b = _mm_setr_epi16(1, 1, -1, -1, 1, 1, -1, -1);

	__m128i result = _mm_add_epi16(a, b);

	int16_t expected[8] = { 1, 2, 1, 2, -3, -4, -7, -8 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_add_epi32_basic(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(0, 1, 2, 3);
	__m128i b = _mm_setr_epi32(1, -1, 1, -1);

	__m128i result = _mm_add_epi32(a, b);

	int32_t expected[4] = { 1, 0, 3, 2 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_add_epi64_basic_1(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi64x(10, 1);
	__m128i b = _mm_set_epi64x(-1, 1);

	__m128i result = _mm_add_epi64(a, b);

	int64_t expected[2] = { 2, 9 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_add_epi64_basic_2(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi64x(-10, -1);
	__m128i b = _mm_set_epi64x(-1, 1);

	__m128i result = _mm_add_epi64(a, b);

	int64_t expected[2] = { 0, -11 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_add_epi8_basic),
		cmocka_unit_test(test_mm_add_epi16_basic),
		cmocka_unit_test(test_mm_add_epi32_basic),
		cmocka_unit_test(test_mm_add_epi64_basic_1),
		cmocka_unit_test(test_mm_add_epi64_basic_2)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
