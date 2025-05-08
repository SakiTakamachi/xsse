#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_srli_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi16(0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF);

	__m128i result = _mm_srli_epi16(x, 4);

	int16_t expected[8] = { 0x0000, 0x0000, 0x0001, 0x000F, 0x00F0, 0x0FFF, 0x0800, 0x07FF };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_srli_epi32(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi32(0x00000001, 0x00000F00, 0xFFFF0000, 0x00080100);

	__m128i result = _mm_srli_epi32(x, 12);

	int32_t expected[4] = { 0x00000000, 0x00000000, 0x000FFFF0, 0x00000080 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_srli_epi64(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi64x(0x0000FF00FFFF0000, 0x0001000200080100);

	__m128i result = _mm_srli_epi64(x, 4);

	int64_t expected[2] = { 0x0000100020008010, 0x00000FF00FFFF000 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

static void test_mm_srl_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi16(0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF);
	__m128i count = _mm_set_epi64x(0, 4);

	__m128i result = _mm_srl_epi16(x, count);

	int16_t expected[8] = { 0x0000, 0x0000, 0x0001, 0x000F, 0x00F0, 0x0FFF, 0x0800, 0x07FF };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_srl_epi32(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi32(0x00000001, 0x00000F00, 0xFFFF0000, 0x00080100);
	__m128i count = _mm_set_epi64x(0, 12);

	__m128i result = _mm_srl_epi32(x, count);

	int32_t expected[4] = { 0x00000000, 0x00000000, 0x000FFFF0, 0x00000080 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_srl_epi64(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi64x(0x0000FF00FFFF0000, 0x0001000200080100);
	__m128i count = _mm_set_epi64x(0, 4);

	__m128i result = _mm_srl_epi64(x, count);

	int64_t expected[2] = { 0x0000100020008010, 0x00000FF00FFFF000 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

static void test_mm_srli_si128(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi16(0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF);

	__m128i result = _mm_srli_si128(x, 2);

	int16_t expected[8] = { 0x8000, 0xFFFF, 0x0F00, 0x00F0, 0x0010, 0x0002, 0x0001, 0x0000 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_bsrli_si128(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi16(0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF);

	__m128i result = _mm_bsrli_si128(x, 2);

	int16_t expected[8] = { 0x8000, 0xFFFF, 0x0F00, 0x00F0, 0x0010, 0x0002, 0x0001, 0x0000 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_srli_epi16),
		cmocka_unit_test(test_mm_srli_epi32),
		cmocka_unit_test(test_mm_srli_epi64),
		cmocka_unit_test(test_mm_srl_epi16),
		cmocka_unit_test(test_mm_srl_epi32),
		cmocka_unit_test(test_mm_srl_epi64),
		cmocka_unit_test(test_mm_srli_si128),
		cmocka_unit_test(test_mm_bsrli_si128)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
