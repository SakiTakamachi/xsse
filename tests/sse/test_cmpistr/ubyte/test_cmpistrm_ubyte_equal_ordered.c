#include "../../../xsse_test.h"

/*****************************************************************************
 * equal ordered                                                                 *
 *****************************************************************************/

static void test_mm_cmpistrm_ubyte_equal_ordered_basic_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_basic_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('x', 'x', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_basic_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_basic_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e', 'a');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_0_lb_0(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_0_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_1_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_2_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_3_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_4_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_5_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_6_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_7_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_8_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_9_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_10_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_11_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_12_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_13_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_14_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_15_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_16_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_0_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_1_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_2_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_3_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_4_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_5_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_6_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_7_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_8_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_9_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_10_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_11_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_12_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_13_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_14_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_15_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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

static void test_mm_cmpistrm_ubyte_equal_ordered_la_16_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_ORDERED | _SIDD_UBYTE_OPS);
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
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_basic_1),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_basic_2),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_basic_3),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_basic_4),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_0_lb_0),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_0_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_1_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_2_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_3_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_4_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_5_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_6_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_7_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_8_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_9_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_10_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_11_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_12_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_13_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_14_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_15_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_16_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_0_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_1_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_2_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_3_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_4_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_5_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_6_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_7_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_8_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_9_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_10_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_11_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_12_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_13_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_14_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_15_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_ubyte_equal_ordered_la_16_lb_8)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
