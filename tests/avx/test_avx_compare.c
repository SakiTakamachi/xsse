#include "../xsse_test.h"

static void test_mm256_cmpeq_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100,
		-100, -100, -100, -100, -100, -100, -100, -100, 100, 100, 100, 100, 100, 100, 100, 100
	);
	__m256i b = _mm256_setr_epi8(
		100, 101, 99, 0, -100, -101, -99, 0, 100, 101, 99, 0, -100, -101, -99, 0,
		100, 101, 99, 0, -100, -101, -99, 0, 100, 100, 100, 100, 100, 100, 100, 100
	);

	__m256i result = _mm256_cmpeq_epi8(a, b);

	int8_t expected[32] = {
		0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFF, 0, 0, 0,
		0, 0, 0, 0, 0xFF, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
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

static void test_mm256_cmpeq_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100
	);
	__m256i b = _mm256_setr_epi16(
		100, 101, 99, 0, -100, -101, -99, 0, 100, 101, 99, 0, -100, -101, -99, 0
	);

	__m256i result = _mm256_cmpeq_epi16(a, b);

	int16_t expected[16] = {
		0xFFFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFFFF, 0, 0, 0
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

static void test_mm256_cmpeq_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		100, 100, 100, 100, -100, -100, -100, -100
	);
	__m256i b = _mm256_setr_epi32(
		100, 101, 99, 0, 0, -101, -99, -100
	);

	__m256i result = _mm256_cmpeq_epi32(a, b);

	int32_t expected[8] = {
		0xFFFFFFFF, 0, 0, 0, 0, 0, 0, 0xFFFFFFFF
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

static void test_mm256_cmpeq_epi64_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(100, 100, 100, 100);
	__m256i b = _mm256_setr_epi64x(100, 101, 99, 0);

	__m256i result = _mm256_cmpeq_epi64(a, b);

	int64_t expected[4] = { 0xFFFFFFFFFFFFFFFF, 0, 0, 0 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cmpeq_epi64_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(-100, -100, -100, -100);
	__m256i b = _mm256_setr_epi64x(-101, -99, 0, -100);

	__m256i result = _mm256_cmpeq_epi64(a, b);

	int64_t expected[4] = { 0, 0, 0, 0xFFFFFFFFFFFFFFFF };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cmpgt_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100,
		-100, -100, -100, -100, -100, -100, -100, -100, 100, 100, 100, 100, 100, 100, 100, 100
	);
	__m256i b = _mm256_setr_epi8(
		100, 101, 99, 0, -100, -101, -99, 0, 100, 101, 99, 0, -100, -101, -99, 0,
		100, 101, 99, 0, -100, -101, -99, 0, 100, 100, 100, 100, 100, 100, 100, 100
	);

	__m256i result = _mm256_cmpgt_epi8(a, b);

	int8_t expected[32] = {
		0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0, 0, 0xFF, 0, 0,
		0, 0, 0, 0, 0, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
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

static void test_mm256_cmpgt_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100
	);
	__m256i b = _mm256_setr_epi16(
		100, 101, 99, 0, -100, -101, -99, 0, 100, 101, 99, 0, -100, -101, -99, 0
	);

	__m256i result = _mm256_cmpgt_epi16(a, b);

	int16_t expected[16] = {
		0, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0, 0, 0, 0, 0, 0xFFFF, 0, 0
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

static void test_mm256_cmpgt_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		100, 100, 100, 100, -100, -100, -100, -100
	);
	__m256i b = _mm256_setr_epi32(
		100, 101, 99, 0, 0, -101, -99, -100
	);

	__m256i result = _mm256_cmpgt_epi32(a, b);

	int32_t expected[8] = {
		0, 0, 0xFFFFFFFF, 0xFFFFFFFF, 0, 0xFFFFFFFF, 0, 0
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

static void test_mm256_cmpgt_epi64_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(100, 100, 100, 100);
	__m256i b = _mm256_setr_epi64x(100, 101, 99, 0);

	__m256i result = _mm256_cmpgt_epi64(a, b);

	int64_t expected[4] = { 0, 0, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_cmpgt_epi64_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(-100, -100, -100, -100);
	__m256i b = _mm256_setr_epi64x(-101, -99, 0, -100);

	__m256i result = _mm256_cmpgt_epi64(a, b);

	int64_t expected[4] = { 0xFFFFFFFFFFFFFFFF, 0, 0, 0 };
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
		cmocka_unit_test(test_mm256_cmpeq_epi8),
		cmocka_unit_test(test_mm256_cmpeq_epi16),
		cmocka_unit_test(test_mm256_cmpeq_epi32),
		cmocka_unit_test(test_mm256_cmpeq_epi64_1),
		cmocka_unit_test(test_mm256_cmpeq_epi64_2),
		cmocka_unit_test(test_mm256_cmpgt_epi8),
		cmocka_unit_test(test_mm256_cmpgt_epi16),
		cmocka_unit_test(test_mm256_cmpgt_epi32),
		cmocka_unit_test(test_mm256_cmpgt_epi64_1),
		cmocka_unit_test(test_mm256_cmpgt_epi64_2)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
