#include "../xsse_test.h"

static void test_mm_cvtsi32_si128(void **state)
{
	(void) state;

	int32_t x = 12345;
	__m128i result = _mm_cvtsi32_si128(x);

	int32_t expected[4] = { 12345, 0, 0, 0 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_cvtsi64_si128(void **state)
{
	(void) state;

	int64_t x = 12345;
	__m128i result = _mm_cvtsi64_si128(x);

	int64_t expected[2] = { 12345, 0 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_cvtsi128_si32(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi32(10000, 20000, 30000, 40000);

	int32_t actual = _mm_cvtsi128_si32(x);
	int32_t expected = 40000;
	assert_int_equal(actual, expected);
}

static void test_mm_cvtsi128_si64(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi64x(10000, 20000);

	int64_t actual = _mm_cvtsi128_si64(x);
	int64_t expected = 20000;
	assert_int_equal(actual, expected);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cvtsi32_si128),
		cmocka_unit_test(test_mm_cvtsi64_si128),
		cmocka_unit_test(test_mm_cvtsi128_si32),
		cmocka_unit_test(test_mm_cvtsi128_si64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
