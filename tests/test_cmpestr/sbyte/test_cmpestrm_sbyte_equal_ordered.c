#include "../../xsse_test.h"

/*****************************************************************************
 * equal ordered                                                                 *
 *****************************************************************************/

static void test_mm_cmpestrm_sbyte_equal_ordered_basic_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_basic_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('x', 'x', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n');

	__m128i result = _mm_cmpestrm(a, 16, b, 20, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x04, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_basic_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_basic_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e', 'a');

	__m128i result = _mm_cmpestrm(a, 3, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00100001, 0b10000100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_0_lb_0(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 0, b, 0, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_0_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 0, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_1_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'x', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 1, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_2_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'x', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 2, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_3_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'x', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 3, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_4_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'x', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 4, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_5_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'x', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 5, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_6_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'x', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 6, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_7_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'x', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 7, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_8_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 8, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_9_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'x', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 9, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_10_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'x', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 10, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_11_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'x', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 11, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_12_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'x', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 12, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_13_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'x', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 13, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_14_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'x', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 14, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_15_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'x');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 15, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_16_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_17_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 17, b, 16, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_0_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 0, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_1_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'x', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 1, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_2_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'x', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 2, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_3_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'x', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 3, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_4_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'x', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 4, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_5_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'x', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 5, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_6_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'x', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 6, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_7_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'x', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 7, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_8_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 8, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_9_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 9, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_10_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 10, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_11_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 11, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_12_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 12, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_13_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 13, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_14_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 14, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_15_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 15, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_16_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_ordered_la_17_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'x', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 17, b, 8, _SIDD_CMP_EQUAL_ORDERED | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_basic_1),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_basic_2),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_basic_3),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_basic_4),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_0_lb_0),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_0_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_1_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_2_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_3_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_4_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_5_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_6_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_7_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_8_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_9_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_10_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_11_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_12_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_13_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_14_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_15_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_16_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_17_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_0_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_1_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_2_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_3_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_4_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_5_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_6_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_7_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_8_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_9_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_10_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_11_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_12_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_13_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_14_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_15_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_16_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_ordered_la_17_lb_8)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
