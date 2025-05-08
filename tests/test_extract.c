#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <inttypes.h>

#include "../src/xsse.h"

static void test_mm_extract_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi16(10, 20, 30, 40, 50, 60, 70, 80);

	int32_t expected = 70;
	int32_t actual = _mm_extract_epi16(x, 6);

	assert_int_equal(actual, expected);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_extract_epi16)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
