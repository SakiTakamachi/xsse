#include "../xsse_test.h"

static void test_mm256_alignr_epi8_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15,
		-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31
	);
	__m256i b = _mm256_setr_epi8(
		0, -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15,
		16, -17, 18, -19, 20, -21, 22, -23, 24, -25, 26, -27, 28, -29, 30, -31
	);

	__m256i result = _mm256_alignr_epi8(a, b, 4);

	int8_t expected[32] = {
		4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15, 0, 1, -2, 3,
		20, -21, 22, -23, 24, -25, 26, -27, 28, -29, 30, -31, -16, 17, -18, 19
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

static void test_mm256_alignr_epi8_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15,
		-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31
	);
	__m256i b = _mm256_setr_epi8(
		0, -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15,
		16, -17, 18, -19, 20, -21, 22, -23, 24, -25, 26, -27, 28, -29, 30, -31
	);

	__m256i result = _mm256_alignr_epi8(a, b, 14);

	int8_t expected[32] = {
		14, -15, 0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13,
		30, -31, -16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29
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

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_alignr_epi8_1),
		cmocka_unit_test(test_mm256_alignr_epi8_2)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
