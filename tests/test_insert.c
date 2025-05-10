#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <inttypes.h>

#include "../src/xsse.h"

static void test_mm_insert_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi16(10, 20, 30, 40, 50, 60, 70, 80);
	int val = -5000;

	__m128i result = _mm_insert_epi16(x, val, 2);

	int16_t expected[8] = { 10, 20, -5000, 40, 50, 60, 70, 80 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_insert_epi8(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, 80, 11, 12, 13, 14, 15, 16, 17, 18);
	int val = -1;

	__m128i result = _mm_insert_epi8(x, val, 14);

	int8_t expected[16] = { 10, 20, 30, 40, 50, 60, 70, 80 , 11, 12, 13, 14, 15, 16, -1, 18 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_insert_epi32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi32(10, 20, 30, 40);
	int val = -800000;

	__m128i result = _mm_insert_epi32(x, val, 0);

	int32_t expected[4] = { -800000, 20, 30, 40};
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_insert_epi64(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(20, 10);
	int64_t val = 0xFFFFFFFFFFFFFFFF;

	__m128i result = _mm_insert_epi64(x, val, 1);

	int64_t expected[2] = { 10, 0xFFFFFFFFFFFFFFFF };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_true(actual[i] == expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_insert_epi16),
		cmocka_unit_test(test_mm_insert_epi8),
		cmocka_unit_test(test_mm_insert_epi32),
		cmocka_unit_test(test_mm_insert_epi64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
