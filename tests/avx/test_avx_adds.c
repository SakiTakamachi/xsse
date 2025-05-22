#include "../xsse_test.h"

static void test_mm256_adds_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, INT8_MAX, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -7,
		0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, INT8_MIN
	);
	__m256i b = _mm256_setr_epi8(
		1, 100, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -2,
		1, 2, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -100
	);

	__m256i result = _mm256_adds_epi8(a, b);

	int8_t expected[32] = {
		1, INT8_MAX, 3, 4, 3, 4, 5, 6, 1, 0, -1, -2, -5, -6, -7, -9,
		1, 3, 3, 4, 3, 4, 5, 6, 1, 0, -1, -2, -5, -6, -7, INT8_MIN
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

static void test_mm256_adds_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, INT16_MAX, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -10000
	);
	__m256i b = _mm256_setr_epi16(
		1, 10000, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, INT16_MIN
	);

	__m256i result = _mm256_adds_epi16(a, b);

	int16_t expected[16] = {
		1, INT16_MAX, 3, 4, 3, 4, 5, 6, 1, 0, -1, -2, -5, -6, -7, INT16_MIN
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

static void test_mm256_adds_epu8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, (int8_t) UINT8_MAX, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
		0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, (int8_t) UINT8_MAX
	);
	__m256i b = _mm256_setr_epi8(
		11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
		11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, (int8_t) UINT8_MAX, 26
	);

	__m256i result = _mm256_adds_epu8(a, b);

	uint8_t expected[32] = {
		11, UINT8_MAX, 15, 17, 19, 21, 23, 25, 19, 21, 23, 25, 27, 29, 31, 33,
		11, 13, 15, 17, 19, 21, 23, 25, 19, 21, 23, 25, 27, 29, UINT8_MAX, UINT8_MAX
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

static void test_mm256_adds_epu16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, (int16_t) UINT16_MAX, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7
	);
	__m256i b = _mm256_setr_epi16(
		11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, (int16_t) UINT16_MAX, 26
	);

	__m256i result = _mm256_adds_epu16(a, b);

	uint16_t expected[16] = {
		11, UINT16_MAX, 15, 17, 19, 21, 23, 25, 19, 21, 23, 25, 27, 29, UINT16_MAX, 33
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
		cmocka_unit_test(test_mm256_adds_epi8),
		cmocka_unit_test(test_mm256_adds_epi16),
		cmocka_unit_test(test_mm256_adds_epu8),
		cmocka_unit_test(test_mm256_adds_epu16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
