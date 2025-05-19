#include "../xsse_test.h"

static void test_mm256_set_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_set_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		15, 14, 13, 12, 11, 10, 9, 8, -7, -6, -5, -4, -3, -2, -1, 0,
		-15, -14, -13, -12, -11, -10, -9, -8, 7, 6, 5, 4, 3, 2, 1, 0
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

static void test_mm256_set_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_set_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { -15, -14, -13, -12, -11, -10, -9, -8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_set_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_set_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected[8] = { -7, -6, -5, -4, 3, 2, 1, 0 };
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_set_epi64x(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_set_epi64x(0, 1, -2, -3);

	int64_t expected[4] = { -3, -2, 1, 0 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_set_m128i(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m128i lo = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);
	__m128i hi = _mm_set_epi8(0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15);

	__m256i result = _mm256_set_m128i(hi, lo);

	int8_t expected[32] = {
		-15, -14, -13, -12, -11, -10, -9, -8, 7, 6, 5, 4, 3, 2, 1, 0,
		15, 14, 13, 12, 11, 10, 9, 8, -7, -6, -5, -4, -3, -2, -1, 0
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

static void test_mm256_setzero_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_setzero_si256();

	int8_t expected[32] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
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

static void test_mm256_undefined_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_undefined_si256();
	assert_int_equal(sizeof(result), 32);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_set_epi8),
		cmocka_unit_test(test_mm256_set_epi16),
		cmocka_unit_test(test_mm256_set_epi32),
		cmocka_unit_test(test_mm256_set_epi64x),
		cmocka_unit_test(test_mm256_set_m128i),
		cmocka_unit_test(test_mm256_setzero_si256),
		cmocka_unit_test(test_mm256_undefined_si256)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
