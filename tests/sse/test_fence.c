#include "../xsse_test.h"

static void test_mm_mfence(void **state)
{
	(void) state;

	_mm_mfence();
	assert_true(true);
}

static void test_mm_lfence(void **state)
{
	(void) state;

	_mm_lfence();
	assert_true(true);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_mfence),
		cmocka_unit_test(test_mm_lfence)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
