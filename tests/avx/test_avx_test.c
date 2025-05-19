#include "../xsse_test.h"

static void test_mm256_testc_si256_true(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0x000F000F000F000F, 0x000F000F000F000F, 0x000F000F000F000F, 0x000F000F000F000F);
	__m256i b = _mm256_set_epi64x(0x0000000d0001000F, 0x0000000d0001000F, 0x0000000d0001000F, 0x0000000d0001000F);

	int actual = _mm256_testc_si256(a, b);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm256_testc_si256_false_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0x000F000F000F000F, 0x000F000F000F000F, 0x000F000F000F000F, 0x000F000F000F000F);
	__m256i b = _mm256_set_epi64x(0x0000000d0001001F, 0x0000000d0001000F, 0x0000000d0001000F, 0x0000000d0001000F);

	int actual = _mm256_testc_si256(a, b);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm256_testc_si256_false_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0x000F000F000F000F, 0x000F000F000F000F, 0x000F000F000F000F, 0x000F000F000F000F);
	__m256i b = _mm256_set_epi64x(0x0000000d0001000F, 0x0000000d0001000F, 0x0000000d0001001F, 0x0000000d0001000F);

	int actual = _mm256_testc_si256(a, b);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm256_testc_si256_false_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0x000F000F000F000F, 0x000F000F000F000F, 0x000F000F000F000F, 0x000F000F000F000F);
	__m256i b = _mm256_set_epi64x(0x0000000d0001001F, 0x0000000d0001000F, 0x0000000d0001001F, 0x0000000d0001000F);

	int actual = _mm256_testc_si256(a, b);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm256_testnzc_si256_true_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0xFFFFFFFFFFFFFFEF, 0xEFFFEFFFFFFFEFFF, 0xFFFFFFFFFFFFFFEF, 0xEFFFEFFFFFFFEFFF);
	__m256i b = _mm256_set_epi64x(0x0000000100000010, 0x1000100010001000, 0x0000000100000010, 0x1000100010001000);

	int actual = _mm256_testnzc_si256(a, b);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm256_testnzc_si256_true_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0xFFFFFFFFFFFFFFEF, 0xEFFFEFFFFFFFEFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF);
	__m256i b = _mm256_set_epi64x(0x0000000100000010, 0x1000100010001000, 0x0000000100000010, 0x1000100010001000);

	int actual = _mm256_testnzc_si256(a, b);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm256_testnzc_si256_true_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0, 0, 0xFFFFFFFFFFFFFFEF, 0xEFFFEFFFFFFFEFFF);
	__m256i b = _mm256_set_epi64x(0x0000000100000010, 0x1000100010001000, 0x0000000100000010, 0x1000100010001000);

	int actual = _mm256_testnzc_si256(a, b);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm256_testnzc_si256_true_4(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0, 0, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF);
	__m256i b = _mm256_set_epi64x(0x0000000100000010, 0x1000100010001000, 0x0000000100000010, 0x1000100010001000);

	int actual = _mm256_testnzc_si256(a, b);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm256_testnzc_si256_false_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0, 0, 0, 0);
	__m256i b = _mm256_set_epi64x(0x0000000100000010, 0x1000100010001000, 0x0000000100000010, 0x1000100010001000);

	int actual = _mm256_testnzc_si256(a, b);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm256_testnzc_si256_false_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF);
	__m256i b = _mm256_set_epi64x(0x0000000100000010, 0x1000100010001000, 0x0000000100000010, 0x1000100010001000);

	int actual = _mm256_testnzc_si256(a, b);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm256_testz_si256_true(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0x00FF00FF00FF00FF, 0x00FF00FF00FF00FF, 0x00FF00FF00FF00FF, 0x00FF00FF00FF00FF);
	__m256i b = _mm256_set_epi64x(0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00);

	int actual = _mm256_testz_si256(a, b);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm256_testz_si256_false_1(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0x10FF00FF00FF00FF, 0x00FF00FF00FF00FF, 0x00FF00FF00FF00FF, 0x00FF00FF00FF00FF);
	__m256i b = _mm256_set_epi64x(0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00);

	int actual = _mm256_testz_si256(a, b);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm256_testz_si256_false_2(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0x00FF00FF00FF00FF, 0x00FF00FF00FF00FF, 0x10FF00FF00FF00FF, 0x00FF00FF00FF00FF);
	__m256i b = _mm256_set_epi64x(0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00);

	int actual = _mm256_testz_si256(a, b);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm256_testz_si256_false_3(void **state)
{
	(void) state;

#ifdef XSSE_AVX
	__m256i a = _mm256_set_epi64x(0x10FF00FF00FF00FF, 0x00FF00FF00FF00FF, 0x10FF00FF00FF00FF, 0x00FF00FF00FF00FF);
	__m256i b = _mm256_set_epi64x(0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00, 0xFF00FF00FF00FF00);

	int actual = _mm256_testz_si256(a, b);
	assert_false(actual);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_testc_si256_true),
		cmocka_unit_test(test_mm256_testc_si256_false_1),
		cmocka_unit_test(test_mm256_testc_si256_false_2),
		cmocka_unit_test(test_mm256_testc_si256_false_3),
		cmocka_unit_test(test_mm256_testnzc_si256_true_1),
		cmocka_unit_test(test_mm256_testnzc_si256_true_2),
		cmocka_unit_test(test_mm256_testnzc_si256_true_3),
		cmocka_unit_test(test_mm256_testnzc_si256_true_4),
		cmocka_unit_test(test_mm256_testnzc_si256_false_1),
		cmocka_unit_test(test_mm256_testnzc_si256_false_2),
		cmocka_unit_test(test_mm256_testz_si256_true),
		cmocka_unit_test(test_mm256_testz_si256_false_1),
		cmocka_unit_test(test_mm256_testz_si256_false_2),
		cmocka_unit_test(test_mm256_testz_si256_false_3)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
