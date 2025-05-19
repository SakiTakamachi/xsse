#include "../../../xsse_test.h"

/*****************************************************************************
 * equal any                                                                 *
 *****************************************************************************/

static void test_mm_cmpistrc_uword_equal_any_true(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('c', 'd'), WORDS('z', 'z'), WORDS('z', 'z'),
		0, 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_equal_any_false(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('b', 'a'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * range                                                                     *
 *****************************************************************************/

static void test_mm_cmpistrc_uword_range_true_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('a', 'a'), WORDS('a', 'z'),
		0, 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_range_true_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('c', 'a'), WORDS('c', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_range_false(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), -2, 2,
		WORDS('z', 'z'), WORDS('c', 'a'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), 1, WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * equal each                                                                *
 *****************************************************************************/

static void test_mm_cmpistrc_uword_equal_each_true(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('e', 'f'), WORDS('z', 'z'),
		0, 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_equal_each_false_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_equal_each_false_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		0, 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * equal ordered                                                             *
 *****************************************************************************/

static void test_mm_cmpistrc_uword_equal_ordered_true_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('m', 'n'), WORDS('o', 'p'), WORDS('a', 'b'), WORDS('c', 'd'),
		WORDS('e', 'f'), WORDS('g', 'h'), WORDS('i', 'j'), WORDS('k', 'l')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_equal_ordered_true_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('o', 'p'), WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'),
		WORDS('g', 'h'), WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_equal_ordered_true_3(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('x', 'y'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('x', 'y')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_equal_ordered_false_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrc_uword_equal_ordered_false_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('e', 'f'), WORDS('c', 'd'), WORDS('g', 'h'),
		0, 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrc(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_any_true),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_any_false),
		cmocka_unit_test(test_mm_cmpistrc_uword_range_true_1),
		cmocka_unit_test(test_mm_cmpistrc_uword_range_true_2),
		cmocka_unit_test(test_mm_cmpistrc_uword_range_false),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_each_true),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_each_false_1),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_each_false_2),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_ordered_true_1),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_ordered_true_2),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_ordered_true_3),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_ordered_false_1),
		cmocka_unit_test(test_mm_cmpistrc_uword_equal_ordered_false_2)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
