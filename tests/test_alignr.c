#include "xsse_test.h"

static void test_mm_alignr_epi8_imm0(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 0);

	int8_t expected[16] = { 31, -30, 29, -28, 27, -26, 25, -24, 23, -22, 21, -20, 19, -18, 17, -16 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm1(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 1);

	int8_t expected[16] = { -30, 29, -28, 27, -26, 25, -24, 23, -22, 21, -20, 19, -18, 17, -16, 15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm2(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 2);

	int8_t expected[16] = { 29, -28, 27, -26, 25, -24, 23, -22, 21, -20, 19, -18, 17, -16, 15, -14 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm3(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 3);

	int8_t expected[16] = { -28, 27, -26, 25, -24, 23, -22, 21, -20, 19, -18, 17, -16, 15, -14, 13 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm4(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 4);

	int8_t expected[16] = { 27, -26, 25, -24, 23, -22, 21, -20, 19, -18, 17, -16, 15, -14, 13, -12 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm5(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 5);

	int8_t expected[16] = { -26, 25, -24, 23, -22, 21, -20, 19, -18, 17, -16, 15, -14, 13, -12, 11 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm6(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 6);

	int8_t expected[16] = { 25, -24, 23, -22, 21, -20, 19, -18, 17, -16, 15, -14, 13, -12, 11, -10 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm7(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 7);

	int8_t expected[16] = { -24, 23, -22, 21, -20, 19, -18, 17, -16, 15, -14, 13, -12, 11, -10, 9 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm8(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 8);

	int8_t expected[16] = { 23, -22, 21, -20, 19, -18, 17, -16, 15, -14, 13, -12, 11, -10, 9, -8 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm9(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 9);

	int8_t expected[16] = { -22, 21, -20, 19, -18, 17, -16, 15, -14, 13, -12, 11, -10, 9, -8, 7 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm10(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 10);

	int8_t expected[16] = { 21, -20, 19, -18, 17, -16, 15, -14, 13, -12, 11, -10, 9, -8, 7, -6 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm11(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 11);

	int8_t expected[16] = { -20, 19, -18, 17, -16, 15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm12(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 12);

	int8_t expected[16] = { 19, -18, 17, -16, 15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5, -4 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm13(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 13);

	int8_t expected[16] = { -18, 17, -16, 15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5, -4, 3 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm14(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 14);

	int8_t expected[16] = { 17, -16, 15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5, -4, 3, -2 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm15(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 15);

	int8_t expected[16] = { -16, 15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5, -4, 3, -2, 1 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm16(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 16);

	int8_t expected[16] = { 15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm17(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 17);

	int8_t expected[16] = { -14, 13, -12, 11, -10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm18(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 18);

	int8_t expected[16] = { 13, -12, 11, -10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm19(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 19);

	int8_t expected[16] = { -12, 11, -10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm20(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 20);

	int8_t expected[16] = { 11, -10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm21(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 21);

	int8_t expected[16] = { -10, 9, -8, 7, -6, 5, -4, 3, -2, 1, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm22(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 22);

	int8_t expected[16] = { 9, -8, 7, -6, 5, -4, 3, -2, 1, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm23(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 23);

	int8_t expected[16] = { -8, 7, -6, 5, -4, 3, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm24(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 24);

	int8_t expected[16] = { 7, -6, 5, -4, 3, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm25(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 25);

	int8_t expected[16] = { -6, 5, -4, 3, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm26(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 26);

	int8_t expected[16] = { 5, -4, 3, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm27(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 27);

	int8_t expected[16] = { -4, 3, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm28(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 28);

	int8_t expected[16] = { 3, -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm29(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 29);

	int8_t expected[16] = { -2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm30(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 30);

	int8_t expected[16] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_alignr_epi8_imm31(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 31);

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

static void test_mm_alignr_epi8_imm32(void **state)
{
	(void) state;

#ifdef XSSSE3
	__m128i a = _mm_set_epi8(0, 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15);
	__m128i b = _mm_set_epi8(-16, 17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 31);

	__m128i result = _mm_alignr_epi8(a, b, 32);

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

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_alignr_epi8_imm0),
		cmocka_unit_test(test_mm_alignr_epi8_imm1),
		cmocka_unit_test(test_mm_alignr_epi8_imm2),
		cmocka_unit_test(test_mm_alignr_epi8_imm3),
		cmocka_unit_test(test_mm_alignr_epi8_imm4),
		cmocka_unit_test(test_mm_alignr_epi8_imm5),
		cmocka_unit_test(test_mm_alignr_epi8_imm6),
		cmocka_unit_test(test_mm_alignr_epi8_imm7),
		cmocka_unit_test(test_mm_alignr_epi8_imm8),
		cmocka_unit_test(test_mm_alignr_epi8_imm9),
		cmocka_unit_test(test_mm_alignr_epi8_imm10),
		cmocka_unit_test(test_mm_alignr_epi8_imm11),
		cmocka_unit_test(test_mm_alignr_epi8_imm12),
		cmocka_unit_test(test_mm_alignr_epi8_imm13),
		cmocka_unit_test(test_mm_alignr_epi8_imm14),
		cmocka_unit_test(test_mm_alignr_epi8_imm15),
		cmocka_unit_test(test_mm_alignr_epi8_imm16),
		cmocka_unit_test(test_mm_alignr_epi8_imm17),
		cmocka_unit_test(test_mm_alignr_epi8_imm18),
		cmocka_unit_test(test_mm_alignr_epi8_imm19),
		cmocka_unit_test(test_mm_alignr_epi8_imm20),
		cmocka_unit_test(test_mm_alignr_epi8_imm21),
		cmocka_unit_test(test_mm_alignr_epi8_imm22),
		cmocka_unit_test(test_mm_alignr_epi8_imm23),
		cmocka_unit_test(test_mm_alignr_epi8_imm24),
		cmocka_unit_test(test_mm_alignr_epi8_imm25),
		cmocka_unit_test(test_mm_alignr_epi8_imm26),
		cmocka_unit_test(test_mm_alignr_epi8_imm27),
		cmocka_unit_test(test_mm_alignr_epi8_imm28),
		cmocka_unit_test(test_mm_alignr_epi8_imm29),
		cmocka_unit_test(test_mm_alignr_epi8_imm30),
		cmocka_unit_test(test_mm_alignr_epi8_imm31),
		cmocka_unit_test(test_mm_alignr_epi8_imm32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
