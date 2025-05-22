#include "../xsse_test.h"

static void test_mm_broadcastb_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	__m128i result = _mm_broadcastb_epi8(x);

	int8_t expected[16] = { -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15, -15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_broadcastw_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi16(0, 1, 2, 3, 4, 5, 6, 450);

	__m128i result = _mm_broadcastw_epi16(x);

	int16_t expected[8] = { 450, 450, 450, 450, 450, 450, 450, 450 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_broadcastd_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi32(0, 1, 2, 500000);

	__m128i result = _mm_broadcastd_epi32(x);

	int32_t expected[4] = { 500000, 500000, 500000, 500000 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_broadcastq_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi64x(0, 30000000000);

	__m128i result = _mm_broadcastq_epi64(x);

	int64_t expected[2] = { 30000000000, 30000000000 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_broadcastb_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, 120);

	__m256i result = _mm256_broadcastb_epi8(x);

	int8_t expected[32] = {
		120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120,
		120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120
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

static void test_mm256_broadcastw_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi16(0, 1, 2, 3, 4, 5, 6, -12000);

	__m256i result = _mm256_broadcastw_epi16(x);

	int16_t expected[16] = {
		-12000, -12000, -12000, -12000, -12000, -12000, -12000, -12000,
		-12000, -12000, -12000, -12000, -12000, -12000, -12000, -12000
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

static void test_mm256_broadcastd_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi32(0, 1, 2, 500000);

	__m256i result = _mm256_broadcastd_epi32(x);

	int32_t expected[8] = {
		500000, 500000, 500000, 500000, 500000, 500000, 500000, 500000
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

static void test_mm256_broadcastq_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi64x(0, -900000000000);

	__m256i result = _mm256_broadcastq_epi64(x);

	int64_t expected[4] = {
		-900000000000, -900000000000, -900000000000, -900000000000
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

static void test_mm_broadcastsi128_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	__m256i result = _mm_broadcastsi128_si256(x);

	int8_t expected[32] = {
		-15, -14, -13, -12, -11, -10, -9, -8, 7, 6, 5, 4, 3, 2, 1, 0,
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

static void test_mm256_broadcastsi128_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	__m256i result = _mm256_broadcastsi128_si256(x);

	int8_t expected[32] = {
		-15, -14, -13, -12, -11, -10, -9, -8, 7, 6, 5, 4, 3, 2, 1, 0,
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

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_broadcastb_epi8),
		cmocka_unit_test(test_mm_broadcastw_epi16),
		cmocka_unit_test(test_mm_broadcastd_epi32),
		cmocka_unit_test(test_mm_broadcastq_epi64),
		cmocka_unit_test(test_mm256_broadcastb_epi8),
		cmocka_unit_test(test_mm256_broadcastw_epi16),
		cmocka_unit_test(test_mm256_broadcastd_epi32),
		cmocka_unit_test(test_mm256_broadcastq_epi64),
		cmocka_unit_test(test_mm_broadcastsi128_si256),
		cmocka_unit_test(test_mm256_broadcastsi128_si256)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
