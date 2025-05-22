#include "../xsse_test.h"

static void test_mm256_packs_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, INT16_MIN
	);
	__m256i b = _mm256_setr_epi16(
		0, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, INT16_MAX
	);

	__m256i result = _mm256_packs_epi16(a, b);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, 0, 21, 22, 23, 24, 25, 26, 27,
		0, -1, -2, -3, -4, -5, -6, INT8_MIN, 28, 29, 30, 31, 32, 33, 34, INT8_MAX
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

static void test_mm256_packs_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0, 1, 2, 3, -4, -5, -6, INT32_MIN
	);
	__m256i b = _mm256_setr_epi32(
		0, 21, 22, 23, 24, 25, 26, INT32_MAX
	);

	__m256i result = _mm256_packs_epi32(a, b);

	int16_t expected[16] = {
		0, 1, 2, 3, 0, 21, 22, 23,
		-4, -5, -6, INT16_MIN, 24, 25, 26, INT16_MAX
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

static void test_mm256_packus_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, INT16_MIN
	);
	__m256i b = _mm256_setr_epi16(
		0, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, INT16_MAX
	);

	__m256i result = _mm256_packus_epi16(a, b);

	uint8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, 0, 21, 22, 23, 24, 25, 26, 27,
		0, 0, 0, 0, 0, 0, 0, 0, 28, 29, 30, 31, 32, 33, 34, UINT8_MAX
	};
	uint8_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_packus_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0, 1, 2, 3, -4, -5, -6, INT32_MIN
	);
	__m256i b = _mm256_setr_epi32(
		0, 21, 22, 23, 24, 25, 26, INT32_MAX
	);

	__m256i result = _mm256_packus_epi32(a, b);

	uint16_t expected[16] = {
		0, 1, 2, 3, 0, 21, 22, 23,
		0, 0, 0, 0, 24, 25, 26, UINT16_MAX
	};
	uint16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_packs_epi16),
		cmocka_unit_test(test_mm256_packs_epi32),
		cmocka_unit_test(test_mm256_packus_epi16),
		cmocka_unit_test(test_mm256_packus_epi32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
