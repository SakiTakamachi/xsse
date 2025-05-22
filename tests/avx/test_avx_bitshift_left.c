#include "../xsse_test.h"

static void test_mm256_slli_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF,
		0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0x00FF, 0x8000, 0x7FFF
	);

	__m256i result = _mm256_slli_epi16(x, 4);

	uint16_t expected[16] = {
		0x0010, 0x0020, 0x0100, 0x0F00, 0xF000, 0xFFF0, 0x0000, 0xFFF0,
		0x0010, 0x0020, 0x0100, 0x0F00, 0xF000, 0x0FF0, 0x0000, 0xFFF0
	};
	uint16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_slli_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi32(
		0x00000001, 0x00000F00, 0xFFFF0000, 0x00080100,
		0x00000001, 0x00000F00, 0xFFFFF000, 0x00080100
	);

	__m256i result = _mm256_slli_epi32(x, 12);

	uint32_t expected[8] = {
		0x00001000, 0x00F00000, 0xF0000000, 0x80100000,
		0x00001000, 0x00F00000, 0xFF000000, 0x80100000
	};
	uint32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_slli_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi64x(0x0001000200080100, 0x0000FF00FFFF0000, 0x0001000200080100, 0x0000FFFFFFFF0000);

	__m256i result = _mm256_slli_epi64(x, 4);

	uint64_t expected[4] = { 0x0010002000801000, 0x000FF00FFFF00000, 0x0010002000801000, 0x000FFFFFFFF00000 };
	uint64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_slli_si256(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i result = _mm256_slli_si256(x, 4);

	int8_t expected[32] = {
		0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11,
		0, 0, 0, 0, 0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11
	};
	int8_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_bslli_epi128(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi8(
		0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11, -12, -13, -14, -15,
		0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11, 12, 13, 14, 15
	);

	__m256i result = _mm256_bslli_epi128(x, 4);

	int8_t expected[32] = {
		0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, -8, -9, -10, -11,
		0, 0, 0, 0, 0, -1, -2, -3, -4, -5, -6, -7, 8, 9, 10, 11
	};
	int8_t actual[32];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 32; i++) {
		assert_int_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_sll_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF,
		0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0x00FF, 0x8000, 0x7FFF
	);
	__m128i count = _mm_set_epi64x(0, 4);

	__m256i result = _mm256_sll_epi16(x, count);

	uint16_t expected[16] = {
		0x0010, 0x0020, 0x0100, 0x0F00, 0xF000, 0xFFF0, 0x0000, 0xFFF0,
		0x0010, 0x0020, 0x0100, 0x0F00, 0xF000, 0x0FF0, 0x0000, 0xFFF0
	};
	uint16_t actual[16];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 16; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_sll_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi32(
		0x00000001, 0x00000F00, 0xFFFF0000, 0x00080100,
		0x00000001, 0x00000F00, 0xFFFFF000, 0x00080100
	);
	__m128i count = _mm_set_epi64x(0, 12);

	__m256i result = _mm256_sll_epi32(x, count);

	uint32_t expected[8] = {
		0x00001000, 0x00F00000, 0xF0000000, 0x80100000,
		0x00001000, 0x00F00000, 0xFF000000, 0x80100000
	};
	uint32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_sll_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi64x(0x0001000200080100, 0x0000FF00FFFF0000, 0x0001000200080100, 0x0000FFFFFFFF0000);
	__m128i count = _mm_set_epi64x(0, 4);

	__m256i result = _mm256_sll_epi64(x, count);

	uint64_t expected[4] = { 0x0010002000801000, 0x000FF00FFFF00000, 0x0010002000801000, 0x000FFFFFFFF00000 };
	uint64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_sllv_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi32(
		0x00000001, 0x00000F00, 0xFFFF0000, 0x00080100
	);
	__m128i count = _mm_setr_epi32(2, 4, 8, 12);

	__m128i result = _mm_sllv_epi32(x, count);

	uint32_t expected[4] = {
		0x00000004, 0x0000F000, 0xFF000000, 0x80100000
	};
	uint32_t actual[4];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm_sllv_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_set_epi64x(0x0000FF00FFFF0000, 0x0001000200080100);
	__m128i count = _mm_set_epi64x(8, 16);

	__m128i result = _mm_sllv_epi64(x, count);

	uint64_t expected[2] = { 0x0002000801000000, 0x00FF00FFFF000000 };
	uint64_t actual[2];
	_mm_storeu_si128((__m128i*) actual, result);

	for (int i = 0; i < 2; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_sllv_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi32(
		0x00000001, 0x00000F00, 0xFFFF0000, 0x00080100,
		0x00000001, 0x00000F00, 0xFFFFF000, 0x00080100
	);
	__m256i count = _mm256_setr_epi32(2, 4, 8, 12, 3, 8, 12, 8);

	__m256i result = _mm256_sllv_epi32(x, count);

	uint32_t expected[8] = {
		0x00000004, 0x0000F000, 0xFF000000, 0x80100000,
		0x00000008, 0x000F0000, 0xFF000000, 0x08010000
	};
	uint32_t actual[8];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 8; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

static void test_mm256_sllv_epi64(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi64x(0x0001000200080100, 0x0000FF00FFFF0000, 0x0001000200080100, 0x0000FFFFFFFF0000);
	__m256i count = _mm256_setr_epi64x(4, 8, 12, 16);

	__m256i result = _mm256_sllv_epi64(x, count);

	uint64_t expected[4] = { 0x0010002000801000, 0x00FF00FFFF000000, 0x1000200080100000, 0xFFFFFFFF00000000 };
	uint64_t actual[4];
	_mm256_storeu_si256((__m256i*) actual, result);

	for (int i = 0; i < 4; i++) {
		assert_uint_equal(actual[i], expected[i]);
	}
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_slli_epi16),
		cmocka_unit_test(test_mm256_slli_epi32),
		cmocka_unit_test(test_mm256_slli_epi64),
		cmocka_unit_test(test_mm256_slli_si256),
		cmocka_unit_test(test_mm256_bslli_epi128),
		cmocka_unit_test(test_mm256_sll_epi16),
		cmocka_unit_test(test_mm256_sll_epi32),
		cmocka_unit_test(test_mm256_sll_epi64),
		cmocka_unit_test(test_mm_sllv_epi32),
		cmocka_unit_test(test_mm_sllv_epi64),
		cmocka_unit_test(test_mm256_sllv_epi32),
		cmocka_unit_test(test_mm256_sllv_epi64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
