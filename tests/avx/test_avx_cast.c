#include "../xsse_test.h"

static void test_mm256_castsi128_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m128i x = _mm_setr_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m256i result = _mm256_castsi128_si256(x);

	int8_t expected[16] = { 0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15 };
	int8_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_castsi256_si128(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);
	__m128i result = _mm256_castsi256_si128(x);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtsi256_si32(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_set_epi32(0, 1, 2, 3, -4, -5, -6, -7);
	int32_t actual = _mm256_cvtsi256_si32(x);
	int8_t expected = -7;

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_castsi128_si256),
		cmocka_unit_test(test_mm256_castsi256_si128),
		cmocka_unit_test(test_mm256_cvtsi256_si32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
