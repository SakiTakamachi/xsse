#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_max_epu8(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(50, 100, 50, 100, 50, 100, 50, (int8_t) 200, 50, 100, 50, 100, 50, 100, 50, (int8_t) 200);
	__m128i b = _mm_setr_epi8(100, 50, 100, 50, 100, 50, (int8_t) 200, 50, 100, 50, 100, 50, 100, 50, 50, (int8_t) 200);

	__m128i result = _mm_max_epu8(a, b);

	uint8_t expected[16] = { 100, 100, 100, 100, 100, 100, (int8_t) 200, (int8_t) 200, 100, 100, 100, 100, 100, 100, 50, (int8_t) 200 };
	uint8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

static void test_mm_max_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(50, 100, 50, 120, 50, -100, 50, 0);
	__m128i b = _mm_setr_epi16(100, 50, -100, 50, 100, 50, 50, -1);

	__m128i result = _mm_max_epi16(a, b);

	int16_t expected[8] = { 100, 100, 50, 120, 100, 50, 50, 0 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_max_epi8(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi8(50, 100, 50, 120, 50, -100, 50, 0, 50, 100, 50, 120, 50, -100, 50, -2);
	__m128i b = _mm_setr_epi8(100, 50, -100, 50, 100, 50, 50, -1, 100, 50, -100, 50, 100, 50, 50, -1);

	__m128i result = _mm_max_epi8(a, b);

	int8_t expected[16] = { 100, 100, 50, 120, 100, 50, 50, 0, 100, 100, 50, 120, 100, 50, 50, -1 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_max_epi32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi32(50, -100, 50, 0);
	__m128i b = _mm_setr_epi32(100, 50, 50, -1);

	__m128i result = _mm_max_epi32(a, b);

	int32_t expected[4] = { 100, 50, 50, 0 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_max_epu16(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi16(50, 100, 50, 100, 50, 100, 50, (int8_t) 200);
	__m128i b = _mm_setr_epi16(100, 50, 100, 50, 100, 50, (int8_t) 200, (int8_t) 200);

	__m128i result = _mm_max_epu16(a, b);

	uint16_t expected[8] = { 100, 100, 100, 100, 100, 100, (int8_t) 200, (int8_t) 200 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_max_epu32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi32(50, 100, 50, (int8_t) 200);
	__m128i b = _mm_setr_epi32(100, 50, (int8_t) 200, (int8_t) 200);

	__m128i result = _mm_max_epu32(a, b);

	uint32_t expected[4] = { 100, 100, (int8_t) 200, (int8_t) 200 };
	uint32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_true(actual[i] == expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_max_epu8),
		cmocka_unit_test(test_mm_max_epi16),
		cmocka_unit_test(test_mm_max_epi8),
		cmocka_unit_test(test_mm_max_epi32),
		cmocka_unit_test(test_mm_max_epu16),
		cmocka_unit_test(test_mm_max_epu32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
