#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#include "../src/xsse.h"

static void test_mm_srai_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi16(0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF);

	__m128i result = _mm_srai_epi16(x, 4);

	int16_t expected[8] = { 0x0000, 0x0000, 0x0001, 0x000F, 0x00F0, 0xFFFF, 0xF800, 0x07FF };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_srai_epi32(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi32(0x00000001, 0x00000F00, 0xFFFF0000, 0x80080100);

	__m128i result = _mm_srai_epi32(x, 12);

	int32_t expected[4] = { 0x00000000, 0x00000000, 0xFFFFFFF0, 0xFFF80080 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_sra_epi16(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi16(0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF);
	__m128i count = _mm_set_epi64x(0, 4);

	__m128i result = _mm_sra_epi16(x, count);

	int16_t expected[8] = { 0x0000, 0x0000, 0x0001, 0x000F, 0x00F0, 0xFFFF, 0xF800, 0x07FF };
	int16_t actual[8];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_sra_epi32(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi32(0x00000001, 0x00000F00, 0xFFFF0000, 0x80080100);
	__m128i count = _mm_set_epi64x(0, 12);

	__m128i result = _mm_sra_epi32(x, count);

	int32_t expected[4] = { 0x00000000, 0x00000000, 0xFFFFFFF0, 0xFFF80080 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i *) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_srai_epi16),
        cmocka_unit_test(test_mm_srai_epi32),
        cmocka_unit_test(test_mm_sra_epi16),
        cmocka_unit_test(test_mm_sra_epi32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}