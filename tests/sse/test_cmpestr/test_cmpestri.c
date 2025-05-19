#include "../../xsse_test.h"

static void test_mm_cmpestri_byte_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestri(a, 16, b, 16, _SIDD_CMP_EQUAL_ANY | _SIDD_UBYTE_OPS | _SIDD_LEAST_SIGNIFICANT);
	int expected = 16;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_byte_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestri(a, 16, b, 16, _SIDD_CMP_EQUAL_ANY | _SIDD_SBYTE_OPS | _SIDD_LEAST_SIGNIFICANT);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_byte_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'c', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'n', 'z', 'z');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestri(a, 16, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS | _SIDD_LEAST_SIGNIFICANT);
	int expected = 2;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_byte_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestri(a, 16, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS | _SIDD_LEAST_SIGNIFICANT);
	int expected = 15;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_byte_5(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'e', 'z', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestri(a, 16, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS | _SIDD_MOST_SIGNIFICANT);
	int expected = 4;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_byte_6(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'e', 'z', 'z', 'z', 'z', 'j', 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestri(a, 16, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS | _SIDD_MOST_SIGNIFICANT);
	int expected = 9;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_byte_7(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'e', 'z', 'z', 'z', 'z', 'j', 'z', 'z', 'z', 'z', 'z', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestri(a, 16, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS | _SIDD_MOST_SIGNIFICANT);
	int expected = 15;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_byte_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestri(a, 16, b, 16, _SIDD_CMP_EQUAL_ANY | _SIDD_SBYTE_OPS | _SIDD_MOST_SIGNIFICANT);
	int expected = 16;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_word_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('x', 'y'), 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestri(a, 8, b, 8, _SIDD_CMP_EQUAL_ANY | _SIDD_UWORD_OPS | _SIDD_LEAST_SIGNIFICANT);
	int expected = 8;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_word_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestri(a, 8, b, 8, _SIDD_CMP_EQUAL_ANY | _SIDD_SWORD_OPS | _SIDD_LEAST_SIGNIFICANT);
	int expected = 0;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_word_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('e', 'f'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestri(a, 8, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS | _SIDD_LEAST_SIGNIFICANT);
	int expected = 2;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_word_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestri(a, 8, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS | _SIDD_LEAST_SIGNIFICANT);
	int expected = 7;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_word_5(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('i', 'j'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestri(a, 8, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS | _SIDD_MOST_SIGNIFICANT);
	int expected = 4;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_word_6(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('e', 'f'), WORDS('z', 'z'),
		WORDS('i', 'j'), WORDS('z', 'z'), WORDS('m', 'n'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestri(a, 8, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS | _SIDD_MOST_SIGNIFICANT);
	int expected = 6;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_word_7(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('e', 'f'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('m', 'n'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestri(a, 8, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS | _SIDD_MOST_SIGNIFICANT);
	int expected = 7;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_cmpestri_word_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestri(a, 8, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS | _SIDD_MOST_SIGNIFICANT);
	int expected = 8;
	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpestri_byte_1),
		cmocka_unit_test(test_mm_cmpestri_byte_2),
		cmocka_unit_test(test_mm_cmpestri_byte_3),
		cmocka_unit_test(test_mm_cmpestri_byte_4),
		cmocka_unit_test(test_mm_cmpestri_byte_5),
		cmocka_unit_test(test_mm_cmpestri_byte_6),
		cmocka_unit_test(test_mm_cmpestri_byte_7),
		cmocka_unit_test(test_mm_cmpestri_byte_8),
		cmocka_unit_test(test_mm_cmpestri_word_1),
		cmocka_unit_test(test_mm_cmpestri_word_2),
		cmocka_unit_test(test_mm_cmpestri_word_3),
		cmocka_unit_test(test_mm_cmpestri_word_4),
		cmocka_unit_test(test_mm_cmpestri_word_5),
		cmocka_unit_test(test_mm_cmpestri_word_6),
		cmocka_unit_test(test_mm_cmpestri_word_7),
		cmocka_unit_test(test_mm_cmpestri_word_8)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
