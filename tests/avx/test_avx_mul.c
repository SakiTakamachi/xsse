#include "../xsse_test.h"

static void test_mm256_madd_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		10, 20, 30, 40, -50, -60, -70, -80,
		10, 20, 30, -40, -50, -60, -70, -80
	);
	__m256i b = _mm256_setr_epi16(
		5, 10, 15, -20, 25, 30, -35, -40,
		5, 10, 15, -20, 25, 30, -35, -40
	);

	__m256i result = _mm256_madd_epi16(a, b);

	int32_t expected[8] = {
		250, -350, -3050, 5650,
		250, 1250, -3050, 5650
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

static void test_mm256_maddubs_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi8(
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160,
		10, 20, 30, 40, 50, 60, 70, 120, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160
	);
	__m256i b = _mm256_setr_epi8(
		1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, 14, 15, 16,
		1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, 14, 15, 30
	);

	__m256i result = _mm256_maddubs_epi16(a, b);

	int16_t expected[16] = {
		-30, -70, -110, -150, -190, -230, 3650, 4810,
		-30, -70, -110, -470, -190, -230, 3650, 7050
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

static void test_mm256_mul_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		1000, 2000, -3000, 4000,
		1200, 2000, -3100, 4000
	);
	__m256i b = _mm256_setr_epi32(
		500, -1500, 2500, 3500,
		510, -1500, 2700, 3500
	);

	__m256i result = _mm256_mul_epi32(a, b);

	int64_t expected[4] = {
		500000, -7500000,
		612000, -8370000
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

static void test_mm256_mul_epu32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		1000, 2000, 3000, 4000,
		1200, 2000, 0x7FFFFFFF, 4000
	);
	__m256i b = _mm256_setr_epi32(
		500, 1500, 2500, 3500,
		510, 1500, 4, 3500
	);

	__m256i result = _mm256_mul_epu32(a, b);

	uint64_t expected[4] = {
		500000, 7500000,
		612000, 0x1FFFFFFFC
	};
	uint64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_mulhi_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0x0001, 0x0002, 0x1234, 0x7FFF, -1, -2, 0x8000, 0x4000,
		0x0001, 0x0002, 0x2345, 0x7FFF, -1, -2, 0x8000, 0x4000
	);
	__m256i b = _mm256_setr_epi16(
		0x0001, 0x0010, 0x0002, 0x0002, -1, 1, 0x0002, 0x4000,
		0x0001, 0x0010, 0x1000, 0x0400, -1, 1, 0x0002, 0x4000
	);

	__m256i result = _mm256_mulhi_epi16(a, b);

	int16_t expected[16] = {
		0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x1000,
		0x0000, 0x0000, 0x0234, 0x01FF, 0x0000, 0xFFFF, 0xFFFF, 0x1000
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

static void test_mm256_mulhi_epu16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0x0001, 0x0002, 0x1234, 0x7FFF, 0xFFFF, 0xFFFF, 0x8000, 0x4000,
		0x0001, 0x0002, 0x2345, 0x7FFF, 0xFFFF, 0xFFFF, 0x8000, 0x4000
	);
	__m256i b = _mm256_setr_epi16(
		0x0001, 0x0010, 0x0002, 0x0002, 0xFFFF, 2, 0x0002, 0x4000,
		0x0001, 0x0010, 0x1000, 0x0400, 0xFFFF, 2, 0x0002, 0x4000
	);

	__m256i result = _mm256_mulhi_epu16(a, b);

	uint16_t expected[16] = {
		0x0000, 0x0000, 0x0000, 0x0000, 0xFFFE, 0x0001, 0x0001, 0x1000,
		0x0000, 0x0000, 0x0234, 0x01FF, 0xFFFE, 0x0001, 0x0001, 0x1000
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

static void test_mm256_mullo_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		0x0001, 0x0002, 0x1234, 0x7FFF, -1, -2, 0x8000, 0x4000,
		0x0001, 0x0002, 0x2345, 0x7FFF, -1, -2, 0x8000, 0x4000
	);
	__m256i b = _mm256_setr_epi16(
		0x0001, 0x0010, 0x0002, 0x0002, -1, 1, 0x0002, 0x4000,
		0x0001, 0x0010, 0x1000, 0x0400, -1, 1, 0x0002, 0x4000
	);

	__m256i result = _mm256_mullo_epi16(a, b);

	int16_t expected[16] = {
		0x0001, 0x0020, 0x2468, 0xFFFE, 1, -2, 0x0000, 0x0000,
		0x0001, 0x0020, 0x5000, 0xFC00, 1, -2, 0x0000, 0x0000
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

static void test_mm256_mullo_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi32(
		0x7FFFFFFF, -1, -2, 0x80000000,
		0x7FFF0000, -1, -2, 0x80000100
	);
	__m256i b = _mm256_setr_epi32(
		2, -1, 1, 2,
		4, -1, 1, 2
	);

	__m256i result = _mm256_mullo_epi32(a, b);

	int32_t expected[8] = {
		0xFFFFFFFE, 1, -2, 0,
		0xFFFC0000, 1, -2, 0x200
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

static void test_mm256_mulhrs_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i a = _mm256_setr_epi16(
		5000, 20000, 32500, 5000, -5000, -20000, -32500, -5000,
		5000, 20000, 42500, 5000, -15000, -20000, -32500, -5000
	);
	__m256i b = _mm256_setr_epi16(
		2, 3, -4, -5, 2, 3, -4, -5,
		2, 1, -4, -5, 2, 3, -6, -5
	);

	__m256i result = _mm256_mulhrs_epi16(a, b);

	int16_t expected[16] = {
		0, 2, -4, -1, 0, -2, 4, 1,
		0, 1, 3, -1, -1, -2, 6, 1
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
		cmocka_unit_test(test_mm256_madd_epi16),
		cmocka_unit_test(test_mm256_maddubs_epi16),
		cmocka_unit_test(test_mm256_mul_epi32),
		cmocka_unit_test(test_mm256_mul_epu32),
		cmocka_unit_test(test_mm256_mulhi_epi16),
		cmocka_unit_test(test_mm256_mulhi_epu16),
		cmocka_unit_test(test_mm256_mullo_epi16),
		cmocka_unit_test(test_mm256_mullo_epi32),
		cmocka_unit_test(test_mm256_mulhrs_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
