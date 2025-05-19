#include "../../../xsse_test.h"

/*****************************************************************************
 * equal any                                                                 *
 *****************************************************************************/

static void test_mm_cmpistrc_sbyte_equal_any_true(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('x', 'd', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_equal_any_false(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * range                                                                     *
 *****************************************************************************/

static void test_mm_cmpistrc_sbyte_range_true_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('a', 'c', -2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8(1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_range_true_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('a', 'c', 'f', 'h', 'z', 'z', 'x', 'z', 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_range_false_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'f', 'h', 'x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('x', 'y', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_range_false_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('a', 'c', 'f', 'h', 'a', 'c', 'f', 'h', 'a', 'c', 'f', 'h', 'a', 'c', 'f', 'h');
	__m128i b = _mm_setr_epi8('w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * equal each                                                                *
 *****************************************************************************/

static void test_mm_cmpistrc_sbyte_equal_each_true(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('u', 'a', 'b', 'c', 'a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'w', 'x', 'y', 'z');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_equal_each_false_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('w', 'x', 'y', 'z', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_equal_each_false_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('b', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', 'w', 'x', 'y', 'z');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * equal ordered                                                             *
 *****************************************************************************/

static void test_mm_cmpistrc_sbyte_equal_ordered_true_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('z', 'a', 'b', 'c', 'd', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_equal_ordered_true_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z');
	__m128i b = _mm_setr_epi8('u', 'a', 'b', 'c', 'd', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_equal_ordered_true_3(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('t', 's', 's', 's', 's', 's', 's', 's', 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('u', 'a', 'b', 'c', 'd', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 't');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_equal_ordered_false_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'z', 'z', 'z', 'z', 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_sbyte_equal_ordered_false_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi8('a', 'c', 'b', 'd', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z', 'w', 'x', 'y', 'z');

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_any_true),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_any_false),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_range_true_1),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_range_true_2),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_range_false_1),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_range_false_2),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_each_true),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_each_false_1),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_each_false_2),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_ordered_true_1),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_ordered_true_2),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_ordered_true_3),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_ordered_false_1),
		cmocka_unit_test(test_mm_cmpistrc_sbyte_equal_ordered_false_2)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
