#include "../xsse_test.h"

static void test_mm_cmpistrz_byte_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'c', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'n', 'z', 'z');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 0);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_UBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_byte_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'c', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'n', 'z', 'z');
	__m128i b = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'x');

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_byte_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'c', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'n', 'z', 'z');
	__m128i b = _mm_setr_epi8('a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_byte_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_byte_5(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 'z', 'z', 'z', 'e', 'z', 'z', 'z', 'z', 'z', 'e', 'z', 'z', 'z', 'z', 'z');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_byte_6(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('z', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_byte_7(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_SBYTE_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_word_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(0, 0, 0, 0, 0, 0, 0, WORDS('a', 'b'));

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_word_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(WORDS('a', 'b'), 0, 0, 0, 0, 0, 0, 0);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_ANY | _SIDD_SWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_word_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('e', 'f'), WORDS('z', 'z'),
		0, 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_word_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), 0
	);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	assert_true(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_word_5(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_word_6(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_word_7(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('e', 'f'), WORDS('z', 'z'),
		0, 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

static void test_mm_cmpistrz_word_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	int actual = _mm_cmpistrz(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_UWORD_OPS);
	assert_false(actual);
#else
	skip();
#endif
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpistrz_byte_1),
		cmocka_unit_test(test_mm_cmpistrz_byte_2),
		cmocka_unit_test(test_mm_cmpistrz_byte_3),
		cmocka_unit_test(test_mm_cmpistrz_byte_4),
		cmocka_unit_test(test_mm_cmpistrz_byte_5),
		cmocka_unit_test(test_mm_cmpistrz_byte_6),
		cmocka_unit_test(test_mm_cmpistrz_byte_7),
		cmocka_unit_test(test_mm_cmpistrz_word_1),
		cmocka_unit_test(test_mm_cmpistrz_word_2),
		cmocka_unit_test(test_mm_cmpistrz_word_3),
		cmocka_unit_test(test_mm_cmpistrz_word_4),
		cmocka_unit_test(test_mm_cmpistrz_word_5),
		cmocka_unit_test(test_mm_cmpistrz_word_6),
		cmocka_unit_test(test_mm_cmpistrz_word_7),
		cmocka_unit_test(test_mm_cmpistrz_word_8)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
