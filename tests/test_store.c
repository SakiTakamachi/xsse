#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <inttypes.h>
#include <cmocka.h>

#if defined(_MSC_VER)
  #include <malloc.h>
#elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
  #include <mm_malloc.h>
#endif

#include "../src/xsse.h"

static void test_mm_store_si128_signed(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };

#ifdef _MSC_VER
	int8_t *actual = _aligned_malloc(16, 16);
#elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	int8_t *actual = _mm_malloc(16, 16);
#else
	int8_t actual[16];
#endif

	_mm_store_si128((__m128i*) actual, x);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}

#ifdef _MSC_VER
	_aligned_free(actual);
#elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	_mm_free(actual);
#endif
}

static void test_mm_store_si128_unsigned(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135);

	uint8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135 };

#ifdef _MSC_VER
	uint8_t *actual = _aligned_malloc(16, 16);
#elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	uint8_t *actual = _mm_malloc(16, 16);
#else
	uint8_t actual[16];
#endif

	_mm_storeu_si128((__m128i*) actual, x);

	for (int i = 0; i < 16; i++) {
		assert_true(actual[i] == expected[i]);
	}

#ifdef _MSC_VER
	_aligned_free(actual);
#elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	_mm_free(actual);
#endif
}

static void test_mm_storeu_si128_signed(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, x);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_storeu_si128_unsigned(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135);

	uint8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135 };
	uint8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, x);

	for (int i = 0; i < 16; i++) {
		assert_true(actual[i] == expected[i]);
	}
}

static void test_mm_stream_si128(void **state)
{
	(void) state;

	__m128i x = _mm_setr_epi8(0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };

#ifdef _MSC_VER
	int8_t *actual = _aligned_malloc(16, 16);
#elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	int8_t *actual = _mm_malloc(16, 16);
#else
	int8_t actual[16];
#endif

	_mm_stream_si128((__m128i*) actual, x);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}

#ifdef _MSC_VER
	_aligned_free(actual);
#elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	_mm_free(actual);
#endif
}

static void test_mm_stream_si32(void **state)
{
	(void) state;

	int x = 1234;
	int actual = 0;

	int expected = 1234;
	_mm_stream_si32(&actual, x);

	assert_int_equal(actual, expected);
}

static void test_mm_stream_si64(void **state)
{
	(void) state;

	int64_t x = 1234;
	int64_t actual = 0;

	int64_t expected = 1234;
	_mm_stream_si64((long long int*) &actual, x);

	assert_true(actual == expected);
}

static void test_mm_storel_epi64(void **state)
{
	(void) state;

	__m128i x = _mm_set_epi64x(10, 40);

	int64_t expected = 40;
	int64_t actual = 0;
	_mm_storel_epi64((__m128i*) &actual, x);

	assert_true(actual == expected);
}

static void test_mm_storeu_si16(void **state)
{
	(void) state;

#ifndef _MSC_VER
	__m128i x = _mm_set_epi16(1, 2, 3, 4, 5, 6, 7, 8);

	int16_t expected = 8;
	int16_t actual;
	_mm_storeu_si16((void*) &actual, x);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_storeu_si32(void **state)
{
	(void) state;

#ifndef _MSC_VER
	__m128i x = _mm_set_epi32(1, 2, 3, 4);

	int32_t expected = 4;
	int32_t actual;
	_mm_storeu_si32((void*) &actual, x);

	assert_int_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_storeu_si64(void **state)
{
	(void) state;

#ifndef _MSC_VER
	__m128i x = _mm_set_epi64x(1, 2);

	int64_t expected = 2;
	int64_t actual;
	_mm_storeu_si64((void*) &actual, x);

	assert_true(actual == expected);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_store_si128_signed),
		cmocka_unit_test(test_mm_store_si128_unsigned),
		cmocka_unit_test(test_mm_storeu_si128_signed),
		cmocka_unit_test(test_mm_storeu_si128_unsigned),
		cmocka_unit_test(test_mm_stream_si128),
		cmocka_unit_test(test_mm_stream_si32),
		cmocka_unit_test(test_mm_stream_si64),
		cmocka_unit_test(test_mm_storel_epi64),
		cmocka_unit_test(test_mm_storeu_si16),
		cmocka_unit_test(test_mm_storeu_si32),
		cmocka_unit_test(test_mm_storeu_si64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
