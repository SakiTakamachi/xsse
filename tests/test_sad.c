#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_sad_epu8(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	__m128i b = _mm_set1_epi8(10);

	__m128i result = _mm_sad_epu8(a, b);

	uint16_t expected[8] = { 44, 0, 0, 0, 22, 0, 0, 0 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

static void test_mm_mpsadbw_epu8_1(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	__m128i b = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	__m128i result = _mm_mpsadbw_epu8(a, b, 0b0000);

	uint16_t expected[8] = { 90, 86, 82, 78, 74, 70, 66, 62 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_mpsadbw_epu8_2(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	__m128i b = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	__m128i result = _mm_mpsadbw_epu8(a, b, 0b0100);

	uint16_t expected[8] = { 74, 70, 66, 62, 58, 54, 52, 50 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_mpsadbw_epu8_3(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	__m128i b = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	__m128i result = _mm_mpsadbw_epu8(a, b, 0b0001);

	uint16_t expected[8] = { 250, 246, 242, 238, 234, 230, 226, 222 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_mpsadbw_epu8_4(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	__m128i b = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	__m128i result = _mm_mpsadbw_epu8(a, b, 0b0010);

	uint16_t expected[8] = { 410, 406, 402, 398, 394, 390, 386, 382 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_mpsadbw_epu8_5(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i a = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	__m128i b = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160);

	__m128i result = _mm_mpsadbw_epu8(a, b, 0b0111);

	uint16_t expected[8] = { 554, 550, 546, 542, 538, 534, 530, 526 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_sad_epu8),
		cmocka_unit_test(test_mm_mpsadbw_epu8_1),
		cmocka_unit_test(test_mm_mpsadbw_epu8_2),
		cmocka_unit_test(test_mm_mpsadbw_epu8_3),
		cmocka_unit_test(test_mm_mpsadbw_epu8_4),
		cmocka_unit_test(test_mm_mpsadbw_epu8_5)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
