#include "../xsse_test.h"

static void test_mm256_hsub_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		1, 1, 2, 3, -4, -5, INT16_MIN, 1,
		0, 1, 2, 3, -4, -5, INT16_MIN, 1
	);
	__m256i b = _mm256_setr_epi16(
		INT16_MAX, -1, 18, 19, -50, -21, 52, 23,
		INT16_MAX, -1, 18, 19, -50, -21, 52, 30
	);

	__m256i result = _mm256_hsub_epi16(a, b);

	int16_t expected[16] = {
		0, -1, 1, INT16_MAX, INT16_MIN, -1, -29, 29,
		-1, -1, 1, INT16_MAX, INT16_MIN, -1, -29, 22
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

static void test_mm256_hsub_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0, 1, 2, 3,
		-4, -5, INT32_MIN, 1
	);
	__m256i b = _mm256_setr_epi32(
		INT32_MAX, -1, 18, 19,
		-50, -21, 52, 23
	);

	__m256i result = _mm256_hsub_epi32(a, b);

	int32_t expected[8] = {
		-1, -1, INT32_MIN, -1,
		1, INT32_MAX, -29, 29,
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

static void test_mm256_hsubs_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		1, 1, 2, 3, -4, -5, INT16_MIN, 100,
		0, 1, 2, 3, -4, -5, INT16_MIN, 1
	);
	__m256i b = _mm256_setr_epi16(
		INT16_MAX, -1, 18, 19, -50, -21, 52, 23,
		INT16_MAX, -100, 18, 19, -50, -21, 52, 30
	);

	__m256i result = _mm256_hsubs_epi16(a, b);

	int16_t expected[16] = {
		0, -1, 1, INT16_MIN, INT16_MAX, -1, -29, 29,
		-1, -1, 1, INT16_MIN, INT16_MAX, -1, -29, 22
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

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_hsub_epi16),
		cmocka_unit_test(test_mm256_hsub_epi32),
		cmocka_unit_test(test_mm256_hsubs_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
