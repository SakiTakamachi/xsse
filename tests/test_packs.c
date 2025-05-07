#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <inttypes.h>

#include "../src/xsse.h"

static void test_mm_packs_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi16(0, 1, 2, 1000, -4, -5, -6, -1000);
	__m128i b = _mm_set_epi16(10, 20, 30, 2000, -40, -50, -60, -2000);

    __m128i result = _mm_packs_epi16(a, b);

	int8_t expected[16] = { INT8_MIN, -6, -5, -4, INT8_MAX, 2, 1, 0, INT8_MIN, -60, -50, -40, INT8_MAX, 30, 20, 10 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_packs_epi32(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi32(1, 2, 100000, -100000);
	__m128i b = _mm_set_epi32(10, 20, 200000, -200000);

    __m128i result = _mm_packs_epi32(a, b);

	int16_t expected[8] = { INT16_MIN, INT16_MAX, 2, 1, INT16_MIN, INT16_MAX, 20, 10 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_packus_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_set_epi16(0, 1, 2, 1000, -4, -5, -6, -1000);
	__m128i b = _mm_set_epi16(10, 20, 30, 2000, -40, -50, -60, -2000);

    __m128i result = _mm_packus_epi16(a, b);

	uint8_t expected[16] = { 0, 0, 0, 0, UINT8_MAX, 2, 1, 0, 0, 0, 0, 0, UINT8_MAX, 30, 20, 10 };
	uint8_t actual[16];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_packs_epi16),
        cmocka_unit_test(test_mm_packs_epi32),
        cmocka_unit_test(test_mm_packus_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}