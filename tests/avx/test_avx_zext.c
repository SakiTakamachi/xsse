#include "../xsse_test.h"

static void test_mm256_zextsi128_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m128i x = _mm_setr_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m256i result = _mm256_zextsi128_si256(x);

	int8_t expected[32] = {
		0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15,
		0, 0, 0, 0, 0, 0, 0, 0
	};
	int8_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_zextsi128_si256)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
