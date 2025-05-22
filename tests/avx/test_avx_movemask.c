#include "../xsse_test.h"

static void test_mm256_movemask_epi8(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_set_epi8(
		0, 0x0F, 0x00, 0xFF, 0x00, 0x0F, 0xF0, 0x00, 0, 0x0F, 0xF0, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF,
		0x0F, 0xF0, 0xFF, 0x00, 0xFF, 0xF0, 0xFF, 0, 0x0F, 0xF0, 0xFF, 0xFF, 0x0F, 0xF0, 0xFF, 0
	);

	int32_t expected = 0x123B6E76;
	int32_t actual = _mm256_movemask_epi8(x);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_movemask_epi8)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
