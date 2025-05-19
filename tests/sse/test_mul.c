#include "../xsse_test.h"

static void test_mm_mulhi_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0x0001, 0x0002, 0x1234, 0x7FFF, -1, -2, 0x8000, 0x4000);
	__m128i b = _mm_setr_epi16(0x0001, 0x0010, 0x0002, 0x0002, -1, 1, 0x0002, 0x4000);

	__m128i result = _mm_mulhi_epi16(a, b);

	int16_t expected[8] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x1000 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_mulhi_epu16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0x0001, 0x0002, 0x1234, 0x7FFF, 0xFFFF, 0xFFFF, 0x8000, 0x4000);
	__m128i b = _mm_setr_epi16(0x0001, 0x0010, 0x0002, 0x0002, 0xFFFF, 2, 0x0002, 0x4000);

	__m128i result = _mm_mulhi_epu16(a, b);

	uint16_t expected[8] = { 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFE, 0x0001, 0x0001, 0x1000 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
}

static void test_mm_mullo_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0x0001, 0x0002, 0x1234, 0x7FFF, -1, -2, 0x8000, 0x4000);
	__m128i b = _mm_setr_epi16(0x0001, 0x0010, 0x0002, 0x0002, -1, 1, 0x0002, 0x4000);

	__m128i result = _mm_mullo_epi16(a, b);

	int16_t expected[8] = { 0x0001, 0x0020, 0x2468, 0xFFFE, 1, -2, 0x0000, 0x0000 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_mul_epu32(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(1000, 2000, 3000, 4000);
	__m128i b = _mm_setr_epi32(500, 1500, 2500, 3500);

	__m128i result = _mm_mul_epu32(a, b);

	uint64_t expected[2] = { 500000, 7500000 };
	uint64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
}

static void test_mm_maddubs_epi16(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, (int8_t) 130, (int8_t) 140, (int8_t) 150, (int8_t) 160);
	__m128i b = _mm_setr_epi8(1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, 14, 15, 16);

	__m128i result = _mm_maddubs_epi16(a, b);

	int16_t expected[8] = { -30, -70, -110, -150, -190, -230, 3650, 4810 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_mulhrs_epi16(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_setr_epi16(5000, 20000, 32500, 5000, -5000, -20000, -32500, -5000);
	__m128i b = _mm_setr_epi16(2, 3, -4, -5, 2, 3, -4, -5);

	__m128i result = _mm_mulhrs_epi16(a, b);

	int16_t expected[8] = { 0, 2, -4, -1, 0, -2, 4, 1 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_mul_epi32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi32(1000, 2000, -3000, 4000);
	__m128i b = _mm_setr_epi32(500, -1500, 2500, 3500);

	__m128i result = _mm_mul_epi32(a, b);

	int64_t expected[2] = { 500000, -7500000 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_mullo_epi32(void **state)
{
	(void) state;
	
#ifdef XSSE4_1
	__m128i a = _mm_setr_epi32(0x7FFFFFFF, -1, -2, 0x80000000);
	__m128i b = _mm_setr_epi32(2, -1, 1, 2);

	__m128i result = _mm_mullo_epi32(a, b);

	int32_t expected[4] = { 0xFFFFFFFE, 1, -2, 0 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

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
		cmocka_unit_test(test_mm_mulhi_epi16),
		cmocka_unit_test(test_mm_mulhi_epu16),
		cmocka_unit_test(test_mm_mullo_epi16),
		cmocka_unit_test(test_mm_mul_epu32),
		cmocka_unit_test(test_mm_maddubs_epi16),
		cmocka_unit_test(test_mm_mulhrs_epi16),
		cmocka_unit_test(test_mm_mul_epi32),
		cmocka_unit_test(test_mm_mullo_epi32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
