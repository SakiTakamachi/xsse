#include "../xsse_test.h"

static void test_mm256_sub_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		0, INT8_MIN, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -7,
		0, 1, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, INT8_MAX
	);
	__m256i b = _mm256_setr_epi8(
		1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -2,
		1, 2, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1
	);

	__m256i result = _mm256_sub_epi8(a, b);

	int8_t expected[32] = {
		-1, INT8_MAX, 1, 2, 5, 6, 7, 8, -1, -2, -3, -4, -3, -4, -5, -5,
		-1, -1, 1, 2, 5, 6, 7, 8, -1, -2, -3, -4, -3, -4, -5, INT8_MIN
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

static void test_mm256_sub_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0, INT16_MIN, 2, 3, 4, 5, 6, 7, 0, -1, -2, -3, -4, -5, -6, -1
	);
	__m256i b = _mm256_setr_epi16(
		1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, INT16_MAX
	);

	__m256i result = _mm256_sub_epi16(a, b);

	int16_t expected[16] = {
		-1, INT16_MAX, 1, 2, 5, 6, 7, 8, -1, -2, -3, -4, -3, -4, -5, INT16_MIN
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

static void test_mm256_sub_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0, INT32_MIN, 2, 3, -4, -5, -6, -1
	);
	__m256i b = _mm256_setr_epi32(
		1, 1, 1, -1, 1, 1, -1, INT32_MAX
	);

	__m256i result = _mm256_sub_epi32(a, b);

	int32_t expected[8] = {
		-1, INT32_MAX, 1, 4, -5, -6, -5, INT32_MIN
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

static void test_mm256_sub_epi64_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(
		2, INT64_MIN, -6, -1
	);
	__m256i b = _mm256_setr_epi64x(
		1, 1, -1, INT64_MAX
	);

	__m256i result = _mm256_sub_epi64(a, b);

	int64_t expected[4] = {
		1, INT64_MAX, -5, INT64_MIN
	};
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_sub_epi64_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi64x(
		-3, INT64_MIN, 7, -1
	);
	__m256i b = _mm256_setr_epi64x(
		1, 1, -1, INT64_MAX
	);

	__m256i result = _mm256_sub_epi64(a, b);

	int64_t expected[4] = {
		-4, INT64_MAX, 8, INT64_MIN
	};
	int64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_sad_epu8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
	);
	__m256i b = _mm256_setr_epi8(
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20
	);

	__m256i result = _mm256_sad_epu8(a, b);

	uint16_t expected[16] = {
		44, 0, 0, 0, 22, 0, 0, 0,
		124, 0, 0, 0, 60, 0, 0, 0
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

static void test_mm256_mpsadbw_epu8_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		1, 2, 3, 4, 15, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
	);
	__m256i b = _mm256_setr_epi8(
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160,
		10, 20, 30, 40, 50, 60, 70, 80, 95, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160
	);

	__m256i result = _mm256_mpsadbw_epu8(a, b, 0b00000000);

	uint16_t expected[16] = {
		90, 86, 82, 78, 74, 70, 66, 62,
		90, 76, 72, 68, 74, 70, 66, 62
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

static void test_mm256_mpsadbw_epu8_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		1, 2, 3, 4, 15, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
	);
	__m256i b = _mm256_setr_epi8(
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160,
		10, 20, 30, 40, 50, 60, 70, 80, 95, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160
	);

	__m256i result = _mm256_mpsadbw_epu8(a, b, 0b00010100);

	uint16_t expected[16] = {
		74, 70, 66, 62, 58, 54, 52, 50,
		415, 401, 397, 393, 389, 395, 391, 387
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

static void test_mm256_mpsadbw_epu8_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		1, 2, 3, 4, 15, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
	);
	__m256i b = _mm256_setr_epi8(
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160,
		10, 20, 30, 40, 50, 60, 70, 80, 95, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160
	);

	__m256i result = _mm256_mpsadbw_epu8(a, b, 0b00100001);

	uint16_t expected[16] = {
		250, 246, 242, 238, 234, 230, 226, 222,
		74, 70, 66, 62, 58, 54, 52, 50
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

static void test_mm256_mpsadbw_epu8_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		1, 2, 3, 4, 15, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
	);
	__m256i b = _mm256_setr_epi8(
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160,
		10, 20, 30, 40, 50, 60, 70, 80, 95, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160
	);

	__m256i result = _mm256_mpsadbw_epu8(a, b, 0b00001010);

	uint16_t expected[16] = {
		410, 406, 402, 398, 394, 390, 386, 382,
		250, 236, 232, 228, 224, 230, 226, 222
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

static void test_mm256_mpsadbw_epu8_5(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
		1, 2, 3, 4, 15, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
	);
	__m256i b = _mm256_setr_epi8(
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160,
		10, 20, 30, 40, 50, 60, 70, 80, 95, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160
	);

	__m256i result = _mm256_mpsadbw_epu8(a, b, 0b00111111);

	uint16_t expected[16] = {
		554, 550, 546, 542, 538, 534, 530, 526,
		544, 550, 546, 542, 538, 534, 530, 526
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
		cmocka_unit_test(test_mm256_sub_epi8),
		cmocka_unit_test(test_mm256_sub_epi16),
		cmocka_unit_test(test_mm256_sub_epi32),
		cmocka_unit_test(test_mm256_sub_epi64_1),
		cmocka_unit_test(test_mm256_sub_epi64_2),
		cmocka_unit_test(test_mm256_sad_epu8),
		cmocka_unit_test(test_mm256_mpsadbw_epu8_1),
		cmocka_unit_test(test_mm256_mpsadbw_epu8_2),
		cmocka_unit_test(test_mm256_mpsadbw_epu8_3),
		cmocka_unit_test(test_mm256_mpsadbw_epu8_4),
		cmocka_unit_test(test_mm256_mpsadbw_epu8_5)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
