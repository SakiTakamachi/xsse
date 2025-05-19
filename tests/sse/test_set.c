#include "../xsse_test.h"

static void test_mm_set_epi8(void **state)
{
	(void) state;

	__m128i result = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int8_t expected[16] = { -15, -14, -13, -12, -11, -10, -9, -8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_set_epi16(void **state)
{
	(void) state;

	__m128i result = _mm_set_epi16(0, 1, 2, 3, -4, -5, -6, -7);

	int16_t expected[8] = { -7, -6, -5, -4, 3, 2, 1, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_set_epi32(void **state)
{
	(void) state;

	__m128i result = _mm_set_epi32(0, 1, -2, -3);

	int32_t expected[4] = { -3, -2, 1, 0 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_set_epi64x(void **state)
{
	(void) state;

	__m128i result = _mm_set_epi64x(1, -1);

	int64_t expected[2] = { -1, 1 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

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
		cmocka_unit_test(test_mm_set_epi8),
		cmocka_unit_test(test_mm_set_epi16),
		cmocka_unit_test(test_mm_set_epi32),
		cmocka_unit_test(test_mm_set_epi64x),
		cmocka_unit_test(test_mm_setzero_si128),
		cmocka_unit_test(test_mm_undefined_si128)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
