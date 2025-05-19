#include "../../../xsse_test.h"

/*****************************************************************************
 * equal each                                                                 *
 *****************************************************************************/

static void test_mm_cmpistrm_sword_equal_each_basic_1(void **state)
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

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
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

static void test_mm_cmpistrm_sword_equal_each_basic_2(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0xFF, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_basic_3(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0x0F, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_0_lb_0(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(0, 0, 0, 0, 0, 0, 0, 0);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0xFF, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_0_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
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

static void test_mm_cmpistrm_sword_equal_each_la_1_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
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

static void test_mm_cmpistrm_sword_equal_each_la_2_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), WORDS('c', 'd'), 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b00000011, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_3_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b00000111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_4_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'), 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b00001111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_5_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b00011111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_6_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b00111111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_7_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b01111111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_8_lb_8(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0xFF, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_0_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(0, 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b11110000, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_1_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), 0, 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b11110001, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_2_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), WORDS('c', 'd'), 0, 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b11110011, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_3_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), 0, 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b11110111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_4_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'), 0, 0, 0, 0);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b11111111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_5_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), 0, 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b11101111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_6_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), 0, 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b11001111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_7_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), 0
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0b10001111, 0, 0, 0, 0, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cmpistrm_sword_equal_each_la_8_lb_4(void **state)
{
#ifdef XSSE4_2
	(void)state;

	__m128i a = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		WORDS('i', 'j'), WORDS('k', 'l'), WORDS('m', 'n'), WORDS('o', 'p')
	);
	__m128i b = _mm_setr_epi16(
		WORDS('a', 'b'), WORDS('c', 'd'), WORDS('e', 'f'), WORDS('g', 'h'),
		0, 0, 0, 0
	);

	__m128i result = _mm_cmpistrm(a, b, _SIDD_CMP_EQUAL_EACH | _SIDD_SWORD_OPS);
	int16_t expected[8] = { 0x0F, 0, 0, 0, 0, 0, 0, 0 };
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
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_basic_1),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_basic_2),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_basic_3),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_0_lb_0),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_0_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_1_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_2_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_3_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_4_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_5_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_6_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_7_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_8_lb_8),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_0_lb_4),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_1_lb_4),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_2_lb_4),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_3_lb_4),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_4_lb_4),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_5_lb_4),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_6_lb_4),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_7_lb_4),
		cmocka_unit_test(test_mm_cmpistrm_sword_equal_each_la_8_lb_4)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
