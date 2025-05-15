#include "../../xsse_test.h"

/*****************************************************************************
 * equal any                                                                 *
 *****************************************************************************/

static void test_mm_cmpestra_uword_equal_any_true(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('b', 'a'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestra(a, 8, b, 8, _SIDD_CMP_EQUAL_ANY | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_any_false_match(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('c', 'd'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestra(a, 4, b, 8, _SIDD_CMP_EQUAL_ANY | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_any_false_b_fewer_len(void **state)
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

	int actual = _mm_cmpestra(a, 8, b, 4, _SIDD_CMP_EQUAL_ANY | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * range                                                                     *
 *****************************************************************************/

static void test_mm_cmpestra_uword_range_true(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), -2, 2,
		WORDS('z', 'z'), WORDS('c', 'a'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), 0, WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestra(a, 8, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_range_false_match_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('a', 'a'), WORDS('a', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestra(a, 4, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_range_false_match_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), 0, 0,
		WORDS('c', 'a'), WORDS('c', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestra(a, 8, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_range_false_b_fewer_len(void **state)
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

	int actual = _mm_cmpestra(a, 2, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * equal each                                                                *
 *****************************************************************************/

static void test_mm_cmpestra_uword_equal_each_true_1(void **state)
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

	int actual = _mm_cmpestra(a, 8, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_each_true_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('m', 'n'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestra(a, 4, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_each_false_match(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('e', 'f'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestra(a, 4, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_each_false_b_fewer_len(void **state)
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

	int actual = _mm_cmpestra(a, 1, b, 4, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

/*****************************************************************************
 * equal ordered                                                             *
 *****************************************************************************/

static void test_mm_cmpestra_uword_equal_ordered_true_1(void **state)
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

	int actual = _mm_cmpestra(a, 8, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_ordered_true_2(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('e', 'f'), WORDS('c', 'd'), WORDS('g', 'h'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestra(a, 4, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_ordered_false_match_1(void **state)
{
	(void)state;

#ifdef XSSE4_2
	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('m', 'n'), WORDS('o', 'p'), WORDS('a', 'b'), WORDS('c', 'd'),
		WORDS('e', 'f'), WORDS('g', 'h'), WORDS('i', 'j'), WORDS('k', 'l')
	);

	int actual = _mm_cmpestra(a, 4, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_ordered_false_match_2(void **state)
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

	int actual = _mm_cmpestra(a, 8, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_ordered_false_match_3(void **state)
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

	int actual = _mm_cmpestra(a, 8, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestra_uword_equal_ordered_false_b_fewer_len(void **state)
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

	int actual = _mm_cmpestra(a, 1, b, 4, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpestra_uword_equal_any_true),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_any_false_match),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_any_false_b_fewer_len),
		cmocka_unit_test(test_mm_cmpestra_uword_range_true),
		cmocka_unit_test(test_mm_cmpestra_uword_range_false_match_1),
		cmocka_unit_test(test_mm_cmpestra_uword_range_false_match_2),
		cmocka_unit_test(test_mm_cmpestra_uword_range_false_b_fewer_len),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_each_true_1),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_each_true_2),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_each_false_match),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_each_false_b_fewer_len),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_ordered_true_1),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_ordered_true_2),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_ordered_false_match_1),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_ordered_false_match_2),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_ordered_false_match_3),
		cmocka_unit_test(test_mm_cmpestra_uword_equal_ordered_false_b_fewer_len)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
