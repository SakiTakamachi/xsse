#include "../xsse_test.h"

static void test_mm256_insert_epi8_0(void **state)
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

static void test_mm256_insert_epi8_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 120, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 1);
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
		0, 1, 120, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 2);
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
		0, 1, 2, 120, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 3);
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
		0, 1, 2, 3, 120, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 4);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 120, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 5);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 120, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 6);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_7(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 120, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 7);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_8(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, 120, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 8);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_9(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, 120, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 9);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_10(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, 120, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 10);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_11(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, 120, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 11);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_12(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, 120, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 12);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_13(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, 120, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 13);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_14(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, 120, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 14);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_15(void **state)
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

static void test_mm256_insert_epi8_16(void **state)
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

static void test_mm256_insert_epi8_17(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, 120, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 17);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_18(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, 120, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 18);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_19(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, 120, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 19);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_20(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, 120, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 20);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_21(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, 120, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 21);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_22(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, 120, -7, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 22);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_23(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, 120, 8, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 23);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_24(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 120, 9, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 24);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_25(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 120, 10, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 25);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_26(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 120, 11, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 26);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_27(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 120, 12, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 27);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_28(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 120, 13, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 28);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_29(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 120, 14, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 29);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_30(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	int8_t expected[32] = {
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 120, 15
	};
	int8_t actual[32];
	__m256i result = _mm256_insert_epi8(x, 120, 30);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi8_31(void **state)
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

static void test_mm256_insert_epi16_0(void **state)
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

static void test_mm256_insert_epi16_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 15000, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 1);
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

	int16_t expected[16] = { 0, 1, 15000, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 2);
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

	int16_t expected[16] = { 0, 1, 2, 15000, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 3);
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

	int16_t expected[16] = { 0, 1, 2, 3, 15000, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 4);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 15000, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 5);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 15000, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 6);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_7(void **state)
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

static void test_mm256_insert_epi16_8(void **state)
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

static void test_mm256_insert_epi16_9(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, 15000, -10, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 9);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_10(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, 15000, -11, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 10);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_11(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, 15000, -12, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 11);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_12(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, 15000, -13, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 12);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_13(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, 15000, -14, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 13);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_14(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int16_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, 15000, -15 };
	int16_t actual[16];
	__m256i result = _mm256_insert_epi16(x, 15000, 14);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi16_15(void **state)
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

static void test_mm256_insert_epi32_0(void **state)
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

static void test_mm256_insert_epi32_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected[8] = { 0, 30000000, 2, 3, -4, -5, -6, -7 };
	int32_t actual[8];
	__m256i result = _mm256_insert_epi32(x, 30000000, 1);
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

	int32_t expected[8] = { 0, 1, 30000000, 3, -4, -5, -6, -7 };
	int32_t actual[8];
	__m256i result = _mm256_insert_epi32(x, 30000000, 2);
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

static void test_mm256_insert_epi32_4(void **state)
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

static void test_mm256_insert_epi32_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected[8] = { 0, 1, 2, 3, -4, 30000000, -6, -7 };
	int32_t actual[8];
	__m256i result = _mm256_insert_epi32(x, 30000000, 5);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi32_6(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i x = _mm256_setr_epi32(0, 1, 2, 3, -4, -5, -6, -7);

	int32_t expected[8] = { 0, 1, 2, 3, -4, -5, 30000000, -7 };
	int32_t actual[8];
	__m256i result = _mm256_insert_epi32(x, 30000000, 6);
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_insert_epi32_7(void **state)
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

static void test_mm256_insert_epi64_0(void **state)
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

static void test_mm256_insert_epi64_1(void **state)
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

static void test_mm256_insert_epi64_2(void **state)
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

static void test_mm256_insert_epi64_3(void **state)
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

static void test_mm256_insertf128_si256_0(void **state)
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
		cmocka_unit_test(test_mm256_insert_epi8_0),
		cmocka_unit_test(test_mm256_insert_epi8_1),
		cmocka_unit_test(test_mm256_insert_epi8_2),
		cmocka_unit_test(test_mm256_insert_epi8_3),
		cmocka_unit_test(test_mm256_insert_epi8_4),
		cmocka_unit_test(test_mm256_insert_epi8_5),
		cmocka_unit_test(test_mm256_insert_epi8_6),
		cmocka_unit_test(test_mm256_insert_epi8_7),
		cmocka_unit_test(test_mm256_insert_epi8_8),
		cmocka_unit_test(test_mm256_insert_epi8_9),
		cmocka_unit_test(test_mm256_insert_epi8_10),
		cmocka_unit_test(test_mm256_insert_epi8_11),
		cmocka_unit_test(test_mm256_insert_epi8_12),
		cmocka_unit_test(test_mm256_insert_epi8_13),
		cmocka_unit_test(test_mm256_insert_epi8_14),
		cmocka_unit_test(test_mm256_insert_epi8_15),
		cmocka_unit_test(test_mm256_insert_epi8_16),
		cmocka_unit_test(test_mm256_insert_epi8_17),
		cmocka_unit_test(test_mm256_insert_epi8_18),
		cmocka_unit_test(test_mm256_insert_epi8_19),
		cmocka_unit_test(test_mm256_insert_epi8_20),
		cmocka_unit_test(test_mm256_insert_epi8_21),
		cmocka_unit_test(test_mm256_insert_epi8_22),
		cmocka_unit_test(test_mm256_insert_epi8_23),
		cmocka_unit_test(test_mm256_insert_epi8_24),
		cmocka_unit_test(test_mm256_insert_epi8_25),
		cmocka_unit_test(test_mm256_insert_epi8_26),
		cmocka_unit_test(test_mm256_insert_epi8_27),
		cmocka_unit_test(test_mm256_insert_epi8_28),
		cmocka_unit_test(test_mm256_insert_epi8_29),
		cmocka_unit_test(test_mm256_insert_epi8_30),
		cmocka_unit_test(test_mm256_insert_epi8_31),
		cmocka_unit_test(test_mm256_insert_epi16_0),
		cmocka_unit_test(test_mm256_insert_epi16_1),
		cmocka_unit_test(test_mm256_insert_epi16_2),
		cmocka_unit_test(test_mm256_insert_epi16_3),
		cmocka_unit_test(test_mm256_insert_epi16_4),
		cmocka_unit_test(test_mm256_insert_epi16_5),
		cmocka_unit_test(test_mm256_insert_epi16_6),
		cmocka_unit_test(test_mm256_insert_epi16_7),
		cmocka_unit_test(test_mm256_insert_epi16_8),
		cmocka_unit_test(test_mm256_insert_epi16_9),
		cmocka_unit_test(test_mm256_insert_epi16_10),
		cmocka_unit_test(test_mm256_insert_epi16_11),
		cmocka_unit_test(test_mm256_insert_epi16_12),
		cmocka_unit_test(test_mm256_insert_epi16_13),
		cmocka_unit_test(test_mm256_insert_epi16_14),
		cmocka_unit_test(test_mm256_insert_epi16_15),
		cmocka_unit_test(test_mm256_insert_epi32_0),
		cmocka_unit_test(test_mm256_insert_epi32_1),
		cmocka_unit_test(test_mm256_insert_epi32_2),
		cmocka_unit_test(test_mm256_insert_epi32_3),
		cmocka_unit_test(test_mm256_insert_epi32_4),
		cmocka_unit_test(test_mm256_insert_epi32_5),
		cmocka_unit_test(test_mm256_insert_epi32_6),
		cmocka_unit_test(test_mm256_insert_epi32_7),
		cmocka_unit_test(test_mm256_insert_epi64_0),
		cmocka_unit_test(test_mm256_insert_epi64_1),
		cmocka_unit_test(test_mm256_insert_epi64_2),
		cmocka_unit_test(test_mm256_insert_epi64_3),
		cmocka_unit_test(test_mm256_insertf128_si256_0),
		cmocka_unit_test(test_mm256_insertf128_si256_1)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
