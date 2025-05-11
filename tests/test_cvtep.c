#include "xsse_test.h"

static void test_mm_cvtepi8_epi16(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi8(10, 20, 30, 40, -50, 60, 70, 80, 11, 12, 13, 14, 15, 16, 17, 18);
	__m128i result = _mm_cvtepi8_epi16(x);

	int16_t expected[8] = { 10, 20, 30, 40, -50, 60, 70, 80 };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepi8_epi32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi8(10, -20, 30, 40, 50, 60, 70, 80, 11, 12, 13, 14, 15, 16, 17, 18);
	__m128i result = _mm_cvtepi8_epi32(x);

	int32_t expected[4] = { 10, -20, 30, 40 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepi8_epi64(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi8(10, -20, 30, 40, 50, 60, 70, 80, 11, 12, 13, 14, 15, 16, 17, 18);
	__m128i result = _mm_cvtepi8_epi64(x);

	int64_t expected[2] = { 10, -20 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepi16_epi32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi16(10, -20, 30, 40, 50, 60, 70, 80);
	__m128i result = _mm_cvtepi16_epi32(x);

	int32_t expected[4] = { 10, -20, 30, 40 };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepi16_epi64(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi16(10, -20, 30, 40, 50, 60, 70, 80);
	__m128i result = _mm_cvtepi16_epi64(x);

	int64_t expected[2] = { 10, -20 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepi32_epi64(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi32(10, -20, 30, 40);
	__m128i result = _mm_cvtepi32_epi64(x);

	int64_t expected[2] = { 10, -20 };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepu8_epi16(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi8(10, 20, 30, 40, 50, 60, 70, (int8_t) UINT8_MAX, 11, 12, 13, 14, 15, 16, 17, 18);
	__m128i result = _mm_cvtepu8_epi16(x);

	int16_t expected[8] = { 10, 20, 30, 40, 50, 60, 70, UINT8_MAX };
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepu8_epi32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi8(10, 20, 30, (int8_t) UINT8_MAX, 50, 60, 70, 80, 11, 12, 13, 14, 15, 16, 17, 18);
	__m128i result = _mm_cvtepu8_epi32(x);

	int32_t expected[4] = { 10, 20, 30, UINT8_MAX };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepu8_epi64(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi8(10, (int8_t) UINT8_MAX, 30, 40, 50, 60, 70, 80, 11, 12, 13, 14, 15, 16, 17, 18);
	__m128i result = _mm_cvtepu8_epi64(x);

	int64_t expected[2] = { 10, UINT8_MAX };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepu16_epi32(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi16(10, 20, 30, (int16_t) UINT16_MAX, 50, 60, 70, 80);
	__m128i result = _mm_cvtepu16_epi32(x);

	int32_t expected[4] = { 10, 20, 30, UINT16_MAX };
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepu16_epi64(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi16(10, (int16_t) UINT16_MAX, 30, 40, 50, 60, 70, 80);
	__m128i result = _mm_cvtepu16_epi64(x);

	int64_t expected[2] = { 10, UINT16_MAX };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_cvtepu32_epi64(void **state)
{
	(void) state;

#ifdef XSSE4_1
	__m128i x = _mm_setr_epi32(10, (int32_t) UINT32_MAX, 30, 40);
	__m128i result = _mm_cvtepu32_epi64(x);

	int64_t expected[2] = { 10, UINT32_MAX };
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_cvtepi8_epi16),
		cmocka_unit_test(test_mm_cvtepi8_epi32),
		cmocka_unit_test(test_mm_cvtepi8_epi64),
		cmocka_unit_test(test_mm_cvtepi16_epi32),
		cmocka_unit_test(test_mm_cvtepi16_epi64),
		cmocka_unit_test(test_mm_cvtepi32_epi64),
		cmocka_unit_test(test_mm_cvtepu8_epi16),
		cmocka_unit_test(test_mm_cvtepu8_epi32),
		cmocka_unit_test(test_mm_cvtepu8_epi64),
		cmocka_unit_test(test_mm_cvtepu16_epi32),
		cmocka_unit_test(test_mm_cvtepu16_epi64),
		cmocka_unit_test(test_mm_cvtepu32_epi64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
