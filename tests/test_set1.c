#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_set1_epi8(void **state)
{
	(void) state;

	__m128i result = _mm_set1_epi8(5);

	int8_t expected[16] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_set1_epi16(void **state)
{
	(void) state;

	__m128i result = _mm_set1_epi16(5);

	int16_t expected[8] = { 5, 5, 5, 5, 5, 5, 5, 5 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_set1_epi32(void **state)
{
	(void) state;

	__m128i result = _mm_set1_epi32(5);

	int32_t expected[4] = { 5, 5, 5, 5 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_set1_epi64x(void **state)
{
	(void) state;

	__m128i result = _mm_set1_epi64x(5);

	int64_t expected[2] = { 5, 5 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_set1_epi8),
        cmocka_unit_test(test_mm_set1_epi16),
        cmocka_unit_test(test_mm_set1_epi32),
        cmocka_unit_test(test_mm_set1_epi64x)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}