#include "../xsse_test.h"

static void test_mm256_set1_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_set1_epi8(10);

	int8_t expected[32] = {
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10
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

static void test_mm256_set1_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_set1_epi16(10);

	int16_t expected[16] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	int16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_set1_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_set1_epi32(10);

	int32_t expected[8] = { 10, 10, 10, 10, 10, 10, 10, 10 };
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_set1_epi64x(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i result = _mm256_set1_epi64x(10);

	int64_t expected[4] = { 10, 10, 10, 10 };
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
		cmocka_unit_test(test_mm256_set1_epi8),
		cmocka_unit_test(test_mm256_set1_epi16),
		cmocka_unit_test(test_mm256_set1_epi32),
		cmocka_unit_test(test_mm256_set1_epi64x)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
