#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_subs_epi8_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi8(INT8_MAX);
	__m128i b = _mm_setr_epi8(0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15);

	__m128i result = _mm_subs_epi8(a, b);

	int8_t expected[16] = {
        INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX,
        INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX
    };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_subs_epi16_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi16(INT16_MAX);
	__m128i b = _mm_setr_epi16(0, -1, -2, -3, -4, -5, -6, -7);

	__m128i result = _mm_subs_epi16(a, b);

	int16_t expected[8] = { INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_subs_epi8_overflow),
		cmocka_unit_test(test_mm_subs_epi16_overflow)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
