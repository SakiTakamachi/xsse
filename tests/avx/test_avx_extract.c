#include "../xsse_test.h"

static void test_mm256_extract_epi32_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected = -7;
	int32_t actual = _mm256_extract_epi32(x, 7);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi32_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected = 1;
	int32_t actual = _mm256_extract_epi32(x, 1);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi32_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected = -4;
	int32_t actual = _mm256_extract_epi32(x, 4);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi32_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected = 3;
	int32_t actual = _mm256_extract_epi32(x, 3);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi64_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(100, 200, 300, 400);

	int32_t expected = 100;
	int32_t actual = _mm256_extract_epi64(x, 0);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi64_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(100, 200, 300, 400);

	int32_t expected = 200;
	int32_t actual = _mm256_extract_epi64(x, 1);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi64_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(100, 200, 300, 400);

	int32_t expected = 300;
	int32_t actual = _mm256_extract_epi64(x, 2);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi64_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(100, 200, 300, 400);

	int32_t expected = 400;
	int32_t actual = _mm256_extract_epi64(x, 3);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extractf128_si256_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(100, 200, 300, 400);

	int64_t expected[2] = { 100, 200 };
	int64_t actual[2];
	__m128i result = _mm256_extractf128_si256(x, 0);
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_extractf128_si256_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(100, 200, 300, 400);

	int64_t expected[2] = { 300, 400 };
	int64_t actual[2];
	__m128i result = _mm256_extractf128_si256(x, 1);
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_extract_epi32_1),
		cmocka_unit_test(test_mm256_extract_epi32_2),
		cmocka_unit_test(test_mm256_extract_epi32_3),
		cmocka_unit_test(test_mm256_extract_epi32_4),
		cmocka_unit_test(test_mm256_extract_epi64_1),
		cmocka_unit_test(test_mm256_extract_epi64_2),
		cmocka_unit_test(test_mm256_extract_epi64_3),
		cmocka_unit_test(test_mm256_extract_epi64_4),
		cmocka_unit_test(test_mm256_extractf128_si256_1),
		cmocka_unit_test(test_mm256_extractf128_si256_2)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
