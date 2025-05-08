#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_alignr_epi8_1(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 0);

	int8_t expected[16] = { 31, -30, 29, -28, 27, -26, 25, -24, 23, -22, 21, -20, 19, -18, 17, -16 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_2(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 5);

	int8_t expected[16] = { -26, 25, -24, 23, -22, 21, -20, 19, -18, 17, -16, 15, -14, 13, -12, 11 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_3(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 16);

	int8_t expected[16] = { 15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_4(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 27);

	int8_t expected[16] = { -4, 3, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_5(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 33);

	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
		cmocka_unit_test(test_mm_alignr_epi8_1),
		cmocka_unit_test(test_mm_alignr_epi8_2),
		cmocka_unit_test(test_mm_alignr_epi8_3),
		cmocka_unit_test(test_mm_alignr_epi8_4),
		cmocka_unit_test(test_mm_alignr_epi8_5)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
