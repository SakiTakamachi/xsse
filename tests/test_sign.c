#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_sign_epi8(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i x = _mm_setr_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i signs = _mm_setr_epi8(0, 0, 1, 1, -1, -1, 10, 10, -10, -10, 20, 20, -20, -20, 30, 30);

	__m128i result = _mm_sign_epi8(x, signs);

	int8_t expected[16] = { 0, 0, -2, 3, 4, -5, -6, 7, 8, -9, -10, 11, 12, -13, -14, 15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_sign_epi16(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i x = _mm_setr_epi16(0, 1, -2, 3, -4, 5, -6, 7);
	__m128i signs = _mm_setr_epi16(0, 0, 1, 1, -1, -1, 10, 10);

	__m128i result = _mm_sign_epi16(x, signs);

	int16_t expected[8] = { 0, 0, -2, 3, 4, -5, -6, 7 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_sign_epi32(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i x = _mm_setr_epi32(0, 1, -2, 3);
	__m128i signs = _mm_setr_epi32(0, -1, 1, 5);

	__m128i result = _mm_sign_epi32(x, signs);

	int32_t expected[4] = { 0, -1, -2, 3 };
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
		cmocka_unit_test(test_mm_sign_epi8),
		cmocka_unit_test(test_mm_sign_epi16),
		cmocka_unit_test(test_mm_sign_epi32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
