#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_madd_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(10, 20, 30, 40, -50, -60, -70, -80);
	__m128i b = _mm_setr_epi16(5, 10, 15, -20, 25, 30, -35, -40);

	__m128i result = _mm_madd_epi16(a, b);

	int32_t expected[4] = { 250, -350, -3050, 5650 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_madd_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
