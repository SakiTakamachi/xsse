#include "../xsse_test.h"

static void test_mm256_avg_epu8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150,
		0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 130, (int8_t) 130
	);
	__m256i b = _mm256_setr_epi8(
		0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60,
		0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 52, 52
	);

	__m256i result = _mm256_avg_epu8(a, b);

	uint8_t expected[32] = {
		0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105,
		0, 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 91, 91
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

static void test_mm256_avg_epu16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		80, 90, 100, 110, 120, (int16_t) 13000, (int16_t) 140, (int16_t) 150,
		80, 90, 100, 110, 120, (int16_t) 130, (int16_t) 13000, (int16_t) 130
	);
	__m256i b = _mm256_setr_epi16(
		32, 36, 40, 44, 48, 52, 56, 60,
		32, 36, 40, 44, 48, 52, 52, 52
	);

	__m256i result = _mm256_avg_epu16(a, b);

	uint16_t expected[16] = {
		56, 63, 70, 77, 84, 6526, 98, 105,
		56, 63, 70, 77, 84, 91, 6526, 91
	};
	uint16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_avg_epu8),
		cmocka_unit_test(test_mm256_avg_epu16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
