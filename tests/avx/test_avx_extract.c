#include "../xsse_test.h"

static void test_mm256_extract_epi32_0(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected = 0;
	int32_t actual = _mm256_extract_epi32(x, 0);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi32_1(void **state)
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

static void test_mm256_extract_epi32_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected = 2;
	int32_t actual = _mm256_extract_epi32(x, 2);

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

	int32_t expected = 3;
	int32_t actual = _mm256_extract_epi32(x, 3);

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

	int32_t expected = -4;
	int32_t actual = _mm256_extract_epi32(x, 4);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi32_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected = -5;
	int32_t actual = _mm256_extract_epi32(x, 5);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi32_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected = -6;
	int32_t actual = _mm256_extract_epi32(x, 6);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi32_7(void **state)
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

static void test_mm256_extract_epi64_0(void **state)
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

static void test_mm256_extract_epi64_1(void **state)
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

static void test_mm256_extract_epi64_2(void **state)
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

static void test_mm256_extract_epi64_3(void **state)
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

static void test_mm256_extractf128_si256_0(void **state)
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

static void test_mm256_extractf128_si256_1(void **state)
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

static void test_mm256_extract_epi8_0(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 0;
	int8_t actual = _mm256_extract_epi8(x, 0);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 1;
	int8_t actual = _mm256_extract_epi8(x, 1);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 2;
	int8_t actual = _mm256_extract_epi8(x, 2);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 3;
	int8_t actual = _mm256_extract_epi8(x, 3);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 4;
	int8_t actual = _mm256_extract_epi8(x, 4);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 5;
	int8_t actual = _mm256_extract_epi8(x, 5);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 6;
	int8_t actual = _mm256_extract_epi8(x, 6);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_7(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 7;
	int8_t actual = _mm256_extract_epi8(x, 7);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 8;
	int8_t actual = _mm256_extract_epi8(x, 8);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_9(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 9;
	int8_t actual = _mm256_extract_epi8(x, 9);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_10(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 10;
	int8_t actual = _mm256_extract_epi8(x, 10);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_11(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 11;
	int8_t actual = _mm256_extract_epi8(x, 11);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_12(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 12;
	int8_t actual = _mm256_extract_epi8(x, 12);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_13(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 13;
	int8_t actual = _mm256_extract_epi8(x, 13);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_14(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 14;
	int8_t actual = _mm256_extract_epi8(x, 14);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_15(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = 15;
	int8_t actual = _mm256_extract_epi8(x, 15);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -16;
	int8_t actual = _mm256_extract_epi8(x, 16);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_17(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -17;
	int8_t actual = _mm256_extract_epi8(x, 17);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_18(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -18;
	int8_t actual = _mm256_extract_epi8(x, 18);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_19(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -19;
	int8_t actual = _mm256_extract_epi8(x, 19);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_20(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -20;
	int8_t actual = _mm256_extract_epi8(x, 20);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_21(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -21;
	int8_t actual = _mm256_extract_epi8(x, 21);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_22(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -22;
	int8_t actual = _mm256_extract_epi8(x, 22);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_23(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -23;
	int8_t actual = _mm256_extract_epi8(x, 23);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_24(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -24;
	int8_t actual = _mm256_extract_epi8(x, 24);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_25(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -25;
	int8_t actual = _mm256_extract_epi8(x, 25);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_26(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -26;
	int8_t actual = _mm256_extract_epi8(x, 26);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_27(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -27;
	int8_t actual = _mm256_extract_epi8(x, 27);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_28(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -28;
	int8_t actual = _mm256_extract_epi8(x, 28);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_29(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -29;
	int8_t actual = _mm256_extract_epi8(x, 29);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_30(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -30;
	int8_t actual = _mm256_extract_epi8(x, 30);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi8_31(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		-16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31
	);

	int8_t expected = -31;
	int8_t actual = _mm256_extract_epi8(x, 31);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_0(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 0;
	int16_t actual = _mm256_extract_epi16(x, 0);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 1;
	int16_t actual = _mm256_extract_epi16(x, 1);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 2;
	int16_t actual = _mm256_extract_epi16(x, 2);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 3;
	int16_t actual = _mm256_extract_epi16(x, 3);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 4;
	int16_t actual = _mm256_extract_epi16(x, 4);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 5;
	int16_t actual = _mm256_extract_epi16(x, 5);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 6;
	int16_t actual = _mm256_extract_epi16(x, 6);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_7(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 7;
	int16_t actual = _mm256_extract_epi16(x, 7);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 8;
	int16_t actual = _mm256_extract_epi16(x, 8);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_9(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 9;
	int16_t actual = _mm256_extract_epi16(x, 9);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_10(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 10;
	int16_t actual = _mm256_extract_epi16(x, 10);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_11(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 11;
	int16_t actual = _mm256_extract_epi16(x, 11);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_12(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 12;
	int16_t actual = _mm256_extract_epi16(x, 12);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_13(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 13;
	int16_t actual = _mm256_extract_epi16(x, 13);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_14(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 14;
	int16_t actual = _mm256_extract_epi16(x, 14);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extract_epi16_15(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int16_t expected = 15;
	int16_t actual = _mm256_extract_epi16(x, 15);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm256_extracti128_si256_0(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi64x(100, 200, 300, 400);

	int64_t expected[2] = { 100, 200 };
	int64_t actual[2];
	__m128i result = _mm256_extracti128_si256(x, 0);
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_extracti128_si256_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi64x(100, 200, 300, 400);

	int64_t expected[2] = { 300, 400 };
	int64_t actual[2];
	__m128i result = _mm256_extracti128_si256(x, 1);
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
		cmocka_unit_test(test_mm256_extract_epi32_0),
		cmocka_unit_test(test_mm256_extract_epi32_1),
		cmocka_unit_test(test_mm256_extract_epi32_2),
		cmocka_unit_test(test_mm256_extract_epi32_3),
		cmocka_unit_test(test_mm256_extract_epi32_4),
		cmocka_unit_test(test_mm256_extract_epi32_5),
		cmocka_unit_test(test_mm256_extract_epi32_6),
		cmocka_unit_test(test_mm256_extract_epi32_7),
		cmocka_unit_test(test_mm256_extract_epi64_0),
		cmocka_unit_test(test_mm256_extract_epi64_1),
		cmocka_unit_test(test_mm256_extract_epi64_2),
		cmocka_unit_test(test_mm256_extract_epi64_3),
		cmocka_unit_test(test_mm256_extractf128_si256_0),
		cmocka_unit_test(test_mm256_extractf128_si256_1),
		cmocka_unit_test(test_mm256_extract_epi8_0),
		cmocka_unit_test(test_mm256_extract_epi8_1),
		cmocka_unit_test(test_mm256_extract_epi8_2),
		cmocka_unit_test(test_mm256_extract_epi8_3),
		cmocka_unit_test(test_mm256_extract_epi8_4),
		cmocka_unit_test(test_mm256_extract_epi8_5),
		cmocka_unit_test(test_mm256_extract_epi8_6),
		cmocka_unit_test(test_mm256_extract_epi8_7),
		cmocka_unit_test(test_mm256_extract_epi8_8),
		cmocka_unit_test(test_mm256_extract_epi8_9),
		cmocka_unit_test(test_mm256_extract_epi8_10),
		cmocka_unit_test(test_mm256_extract_epi8_11),
		cmocka_unit_test(test_mm256_extract_epi8_12),
		cmocka_unit_test(test_mm256_extract_epi8_13),
		cmocka_unit_test(test_mm256_extract_epi8_14),
		cmocka_unit_test(test_mm256_extract_epi8_15),
		cmocka_unit_test(test_mm256_extract_epi8_16),
		cmocka_unit_test(test_mm256_extract_epi8_17),
		cmocka_unit_test(test_mm256_extract_epi8_18),
		cmocka_unit_test(test_mm256_extract_epi8_19),
		cmocka_unit_test(test_mm256_extract_epi8_20),
		cmocka_unit_test(test_mm256_extract_epi8_21),
		cmocka_unit_test(test_mm256_extract_epi8_22),
		cmocka_unit_test(test_mm256_extract_epi8_23),
		cmocka_unit_test(test_mm256_extract_epi8_24),
		cmocka_unit_test(test_mm256_extract_epi8_25),
		cmocka_unit_test(test_mm256_extract_epi8_26),
		cmocka_unit_test(test_mm256_extract_epi8_27),
		cmocka_unit_test(test_mm256_extract_epi8_28),
		cmocka_unit_test(test_mm256_extract_epi8_29),
		cmocka_unit_test(test_mm256_extract_epi8_30),
		cmocka_unit_test(test_mm256_extract_epi8_31),
		cmocka_unit_test(test_mm256_extract_epi16_0),
		cmocka_unit_test(test_mm256_extract_epi16_1),
		cmocka_unit_test(test_mm256_extract_epi16_2),
		cmocka_unit_test(test_mm256_extract_epi16_3),
		cmocka_unit_test(test_mm256_extract_epi16_4),
		cmocka_unit_test(test_mm256_extract_epi16_5),
		cmocka_unit_test(test_mm256_extract_epi16_6),
		cmocka_unit_test(test_mm256_extract_epi16_7),
		cmocka_unit_test(test_mm256_extract_epi16_8),
		cmocka_unit_test(test_mm256_extract_epi16_9),
		cmocka_unit_test(test_mm256_extract_epi16_10),
		cmocka_unit_test(test_mm256_extract_epi16_11),
		cmocka_unit_test(test_mm256_extract_epi16_12),
		cmocka_unit_test(test_mm256_extract_epi16_13),
		cmocka_unit_test(test_mm256_extract_epi16_14),
		cmocka_unit_test(test_mm256_extract_epi16_15),
		cmocka_unit_test(test_mm256_extracti128_si256_0),
		cmocka_unit_test(test_mm256_extracti128_si256_1)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
