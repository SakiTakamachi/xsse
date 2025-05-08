#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_hsub_epi16(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi16(0, 1, 2, 3, -4, -5, -1, INT16_MAX);
	__m128i b = _mm_set_epi16(1, INT16_MIN, 18, 19, -50, -21, 52, 23);

	__m128i result = _mm_hsub_epi16(a, b);

	int16_t expected[8] = { INT16_MIN, -1, 1, 1, -29, 29, 1, INT16_MAX };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_hsub_epi32(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi32(5, 3, -2, INT32_MAX);
	__m128i b = _mm_set_epi32(2, INT32_MIN, -32, -23);

	__m128i result = _mm_hsub_epi32(a, b);

	int32_t expected[4] = { INT32_MIN + 1, -2, 9, INT32_MAX - 1 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_hsubs_epi16(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi16(10, INT16_MIN + 5, 2, 3, -4, 8, -1, INT16_MAX);
	__m128i b = _mm_set_epi16(1, INT16_MIN, 28, 19, -20, -41, -23, INT16_MAX - 10);

	__m128i result = _mm_hsubs_epi16(a, b);

	int16_t expected[8] = { INT16_MAX, 12, 1, INT16_MIN, INT16_MAX, -21, -9, INT16_MIN };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_hsub_epi16),
		cmocka_unit_test(test_mm_hsub_epi32),
		cmocka_unit_test(test_mm_hsubs_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
