#include "../xsse_test.h"

static void test_mm256_add_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, INT8_MAX, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -7,
		0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, INT8_MIN
	);
	__m256i b = _mm256_setr_epi8(
		1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -2,
		1, 2, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1
	);

	__m256i result = _mm256_add_epi8(a, b);

	int8_t expected[32] = {
		1, INT8_MIN, 3, 4, 3, 4, 5, 6, 1, 0, -1, -2, -5, -6, -7, -9,
		1, 3, 3, 4, 3, 4, 5, 6, 1, 0, -1, -2, -5, -6, -7, INT8_MAX
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

static void test_mm256_add_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, INT16_MAX, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -1
	);
	__m256i b = _mm256_setr_epi16(
		1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, INT16_MIN
	);

	__m256i result = _mm256_add_epi16(a, b);

	int16_t expected[16] = {
		1, INT16_MIN, 3, 4, 3, 4, 5, 6, 1, 0, -1, -2, -5, -6, -7, INT16_MAX
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

static void test_mm256_add_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0, INT32_MAX, 2, 3, -4, -5, -6, -1
	);
	__m256i b = _mm256_setr_epi32(
		1, 1, 1, -1, 1, 1, -1, INT32_MIN
	);

	__m256i result = _mm256_add_epi32(a, b);

	int32_t expected[8] = {
		1, INT32_MIN, 3, 2, -3, -4, -7, INT32_MAX
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

static void test_mm256_add_epi64_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(
		2, INT64_MAX, -6, -1
	);
	__m256i b = _mm256_setr_epi64x(
		1, 1, -1, INT64_MIN
	);

	__m256i result = _mm256_add_epi64(a, b);

	int64_t expected[4] = {
		3, INT64_MIN, -7, INT64_MAX
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

static void test_mm256_add_epi64_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(
		-3, INT64_MAX, 7, -1
	);
	__m256i b = _mm256_setr_epi64x(
		1, 1, -1, INT64_MIN
	);

	__m256i result = _mm256_add_epi64(a, b);

	int64_t expected[4] = {
		-2, INT64_MIN, 6, INT64_MAX
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
		cmocka_unit_test(test_mm256_add_epi8),
		cmocka_unit_test(test_mm256_add_epi16),
		cmocka_unit_test(test_mm256_add_epi32),
		cmocka_unit_test(test_mm256_add_epi64_1),
		cmocka_unit_test(test_mm256_add_epi64_2)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
