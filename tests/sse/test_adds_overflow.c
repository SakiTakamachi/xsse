#include "../xsse_test.h"

static void test_mm_adds_epi8_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi8(INT8_MAX);
	__m128i b = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	__m128i result = _mm_adds_epi8(a, b);

	int8_t expected[16] = {
		INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX,
		INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX, INT8_MAX
	};
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_adds_epi16_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi16(INT16_MAX);
	__m128i b = _mm_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7);

	__m128i result = _mm_adds_epi16(a, b);

	int16_t expected[8] = { INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_adds_epu8_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi8((int8_t) UINT8_MAX);
	__m128i b = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	__m128i result = _mm_adds_epu8(a, b);

	uint8_t expected[16] = {
		UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX,
		UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX
	};
	uint8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
}

static void test_mm_adds_epu16_overflow(void **state)
{
	(void) state;

	__m128i a = _mm_set1_epi16((int16_t) UINT16_MAX);
	__m128i b = _mm_setr_epi16(0, 1, 2, 3, 4, 5, 6, 7);

	__m128i result = _mm_adds_epu16(a, b);

	uint16_t expected[8] = { UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX };
	uint16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_adds_epi8_overflow),
		cmocka_unit_test(test_mm_adds_epi16_overflow),
		cmocka_unit_test(test_mm_adds_epu8_overflow),
		cmocka_unit_test(test_mm_adds_epu16_overflow),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
