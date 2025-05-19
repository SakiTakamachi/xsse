#include "../xsse_test.h"

static void test_mm_shuffle_macro(void **state)
{
	(void) state;

	int32_t expected = 0b00100111;
	int32_t actual = _MM_SHUFFLE(0, 2, 1, 3);

	assert_int_equal(actual, expected);
}

static void test_mm_shuffle_epi32(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi32(0, 100, 200, 300);

	__m128i result = _mm_shuffle_epi32(x, _MM_SHUFFLE(1, 2, 0, 3));

	int32_t expected[4] = { 0, 300, 100, 200 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_shufflehi_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi16(0, 100, 200, 300, 400, 500, 600, 700);

	__m128i result = _mm_shufflehi_epi16(x, _MM_SHUFFLE(1, 2, 0, 3));

	int16_t expected[8] = { 700, 600, 500, 400, 0, 300, 100, 200 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_shufflelo_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi16(0, 100, 200, 300, 400, 500, 600, 700);

	__m128i result = _mm_shufflelo_epi16(x, _MM_SHUFFLE(1, 2, 0, 3));

	int16_t expected[8] = { 400, 700, 500, 600, 300, 200, 100, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_shuffle_epi8(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i x = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	__m128i index = _mm_set_epi8(2, 4, 6, 8, 7, 3, 5, 1, 1, 12, 0x80, 10, 0x0F, 13, 15, 0xFF);

	__m128i result = _mm_shuffle_epi8(x, index);

	int8_t expected[16] = { 0, 0, 2, 0, 5, 0, 3, 14, 14, 10, 12, 8, 7, 9, 11, 13 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_shuffle_macro),
		cmocka_unit_test(test_mm_shuffle_epi32),
		cmocka_unit_test(test_mm_shufflehi_epi16),
		cmocka_unit_test(test_mm_shufflelo_epi16),
		cmocka_unit_test(test_mm_shuffle_epi8),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
