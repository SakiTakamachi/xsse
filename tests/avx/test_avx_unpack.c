#include "../xsse_test.h"

static void test_mm256_unpackhi_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -7,
		0, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
	);
	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
		0, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45
	);

	__m256i result = _mm256_unpackhi_epi8(a, b);

	int8_t expected[32] = {
		0, 28, -1, 29, -2, 30, -3, 31, -4, 32, -5, 33, -6, 34, -7, 35,
		18, 38, 19, 39, 20, 40, 21, 41, 22, 42, 23, 43, 24, 44, 25, 45
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

static void test_mm256_unpackhi_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7,
		0, -1, -2, -3, -4, -5, -6, -7
	);
	__m256i b = _mm256_setr_epi16(
		0, 21, 22, 23, 24, 25, 26, 27,
		28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_unpackhi_epi16(a, b);

	int16_t expected[16] = {
		4, 24, 5, 25, 6, 26, 7, 27,
		-4, 32, -5, 33, -6, 34, -7, 35
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

static void test_mm256_unpackhi_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0, 1, 2, 3,
		-4, -5, -6, -7
	);
	__m256i b = _mm256_setr_epi32(
		0, 21, 22, 23,
		24, 25, 26, 27
	);

	__m256i result = _mm256_unpackhi_epi32(a, b);

	int32_t expected[8] = {
		2, 22, 3, 23, -6, 26, -7, 27
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

static void test_mm256_unpackhi_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(0, 1, -2, -3);
	__m256i b = _mm256_setr_epi64x(0, 21, 22, 23);

	__m256i result = _mm256_unpackhi_epi64(a, b);

	int64_t expected[4] = {
		1, 21, -3, 23
	};
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_unpacklo_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -7,
		0, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25
	);
	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
		0, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45
	);

	__m256i result = _mm256_unpacklo_epi8(a, b);

	int8_t expected[32] = {
		0, 0, 1, 21, 2, 22, 3, 23, 4, 24, 5, 25, 6, 26, 7, 27,
		0, 0, 11, 31, 12, 32, 13, 33, 14, 34, 15, 35, 16, 36, 17, 37
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

static void test_mm256_unpacklo_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7,
		0, -1, -2, -3, -4, -5, -6, -7
	);
	__m256i b = _mm256_setr_epi16(
		0, 21, 22, 23, 24, 25, 26, 27,
		28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_unpacklo_epi16(a, b);

	int16_t expected[16] = {
		0, 0, 1, 21, 2, 22, 3, 23,
		0, 28, -1, 29, -2, 30, -3, 31,
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

static void test_mm256_unpacklo_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0, 1, 2, 3,
		-4, -5, -6, -7
	);
	__m256i b = _mm256_setr_epi32(
		0, 21, 22, 23,
		24, 25, 26, 27
	);

	__m256i result = _mm256_unpacklo_epi32(a, b);

	int32_t expected[8] = {
		0, 0, 1, 21, -4, 24, -5, 25
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

static void test_mm256_unpacklo_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(0, 1, -2, -3);
	__m256i b = _mm256_setr_epi64x(0, 21, 22, 23);

	__m256i result = _mm256_unpacklo_epi64(a, b);

	int64_t expected[4] = {
		0, 0, -2, 22
	};
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_unpackhi_epi8),
		cmocka_unit_test(test_mm256_unpackhi_epi16),
		cmocka_unit_test(test_mm256_unpackhi_epi32),
		cmocka_unit_test(test_mm256_unpackhi_epi64),
		cmocka_unit_test(test_mm256_unpacklo_epi8),
		cmocka_unit_test(test_mm256_unpacklo_epi16),
		cmocka_unit_test(test_mm256_unpacklo_epi32),
		cmocka_unit_test(test_mm256_unpacklo_epi64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
