#include "../xsse_test.h"

static void test_mm256_cvtepi8_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi8(0, -1, 2, -3, 4, -5, 6, -7, -8, 9, -10, 11, -12, 13, -14, 15);

	__m256i result = _mm256_cvtepi8_epi16(x);

	int16_t expected[16] = { 0, -1, 2, -3, 4, -5, 6, -7, -8, 9, -10, 11, -12, 13, -14, 15 };
	int16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepi8_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi8(0, -1, 2, -3, 4, -5, 6, -7, -8, 9, -10, 11, -12, 13, -14, 15);

	__m256i result = _mm256_cvtepi8_epi32(x);

	int32_t expected[8] = { 0, -1, 2, -3, 4, -5, 6, -7 };
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepi8_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi8(0, -1, 2, -3, 4, -5, 6, -7, -8, 9, -10, 11, -12, 13, -14, 15);

	__m256i result = _mm256_cvtepi8_epi64(x);

	int64_t expected[4] = { 0, -1, 2, -3 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepi16_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi16(0, -10000, 2, -3, 4, -5, 6, -7);

	__m256i result = _mm256_cvtepi16_epi32(x);

	int32_t expected[8] = { 0, -10000, 2, -3, 4, -5, 6, -7 };
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepi16_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi16(0, -10000, 2, -3, 4, -5, 6, -7);

	__m256i result = _mm256_cvtepi16_epi64(x);

	int64_t expected[4] = { 0, -10000, 2, -3 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepi32_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi32(0, -1, 200000, -3);

	__m256i result = _mm256_cvtepi32_epi64(x);

	int64_t expected[4] = { 0, -1, 200000, -3 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepu8_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi8(0, 100, (int8_t) 200, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	__m256i result = _mm256_cvtepu8_epi16(x);

	int16_t expected[16] = { 0, 100, 200, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepu8_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi8(0, 100, (int8_t) 200, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	__m256i result = _mm256_cvtepu8_epi32(x);

	int32_t expected[8] = { 0, 100, 200, 3, 4, 5, 6, 7 };
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepu8_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi8(0, 100, (int8_t) 200, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	__m256i result = _mm256_cvtepu8_epi64(x);

	int64_t expected[4] = { 0, 100, 200, 3 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepu16_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi16(0, 10000, (int16_t) 60000, 3, 4, 5, 6, 7);

	__m256i result = _mm256_cvtepu16_epi32(x);

	int32_t expected[8] = { 0, 10000, 60000, 3, 4, 5, 6, 7 };
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepu16_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi16(0, 10000, (int16_t) 60000, 3, 4, 5, 6, 7);

	__m256i result = _mm256_cvtepu16_epi64(x);

	int64_t expected[4] = { 0, 10000, 60000, 3 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cvtepu32_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi32(0, 100000, (int32_t) UINT32_MAX, 3);

	__m256i result = _mm256_cvtepu32_epi64(x);

	int64_t expected[4] = { 0, 100000, UINT32_MAX, 3 };
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
		cmocka_unit_test(test_mm256_cvtepi8_epi16),
		cmocka_unit_test(test_mm256_cvtepi8_epi32),
		cmocka_unit_test(test_mm256_cvtepi8_epi64),
		cmocka_unit_test(test_mm256_cvtepi16_epi32),
		cmocka_unit_test(test_mm256_cvtepi16_epi64),
		cmocka_unit_test(test_mm256_cvtepi32_epi64),
		cmocka_unit_test(test_mm256_cvtepu8_epi16),
		cmocka_unit_test(test_mm256_cvtepu8_epi32),
		cmocka_unit_test(test_mm256_cvtepu8_epi64),
		cmocka_unit_test(test_mm256_cvtepu16_epi32),
		cmocka_unit_test(test_mm256_cvtepu16_epi64),
		cmocka_unit_test(test_mm256_cvtepu32_epi64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
