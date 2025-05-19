#include "../xsse_test.h"

static void test_mm_load_si128_signed(void **state)
{
	(void) state;

#if defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	int8_t *data = _mm_malloc(16, 16);
#elif defined(_MSC_VER)
	int8_t *data = _aligned_malloc(16, 16);
#else
	int8_t data[16];
#endif

	memcpy(data, (int8_t[]){ 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 }, 16);
	__m128i result = _mm_load_si128((const __m128i*) data);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}

#if defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	_mm_free(data);
#elif defined(_MSC_VER)
	_aligned_free(data);
#endif
}

static void test_mm_load_si128_unsigned(void **state)
{
	(void) state;

#if defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	uint8_t *data = _mm_malloc(16, 16);
#elif defined(_MSC_VER)
	uint8_t *data = _aligned_malloc(16, 16);
#else
	uint8_t data[16];
#endif

	memcpy(data, (uint8_t[]){ 0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135 }, 16);
	__m128i result = _mm_load_si128((const __m128i*) data);

	uint8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135 };
	uint8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}

#if defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	_mm_free(data);
#elif defined(_MSC_VER)
	_aligned_free(data);
#endif
}

static void test_mm_loadu_si128_signed(void **state)
{
	(void) state;

	int8_t data[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	__m128i result = _mm_loadu_si128((const __m128i*) data);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
}

static void test_mm_loadu_si128_unsigned(void **state)
{
	(void) state;

	uint8_t data[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135 };
	__m128i result = _mm_loadu_si128((const __m128i*) data);

	uint8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135 };
	uint8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
}

static void test_mm_loadl_epi64(void **state)
{
	(void) state;

#if defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	int8_t *data = _mm_malloc(16, 16);
#elif defined(_MSC_VER)
	int8_t *data = _aligned_malloc(16, 16);
#else
	int8_t data[16];
#endif

	memcpy(data, (int8_t[]){ 0, 1, 2, 3, -4, -5, -6, -7, 8, 9, 10, 11, -12, -13, -14, -15 }, 16);
	__m128i result = _mm_loadl_epi64((const __m128i*) data);

	int8_t expected[8] = { 0, 1, 2, 3, -4, -5, -6, -7 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_int_equal(actual[i], expected[i]);
	}

#if defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64)
	_mm_free(data);
#elif defined(_MSC_VER)
	_aligned_free(data);
#endif
}

static void test_mm_lddqu_si128(void **state)
{
	(void) state;

#ifdef XSSE3
	uint8_t data[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135 };
	__m128i result = _mm_lddqu_si128((const __m128i*) data);

	uint8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 128, 129, 130, 131, 132, 133, 134, 135 };
	uint8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_loadu_si16(void **state)
{
	(void) state;

#ifndef _MSC_VER
	int16_t data[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	__m128i result = _mm_loadu_si16((void const*) data);

	int16_t expected = 1;
	int16_t actual[8];
	_mm_storeu_si128((__m128i*) actual, result);

	assert_int_equal(actual[0], expected);
#else
	skip();
#endif
}

static void test_mm_loadu_si32(void **state)
{
	(void) state;

#ifndef _MSC_VER
	int32_t data[8] = { 1, 2, 3, 4 };
	__m128i result = _mm_loadu_si32((void const*) data);

	int32_t expected = 1;
	int32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	assert_int_equal(actual[0], expected);
#else
	skip();
#endif
}

static void test_mm_loadu_si64(void **state)
{
	(void) state;

#ifndef _MSC_VER
	int64_t data[2] = { 1, 2 };
	__m128i result = _mm_loadu_si64((void const*) data);

	int64_t expected = 1;
	int64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	assert_int_equal(actual[0], expected);
#else
	skip();
#endif
}

static void test_mm_stream_load_si128(void **state)
{
	(void) state;

#ifdef XSSE4_1

#if defined(__SSE4_1__) || defined(__x86_64__) || defined(_M_X64)
	int8_t *data = _mm_malloc(16, 16);
#elif defined(_MSC_VER)
	int8_t *data = _aligned_malloc(16, 16);
#else
	int8_t data[16];
#endif

	memcpy(data, (int8_t[]){ 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 }, 16);
	__m128i result = _mm_stream_load_si128((__m128i*) data);

	int8_t expected[16] = { 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15 };
	int8_t actual[16];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_int_equal(actual[i], expected[i]);
	}

#if defined(__SSE4_1__) || defined(__x86_64__) || defined(_M_X64)
	_mm_free(data);
#elif defined(_MSC_VER)
	_aligned_free(data);
#endif

#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_load_si128_signed),
		cmocka_unit_test(test_mm_load_si128_unsigned),
		cmocka_unit_test(test_mm_loadu_si128_signed),
		cmocka_unit_test(test_mm_loadu_si128_unsigned),
		cmocka_unit_test(test_mm_loadl_epi64),
		cmocka_unit_test(test_mm_lddqu_si128),
		cmocka_unit_test(test_mm_loadu_si16),
		cmocka_unit_test(test_mm_loadu_si32),
		cmocka_unit_test(test_mm_loadu_si64),
		cmocka_unit_test(test_mm_stream_load_si128)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
