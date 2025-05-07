#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <inttypes.h>

#include "../src/xsse.h"

static void test_mm_movemask_epi8(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi8(0, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF);

	int32_t expected = 0x00003333;
	int32_t actual = _mm_movemask_epi8(x);

	assert_int_equal(actual, expected);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_movemask_epi8)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}