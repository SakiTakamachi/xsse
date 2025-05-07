#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_mulhi_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0x0001, 0x0002, 0x1234, 0x7FFF, -1, -2, 0x8000, 0x4000);
	__m128i b = _mm_setr_epi16(0x0001, 0x0010, 0x0002, 0x0002, -1, 1, 0x0002, 0x4000);

	__m128i result = _mm_mulhi_epi16(a, b);

	int16_t expected[8] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x1000 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_mulhi_epu16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0x0001, 0x0002, 0x1234, 0x7FFF, 0xFFFF, 0xFFFF, 0x8000, 0x4000);
	__m128i b = _mm_setr_epi16(0x0001, 0x0010, 0x0002, 0x0002, 0xFFFF, 2, 0x0002, 0x4000);

	__m128i result = _mm_mulhi_epu16(a, b);

	uint16_t expected[8] = { 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFE, 0x0001, 0x0001, 0x1000 };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

static void test_mm_mullo_epi16(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi16(0x0001, 0x0002, 0x1234, 0x7FFF, -1, -2, 0x8000, 0x4000);
	__m128i b = _mm_setr_epi16(0x0001, 0x0010, 0x0002, 0x0002, -1, 1, 0x0002, 0x4000);

	__m128i result = _mm_mullo_epi16(a, b);

	int16_t expected[8] = { 0x0001, 0x0020, 0x2468, 0xFFFE, 1, -2, 0x0000, 0x0000 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_mul_epu32(void **state)
{
	(void) state;

	__m128i a = _mm_setr_epi32(1000, 2000, 3000, 4000);
	__m128i b = _mm_setr_epi32(500, 1500, 2500, 3500);

	__m128i result = _mm_mul_epu32(a, b);

	uint64_t expected[2] = { 500000, 7500000 };
	uint64_t actual[2];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_mulhi_epi16),
        cmocka_unit_test(test_mm_mulhi_epu16),
        cmocka_unit_test(test_mm_mullo_epi16),
        cmocka_unit_test(test_mm_mul_epu32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
