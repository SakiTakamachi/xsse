#include "../../../xsse_test.h"

/*****************************************************************************
 * ranges                                                                    *
 *****************************************************************************/

static void test_mm_cmpistrm_sbyte_ranges_basic_1(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('x', 'z', 'c', 'a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_basic_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8(-2, 2, 'd', 'f', 'h', 'j', 'l', 'n', 'p', 's', 'u', 'v', 'w', 'x', 'y', 'z');
	__m128i b = _mm_set_epi8(1, 1, 2, 'd', 'e', 'f', 'g', 'h', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0x1D, 0xFD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sbyte_ranges_basic_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'd', 'f', 'h', 'j', 'l', 'n', 'p', 's', 'u', 'v', 'w', 'x', 'y', 'z');
	__m128i b = _mm_setr_epi8('h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0xFD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sbyte_ranges_la_0_lb_0(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_0_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_1_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_2_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_3_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_4_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_5_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_6_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_7_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_8_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_9_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_10_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_11_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_12_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_13_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 'm', 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_14_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 'm', 'o', 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_15_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 'm', 'o', 'o', 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_16_lb_16(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 'm', 'o', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p');

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_0_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_1_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
	int8_t expected[16] = { 0b00000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sbyte_ranges_la_2_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_3_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_4_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_5_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a,b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_6_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_7_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 0, 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_8_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_9_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_10_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_11_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_12_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 0, 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_13_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 'm', 0, 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_14_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 'm', 'o', 0, 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_15_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 'm', 'o', 'o', 0);
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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

static void test_mm_cmpistrm_sbyte_ranges_la_16_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi8('a', 'c', 'c', 'e', 'e', 'g', 'g', 'i', 'i', 'k', 'k', 'm', 'm', 'o', 'o', 'p');
	__m128i b = _mm_setr_epi8('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_RANGES | _SIDD_SBYTE_OPS);
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
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_basic_1),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_basic_2),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_basic_3),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_0_lb_0),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_0_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_1_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_2_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_3_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_4_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_5_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_6_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_7_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_8_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_9_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_10_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_11_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_12_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_13_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_14_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_15_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_16_lb_16),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_0_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_1_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_2_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_3_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_4_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_5_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_6_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_7_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_8_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_9_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_10_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_11_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_12_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_13_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_14_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_15_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sbyte_ranges_la_16_lb_8)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
