#include "../xsse_test.h"

static void test_mm256_abs_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15,
		-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31
	);

	__m256i result = _mm256_abs_epi8(x);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
	};
	int8_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_abs_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, -2, 3, -4, 5, -6000, 7000, -8, 9, -10, 11, -12, 13, -14000, 15000
	);

	__m256i result = _mm256_abs_epi16(x);

	int16_t expected[16] = {
		0, 1, 2, 3, 4, 5, 6000, 7000, 8, 9, 10, 11, 12, 13, 14000, 15000
	};
	int16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_abs_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi32(
		0, 1, -200000, 300000, -4, 5, -60000, 70000
	);

	__m256i result = _mm256_abs_epi32(x);

	int32_t expected[8] = {
		0, 1, 200000, 300000, 4, 5, 60000, 70000
	};
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_abs_epi8),
		cmocka_unit_test(test_mm256_abs_epi16),
		cmocka_unit_test(test_mm256_abs_epi32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
