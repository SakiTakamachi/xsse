#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_cmpeq_epi8(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100);
	__m128i b = _mm_setr_epi8(100, 101, 99, 0, -100, -101, -99, 0, 100, 101, 99, 0, -100, -101, -99, 0);

	__m128i result = _mm_cmpeq_epi8(a, b);

	int8_t expected[16] = { 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFF, 0, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmpeq_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(100, 100, 100, 100, -100, -100, -100, -100);
	__m128i b = _mm_setr_epi16(100, 101, 99, 0, -100, -101, -99, 0);

	__m128i result = _mm_cmpeq_epi16(a, b);

	int16_t expected[8] = { 0xFFFF, 0, 0, 0, 0xFFFF, 0, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmpeq_epi32_1(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(100, 100, 100, 100);
	__m128i b = _mm_setr_epi32(100, 101, 99, 0);

	__m128i result = _mm_cmpeq_epi32(a, b);

	int32_t expected[4] = { 0xFFFFFFFF, 0, 0, 0 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmpeq_epi32_2(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(-100, -100, -100, -100);
	__m128i b = _mm_setr_epi32(-100, -101, -99, 0);

	__m128i result = _mm_cmpeq_epi32(a, b);

	int32_t expected[4] = { 0xFFFFFFFF, 0, 0, 0 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmplt_epi8(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100);
	__m128i b = _mm_setr_epi8(100, 101, 99, 0, -100, -101, -99, 0, 100, 101, 99, 0, -100, -101, -99, 0);

	__m128i result = _mm_cmplt_epi8(a, b);

	int8_t expected[16] = { 0, 0xFF, 0, 0, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0xFF, 0xFF };
	int8_t actual[16];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmplt_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(100, 100, 100, 100, -100, -100, -100, -100);
	__m128i b = _mm_setr_epi16(100, 101, 99, 0, -100, -101, -99, 0);

	__m128i result = _mm_cmplt_epi16(a, b);

	int16_t expected[8] = { 0, 0xFFFF, 0, 0, 0, 0, 0xFFFF, 0xFFFF };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmplt_epi32_1(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(100, 100, 100, 100);
	__m128i b = _mm_setr_epi32(100, 101, 99, 0);

	__m128i result = _mm_cmplt_epi32(a, b);

	int32_t expected[4] = { 0, 0xFFFFFFFF, 0, 0 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmplt_epi32_2(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(-100, -100, -100, -100);
	__m128i b = _mm_setr_epi32(-100, -101, -99, 0);

	__m128i result = _mm_cmplt_epi32(a, b);

	int32_t expected[4] = { 0, 0, 0xFFFFFFFF, 0xFFFFFFFF };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmpgt_epi8(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100);
	__m128i b = _mm_setr_epi8(100, 101, 99, 0, -100, -101, -99, 0, 100, 101, 99, 0, -100, -101, -99, 0);

	__m128i result = _mm_cmpgt_epi8(a, b);

	int8_t expected[16] = { 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0, 0, 0, 0xFF, 0, 0 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmpgt_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(100, 100, 100, 100, -100, -100, -100, -100);
	__m128i b = _mm_setr_epi16(100, 101, 99, 0, -100, -101, -99, 0);

	__m128i result = _mm_cmpgt_epi16(a, b);

	int16_t expected[8] = { 0, 0, 0xFFFF, 0xFFFF, 0, 0xFFFF, 0, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmpgt_epi32_1(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(100, 100, 100, 100);
	__m128i b = _mm_setr_epi32(100, 101, 99, 0);

	__m128i result = _mm_cmpgt_epi32(a, b);

	int32_t expected[4] = { 0, 0, 0xFFFFFFFF, 0xFFFFFFFF };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

static void test_mm_cmpgt_epi32_2(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(-100, -100, -100, -100);
	__m128i b = _mm_setr_epi32(-100, -101, -99, 0);

	__m128i result = _mm_cmpgt_epi32(a, b);

	int32_t expected[4] = { 0, 0xFFFFFFFF, 0, 0 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
    }
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cmpeq_epi8),
        cmocka_unit_test(test_mm_cmpeq_epi16),
        cmocka_unit_test(test_mm_cmpeq_epi32_1),
        cmocka_unit_test(test_mm_cmpeq_epi32_2),
        cmocka_unit_test(test_mm_cmplt_epi8),
        cmocka_unit_test(test_mm_cmplt_epi16),
        cmocka_unit_test(test_mm_cmplt_epi32_1),
        cmocka_unit_test(test_mm_cmplt_epi32_2),
        cmocka_unit_test(test_mm_cmpgt_epi8),
        cmocka_unit_test(test_mm_cmpgt_epi16),
        cmocka_unit_test(test_mm_cmpgt_epi32_1),
        cmocka_unit_test(test_mm_cmpgt_epi32_2)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
