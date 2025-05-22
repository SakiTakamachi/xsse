#include "../xsse_test.h"

static void test_mm256_min_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		50, 100, 50, 120, 50, -100, 50, 0, 50, 100, 50, 120, 50, -100, 80, -2,
		50, 100, 50, 120, 50, -100, 70, 0, 50, 100, 50, 120, 50, -100, 50, -2
	);
	__m256i b = _mm256_setr_epi8(
		100, 50, -100, 50, 100, 50, 50, -1, 100, 50, -100, 50, 100, 50, 50, -1,
		100, 50, -100, 50, 100, 50, 50, -1, 100, 50, -120, 50, 100, 50, 50, -1
	);

	__m256i result = _mm256_min_epi8(a, b);

	int8_t expected[32] = {
		50, 50, -100, 50, 50, -100, 50, -1, 50, 50, -100, 50, 50, -100, 50, -2,
		50, 50, -100, 50, 50, -100, 50, -1, 50, 50, -120, 50, 50, -100, 50, -2
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

static void test_mm256_min_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		50, 100, 50, 120, 50, -100, -30000, 0, 50, 100, 50, 120, 50, -100, 80, -2
	);
	__m256i b = _mm256_setr_epi16(
		100, 50, -100, 50, 100, 50, 50, -1, 100, 50, -100, 50, -10000, 50, 50, -1
	);

	__m256i result = _mm256_min_epi16(a, b);

	int16_t expected[16] = {
		50, 50, -100, 50, 50, -100, -30000, -1, 50, 50, -100, 50, -10000, -100, 50, -2
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

static void test_mm256_min_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		-500000, 100, 50, 120, 50, -100, 80, -2
	);
	__m256i b = _mm256_setr_epi32(
		100, 50, -100, 50, -100000, 50, 50, -1
	);

	__m256i result = _mm256_min_epi32(a, b);

	int32_t expected[8] = {
		-500000, 50, -100, 50, -100000, -100, 50, -2
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

static void test_mm256_min_epu8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		50, 100, 50, 100, 50, 100, 50, 1, 50, 100, 50, 100, 50, 100, 50, (int8_t) 200,
		50, 100, 50, 100, 50, 100, 50, (int8_t) 200, 50, 100, 50, 100, 50, 100, 50, (int8_t) 250
	);
	__m256i b = _mm256_setr_epi8(
		100, 50, 100, 50, 100, 50, (int8_t) 200, 50, 100, 50, 100, 50, 100, 50, 50, (int8_t) 200,
		100, 50, 100, 50, 100, 50, 1, 50, 100, 50, 100, 50, 100, 50, 50, (int8_t) 200
	);

	__m256i result = _mm256_min_epu8(a, b);

	uint8_t expected[32] = {
		50, 50, 50, 50, 50, 50, 50, 1, 50, 50, 50, 50, 50, 50, 50, 200,
		50, 50, 50, 50, 50, 50, 1, 50, 50, 50, 50, 50, 50, 50, 50, 200,
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

static void test_mm256_min_epu16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		50, 100, 50, 100, 50, 100, 50, (int16_t) 60000, 50, 100, 50, 100, 50, 100, 50, 200
	);
	__m256i b = _mm256_setr_epi16(
		100, 50, 100, 50, 100, 50, 200, 50, 100, 50, 100, 50, 100, 50, 50, (int16_t) 20000
	);

	__m256i result = _mm256_min_epu16(a, b);

	uint16_t expected[16] = {
		50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 200
	};
	uint16_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_min_epu32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		50, 100, 50, 100, 50, 100, 30, (int32_t) 600000
	);
	__m256i b = _mm256_setr_epi32(
		100, 20, (int32_t) 500000, 50, 100, 50, 200, 50
	);

	__m256i result = _mm256_min_epu32(a, b);

	uint32_t expected[8] = {
		50, 20, 50, 50, 50, 50, 30, 50
	};
	uint32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_min_epi8),
		cmocka_unit_test(test_mm256_min_epi16),
		cmocka_unit_test(test_mm256_min_epi32),
		cmocka_unit_test(test_mm256_min_epu8),
		cmocka_unit_test(test_mm256_min_epu16),
		cmocka_unit_test(test_mm256_min_epu32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
