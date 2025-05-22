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

static void test_mm256_permute2x128_si256_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2x128_si256(a, b, ((1 << 3) | 0x03 | (0x01 << 4)));

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

static void test_mm256_permute2x128_si256_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2x128_si256(a, b, (((1 << 3) << 4) | 0x03 | (0x01 << 4)));

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

static void test_mm256_permute2x128_si256_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2x128_si256(a, b, ((1 << 3) | ((1 << 3) << 4) | 0x03 | (0x03 << 4)));

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

static void test_mm256_permute2x128_si256_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2x128_si256(a, b, (0x00 | (0x03 << 4)));

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

static void test_mm256_permute2x128_si256_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2x128_si256(a, b, (0x01 | (0x02 << 4)));

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

static void test_mm256_permute2x128_si256_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2x128_si256(a, b, (0x02 | (0x01 << 4)));

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

static void test_mm256_permute2x128_si256_7(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2x128_si256(a, b, (0x03 | (0x00 << 4)));

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

static void test_mm256_permute2x128_si256_8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i b = _mm256_setr_epi8(
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -21, -22, -23, -24, -25, -26, -27, 28, 29, 30, 31, 32, 33, 34, 35
	);

	__m256i result = _mm256_permute2x128_si256(a, b, (0x01 | (0x01 << 4)));

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

static void test_mm256_permute4x64_epi64_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b11111100);

	int64_t expected[4] = { 10000, -20000, -20000, -20000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00000001);

	int64_t expected[4] = { 20000, 10000, 10000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00000010);

	int64_t expected[4] = { -10000, 10000, 10000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00000011);

	int64_t expected[4] = { -20000, 10000, 10000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b11110011);

	int64_t expected[4] = { -20000, 10000, -20000, -20000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00000100);

	int64_t expected[4] = { 10000, 20000, 10000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_7(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00001000);

	int64_t expected[4] = { 10000, -10000, 10000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00001100);

	int64_t expected[4] = { 10000, -20000, 10000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_9(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b11001111);

	int64_t expected[4] = { -20000, -20000, 10000, -20000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_10(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00010000);

	int64_t expected[4] = { 10000, 10000, 20000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_11(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00100000);

	int64_t expected[4] = { 10000, 10000, -10000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_12(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00110000);

	int64_t expected[4] = { 10000, 10000, -20000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_13(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b00111111);

	int64_t expected[4] = { -20000, -20000, -20000, 10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_14(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b01000000);

	int64_t expected[4] = { 10000, 10000, 10000, 20000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_15(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b10000000);

	int64_t expected[4] = { 10000, 10000, 10000, -10000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permute4x64_epi64_16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(10000, 20000, -10000, -20000);

	__m256i result = _mm256_permute4x64_epi64(a, 0b11000000);

	int64_t expected[4] = { 10000, 10000, 10000, -20000 };
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permutevar8x32_epi32_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(10000, 20000, 30000, 40000, -10000, -20000, -30000, -40000);
	__m256i idx = _mm256_setr_epi32(3, 2, 0, 1, 7, 5, 6, 4);

	__m256i result = _mm256_permutevar8x32_epi32(a, idx);

	int32_t expected[8] = { 40000, 30000, 10000, 20000, -40000, -20000, -30000, -10000 };
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_permutevar8x32_epi32_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(10000, 20000, 30000, 40000, -10000, -20000, -30000, -40000);
	__m256i idx = _mm256_setr_epi32(4, 4, 0xF3, 0, 0, 1, 5, 6);

	__m256i result = _mm256_permutevar8x32_epi32(a, idx);

	int32_t expected[8] = { -10000, -10000, 40000, 10000, 10000, 20000, -20000, -30000 };
	int32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_shuffle_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_set_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);
	__m256i b = _mm256_set_epi8(
		2, 4, 6, 8, 7, 3, 5, 1, 1, 12, 0x80, 0x8E, 0x6F, 13, 15, 0xFF,
		2, 0x6F, 6, 8, 7, 3, 5, 1, 1, 12, 0x80, 0x8E, 0x6F, 13, 15, 0xFF
	);

	__m256i result = _mm256_shuffle_epi8(a, b);

	int8_t expected[32] = {
		0, -16, -18, -16, 0, 0, -19, -30, -30, -26, -28, -24, -23, -25, -16, -29,
		0, 0, 2, 0, 0, 0, 3, 14, 14, 10, 12, 8, 7, 9, 11, 13
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

static void test_mm256_shuffle_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_set_epi32(
		0, 100, 200, 300,
		-400, -500, -600, -700
	);

	__m256i result = _mm256_shuffle_epi32(x, _MM_SHUFFLE(3, 1, 0, 2));

	int32_t expected[8] = {
		-500, -700, -600, -400,
		100, 300, 200, 0
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

static void test_mm256_shufflehi_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_set_epi16(
		0, 100, 200, 300, 400, 500, 600, 700,
		-800, -900, -1000, -1100, -1200, -1300, -1400, -1500
	);

	__m256i result = _mm256_shufflehi_epi16(x, _MM_SHUFFLE(3, 1, 0, 2));

	int16_t expected[16] = {
		-1500, -1400, -1300, -1200, -900, -1100, -1000, -800,
		700, 600, 500, 400, 100, 300, 200, 0
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

static void test_mm256_shufflelo_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_set_epi16(
		0, 100, 200, 300, 400, 500, 600, 700,
		-800, -900, -1000, -1100, -1200, -1300, -1400, -1500
	);

	__m256i result = _mm256_shufflelo_epi16(x, _MM_SHUFFLE(3, 1, 0, 2));

	int16_t expected[16] = {
		-1300, -1500, -1400, -1200, -1100, -1000, -900, -800,
		500, 700, 600, 400, 300, 200, 100, 0
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
		cmocka_unit_test(test_mm256_permute2f128_si256_8),
		cmocka_unit_test(test_mm256_permute2x128_si256_1),
		cmocka_unit_test(test_mm256_permute2x128_si256_2),
		cmocka_unit_test(test_mm256_permute2x128_si256_3),
		cmocka_unit_test(test_mm256_permute2x128_si256_4),
		cmocka_unit_test(test_mm256_permute2x128_si256_5),
		cmocka_unit_test(test_mm256_permute2x128_si256_6),
		cmocka_unit_test(test_mm256_permute2x128_si256_7),
		cmocka_unit_test(test_mm256_permute2x128_si256_8),
		cmocka_unit_test(test_mm256_permute4x64_epi64_1),
		cmocka_unit_test(test_mm256_permute4x64_epi64_2),
		cmocka_unit_test(test_mm256_permute4x64_epi64_3),
		cmocka_unit_test(test_mm256_permute4x64_epi64_4),
		cmocka_unit_test(test_mm256_permute4x64_epi64_5),
		cmocka_unit_test(test_mm256_permute4x64_epi64_6),
		cmocka_unit_test(test_mm256_permute4x64_epi64_7),
		cmocka_unit_test(test_mm256_permute4x64_epi64_8),
		cmocka_unit_test(test_mm256_permute4x64_epi64_9),
		cmocka_unit_test(test_mm256_permute4x64_epi64_10),
		cmocka_unit_test(test_mm256_permute4x64_epi64_11),
		cmocka_unit_test(test_mm256_permute4x64_epi64_12),
		cmocka_unit_test(test_mm256_permute4x64_epi64_13),
		cmocka_unit_test(test_mm256_permute4x64_epi64_14),
		cmocka_unit_test(test_mm256_permute4x64_epi64_15),
		cmocka_unit_test(test_mm256_permute4x64_epi64_16),
		cmocka_unit_test(test_mm256_permutevar8x32_epi32_1),
		cmocka_unit_test(test_mm256_permutevar8x32_epi32_2),
		cmocka_unit_test(test_mm256_shuffle_epi8),
		cmocka_unit_test(test_mm256_shuffle_epi32),
		cmocka_unit_test(test_mm256_shufflehi_epi16),
		cmocka_unit_test(test_mm256_shufflelo_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
