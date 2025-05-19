#include "../xsse_test.h"

static void test_mm_crc32_u8(void **state)
{
	(void) state;

#ifdef XSSE4_2
	uint8_t data = 0xAB;
	uint32_t crc = 0xFFFFFFFF;

	uint32_t actual = _mm_crc32_u8(crc, data);
	uint32_t expected = 0x9640b233;

	assert_uint_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_crc32_u16(void **state)
{
	(void) state;

#ifdef XSSE4_2
	uint16_t data = 0xBEEF;
	uint32_t crc = 0xFFFFFFFF;

	uint32_t actual = _mm_crc32_u16(crc, data);
	uint32_t expected = 0x8cd590c1;

	assert_uint_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_crc32_u32(void **state)
{
	(void) state;

#ifdef XSSE4_2
	uint32_t data = 0xDEADBEEF;
	uint32_t crc = 0xFFFFFFFF;

	uint32_t actual = _mm_crc32_u32(crc, data);
	uint32_t expected = 0xbe01a92c;

	assert_uint_equal(actual, expected);
#else
	skip();
#endif
}

static void test_mm_crc32_u64(void **state)
{
	(void) state;

#ifdef XSSE4_2
	uint64_t data = 0x0123456789ABCDEF;
	uint64_t crc = 0xFFFFFFFF;

	uint64_t actual = _mm_crc32_u64(crc, data);
	uint64_t expected = 0x9a4f27dc;

	assert_uint_equal(actual, expected);
#else
	skip();
#endif
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_mm_crc32_u8),
		cmocka_unit_test(test_mm_crc32_u16),
		cmocka_unit_test(test_mm_crc32_u32),
		cmocka_unit_test(test_mm_crc32_u64)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
