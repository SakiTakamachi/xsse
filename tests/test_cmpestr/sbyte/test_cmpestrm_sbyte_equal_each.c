#include "../../xsse_test.h"

/*****************************************************************************
 * equal each                                                                 *
 *****************************************************************************/

static void test_mm_cmpestrm_sbyte_equal_each_basic_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpestrm_sbyte_equal_each_basic_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 20, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpestrm_sbyte_equal_each_basic_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_0_lb_0(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 0, b, 0, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpestrm_sbyte_equal_each_la_0_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 0, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpestrm_sbyte_equal_each_la_1_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 1, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00000001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_2_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 2, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00000011, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_3_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 3, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00000111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_4_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 4, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00001111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_5_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 5, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00011111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_6_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 6, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00111111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_7_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 7, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b01111111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_8_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 8, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_9_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 9, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b00000001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_10_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 10, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b00000011, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_11_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 11, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b00000111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_12_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 12, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b00001111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_13_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 13, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b00011111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_14_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 14, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b00111111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_15_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 15, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b01111111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_16_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpestrm_sbyte_equal_each_la_17_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 17, b, 16, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpestrm_sbyte_equal_each_la_0_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 0, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_1_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 1, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00000001, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_2_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 2, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00000011, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_3_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 3, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00000111, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_4_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 4, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00001111, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_5_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 5, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00011111, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_6_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 6, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00111111, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_7_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 7, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b01111111, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_8_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 8, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpestrm_sbyte_equal_each_la_9_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 9, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b11111110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_10_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 10, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b11111100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_11_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 11, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b11111000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_12_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 12, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b11110000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_13_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 13, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b11100000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_14_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 14, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b11000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_15_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 15, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0b10000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_16_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 16, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpestrm_sbyte_equal_each_la_17_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpestrm(a, 17, b, 8, _SIDD_CMP_EQUAL_EACH | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_basic_1),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_basic_2),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_basic_3),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_0_lb_0),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_0_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_1_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_2_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_3_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_4_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_5_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_6_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_7_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_8_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_9_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_10_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_11_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_12_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_13_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_14_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_15_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_16_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_17_lb_16),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_0_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_1_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_2_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_3_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_4_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_5_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_6_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_7_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_8_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_9_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_10_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_11_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_12_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_13_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_14_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_15_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_16_lb_8),
		cmocka_unit_test(test_mm_cmpestrm_sbyte_equal_each_la_17_lb_8)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
