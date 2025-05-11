#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <inttypes.h>

#include "../src/xsse.h"

static void test_mm_blend_epi16(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi16(0, 1, 2, 1000, -4, -5, -6, -1000);
	__m128i b = _mm_setr_epi16(10, 20, 30, 2000, -40, -50, -60, -2000);

	__m128i result = _mm_blend_epi16(a, b, 0b10110011);

	int16_t expected[8] = { 10, 20, 2, 1000, -40, -50, -6, -2000 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_blendv_epi8(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	__m128i b = _mm_setr_epi8(0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15);
	__m128i mask = _mm_setr_epi8(0xFF, 0, 0x7F, 0x80, 0, 0, 0, 0, 1, 0, 0xFF, 0, 0xFF, 0, 0, 0xF0);

	__m128i result = _mm_blendv_epi8(a, b, mask);

	int8_t expected[16] = { 0, 1, 2, -3, 4, 5, 6, 7, 8, 9, -10, 11, -12, 13, 14, -15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

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
		cmocka_unit_test(test_mm_blend_epi16),
		cmocka_unit_test(test_mm_blendv_epi8)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
