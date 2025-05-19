#include "../xsse_test.h"

static void test_mm256_zeroupper(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	_mm256_zeroupper();
	assert_true(1);
#else
	skip();
#endif
}

static void test_mm256_zeroall(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	_mm256_zeroall();
	assert_true(1);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_zeroupper),
		cmocka_unit_test(test_mm256_zeroall)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
