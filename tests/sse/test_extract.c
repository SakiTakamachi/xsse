#include "../xsse_test.h"

static void test_mm_extract_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi16(10, 20, 30, 40, 50, 60, 7000, 80);

	int16_t expected = 7000;
	int16_t actual = _mm_extract_epi16(x, 6);

	assert_int_equal(actual, expected);
}

static void test_mm_extract_epi8(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, 80, 11, 12, 13, 14, 15, 16, 17, 18);

	int8_t expected = 15;
	int8_t actual = _mm_extract_epi8(x, 12);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_extract_epi32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi32(10, 20, -300000, 40);

	int32_t expected = -300000;
	int32_t actual = _mm_extract_epi32(x, 2);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_extract_epi64(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(0xFFFFFFFFFFFFFF00, 10);

	int64_t expected = 0xFFFFFFFFFFFFFF00;
	int64_t actual = _mm_extract_epi64(x, 1);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_extract_epi16),
		cmocka_unit_test(test_mm_extract_epi8),
		cmocka_unit_test(test_mm_extract_epi32),
		cmocka_unit_test(test_mm_extract_epi64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
