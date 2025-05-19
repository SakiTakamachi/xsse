#include "../xsse_test.h"

static void test_mm_test_all_ones_true(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF);

	int actual = _mm_test_all_ones(x);
	int expected = 1;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_test_all_ones_false(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(0xFFFFFFFFFFFFFFFF, 0xEFFFFFFFFFFFFFFF);

	int actual = _mm_test_all_ones(x);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_test_all_zeros_true(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(0xFFFFFFFEFFFFFFEF, 0xEFFFEFFFEFFFEFFF);
	__m128i mask = _mm_set_epi64x(0x0000000100000010, 0x1000100010001000);

	int actual = _mm_test_all_zeros(mask, x);
	int expected = 1;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_test_all_zeros_false(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(0xFFFFFFFFFFFFFFEF, 0xEFFFEFFFEFFFEFFF);
	__m128i mask = _mm_set_epi64x(0x0000000100000010, 0x1000100010001000);

	int actual = _mm_test_all_zeros(mask, x);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_test_mix_ones_zeros_true(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(0xFFFFFFFFFFFFFFEF, 0xEFFFEFFFFFFFEFFF);
	__m128i mask = _mm_set_epi64x(0x0000000100000010, 0x1000100010001000);

	int actual = _mm_test_mix_ones_zeros(x, mask);
	int expected = 1;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_test_mix_ones_zeros_false_1(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(0, 0);
	__m128i mask = _mm_set_epi64x(0x0000000100000010, 0x1000100010001000);

	int actual = _mm_test_mix_ones_zeros(x, mask);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_test_mix_ones_zeros_false_2(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_set_epi64x(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF);
	__m128i mask = _mm_set_epi64x(0x0000000100000010, 0x1000100010001000);

	int actual = _mm_test_mix_ones_zeros(x, mask);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_testc_si128_true(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_set_epi64x(0x000F000F000F000F, 0x000F000F000F000F);
	__m128i b = _mm_set_epi64x(0x0000000d0001000F, 0x0000000d0001000F);

	int actual = _mm_testc_si128(a, b);
	int expected = 1;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_testc_si128_false(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_set_epi64x(0x000F000F000F000F, 0x000F000F000F000F);
	__m128i b = _mm_set_epi64x(0x0000000d0001001F, 0x0000000d0001000F);

	int actual = _mm_testc_si128(a, b);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_testnzc_si128_true(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_set_epi64x(0xFFFFFFFFFFFFFFEF, 0xEFFFEFFFFFFFEFFF);
	__m128i b = _mm_set_epi64x(0x0000000100000010, 0x1000100010001000);

	int actual = _mm_testnzc_si128(a, b);
	int expected = 1;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_testnzc_si128_false_1(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_set_epi64x(0, 0);
	__m128i b = _mm_set_epi64x(0x0000000100000010, 0x1000100010001000);

	int actual = _mm_testnzc_si128(a, b);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_testnzc_si128_false_2(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_set_epi64x(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF);
	__m128i b = _mm_set_epi64x(0x0000000100000010, 0x1000100010001000);

	int actual = _mm_testnzc_si128(a, b);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void _mm_testz_si128_true(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_set_epi64x(0x00FF00FF00FF00FF, 0x00FF00FF00FF00FF);
	__m128i b = _mm_set_epi64x(0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00);

	int actual = _mm_testz_si128(a, b);
	int expected = 1;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void _mm_testz_si128_false(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_set_epi64x(0x10FF00FF00FF00FF, 0x00FF00FF00FF00FF);
	__m128i b = _mm_set_epi64x(0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00);

	int actual = _mm_testz_si128(a, b);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_test_all_ones_true),
		cmocka_unit_test(test_mm_test_all_ones_false),
		cmocka_unit_test(test_mm_test_all_zeros_true),
		cmocka_unit_test(test_mm_test_all_zeros_false),
		cmocka_unit_test(test_mm_test_mix_ones_zeros_true),
		cmocka_unit_test(test_mm_test_mix_ones_zeros_false_1),
		cmocka_unit_test(test_mm_test_mix_ones_zeros_false_2),
		cmocka_unit_test(test_mm_testc_si128_true),
		cmocka_unit_test(test_mm_testc_si128_false),
		cmocka_unit_test(test_mm_testnzc_si128_true),
		cmocka_unit_test(test_mm_testnzc_si128_false_1),
		cmocka_unit_test(test_mm_testnzc_si128_false_2),
		cmocka_unit_test(_mm_testz_si128_true),
		cmocka_unit_test(_mm_testz_si128_false)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
