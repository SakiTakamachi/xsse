#include "../xsse_test.h"

static void test_mm256_load_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX

#if defined(__AVX__)
	int8_t *data = _mm_malloc(32, 32);
#elif defined(_MSC_VER)
	int8_t *data = _aligned_malloc(32, 32);
#else
	int8_t data[32];
#endif

	memcpy(data, (int8_t[]) {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	}, 32);
	__m256i result = _mm256_load_si256((const __m256i*) data);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}

#if defined(__AVX__)
	_mm_free(data);
#elif defined(_MSC_VER)
	_aligned_free(data);
#endif

#else
	skip();
#endif
}

static void test_mm256_loadu_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	int8_t data[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	__m256i result = _mm256_loadu_si256((const __m256i*) data);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
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

static void test_mm256_lddqu_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	int8_t data[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	__m256i result = _mm256_lddqu_si256((const __m256i*) data);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
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

static void test_mm256_loadu2_m128i(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	int8_t data_1[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t data_2[32] = {
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	};
	__m256i result = _mm256_loadu2_m128i((const __m128i*) data_1, (const __m128i*) data_2);

	int8_t expected[32] = {
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15
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
		cmocka_unit_test(test_mm256_load_si256),
		cmocka_unit_test(test_mm256_loadu_si256),
		cmocka_unit_test(test_mm256_lddqu_si256),
		cmocka_unit_test(test_mm256_loadu2_m128i)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
