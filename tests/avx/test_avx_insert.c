#include "../xsse_test.h"

static void test_mm256_insert_epi8_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		120, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 0);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, 120,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 15);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		120, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 16);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 120
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 31);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 15000, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 0);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 15000, -8, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 7);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 15000, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 8);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, 15000 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 15);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi32_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected[8] = { 30000000, 1, 2, 3, -4, -5, -6, -7 };
	int32_t actual[8];
	__m256i result = _mm256_insert_epi32(x, 30000000, 0);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi32_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected[8] = { 0, 1, 2, 30000000, -4, -5, -6, -7 };
	int32_t actual[8];
	__m256i result = _mm256_insert_epi32(x, 30000000, 3);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi32_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected[8] = { 0, 1, 2, 3, 30000000, -5, -6, -7 };
	int32_t actual[8];
	__m256i result = _mm256_insert_epi32(x, 30000000, 4);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi32_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected[8] = { 0, 1, 2, 3, -4, -5, -6, 30000000 };
	int32_t actual[8];
	__m256i result = _mm256_insert_epi32(x, 30000000, 7);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi64_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(0, 1, -2, -3);

	int64_t expected[4] = { 700000000000, 1, -2, -3 };
	int64_t actual[4];
	__m256i result = _mm256_insert_epi64(x, 700000000000, 0);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi64_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(0, 1, -2, -3);

	int64_t expected[4] = { 0, 700000000000, -2, -3 };
	int64_t actual[4];
	__m256i result = _mm256_insert_epi64(x, 700000000000, 1);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi64_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(0, 1, -2, -3);

	int64_t expected[4] = { 0, 1, 700000000000, -3 };
	int64_t actual[4];
	__m256i result = _mm256_insert_epi64(x, 700000000000, 2);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi64_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi64x(0, 1, -2, -3);

	int64_t expected[4] = { 0, 1, -2, 700000000000 };
	int64_t actual[4];
	__m256i result = _mm256_insert_epi64(x, 700000000000, 3);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insertf128_si256_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);
	__m128i b = _mm_setr_epi8(0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35);

	int8_t expected[32] = {
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insertf128_si256(a, b, 0);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insertf128_si256_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);
	__m128i b = _mm_setr_epi8(0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, 21, 22, 23, 24, 25, 26, 27, -28, -29, -30, -31, -32, -33, -34, -35
	};
	int8_t actual[32];
	__m256i result = _mm256_insertf128_si256(a, b, 1);
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
		cmocka_unit_test(test_mm256_insert_epi8_1),
		cmocka_unit_test(test_mm256_insert_epi8_2),
		cmocka_unit_test(test_mm256_insert_epi8_3),
		cmocka_unit_test(test_mm256_insert_epi8_4),
		cmocka_unit_test(test_mm256_insert_epi16_1),
		cmocka_unit_test(test_mm256_insert_epi16_2),
		cmocka_unit_test(test_mm256_insert_epi16_3),
		cmocka_unit_test(test_mm256_insert_epi16_4),
		cmocka_unit_test(test_mm256_insert_epi32_1),
		cmocka_unit_test(test_mm256_insert_epi32_2),
		cmocka_unit_test(test_mm256_insert_epi32_3),
		cmocka_unit_test(test_mm256_insert_epi32_4),
		cmocka_unit_test(test_mm256_insert_epi64_1),
		cmocka_unit_test(test_mm256_insert_epi64_2),
		cmocka_unit_test(test_mm256_insert_epi64_3),
		cmocka_unit_test(test_mm256_insert_epi64_4),
		cmocka_unit_test(test_mm256_insertf128_si256_1),
		cmocka_unit_test(test_mm256_insertf128_si256_2)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
