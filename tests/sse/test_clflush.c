#include "../xsse_test.h"

static void test_mm_clflush(void **state)
{
	(void) state;

	char *tmp[16] = { 0 };
	_mm_clflush((void const*) tmp);
	(void) tmp;
	assert_true(true);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_clflush)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
