#include "../xsse_test.h"

static void test_mm_pause(void **state)
{
	(void) state;

	_mm_pause();
	assert_true(true);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_pause)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
