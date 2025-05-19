#include "../xsse_test.h"

static void test_mm256_permute2f128_si256_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2f128_si256(a, b, ((1 << 3) | 0x03 | (0x01 << 4)));

	int8_t expected[32] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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

static void test_mm256_permute2f128_si256_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2f128_si256(a, b, (((1 << 3) << 4) | 0x03 | (0x01 << 4)));

	int8_t expected[32] = {
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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

static void test_mm256_permute2f128_si256_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2f128_si256(a, b, ((1 << 3) | ((1 << 3) << 4) | 0x03 | (0x03 << 4)));

	int8_t expected[32] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
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

static void test_mm256_permute2f128_si256_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2f128_si256(a, b, (0x00 | (0x03 << 4)));

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
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

static void test_mm256_permute2f128_si256_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2f128_si256(a, b, (0x01 | (0x02 << 4)));

	int8_t expected[32] = {
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15,
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35
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

static void test_mm256_permute2f128_si256_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2f128_si256(a, b, (0x02 | (0x01 << 4)));

	int8_t expected[32] = {
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
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

static void test_mm256_permute2f128_si256_7(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2f128_si256(a, b, (0x03 | (0x00 << 4)));

	int8_t expected[32] = {
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35,
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

static void test_mm256_permute2f128_si256_8(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2f128_si256(a, b, (0x01 | (0x01 << 4)));

	int8_t expected[32] = {
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15,
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

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_permute2f128_si256_1),
		cmocka_unit_test(test_mm256_permute2f128_si256_2),
		cmocka_unit_test(test_mm256_permute2f128_si256_3),
		cmocka_unit_test(test_mm256_permute2f128_si256_4),
		cmocka_unit_test(test_mm256_permute2f128_si256_5),
		cmocka_unit_test(test_mm256_permute2f128_si256_6),
		cmocka_unit_test(test_mm256_permute2f128_si256_7),
		cmocka_unit_test(test_mm256_permute2f128_si256_8)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
