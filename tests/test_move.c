#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <inttypes.h>

#include "../src/xsse.h"

static void test_mm_move_epi64(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi64x(100, 200);

	__m128i result = _mm_move_epi64(x);

	int64_t expected[2] = { 200, 0 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_move_epi64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}