#include "../../xsse_test.h"

/*****************************************************************************
 * ranges                                                                    *
 *****************************************************************************/

static void test_mm_cmpestrm_uword_ranges_basic_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('c', 'a'),
		WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z'), WORDS('z', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpestrm(a, 8, b, 15, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_basic_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 15, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b11110101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_basic_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 12, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_0_lb_0(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 0, b, 0, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_0_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 0, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_1_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 1, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_2_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 2, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000001, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_3_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 3, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000001, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_4_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 4, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_5_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 5, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_6_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 6, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00010101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_7_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 7, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00010101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_8_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 8, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b11110101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_9_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 9, b, 8, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b11110101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_0_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 0, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_1_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 1, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_2_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 2, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000001, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_3_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 3, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000001, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_4_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 4, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_5_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 5, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_6_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 6, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_7_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 7, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_8_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 8, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_uword_ranges_la_9_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'a'), WORDS('a', 'z'), WORDS('c', 'a'), WORDS('c', 'z'),
		WORDS('e', 'a'), WORDS('e', 'z'), WORDS('f', 'a'), WORDS('h', 'z')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'x'), WORDS('b', 'x'), WORDS('c', 'x'), WORDS('d', 'x'),
		WORDS('e', 'e'), WORDS('f', 'f'), WORDS('g', 'g'), WORDS('h', 'h')
	);

	__m128i result = _mm_cmpestrm(a, 9, b, 4, _SIDD_CMP_RANGES | _SIDD_UWORD_OPS);
	int16_t expected[8] = { 0b00000101, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_basic_1),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_basic_2),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_basic_3),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_0_lb_0),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_0_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_1_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_2_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_3_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_4_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_5_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_6_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_7_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_8_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_9_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_0_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_1_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_2_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_3_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_4_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_5_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_6_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_7_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_8_lb_4),
		cmocka_unit_test(test_mm_cmpestrm_uword_ranges_la_9_lb_4)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
