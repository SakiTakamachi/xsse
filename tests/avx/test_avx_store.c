#include "../xsse_test.h"

static void test_mm256_store_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);
	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};

#if defined(__AVX__)
	int8_t *actual = _mm_malloc(32, 32);
#elif defined(_MSC_VER)
	int8_t *actual = _aligned_malloc(32, 32);
#else
	int8_t actual[32];
#endif

	_mm256_store_si256((__m256i*) actual, x);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}

#if defined(__AVX__)
	_mm_free(actual);
#elif defined(_MSC_VER)
	_aligned_free(actual);
#endif

#else
	skip();
#endif
}

static void test_mm256_storeu_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);
	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};

	int8_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, x);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_stream_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);
	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};

#if defined(__AVX__)
	int8_t *actual = _mm_malloc(32, 32);
#elif defined(_MSC_VER)
	int8_t *actual = _aligned_malloc(32, 32);
#else
	int8_t actual[32];
#endif

	_mm256_stream_si256((__m256i*) actual, x);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}

#if defined(__AVX__)
	_mm_free(actual);
#elif defined(_MSC_VER)
	_aligned_free(actual);
#endif

#else
	skip();
#endif
}

static void test_mm256_storeu2_m128i(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t actual_1[16];
	int8_t actual_2[16];
	__m128i result_2;

	int8_t expected_1[16] = {
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t expected_2[16] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15
	};

	_mm256_storeu2_m128i((__m128i*) actual_1, (__m128i*) &result_2, x);
	_mm_storeu_si128((__m128i*) actual_2, result_2);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual_1[i], expected_1[i]);
	}
	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual_2[i], expected_2[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_store_si256),
		cmocka_unit_test(test_mm256_storeu_si256),
		cmocka_unit_test(test_mm256_stream_si256),
		cmocka_unit_test(test_mm256_storeu2_m128i)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
