#include "xsse_test.h"

static void test_mm_setr_epi8(void **state)
{
	(void) state;

	__m128i result = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_setr_epi16(void **state)
{
	(void) state;

	__m128i result = _mm_setr_epi16(0, 1, 2, 3, -4, -5, -6, -7);

	int16_t expected[8] = { 0, 1, 2, 3, -4, -5, -6, -7 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_setr_epi32(void **state)
{
	(void) state;

	__m128i result = _mm_setr_epi32(0, 1, -2, -3);

	int32_t expected[4] = { 0, 1, -2, -3 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_setr_epi8),
		cmocka_unit_test(test_mm_setr_epi16),
		cmocka_unit_test(test_mm_setr_epi32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
