#include "../../xsse_test.h"

static void test_mm_cmpestrz_byte_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestrz(a, 16, b, 15, _SIDD_CMP_EQUAL_ANY | _SIDD_UBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_byte_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestrz(a, 20, b, 0, _SIDD_CMP_EQUAL_ANY | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_byte_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'c', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'n', 'z', 'z');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestrz(a, 16, b, 1, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_byte_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestrz(a, 10, b, 5, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_byte_5(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'e', 'z', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestrz(a, 16, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_byte_6(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'e', 'z', 'z', 'z', 'z', 'j', 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestrz(a, 16, b, 20, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_byte_7(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'e', 'z', 'z', 'z', 'z', 'j', 'z', 'z', 'z', 'z', 'z', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestrz(a, 1, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_byte_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpestrz(a, 0, b, 20, _SIDD_CMP_EQUAL_ANY | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_word_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('x', 'y'), 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestrz(a, 8, b, 0, _SIDD_CMP_EQUAL_ANY | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_word_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpestrz(a, 12, b, 1, _SIDD_CMP_EQUAL_ANY | _SIDD_SWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_word_3(void **state)
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

	int actual = _mm_cmpestrz(a, 4, b, 4, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_word_4(void **state)
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

	int actual = _mm_cmpestrz(a, 8, b, 7, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_word_5(void **state)
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

	int actual = _mm_cmpestrz(a, 0, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_word_6(void **state)
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

	int actual = _mm_cmpestrz(a, 1, b, 12, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_word_7(void **state)
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

	int actual = _mm_cmpestrz(a, 4, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpestrz_word_8(void **state)
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

	int actual = _mm_cmpestrz(a, 7, b, 12, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpestrz_byte_1),
		cmocka_unit_test(test_mm_cmpestrz_byte_2),
		cmocka_unit_test(test_mm_cmpestrz_byte_3),
		cmocka_unit_test(test_mm_cmpestrz_byte_4),
		cmocka_unit_test(test_mm_cmpestrz_byte_5),
		cmocka_unit_test(test_mm_cmpestrz_byte_6),
		cmocka_unit_test(test_mm_cmpestrz_byte_7),
		cmocka_unit_test(test_mm_cmpestrz_byte_8),
		cmocka_unit_test(test_mm_cmpestrz_word_1),
		cmocka_unit_test(test_mm_cmpestrz_word_2),
		cmocka_unit_test(test_mm_cmpestrz_word_3),
		cmocka_unit_test(test_mm_cmpestrz_word_4),
		cmocka_unit_test(test_mm_cmpestrz_word_5),
		cmocka_unit_test(test_mm_cmpestrz_word_6),
		cmocka_unit_test(test_mm_cmpestrz_word_7),
		cmocka_unit_test(test_mm_cmpestrz_word_8)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
