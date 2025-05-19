#include "../xsse_test.h"

static void test_mm_movemask_epi8(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi8(0, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF, 0, 0x0F, 0xF0, 0xFF, 0x00, 0x0F, 0xF0, 0xFF);

	int32_t expected = 0x00003333;
	int32_t actual = _mm_movemask_epi8(x);

	assert_int_equal(actual, expected);
}

static void test_mm_maskmoveu_si128(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	char dest[16] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	__m128i mask = _mm_setr_epi8(
		0x00, 0x01, 0x80, 0x00, 0xFF, 0xFF, 0x00, 0x80,
		0xFF, 0x00, 0x80, 0x00, 0xFF, 0xFF, 0x00, 0x80
	);

	char expected[16] = { 11, 12, 3, 14, 5, 6, 17, 8, 9, 20, 11, 22, 13, 14, 25, 16 };
	_mm_maskmoveu_si128(x, mask, dest);
	char *actual = dest;

	for (int i = 0; i < 16; i++) {
		assert_int_equal((int8_t) actual[i], (int8_t) expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_movemask_epi8),
		cmocka_unit_test(test_mm_maskmoveu_si128)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
