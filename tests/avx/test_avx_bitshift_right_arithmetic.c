#include "../xsse_test.h"

static void test_mm256_srai_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF,
		0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0x00FF, 0x8000, 0x7FFF
	);

	__m256i result = _mm256_srai_epi16(x, 4);

	uint16_t expected[16] = {
		0x0000, 0x0000, 0x0001, 0x000F, 0x00F0, 0xFFFF, 0xF800, 0x07FF,
		0x0000, 0x0000, 0x0001, 0x000F, 0x00F0, 0x000F, 0xF800, 0x07FF
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

static void test_mm256_srai_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi32(
		0x00000001, 0x00000F00, 0xFFFF0000, 0x00080100,
		0x00000001, 0x00000F00, 0xFFFFF000, 0x00080100
	);

	__m256i result = _mm256_srai_epi32(x, 12);

	uint32_t expected[8] = {
		0x00000000, 0x00000000, 0xFFFFFFF0, 0x00000080,
		0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000080
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

static void test_mm256_sra_epi16(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi16(
		0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0xFFFF, 0x8000, 0x7FFF,
		0x0001, 0x0002, 0x0010, 0x00F0, 0x0F00, 0x00FF, 0x8000, 0x7FFF
	);
	__m128i count = _mm_set_epi64x(0, 4);

	__m256i result = _mm256_sra_epi16(x, count);

	uint16_t expected[16] = {
		0x0000, 0x0000, 0x0001, 0x000F, 0x00F0, 0xFFFF, 0xF800, 0x07FF,
		0x0000, 0x0000, 0x0001, 0x000F, 0x00F0, 0x000F, 0xF800, 0x07FF
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

static void test_mm256_sra_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi32(
		0x00000001, 0x00000F00, 0xFFFF0000, 0x00080100,
		0x00000001, 0x00000F00, 0xFFFFF000, 0x00080100
	);
	__m128i count = _mm_set_epi64x(0, 12);

	__m256i result = _mm256_sra_epi32(x, count);

	uint32_t expected[8] = {
		0x00000000, 0x00000000, 0xFFFFFFF0, 0x00000080,
		0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000080
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

static void test_mm_srav_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m128i x = _mm_setr_epi32(
		0x00000008, 0x00000F00, 0xFFFF0000, 0x00080100
	);
	__m128i count = _mm_setr_epi32(2, 4, 8, 12);

	__m128i result = _mm_srav_epi32(x, count);

	uint32_t expected[4] = {
		0x00000002, 0x000000F0, 0xFFFFFF00, 0x00000080
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

static void test_mm256_srav_epi32(void **state)
{
	(void) state;

#ifdef XSSE_AVX2
	__m256i x = _mm256_setr_epi32(
		0x00000008, 0x00000F00, 0xFFFF0000, 0x00080100,
		0x00000008, 0x00000F00, 0xFFFFF000, 0x00080100
	);
	__m256i count = _mm256_setr_epi32(2, 4, 8, 12, 3, 8, 12, 8);

	__m256i result = _mm256_srav_epi32(x, count);

	uint32_t expected[8] = {
		0x00000002, 0x000000F0, 0xFFFFFF00, 0x00000080,
		0x00000001, 0x0000000F, 0xFFFFFFFF, 0x00000801
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

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm256_srai_epi16),
		cmocka_unit_test(test_mm256_srai_epi32),
		cmocka_unit_test(test_mm256_sra_epi16),
		cmocka_unit_test(test_mm256_sra_epi32),
		cmocka_unit_test(test_mm_srav_epi32),
		cmocka_unit_test(test_mm256_srav_epi32)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
