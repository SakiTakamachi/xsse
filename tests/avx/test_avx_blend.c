#include "../xsse_test.h"

static void test_mm_blend_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i a = _mm_setr_epi32(1, 100000, -2, -100000);
	__m128i b = _mm_setr_epi32(10, 200000, -20, -200000);

	__m128i result = _mm_blend_epi32(a, b, 0b0101);

	int32_t expected[4] = { 10, 100000, -20, -100000 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_blend_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, 1, 2, 1000, -4, -5, -6, -1000,
		100, -1, -2, -1200, 4, 5, 6, 1200
	);
	__m256i b = _mm256_setr_epi16(
		10, 20, 30, 2000, -40, -50, -60, -2000,
		51, 52, 53, 2400, -54, -55, -56, -2400
	);

	__m256i result = _mm256_blend_epi16(a, b, 0b10110011);

	int16_t expected[16] = {
		10, 20, 2, 1000, -40, -50, -6, -2000,
		51, 52, -2, -1200, -54, -55, 6, -2400
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

static void test_mm256_blend_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0, 1, 2, 1000,
		-4, -5, -6, -1000
	);
	__m256i b = _mm256_setr_epi32(
		10, 20, 30, 2000,
		-40, -50, -60, -2000
	);

	__m256i result = _mm256_blend_epi32(a, b, 0b00110101);

	int32_t expected[8] = {
		10, 1, 30, 1000,
		-40, -50, -6, -1000
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

static void test_mm256_blendv_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
	);
	__m256i b = _mm256_setr_epi8(
		-100, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);
	__m256i mask = _mm256_setr_epi8(
		0xFF, 0, 0x7F, 0x80, 0, 0, 0, 0, 1, 0, 0xFF, 0, 0xFF, 0, 0, 0xF0,
		0, 0, 0, 0x7F, 0x80, 0, 0, 0, 1, 0, 0xFF, 0, 0xFF, 0, 0xF0, 0
	);

	__m256i result = _mm256_blendv_epi8(a, b, mask);

	int8_t expected[32] = {
		-100, 1, 2, -3, 4, 5, 6, 7, 8, 9, -10, 11, -12, 13, 14, -15,
		16, 17, 18, 19, -20, 21, 22, 23, 24, 25, -26, 27, -28, 29, -30, 31
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
		cmocka_unit_test(test_mm_blend_epi32),
		cmocka_unit_test(test_mm256_blend_epi16),
		cmocka_unit_test(test_mm256_blend_epi32),
		cmocka_unit_test(test_mm256_blendv_epi8)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
