/********************************************************************************
 * MIT License
 * Copyright (c) 2025 Saki Takamachi <saki@sakiot.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *********************************************************************************
 * This is a wrapper library that allows you to use AVX and AVX2 APIs directly
 * with NEON.
 * Please note that APIs for floating-point operations and some cryptographic
 * functions are not supported.
 *
 * In an AVX environment, if `__AVX__` is defined, the `XSSE_AVX` macro will be
 * defined as well.
 * Similarly, if `__AVX2__` is defined, `XSSE_AVX2` will also be defined.
 * 
 * In a NEON environment, the macros `XSSE_AVX` and `XSSE_AVX2` are defined.
 * 
 * Since this header file includes `xsse.h`, including this file will also
 * include all SSE functionalities.
 *********************************************************************************/


#ifndef XSSE_AVX_H
#define XSSE_AVX_H

#include "xsse.h"

#if defined(__aarch64__) || defined(_M_ARM64)
typedef struct __m256i {
	__m128i v0;
	__m128i v1;
} __m256i;
#endif


/*****************************************************************************
 *                                                                           *
 * AVX                                                                       *
 *                                                                           *
 *****************************************************************************/

#if defined(__AVX__)
#include <immintrin.h>
#define XSSE_AVX


#elif defined(__aarch64__) || defined(_M_ARM64)
#define XSSE_AVX

/*****************************************************************************
 * Load / Store                                                              *
 *****************************************************************************/

static XSSE_FORCE_INLINE __m256i _mm256_set_epi8(
	char e31, char e30, char e29, char e28, char e27, char e26, char e25, char e24,
	char e23, char e22, char e21, char e20, char e19, char e18, char e17, char e16,
	char e15, char e14, char e13, char e12, char e11, char e10, char e9, char e8,
	char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0)
{
	__m256i x;
	x.v0 = _mm_set_epi8(e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0);
	x.v1 = _mm_set_epi8(e31, e30, e29, e28, e27, e26, e25, e24, e23, e22, e21, e20, e19, e18, e17, e16);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_set_epi16(
	short e15, short e14, short e13, short e12, short e11, short e10, short e9, short e8,
	short e7, short e6, short e5, short e4, short e3, short e2, short e1, short e0)
{
	__m256i x;
	x.v0 = _mm_set_epi16(e7, e6, e5, e4, e3, e2, e1, e0);
	x.v1 = _mm_set_epi16(e15, e14, e13, e12, e11, e10, e9, e8);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_set_epi32(int e7, int e6, int e5, int e4, int e3, int e2, int e1, int e0)
{
	__m256i x;
	x.v0 = _mm_set_epi32(e3, e2, e1, e0);
	x.v1 = _mm_set_epi32(e7, e6, e5, e4);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_set_epi64x(int64_t e3, int64_t e2, int64_t e1, int64_t e0)
{
	__m256i x;
	x.v0 = _mm_set_epi64x(e1, e0);
	x.v1 = _mm_set_epi64x(e3, e2);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_set1_epi8(char a)
{
	__m256i x;
	__m128i va = _mm_set1_epi8(a);
	x.v0 = va;
	x.v1 = va;
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_set1_epi16(short a)
{
	__m256i x;
	__m128i va = _mm_set1_epi16(a);
	x.v0 = va;
	x.v1 = va;
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_set1_epi32(int a)
{
	__m256i x;
	__m128i va = _mm_set1_epi32(a);
	x.v0 = va;
	x.v1 = va;
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_set1_epi64x(int64_t a)
{
	__m256i x;
	__m128i va = _mm_set1_epi64x(a);
	x.v0 = va;
	x.v1 = va;
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_setr_epi8(
	char e31, char e30, char e29, char e28, char e27, char e26, char e25, char e24,
	char e23, char e22, char e21, char e20, char e19, char e18, char e17, char e16,
	char e15, char e14, char e13, char e12, char e11, char e10, char e9, char e8,
	char e7, char e6, char e5, char e4, char e3, char e2, char e1, char e0)
{
	__m256i x;
	x.v0 = _mm_set_epi8(e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
	x.v1 = _mm_set_epi8(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_setr_epi16(
	short e15, short e14, short e13, short e12, short e11, short e10, short e9, short e8,
	short e7, short e6, short e5, short e4, short e3, short e2, short e1, short e0)
{
	__m256i x;
	x.v0 = _mm_set_epi16(e8, e9, e10, e11, e12, e13, e14, e15);
	x.v1 = _mm_set_epi16(e0, e1, e2, e3, e4, e5, e6, e7);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_setr_epi32(int e7, int e6, int e5, int e4, int e3, int e2, int e1, int e0)
{
	__m256i x;
	x.v0 = _mm_set_epi32(e4, e5, e6, e7);
	x.v1 = _mm_set_epi32(e0, e1, e2, e3);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_setr_epi64x(int64_t e3, int64_t e2, int64_t e1, int64_t e0)
{
	__m256i x;
	x.v0 = _mm_set_epi64x(e2, e3);
	x.v1 = _mm_set_epi64x(e0, e1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_set_m128i(__m128i hi, __m128i lo)
{
	__m256i x;
	x.v0 = lo;
	x.v1 = hi;
	return x;
}
#define _mm256_setr_m128i(lo, hi) _mm256_set_m128i(hi, lo)

static XSSE_FORCE_INLINE __m256i _mm256_setzero_si256(void)
{
	__m256i x;
	x.v0 = _mm_setzero_si128();
	x.v1 = _mm_setzero_si128();
	return x;
}
#define _mm256_undefined_si256() _mm256_setzero_si256()

static XSSE_FORCE_INLINE __m256i _mm256_load_si256(__m256i const *mem_addr)
{
	__m256i x;
	x.v0 = _mm_load_si128((__m128i*) mem_addr);
	x.v1 = _mm_load_si128(((__m128i*) mem_addr) + 1);
	return x;
}
#define _mm256_loadu_si256(x) _mm256_load_si256(x)
#define _mm256_lddqu_si256(x) _mm256_load_si256(x)
static XSSE_FORCE_INLINE __m256i _mm256_loadu2_m128i(__m128i const *hiaddr, __m128i const *loaddr)
{
	__m256i x;
	x.v0 = _mm_load_si128((__m128i*) loaddr);
	x.v1 = _mm_load_si128((__m128i*) hiaddr);
	return x;
}

static XSSE_FORCE_INLINE void _mm256_store_si256(__m256i *mem_addr, __m256i x)
{
	_mm_store_si128((__m128i*) mem_addr, x.v0);
	_mm_store_si128(((__m128i*) mem_addr) + 1, x.v1);
}
#define _mm256_storeu_si256(to, x) _mm256_store_si256((to), (x))
#define _mm256_stream_si256(to, x) _mm256_store_si256((to), (x))
static XSSE_FORCE_INLINE void _mm256_storeu2_m128i(__m128i *hiaddr, __m128i *loaddr, __m256i x)
{
	_mm_store_si128(loaddr, x.v0);
	_mm_store_si128(hiaddr, x.v1);
}


/*****************************************************************************
 * Convert                                                                   *
 *****************************************************************************/

static XSSE_FORCE_INLINE __m256i _mm256_castsi128_si256(__m128i a)
{
	__m256i x;
	x.v0 = a;
	return x;
}
#define _mm256_castsi256_si128(x) ((x).v0)
#define _mm256_cvtsi256_si32(x) _mm_cvtsi128_si32((x).v0)


/*****************************************************************************
 * Tests                                                                     *
 *****************************************************************************/

static XSSE_FORCE_INLINE int _mm256_testc_si256(__m256i a, __m256i b)
{
	int8x16_t andnot_1 = vbicq_s8(b.v0, a.v0);
	int8x16_t andnot_2 = vbicq_s8(b.v1, a.v1);
	int8x16_t andnot = vorrq_s8(andnot_1, andnot_2);
	uint64x2_t andnot64 = vreinterpretq_u64_s8(andnot);
	return (vgetq_lane_u64(andnot64, 0) == 0) && (vgetq_lane_u64(andnot64, 1) == 0);
}
static XSSE_FORCE_INLINE int _mm256_testnzc_si256(__m256i mask, __m256i x)
{
	int8x16_t and_1 = vandq_s8(x.v0, mask.v0);
	int8x16_t and_2 = vandq_s8(x.v1, mask.v1);
	int8x16_t and = vorrq_s8(and_1, and_2);
	uint64x2_t and64 = vreinterpretq_u64_s8(and);
	int has_ones = (vgetq_lane_u64(and64, 0) | vgetq_lane_u64(and64, 1)) != 0;

	int8x16_t andnot_1 = vbicq_s8(x.v0, mask.v0);
	int8x16_t andnot_2 = vbicq_s8(x.v1, mask.v1);
	int8x16_t andnot = vorrq_s8(andnot_1, andnot_2);
	uint64x2_t andnot64 = vreinterpretq_u64_s8(andnot);
	int has_zeros = (vgetq_lane_u64(andnot64, 0) | vgetq_lane_u64(andnot64, 1)) != 0;

	return has_ones && has_zeros;
}
static XSSE_FORCE_INLINE int _mm256_testz_si256(__m256i mask, __m256i x)
{
	int8x16_t masked_1 = vandq_s8(x.v0, mask.v0);
	int8x16_t masked_2 = vandq_s8(x.v1, mask.v1);
	int8x16_t masked = vorrq_s8(masked_1, masked_2);
	uint64x2_t masked64 = vreinterpretq_u64_s8(masked);
	return (vgetq_lane_u64(masked64, 0) == 0) && (vgetq_lane_u64(masked64, 1) == 0);
}


/*****************************************************************************
 * Others                                                                    *
 *****************************************************************************/

static XSSE_FORCE_INLINE int32_t _mm256_extract_epi32(__m256i x, const int index)
{
	switch (index) {
		case 0: return _mm_extract_epi32(x.v0, 0);
		case 1: return _mm_extract_epi32(x.v0, 1);
		case 2: return _mm_extract_epi32(x.v0, 2);
		case 3: return _mm_extract_epi32(x.v0, 3);
		case 4: return _mm_extract_epi32(x.v1, 0);
		case 5: return _mm_extract_epi32(x.v1, 1);
		case 6: return _mm_extract_epi32(x.v1, 2);
		case 7: return _mm_extract_epi32(x.v1, 3);
		default: XSSE_UNREACHABLE();
	}
}
static XSSE_FORCE_INLINE int64_t _mm256_extract_epi64(__m256i x, const int index)
{
	switch (index) {
		case 0: return _mm_extract_epi64(x.v0, 0);
		case 1: return _mm_extract_epi64(x.v0, 1);
		case 2: return _mm_extract_epi64(x.v1, 0);
		case 3: return _mm_extract_epi64(x.v1, 1);
		default: XSSE_UNREACHABLE();
	}
}
static XSSE_FORCE_INLINE __m128i _mm256_extractf128_si256(__m256i x, const int imm8)
{
	if (imm8 == 0) {
		return x.v0;
	} else {
		return x.v1;
	}
}

static XSSE_FORCE_INLINE __m256i _mm256_insert_epi8(__m256i x, int8_t val, const int index)
{
	switch (index) {
		case 0: x.v0 = _mm_insert_epi8(x.v0, val, 0); break;
		case 1: x.v0 = _mm_insert_epi8(x.v0, val, 1); break;
		case 2: x.v0 = _mm_insert_epi8(x.v0, val, 2); break;
		case 3: x.v0 = _mm_insert_epi8(x.v0, val, 3); break;
		case 4: x.v0 = _mm_insert_epi8(x.v0, val, 4); break;
		case 5: x.v0 = _mm_insert_epi8(x.v0, val, 5); break;
		case 6: x.v0 = _mm_insert_epi8(x.v0, val, 6); break;
		case 7: x.v0 = _mm_insert_epi8(x.v0, val, 7); break;
		case 8: x.v0 = _mm_insert_epi8(x.v0, val, 8); break;
		case 9: x.v0 = _mm_insert_epi8(x.v0, val, 9); break;
		case 10: x.v0 = _mm_insert_epi8(x.v0, val, 10); break;
		case 11: x.v0 = _mm_insert_epi8(x.v0, val, 11); break;
		case 12: x.v0 = _mm_insert_epi8(x.v0, val, 12); break;
		case 13: x.v0 = _mm_insert_epi8(x.v0, val, 13); break;
		case 14: x.v0 = _mm_insert_epi8(x.v0, val, 14); break;
		case 15: x.v0 = _mm_insert_epi8(x.v0, val, 15); break;
		case 16: x.v1 = _mm_insert_epi8(x.v1, val, 0); break;
		case 17: x.v1 = _mm_insert_epi8(x.v1, val, 1); break;
		case 18: x.v1 = _mm_insert_epi8(x.v1, val, 2); break;
		case 19: x.v1 = _mm_insert_epi8(x.v1, val, 3); break;
		case 20: x.v1 = _mm_insert_epi8(x.v1, val, 4); break;
		case 21: x.v1 = _mm_insert_epi8(x.v1, val, 5); break;
		case 22: x.v1 = _mm_insert_epi8(x.v1, val, 6); break;
		case 23: x.v1 = _mm_insert_epi8(x.v1, val, 7); break;
		case 24: x.v1 = _mm_insert_epi8(x.v1, val, 8); break;
		case 25: x.v1 = _mm_insert_epi8(x.v1, val, 9); break;
		case 26: x.v1 = _mm_insert_epi8(x.v1, val, 10); break;
		case 27: x.v1 = _mm_insert_epi8(x.v1, val, 11); break;
		case 28: x.v1 = _mm_insert_epi8(x.v1, val, 12); break;
		case 29: x.v1 = _mm_insert_epi8(x.v1, val, 13); break;
		case 30: x.v1 = _mm_insert_epi8(x.v1, val, 14); break;
		case 31: x.v1 = _mm_insert_epi8(x.v1, val, 15); break;
		default: XSSE_UNREACHABLE();
	}
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_insert_epi16(__m256i x, int16_t val, const int index)
{
	switch (index) {
		case 0: x.v0 = _mm_insert_epi16(x.v0, val, 0); break;
		case 1: x.v0 = _mm_insert_epi16(x.v0, val, 1); break;
		case 2: x.v0 = _mm_insert_epi16(x.v0, val, 2); break;
		case 3: x.v0 = _mm_insert_epi16(x.v0, val, 3); break;
		case 4: x.v0 = _mm_insert_epi16(x.v0, val, 4); break;
		case 5: x.v0 = _mm_insert_epi16(x.v0, val, 5); break;
		case 6: x.v0 = _mm_insert_epi16(x.v0, val, 6); break;
		case 7: x.v0 = _mm_insert_epi16(x.v0, val, 7); break;
		case 8: x.v1 = _mm_insert_epi16(x.v1, val, 0); break;
		case 9: x.v1 = _mm_insert_epi16(x.v1, val, 1); break;
		case 10: x.v1 = _mm_insert_epi16(x.v1, val, 2); break;
		case 11: x.v1 = _mm_insert_epi16(x.v1, val, 3); break;
		case 12: x.v1 = _mm_insert_epi16(x.v1, val, 4); break;
		case 13: x.v1 = _mm_insert_epi16(x.v1, val, 5); break;
		case 14: x.v1 = _mm_insert_epi16(x.v1, val, 6); break;
		case 15: x.v1 = _mm_insert_epi16(x.v1, val, 7); break;
		default: XSSE_UNREACHABLE();
	}
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_insert_epi32(__m256i x, int32_t val, const int index)
{
	switch (index) {
		case 0: x.v0 = _mm_insert_epi32(x.v0, val, 0); break;
		case 1: x.v0 = _mm_insert_epi32(x.v0, val, 1); break;
		case 2: x.v0 = _mm_insert_epi32(x.v0, val, 2); break;
		case 3: x.v0 = _mm_insert_epi32(x.v0, val, 3); break;
		case 4: x.v1 = _mm_insert_epi32(x.v1, val, 0); break;
		case 5: x.v1 = _mm_insert_epi32(x.v1, val, 1); break;
		case 6: x.v1 = _mm_insert_epi32(x.v1, val, 2); break;
		case 7: x.v1 = _mm_insert_epi32(x.v1, val, 3); break;
		default: XSSE_UNREACHABLE();
	}
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_insert_epi64(__m256i x, int64_t val, const int index)
{
	switch (index) {
		case 0: x.v0 = _mm_insert_epi64(x.v0, val, 0); break;
		case 1: x.v0 = _mm_insert_epi64(x.v0, val, 1); break;
		case 2: x.v1 = _mm_insert_epi64(x.v1, val, 0); break;
		case 3: x.v1 = _mm_insert_epi64(x.v1, val, 1); break;
		default: XSSE_UNREACHABLE();
	}
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_insertf128_si256(__m256i a, __m128i b, int imm8)
{
	if (imm8 == 0) {
		a.v0 = b;
	} else {
		a.v1 = b;
	}
	return a;
}

static XSSE_FORCE_INLINE __m256i _mm256_permute2f128_si256(__m256i a, __m256i b, int imm8)
{
	__m256i x;
	if (imm8 & (1 << 3)) {
		x.v0 = _mm_setzero_si128();
	} else {
		switch (imm8 & 0x03) {
			case 0: x.v0 = a.v0; break;
			case 1: x.v0 = a.v1; break;
			case 2: x.v0 = b.v0; break;
			case 3: x.v0 = b.v1; break;
		}
	}
	if ((imm8 >> 4) & (1 << 3)) {
		x.v1 = _mm_setzero_si128();
	} else {
		switch ((imm8 >> 4) & 0x03) {
			case 0: x.v1 = a.v0; break;
			case 1: x.v1 = a.v1; break;
			case 2: x.v1 = b.v0; break;
			case 3: x.v1 = b.v1; break;
		}
	}
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_zextsi128_si256(__m128i a)
{
	__m256i x;
	x.v0 = a;
	x.v1 = _mm_setzero_si128();
	return x;
}

#define _mm256_zeroupper() ((void)0)
#define _mm256_zeroall() ((void)0)

#endif /* AVX */


/*****************************************************************************
 *                                                                           *
 * AVX2                                                                      *
 *                                                                           *
 *****************************************************************************/

#if defined(__AVX2__)
#include <immintrin.h>
#define XSSE_AVX2


#elif defined(__aarch64__) || defined(_M_ARM64)
#define XSSE_AVX2

/*****************************************************************************
 * Load / Store                                                              *
 *****************************************************************************/

#define _mm256_stream_load_si256(x) _mm256_load_si256(x)

static XSSE_FORCE_INLINE __m128i _mm_maskload_epi32(int const *mem_addr, __m128i mask)
{
	uint32x4_t x = vreinterpretq_u32_s32(vld1q_s32((const int32_t*) mem_addr));
	uint32x4_t mask_fill = vcltq_s32(vreinterpretq_s32_s8(mask), vdupq_n_s32(0x00));
	return vreinterpretq_s8_u32(vandq_u32(x, mask_fill));
}
static XSSE_FORCE_INLINE __m128i _mm_maskload_epi64(int64_t const *mem_addr, __m128i mask)
{
	uint64x2_t x = vreinterpretq_u64_s64(vld1q_s64((const int64_t*) mem_addr));
	uint64x2_t mask_fill = vcltq_s64(vreinterpretq_s64_s8(mask), vdupq_n_s64(0x00));
	return vreinterpretq_s8_u64(vandq_u64(x, mask_fill));
}
static XSSE_FORCE_INLINE __m256i _mm256_maskload_epi32(int const *mem_addr, __m256i mask)
{
	__m256i x;
	x.v0 = _mm_maskload_epi32(mem_addr, mask.v0);
	x.v1 = _mm_maskload_epi32(mem_addr + 4, mask.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_maskload_epi64(int64_t const *mem_addr, __m256i mask)
{
	__m256i x;
	x.v0 = _mm_maskload_epi64(mem_addr, mask.v0);
	x.v1 = _mm_maskload_epi64(mem_addr + 2, mask.v1);
	return x;
}

static XSSE_FORCE_INLINE __m128i _mm_i32gather_epi32(int const *base_addr, __m128i vindex, const int scale)
{
	int32x4_t vindex32 = vreinterpretq_s32_s8(vindex);
	switch (scale) {
		case 1:
			{
				char *data = (char*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 0)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 1)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 2)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 3))
				});
			}
		case 2:
			{
				short *data = (short*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 0)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 1)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 2)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 3))
				});
			}
		case 4:
			{
				int *data = (int*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 0)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 1)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 2)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 3))
				});
			}
		case 8:
			{
				int64_t *data = (int64_t*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 0)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 1)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 2)),
					*(int32_t *) (data + vgetq_lane_s32(vindex32, 3))
				});
			}
		default: XSSE_UNREACHABLE();
	}
}
static XSSE_FORCE_INLINE __m128i _mm_i32gather_epi64(int64_t const *base_addr, __m128i vindex, const int scale)
{
	int32x4_t vindex32 = vreinterpretq_s32_s8(vindex);
	switch (scale) {
		case 1:
			{
				char *data = (char*) base_addr;
				return vreinterpretq_s8_s64((int64x2_t) {
					*(int64_t *) (data + vgetq_lane_s32(vindex32, 0)),
					*(int64_t *) (data + vgetq_lane_s32(vindex32, 1))
				});
			}
		case 2:
			{
				short *data = (short*) base_addr;
				return vreinterpretq_s8_s64((int64x2_t) {
					*(int64_t *) (data + vgetq_lane_s32(vindex32, 0)),
					*(int64_t *) (data + vgetq_lane_s32(vindex32, 1))
				});
			}
		case 4:
			{
				int *data = (int*) base_addr;
				return vreinterpretq_s8_s64((int64x2_t) {
					*(int64_t *) (data + vgetq_lane_s32(vindex32, 0)),
					*(int64_t *) (data + vgetq_lane_s32(vindex32, 1))
				});
			}
		case 8:
			{
				int64_t *data = (int64_t*) base_addr;
				return vreinterpretq_s8_s64((int64x2_t) {
					*(int64_t *) (data + vgetq_lane_s32(vindex32, 0)),
					*(int64_t *) (data + vgetq_lane_s32(vindex32, 1))
				});
			}
		default: XSSE_UNREACHABLE();
	}
}
static XSSE_FORCE_INLINE __m128i _mm_i64gather_epi32(int const *base_addr, __m128i vindex, const int scale)
{
	int64x2_t vindex64 = vreinterpretq_s64_s8(vindex);
	switch (scale) {
		case 1:
			{
				char *data = (char*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s64(vindex64, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64, 1)),
					0,
					0
				});
			}
		case 2:
			{
				short *data = (short*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s64(vindex64, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64, 1)),
					0,
					0
				});
			}
		case 4:
			{
				int *data = (int*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s64(vindex64, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64, 1)),
					0,
					0
				});
			}
		case 8:
			{
				int64_t *data = (int64_t*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s64(vindex64, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64, 1)),
					0,
					0
				});
			}
		default: XSSE_UNREACHABLE();
	}
}
static XSSE_FORCE_INLINE __m128i _mm_i64gather_epi64(int64_t const *base_addr, __m128i vindex, const int scale)
{
	int64x2_t vindex64 = vreinterpretq_s64_s8(vindex);
	switch (scale) {
		case 1:
			{
				char *data = (char*) base_addr;
				return vreinterpretq_s8_s64((int64x2_t) {
					*(int64_t *) (data + vgetq_lane_s64(vindex64, 0)),
					*(int64_t *) (data + vgetq_lane_s64(vindex64, 1))
				});
			}
		case 2:
			{
				short *data = (short*) base_addr;
				return vreinterpretq_s8_s64((int64x2_t) {
					*(int64_t *) (data + vgetq_lane_s64(vindex64, 0)),
					*(int64_t *) (data + vgetq_lane_s64(vindex64, 1))
				});
			}
		case 4:
			{
				int *data = (int*) base_addr;
				return vreinterpretq_s8_s64((int64x2_t) {
					*(int64_t *) (data + vgetq_lane_s64(vindex64, 0)),
					*(int64_t *) (data + vgetq_lane_s64(vindex64, 1))
				});
			}
		case 8:
			{
				int64_t *data = (int64_t*) base_addr;
				return vreinterpretq_s8_s64((int64x2_t) {
					*(int64_t *) (data + vgetq_lane_s64(vindex64, 0)),
					*(int64_t *) (data + vgetq_lane_s64(vindex64, 1))
				});
			}
		default: XSSE_UNREACHABLE();
	}
}

static XSSE_FORCE_INLINE __m128i _mm_mask_i32gather_epi32(__m128i src, int const *base_addr, __m128i vindex, __m128i mask, const int scale)
{
	int32x4_t gathered = vreinterpretq_s32_s8(_mm_i32gather_epi32(base_addr, vindex, scale));
	uint32x4_t mask_fill = vcltq_s32(vreinterpretq_s32_s8(mask), vdupq_n_s32(0x00));
	return vreinterpretq_s8_s32(vbslq_s32(mask_fill, gathered, vreinterpretq_s32_s8(src)));
}
static XSSE_FORCE_INLINE __m128i _mm_mask_i32gather_epi64(__m128i src, int64_t const *base_addr, __m128i vindex, __m128i mask, const int scale)
{
	int64x2_t gathered = vreinterpretq_s64_s8(_mm_i32gather_epi64(base_addr, vindex, scale));
	uint64x2_t mask_fill = vcltq_s64(vreinterpretq_s64_s8(mask), vdupq_n_s64(0x00));
	return vreinterpretq_s8_s64(vbslq_s64(mask_fill, gathered, vreinterpretq_s64_s8(src)));
}
static XSSE_FORCE_INLINE __m128i _mm_mask_i64gather_epi32(__m128i src, int const *base_addr, __m128i vindex, __m128i mask, const int scale)
{
	int32x4_t gathered = vreinterpretq_s32_s8(_mm_i64gather_epi32(base_addr, vindex, scale));
	uint32x2_t mask_fill = vclt_s32(vget_low_s32(vreinterpretq_s32_s8(mask)), vdup_n_s32(0x00));
	return vreinterpretq_s8_s32(vbslq_s32(
		vcombine_u32(mask_fill, vdup_n_u32(0xFF)),
		gathered,
		vreinterpretq_s32_s8(src)
	));
}
static XSSE_FORCE_INLINE __m128i _mm_mask_i64gather_epi64(__m128i src, int64_t const *base_addr, __m128i vindex, __m128i mask, const int scale)
{
	int64x2_t gathered = vreinterpretq_s64_s8(_mm_i64gather_epi64(base_addr, vindex, scale));
	uint64x2_t mask_fill = vcltq_s64(vreinterpretq_s64_s8(mask), vdupq_n_s64(0x00));
	return vreinterpretq_s8_s64(vbslq_s64(mask_fill, gathered, vreinterpretq_s64_s8(src)));
}

static XSSE_FORCE_INLINE __m256i _mm256_i32gather_epi32(int const *base_addr, __m256i vindex, const int scale)
{
	__m256i x;
	x.v0 = _mm_i32gather_epi32(base_addr, vindex.v0, scale);
	x.v1 = _mm_i32gather_epi32(base_addr, vindex.v1, scale);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_i32gather_epi64(int64_t const *base_addr, __m128i vindex, const int scale)
{
	__m256i x;
	int64x2_t vindex64 = vreinterpretq_s64_s8(vindex);
	int64x2_t vindex_reverse = (int64x2_t) { vgetq_lane_s64(vindex64, 1), vgetq_lane_s64(vindex64, 0) };
	x.v0 = _mm_i32gather_epi64(base_addr, vindex, scale);
	x.v1 = _mm_i32gather_epi64(base_addr, vreinterpretq_s8_s64(vindex_reverse), scale);
	return x;
}
static XSSE_FORCE_INLINE __m128i _mm256_i64gather_epi32(int const *base_addr, __m256i vindex, const int scale)
{
	int64x2_t vindex64_1 = vreinterpretq_s64_s8(vindex.v0);
	int64x2_t vindex64_2 = vreinterpretq_s64_s8(vindex.v1);
	switch (scale) {
		case 1:
			{
				char *data = (char*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s64(vindex64_1, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_1, 1)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_2, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_2, 1))
				});
			}
		case 2:
			{
				short *data = (short*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s64(vindex64_1, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_1, 1)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_2, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_2, 1))
				});
			}
		case 4:
			{
				int *data = (int*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s64(vindex64_1, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_1, 1)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_2, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_2, 1))
				});
			}
		case 8:
			{
				int64_t *data = (int64_t*) base_addr;
				return vreinterpretq_s8_s32((int32x4_t) {
					*(int32_t *) (data + vgetq_lane_s64(vindex64_1, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_1, 1)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_2, 0)),
					*(int32_t *) (data + vgetq_lane_s64(vindex64_2, 1))
				});
			}
		default: XSSE_UNREACHABLE();
	}
}
static XSSE_FORCE_INLINE __m256i _mm256_i64gather_epi64(int64_t const *base_addr, __m256i vindex, const int scale)
{
	__m256i x;
	x.v0 = _mm_i64gather_epi64(base_addr, vindex.v0, scale);
	x.v1 = _mm_i64gather_epi64(base_addr, vindex.v1, scale);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_mask_i32gather_epi32(__m256i src, int const *base_addr, __m256i vindex, __m256i mask, const int scale)
{
	__m256i gathered = _mm256_i32gather_epi32(base_addr, vindex, scale);
	uint32x4_t mask_fill_1 = vcltq_s32(vreinterpretq_s32_s8(mask.v0), vdupq_n_s32(0x00));
	uint32x4_t mask_fill_2 = vcltq_s32(vreinterpretq_s32_s8(mask.v1), vdupq_n_s32(0x00));

	__m256i x;
	x.v0 = vreinterpretq_s8_s32(vbslq_s32(mask_fill_1, vreinterpretq_s32_s8(gathered.v0), vreinterpretq_s32_s8(src.v0)));
	x.v1 = vreinterpretq_s8_s32(vbslq_s32(mask_fill_2, vreinterpretq_s32_s8(gathered.v1), vreinterpretq_s32_s8(src.v1)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_mask_i32gather_epi64(__m256i src, int64_t const *base_addr, __m128i vindex, __m256i mask, const int scale)
{
	__m256i gathered = _mm256_i32gather_epi64(base_addr, vindex, scale);
	uint64x2_t mask_fill_1 = vcltq_s64(vreinterpretq_s64_s8(mask.v0), vdupq_n_s64(0x00));
	uint64x2_t mask_fill_2 = vcltq_s64(vreinterpretq_s64_s8(mask.v1), vdupq_n_s64(0x00));

	__m256i x;
	x.v0 = vreinterpretq_s8_s64(vbslq_s64(mask_fill_1, vreinterpretq_s64_s8(gathered.v0), vreinterpretq_s64_s8(src.v0)));
	x.v1 = vreinterpretq_s8_s64(vbslq_s64(mask_fill_2, vreinterpretq_s64_s8(gathered.v1), vreinterpretq_s64_s8(src.v1)));
	return x;
}
static XSSE_FORCE_INLINE __m128i _mm256_mask_i64gather_epi32(__m128i src, int const *base_addr, __m256i vindex, __m128i mask, const int scale)
{
	__m128i gathered = _mm256_i64gather_epi32(base_addr, vindex, scale);
	uint32x4_t mask_fill = vcltq_s32(vreinterpretq_s32_s8(mask), vdupq_n_s32(0x00));
	return vreinterpretq_s8_s32(vbslq_s32(mask_fill, vreinterpretq_s32_s8(gathered), vreinterpretq_s32_s8(src)));
}
static XSSE_FORCE_INLINE __m256i _mm256_mask_i64gather_epi64(__m256i src, int64_t const *base_addr, __m256i vindex, __m256i mask, const int scale)
{
	__m256i gathered = _mm256_i64gather_epi64(base_addr, vindex, scale);
	uint64x2_t mask_fill_1 = vcltq_s64(vreinterpretq_s64_s8(mask.v0), vdupq_n_s64(0x00));
	uint64x2_t mask_fill_2 = vcltq_s64(vreinterpretq_s64_s8(mask.v1), vdupq_n_s64(0x00));

	__m256i x;
	x.v0 = vreinterpretq_s8_s64(vbslq_s64(mask_fill_1, vreinterpretq_s64_s8(gathered.v0), vreinterpretq_s64_s8(src.v0)));
	x.v1 = vreinterpretq_s8_s64(vbslq_s64(mask_fill_2, vreinterpretq_s64_s8(gathered.v1), vreinterpretq_s64_s8(src.v1)));
	return x;
}


/*****************************************************************************
 * Bit shift / Bit wise                                                      *
 *****************************************************************************/

static XSSE_FORCE_INLINE __m256i _mm256_or_si256(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_or_si128(a.v0, b.v0);
	x.v1 = _mm_or_si128(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_xor_si256(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_xor_si128(a.v0, b.v0);
	x.v1 = _mm_xor_si128(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_and_si256(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_and_si128(a.v0, b.v0);
	x.v1 = _mm_and_si128(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_andnot_si256(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_andnot_si128(a.v0, b.v0);
	x.v1 = _mm_andnot_si128(a.v1, b.v1);
	return x;
}

#ifdef XSSE_HAS_MACRO_EXTENSION
#define _mm256_slli_epi16(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_slli_epi16(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_slli_epi16(x.v1, imm8); \
		__xsse_tmp; \
	})
#define _mm256_slli_epi32(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_slli_epi32(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_slli_epi32(x.v1, imm8); \
		__xsse_tmp; \
	})
#define _mm256_slli_epi64(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_slli_epi64(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_slli_epi64(x.v1, imm8); \
		__xsse_tmp; \
	})
#define _mm256_slli_si256(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_slli_si128(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_slli_si128(x.v1, imm8); \
		__xsse_tmp; \
	})
#else
static XSSE_FORCE_INLINE __m256i _mm256_slli_epi16(__m256i x, const int imm8)
{
	int16x8_t shifts = vdupq_n_s16((int16_t) imm8);
	x.v0 = vreinterpretq_s8_u16(vshlq_u16(vreinterpretq_u16_s8(x.v0), shifts));
	x.v1 = vreinterpretq_s8_u16(vshlq_u16(vreinterpretq_u16_s8(x.v1), shifts));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_slli_epi32(__m256i x, const int imm8)
{
	int32x4_t shifts = vdupq_n_s32((int32_t) imm8);
	x.v0 = vreinterpretq_s8_u32(vshlq_u32(vreinterpretq_u32_s8(x.v0), shifts));
	x.v1 = vreinterpretq_s8_u32(vshlq_u32(vreinterpretq_u32_s8(x.v1), shifts));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_slli_epi64(__m256i x, const int imm8)
{
	int64x2_t shifts = vdupq_n_s64((int64_t) imm8);
	x.v0 = vreinterpretq_s8_u64(vshlq_u64(vreinterpretq_u64_s8(x.v0), shifts));
	x.v1 = vreinterpretq_s8_u64(vshlq_u64(vreinterpretq_u64_s8(x.v1), shifts));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_slli_si256(__m256i x, const int imm8)
{
	x.v0 = _mm_slli_si128(x.v0, imm8);
	x.v1 = _mm_slli_si128(x.v1, imm8);
	return x;
}
#endif
#define _mm256_bslli_epi128(x, imm) _mm256_slli_si256(x, imm)

static XSSE_FORCE_INLINE __m256i _mm256_sll_epi16(__m256i x, __m128i count)
{
	x.v0 = _mm_sll_epi16(x.v0, count);
	x.v1 = _mm_sll_epi16(x.v1, count);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sll_epi32(__m256i x, __m128i count)
{
	x.v0 = _mm_sll_epi32(x.v0, count);
	x.v1 = _mm_sll_epi32(x.v1, count);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sll_epi64(__m256i x, __m128i count)
{
	x.v0 = _mm_sll_epi64(x.v0, count);
	x.v1 = _mm_sll_epi64(x.v1, count);
	return x;
}

#define _mm_sllv_epi32(x, count) (vreinterpretq_s8_u32(vshlq_u32(vreinterpretq_u32_s8(x), vreinterpretq_s32_s8(count))))
#define _mm_sllv_epi64(x, count) (vreinterpretq_s8_u64(vshlq_u64(vreinterpretq_u64_s8(x), vreinterpretq_s64_s8(count))))
static XSSE_FORCE_INLINE __m256i _mm256_sllv_epi32(__m256i x, __m256i count)
{
	x.v0 = _mm_sllv_epi32(x.v0, count.v0);
	x.v1 = _mm_sllv_epi32(x.v1, count.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sllv_epi64(__m256i x, __m256i count)
{
	x.v0 = _mm_sllv_epi64(x.v0, count.v0);
	x.v1 = _mm_sllv_epi64(x.v1, count.v1);
	return x;
}

#ifdef XSSE_HAS_MACRO_EXTENSION
#define _mm256_srai_epi16(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_srai_epi16(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_srai_epi16(x.v1, imm8); \
		__xsse_tmp; \
	})
#define _mm256_srai_epi32(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_srai_epi32(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_srai_epi32(x.v1, imm8); \
		__xsse_tmp; \
	})
#else
static XSSE_FORCE_INLINE __m256i _mm256_srai_epi16(__m256i x, const int imm8)
{
	int16x8_t shifts = vdupq_n_s16(-(int16_t) imm8);
	x.v0 = vreinterpretq_s8_s16(vshlq_s16(vreinterpretq_s16_s8(x.v0), shifts));
	x.v1 = vreinterpretq_s8_s16(vshlq_s16(vreinterpretq_s16_s8(x.v1), shifts));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_srai_epi32(__m256i x, const int imm8)
{
	int32x4_t shifts = vdupq_n_s32(-(int32_t) imm8);
	x.v0 = vreinterpretq_s8_s32(vshlq_s32(vreinterpretq_s32_s8(x.v0), shifts));
	x.v1 = vreinterpretq_s8_s32(vshlq_s32(vreinterpretq_s32_s8(x.v1), shifts));
	return x;
}
#endif
static XSSE_FORCE_INLINE __m256i _mm256_sra_epi16(__m256i x, __m128i count)
{
	x.v0 = _mm_sra_epi16(x.v0, count);
	x.v1 = _mm_sra_epi16(x.v1, count);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sra_epi32(__m256i x, __m128i count)
{
	x.v0 = _mm_sra_epi32(x.v0, count);
	x.v1 = _mm_sra_epi32(x.v1, count);
	return x;
}
#define _mm_srav_epi32(x, count) (vreinterpretq_s8_s32(vshlq_s32(vreinterpretq_s32_s8(x), vnegq_s32(vreinterpretq_s32_s8(count)))))
static XSSE_FORCE_INLINE __m256i _mm256_srav_epi32(__m256i x, __m256i count)
{
	x.v0 = _mm_srav_epi32(x.v0, count.v0);
	x.v1 = _mm_srav_epi32(x.v1, count.v1);
	return x;
}

#ifdef XSSE_HAS_MACRO_EXTENSION
#define _mm256_srli_epi16(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_srli_epi16(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_srli_epi16(x.v1, imm8); \
		__xsse_tmp; \
	})
#define _mm256_srli_epi32(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_srli_epi32(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_srli_epi32(x.v1, imm8); \
		__xsse_tmp; \
	})
#define _mm256_srli_epi64(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_srli_epi64(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_srli_epi64(x.v1, imm8); \
		__xsse_tmp; \
	})
#define _mm256_srli_si256(x, imm8) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_srli_si128(x.v0, imm8); \
		__xsse_tmp.v1 = _mm_srli_si128(x.v1, imm8); \
		__xsse_tmp; \
	})
#else
static XSSE_FORCE_INLINE __m256i _mm256_srli_epi16(__m256i x, const int imm8)
{
	int16x8_t shifts = vdupq_n_s16(-(int16_t) imm8);
	x.v0 = vreinterpretq_s8_u16(vshlq_u16(vreinterpretq_u16_s8(x.v0), shifts));
	x.v1 = vreinterpretq_s8_u16(vshlq_u16(vreinterpretq_u16_s8(x.v1), shifts));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_srli_epi32(__m256i x, const int imm8)
{
	int32x4_t shifts = vdupq_n_s32(-(int32_t) imm8);
	x.v0 = vreinterpretq_s8_u32(vshlq_u32(vreinterpretq_u32_s8(x.v0), shifts));
	x.v1 = vreinterpretq_s8_u32(vshlq_u32(vreinterpretq_u32_s8(x.v1), shifts));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_srli_epi64(__m256i x, const int imm8)
{
	int64x2_t shifts = vdupq_n_s64(-(int64_t) imm8);
	x.v0 = vreinterpretq_s8_u64(vshlq_u64(vreinterpretq_u64_s8(x.v0), shifts));
	x.v1 = vreinterpretq_s8_u64(vshlq_u64(vreinterpretq_u64_s8(x.v1), shifts));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_srli_si256(__m256i x, const int imm8)
{
	x.v0 = _mm_srli_si128(x.v0, imm8);
	x.v1 = _mm_srli_si128(x.v1, imm8);
	return x;
}
#endif
#define _mm256_bsrli_epi128(x, imm) _mm256_srli_si256(x, imm)

static XSSE_FORCE_INLINE __m256i _mm256_srl_epi16(__m256i x, __m128i count)
{
	x.v0 = _mm_srl_epi16(x.v0, count);
	x.v1 = _mm_srl_epi16(x.v1, count);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_srl_epi32(__m256i x, __m128i count)
{
	x.v0 = _mm_srl_epi32(x.v0, count);
	x.v1 = _mm_srl_epi32(x.v1, count);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_srl_epi64(__m256i x, __m128i count)
{
	x.v0 = _mm_srl_epi64(x.v0, count);
	x.v1 = _mm_srl_epi64(x.v1, count);
	return x;
}

#define _mm_srlv_epi32(x, count) (vreinterpretq_s8_u32(vshlq_u32(vreinterpretq_u32_s8(x), vnegq_s32(vreinterpretq_s32_s8(count)))))
#define _mm_srlv_epi64(x, count) (vreinterpretq_s8_u64(vshlq_u64(vreinterpretq_u64_s8(x), vnegq_s64(vreinterpretq_s64_s8(count)))))
static XSSE_FORCE_INLINE __m256i _mm256_srlv_epi32(__m256i x, __m256i count)
{
	x.v0 = _mm_srlv_epi32(x.v0, count.v0);
	x.v1 = _mm_srlv_epi32(x.v1, count.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_srlv_epi64(__m256i x, __m256i count)
{
	x.v0 = _mm_srlv_epi64(x.v0, count.v0);
	x.v1 = _mm_srlv_epi64(x.v1, count.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_alignr_epi8(__m256i a, __m256i b, const int imm8)
{
	__m256i x;
	x.v0 = _mm_alignr_epi8(a.v0, b.v0, imm8);
	x.v1 = _mm_alignr_epi8(a.v1, b.v1, imm8);
	return x;
}


/*****************************************************************************
 * Broadcast                                                                 *
 *****************************************************************************/

#define _mm_broadcastb_epi8(x) _mm_set1_epi8(vgetq_lane_s8((x), 0))
#define _mm_broadcastw_epi16(x) _mm_set1_epi16(vgetq_lane_s16(vreinterpretq_s16_s8(x), 0))
#define _mm_broadcastd_epi32(x) _mm_set1_epi32(vgetq_lane_s32(vreinterpretq_s32_s8(x), 0))
#define _mm_broadcastq_epi64(x) _mm_set1_epi64x(vgetq_lane_s64(vreinterpretq_s64_s8(x), 0))

static XSSE_FORCE_INLINE __m256i _mm256_broadcastb_epi8(__m128i a)
{
	__m128i low_8_repeat = _mm_broadcastb_epi8(a);
	__m256i x;
	x.v0 = low_8_repeat;
	x.v1 = low_8_repeat;
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_broadcastw_epi16(__m128i a)
{
	__m128i low_16_repeat = _mm_broadcastw_epi16(a);
	__m256i x;
	x.v0 = low_16_repeat;
	x.v1 = low_16_repeat;
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_broadcastd_epi32(__m128i a)
{
	__m128i low_32_repeat = _mm_broadcastd_epi32(a);
	__m256i x;
	x.v0 = low_32_repeat;
	x.v1 = low_32_repeat;
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_broadcastq_epi64(__m128i a)
{
	__m128i low_64_repeat = _mm_broadcastq_epi64(a);
	__m256i x;
	x.v0 = low_64_repeat;
	x.v1 = low_64_repeat;
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm_broadcastsi128_si256(__m128i a)
{
	__m256i x;
	x.v0 = a;
	x.v1 = a;
	return x;
}
#define _mm256_broadcastsi128_si256(x) _mm_broadcastsi128_si256(x)


/*****************************************************************************
 * Integer Arithmetic Operations                                             *
 *****************************************************************************/

static XSSE_FORCE_INLINE __m256i _mm256_abs_epi8(__m256i x)
{
	x.v0 = _mm_abs_epi8(x.v0);
	x.v1 = _mm_abs_epi8(x.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_abs_epi16(__m256i x)
{
	x.v0 = _mm_abs_epi16(x.v0);
	x.v1 = _mm_abs_epi16(x.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_abs_epi32(__m256i x)
{
	x.v0 = _mm_abs_epi32(x.v0);
	x.v1 = _mm_abs_epi32(x.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_avg_epu8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_avg_epu8(a.v0, b.v0);
	x.v1 = _mm_avg_epu8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_avg_epu16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_avg_epu16(a.v0, b.v0);
	x.v1 = _mm_avg_epu16(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_max_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_max_epi8(a.v0, b.v0);
	x.v1 = _mm_max_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_max_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_max_epi16(a.v0, b.v0);
	x.v1 = _mm_max_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_max_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_max_epi32(a.v0, b.v0);
	x.v1 = _mm_max_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_max_epu8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_max_epu8(a.v0, b.v0);
	x.v1 = _mm_max_epu8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_max_epu16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_max_epu16(a.v0, b.v0);
	x.v1 = _mm_max_epu16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_max_epu32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_max_epu32(a.v0, b.v0);
	x.v1 = _mm_max_epu32(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_min_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_min_epi8(a.v0, b.v0);
	x.v1 = _mm_min_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_min_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_min_epi16(a.v0, b.v0);
	x.v1 = _mm_min_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_min_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_min_epi32(a.v0, b.v0);
	x.v1 = _mm_min_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_min_epu8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_min_epu8(a.v0, b.v0);
	x.v1 = _mm_min_epu8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_min_epu16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_min_epu16(a.v0, b.v0);
	x.v1 = _mm_min_epu16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_min_epu32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_min_epu32(a.v0, b.v0);
	x.v1 = _mm_min_epu32(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_sign_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_sign_epi8(a.v0, b.v0);
	x.v1 = _mm_sign_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sign_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_sign_epi16(a.v0, b.v0);
	x.v1 = _mm_sign_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sign_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_sign_epi32(a.v0, b.v0);
	x.v1 = _mm_sign_epi32(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_add_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_add_epi8(a.v0, b.v0);
	x.v1 = _mm_add_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_add_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_add_epi16(a.v0, b.v0);
	x.v1 = _mm_add_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_add_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_add_epi32(a.v0, b.v0);
	x.v1 = _mm_add_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_add_epi64(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_add_epi64(a.v0, b.v0);
	x.v1 = _mm_add_epi64(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_adds_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_adds_epi8(a.v0, b.v0);
	x.v1 = _mm_adds_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_adds_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_adds_epi16(a.v0, b.v0);
	x.v1 = _mm_adds_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_adds_epu8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_adds_epu8(a.v0, b.v0);
	x.v1 = _mm_adds_epu8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_adds_epu16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_adds_epu16(a.v0, b.v0);
	x.v1 = _mm_adds_epu16(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_hadd_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_hadd_epi16(a.v0, b.v0);
	x.v1 = _mm_hadd_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_hadd_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_hadd_epi32(a.v0, b.v0);
	x.v1 = _mm_hadd_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_hadds_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_hadds_epi16(a.v0, b.v0);
	x.v1 = _mm_hadds_epi16(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_madd_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_madd_epi16(a.v0, b.v0);
	x.v1 = _mm_madd_epi16(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_maddubs_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_maddubs_epi16(a.v0, b.v0);
	x.v1 = _mm_maddubs_epi16(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_mul_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_mul_epi32(a.v0, b.v0);
	x.v1 = _mm_mul_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_mul_epu32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_mul_epu32(a.v0, b.v0);
	x.v1 = _mm_mul_epu32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_mulhi_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_mulhi_epi16(a.v0, b.v0);
	x.v1 = _mm_mulhi_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_mulhi_epu16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_mulhi_epu16(a.v0, b.v0);
	x.v1 = _mm_mulhi_epu16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_mullo_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_mullo_epi16(a.v0, b.v0);
	x.v1 = _mm_mullo_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_mullo_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_mullo_epi32(a.v0, b.v0);
	x.v1 = _mm_mullo_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_mulhrs_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_mulhrs_epi16(a.v0, b.v0);
	x.v1 = _mm_mulhrs_epi16(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_sub_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_sub_epi8(a.v0, b.v0);
	x.v1 = _mm_sub_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sub_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_sub_epi16(a.v0, b.v0);
	x.v1 = _mm_sub_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sub_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_sub_epi32(a.v0, b.v0);
	x.v1 = _mm_sub_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_sub_epi64(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_sub_epi64(a.v0, b.v0);
	x.v1 = _mm_sub_epi64(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_subs_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_subs_epi8(a.v0, b.v0);
	x.v1 = _mm_subs_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_subs_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_subs_epi16(a.v0, b.v0);
	x.v1 = _mm_subs_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_subs_epu8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_subs_epu8(a.v0, b.v0);
	x.v1 = _mm_subs_epu8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_subs_epu16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_subs_epu16(a.v0, b.v0);
	x.v1 = _mm_subs_epu16(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_hsub_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_hsub_epi16(a.v0, b.v0);
	x.v1 = _mm_hsub_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_hsub_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_hsub_epi32(a.v0, b.v0);
	x.v1 = _mm_hsub_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_hsubs_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_hsubs_epi16(a.v0, b.v0);
	x.v1 = _mm_hsubs_epi16(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_sad_epu8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_sad_epu8(a.v0, b.v0);
	x.v1 = _mm_sad_epu8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_mpsadbw_epu8(__m256i a, __m256i b, const int imm8)
{
	__m256i x;
	x.v0 = _mm_mpsadbw_epu8(a.v0, b.v0, imm8);
	x.v1 = _mm_mpsadbw_epu8(a.v1, b.v1, (imm8 >> 3));
	return x;
}


/*****************************************************************************
 * Comparison                                                                *
 *****************************************************************************/

static XSSE_FORCE_INLINE __m256i _mm256_cmpeq_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_cmpeq_epi8(a.v0, b.v0);
	x.v1 = _mm_cmpeq_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cmpeq_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_cmpeq_epi16(a.v0, b.v0);
	x.v1 = _mm_cmpeq_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cmpeq_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_cmpeq_epi32(a.v0, b.v0);
	x.v1 = _mm_cmpeq_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cmpeq_epi64(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_cmpeq_epi64(a.v0, b.v0);
	x.v1 = _mm_cmpeq_epi64(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cmpgt_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_cmpgt_epi8(a.v0, b.v0);
	x.v1 = _mm_cmpgt_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cmpgt_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_cmpgt_epi16(a.v0, b.v0);
	x.v1 = _mm_cmpgt_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cmpgt_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_cmpgt_epi32(a.v0, b.v0);
	x.v1 = _mm_cmpgt_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cmpgt_epi64(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_cmpgt_epi64(a.v0, b.v0);
	x.v1 = _mm_cmpgt_epi64(a.v1, b.v1);
	return x;
}


/*****************************************************************************
 * Convert                                                                   *
 *****************************************************************************/

static XSSE_FORCE_INLINE __m256i _mm256_cvtepi8_epi16(__m128i a)
{
	__m256i x;
	x.v0 = vreinterpretq_s8_s16(vmovl_s8(vget_low_s8(a)));
	x.v1 = vreinterpretq_s8_s16(vmovl_s8(vget_high_s8(a)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepi8_epi32(__m128i a)
{
	__m256i x;
	int16x8_t a16 = vmovl_s8(vget_low_s8(a));
	x.v0 = vreinterpretq_s8_s32(vmovl_s16(vget_low_s16(a16)));
	x.v1 = vreinterpretq_s8_s32(vmovl_s16(vget_high_s16(a16)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepi8_epi64(__m128i a)
{
	__m256i x;
	int32x4_t a32 = vmovl_s16(vget_low_s16(vmovl_s8(vget_low_s8(a))));
	x.v0 = vreinterpretq_s8_s64(vmovl_s32(vget_low_s32(a32)));
	x.v1 = vreinterpretq_s8_s64(vmovl_s32(vget_high_s32(a32)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepi16_epi32(__m128i a)
{
	__m256i x;
	int16x8_t a16 = vreinterpretq_s16_s8(a);
	x.v0 = vreinterpretq_s8_s32(vmovl_s16(vget_low_s16(a16)));
	x.v1 = vreinterpretq_s8_s32(vmovl_s16(vget_high_s16(a16)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepi16_epi64(__m128i a)
{
	__m256i x;
	int32x4_t a32 = vmovl_s16(vget_low_s16(vreinterpretq_s16_s8(a)));
	x.v0 = vreinterpretq_s8_s64(vmovl_s32(vget_low_s32(a32)));
	x.v1 = vreinterpretq_s8_s64(vmovl_s32(vget_high_s32(a32)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepi32_epi64(__m128i a)
{
	__m256i x;
	int32x4_t a32 = vreinterpretq_s32_s8(a);
	x.v0 = vreinterpretq_s8_s64(vmovl_s32(vget_low_s32(a32)));
	x.v1 = vreinterpretq_s8_s64(vmovl_s32(vget_high_s32(a32)));
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_cvtepu8_epi16(__m128i a)
{
	__m256i x;
	x.v0 = vreinterpretq_s8_u16(vmovl_u8(vget_low_u8(vreinterpretq_u8_s8(a))));
	x.v1 = vreinterpretq_s8_u16(vmovl_u8(vget_high_u8(vreinterpretq_u8_s8(a))));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepu8_epi32(__m128i a)
{
	__m256i x;
	uint16x8_t a16 = vmovl_u8(vget_low_u8(vreinterpretq_u8_s8(a)));
	x.v0 = vreinterpretq_s8_u32(vmovl_u16(vget_low_u16(a16)));
	x.v1 = vreinterpretq_s8_u32(vmovl_u16(vget_high_u16(a16)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepu8_epi64(__m128i a)
{
	__m256i x;
	uint32x4_t a32 = vmovl_u16(vget_low_u16(vmovl_u8(vget_low_u8(vreinterpretq_u8_s8(a)))));
	x.v0 = vreinterpretq_s8_u64(vmovl_u32(vget_low_u32(a32)));
	x.v1 = vreinterpretq_s8_u64(vmovl_u32(vget_high_u32(a32)));
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_cvtepu16_epi32(__m128i a)
{
	__m256i x;
	uint16x8_t a16 = vreinterpretq_u16_s8(a);
	x.v0 = vreinterpretq_s8_u32(vmovl_u16(vget_low_u16(a16)));
	x.v1 = vreinterpretq_s8_u32(vmovl_u16(vget_high_u16(a16)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepu16_epi64(__m128i a)
{
	__m256i x;
	uint32x4_t a32 = vmovl_u16(vget_low_u16(vreinterpretq_u16_s8(a)));
	x.v0 = vreinterpretq_s8_u64(vmovl_u32(vget_low_u32(a32)));
	x.v1 = vreinterpretq_s8_u64(vmovl_u32(vget_high_u32(a32)));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_cvtepu32_epi64(__m128i a)
{
	__m256i x;
	uint32x4_t a32 = vreinterpretq_u32_s8(a);
	x.v0 = vreinterpretq_s8_u64(vmovl_u32(vget_low_u32(a32)));
	x.v1 = vreinterpretq_s8_u64(vmovl_u32(vget_high_u32(a32)));
	return x;
}


/*****************************************************************************
 * Others                                                                    *
 *****************************************************************************/

static XSSE_FORCE_INLINE __m256i _mm256_packs_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_packs_epi16(a.v0, b.v0);
	x.v1 = _mm_packs_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_packs_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_packs_epi32(a.v0, b.v0);
	x.v1 = _mm_packs_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_packus_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_packus_epi16(a.v0, b.v0);
	x.v1 = _mm_packus_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_packus_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_packus_epi32(a.v0, b.v0);
	x.v1 = _mm_packus_epi32(a.v1, b.v1);
	return x;
}

static XSSE_FORCE_INLINE int32_t _mm256_extract_epi8(__m256i x, const int index)
{
	switch (index) {
		case 0: return _mm_extract_epi8(x.v0, 0);
		case 1: return _mm_extract_epi8(x.v0, 1);
		case 2: return _mm_extract_epi8(x.v0, 2);
		case 3: return _mm_extract_epi8(x.v0, 3);
		case 4: return _mm_extract_epi8(x.v0, 4);
		case 5: return _mm_extract_epi8(x.v0, 5);
		case 6: return _mm_extract_epi8(x.v0, 6);
		case 7: return _mm_extract_epi8(x.v0, 7);
		case 8: return _mm_extract_epi8(x.v0, 8);
		case 9: return _mm_extract_epi8(x.v0, 9);
		case 10: return _mm_extract_epi8(x.v0, 10);
		case 11: return _mm_extract_epi8(x.v0, 11);
		case 12: return _mm_extract_epi8(x.v0, 12);
		case 13: return _mm_extract_epi8(x.v0, 13);
		case 14: return _mm_extract_epi8(x.v0, 14);
		case 15: return _mm_extract_epi8(x.v0, 15);
		case 16: return _mm_extract_epi8(x.v1, 0);
		case 17: return _mm_extract_epi8(x.v1, 1);
		case 18: return _mm_extract_epi8(x.v1, 2);
		case 19: return _mm_extract_epi8(x.v1, 3);
		case 20: return _mm_extract_epi8(x.v1, 4);
		case 21: return _mm_extract_epi8(x.v1, 5);
		case 22: return _mm_extract_epi8(x.v1, 6);
		case 23: return _mm_extract_epi8(x.v1, 7);
		case 24: return _mm_extract_epi8(x.v1, 8);
		case 25: return _mm_extract_epi8(x.v1, 9);
		case 26: return _mm_extract_epi8(x.v1, 10);
		case 27: return _mm_extract_epi8(x.v1, 11);
		case 28: return _mm_extract_epi8(x.v1, 12);
		case 29: return _mm_extract_epi8(x.v1, 13);
		case 30: return _mm_extract_epi8(x.v1, 14);
		case 31: return _mm_extract_epi8(x.v1, 15);
		default: XSSE_UNREACHABLE();
	}
}
static XSSE_FORCE_INLINE int32_t _mm256_extract_epi16(__m256i x, const int index)
{
	switch (index) {
		case 0: return _mm_extract_epi16(x.v0, 0);
		case 1: return _mm_extract_epi16(x.v0, 1);
		case 2: return _mm_extract_epi16(x.v0, 2);
		case 3: return _mm_extract_epi16(x.v0, 3);
		case 4: return _mm_extract_epi16(x.v0, 4);
		case 5: return _mm_extract_epi16(x.v0, 5);
		case 6: return _mm_extract_epi16(x.v0, 6);
		case 7: return _mm_extract_epi16(x.v0, 7);
		case 8: return _mm_extract_epi16(x.v1, 0);
		case 9: return _mm_extract_epi16(x.v1, 1);
		case 10: return _mm_extract_epi16(x.v1, 2);
		case 11: return _mm_extract_epi16(x.v1, 3);
		case 12: return _mm_extract_epi16(x.v1, 4);
		case 13: return _mm_extract_epi16(x.v1, 5);
		case 14: return _mm_extract_epi16(x.v1, 6);
		case 15: return _mm_extract_epi16(x.v1, 7);
		default: XSSE_UNREACHABLE();
	}
}
#define _mm256_extracti128_si256(x, imm8) _mm256_extractf128_si256(x, imm8)

#define _mm256_inserti128_si256(a, b, imm8) _mm256_insertf128_si256(a, b, imm8)

#define _mm_blend_epi32(a, b, imm8) \
	(vreinterpretq_s8_s32(vbslq_s32( \
		(uint32x4_t) { \
			(imm8 & (1 << 0)) ? 0xFFFFFFFF : 0x00000000, \
			(imm8 & (1 << 1)) ? 0xFFFFFFFF : 0x00000000, \
			(imm8 & (1 << 2)) ? 0xFFFFFFFF : 0x00000000, \
			(imm8 & (1 << 3)) ? 0xFFFFFFFF : 0x00000000 \
		}, \
		vreinterpretq_s32_s8(b), \
		vreinterpretq_s32_s8(a) \
	)))
static XSSE_FORCE_INLINE __m256i _mm256_blend_epi16(__m256i a, __m256i b, const int imm8)
{
	__m256i x;
	uint16x8_t mask = (uint16x8_t) {
		(imm8 & (1 << 0)) ? 0xFFFF : 0x0000,
		(imm8 & (1 << 1)) ? 0xFFFF : 0x0000,
		(imm8 & (1 << 2)) ? 0xFFFF : 0x0000,
		(imm8 & (1 << 3)) ? 0xFFFF : 0x0000,
		(imm8 & (1 << 4)) ? 0xFFFF : 0x0000,
		(imm8 & (1 << 5)) ? 0xFFFF : 0x0000,
		(imm8 & (1 << 6)) ? 0xFFFF : 0x0000,
		(imm8 & (1 << 7)) ? 0xFFFF : 0x0000
	};
	x.v0 = vreinterpretq_s8_s16(vbslq_s16(
		mask,
		vreinterpretq_s16_s8(b.v0),
		vreinterpretq_s16_s8(a.v0)
	));
	x.v1 = vreinterpretq_s8_s16(vbslq_s16(
		mask,
		vreinterpretq_s16_s8(b.v1),
		vreinterpretq_s16_s8(a.v1)
	));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_blend_epi32(__m256i a, __m256i b, const int imm8)
{
	__m256i x;
	x.v0 = _mm_blend_epi32(a.v0, b.v0, imm8);
	x.v1 = _mm_blend_epi32(a.v1, b.v1, (imm8 >> 4));
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_blendv_epi8(__m256i a, __m256i b, __m256i mask)
{
	__m256i x;
	uint8x16_t repeat_0x80 = vdupq_n_u8(0x80);
	uint8x16_t mask_fill_0 = vcgeq_u8(vreinterpretq_u8_s8(mask.v0), repeat_0x80);
	uint8x16_t mask_fill_1 = vcgeq_u8(vreinterpretq_u8_s8(mask.v1), repeat_0x80);
	x.v0 = vbslq_s8(mask_fill_0, b.v0, a.v0);
	x.v1 = vbslq_s8(mask_fill_1, b.v1, a.v1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_shuffle_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_shuffle_epi8(a.v0, b.v0);
	x.v1 = _mm_shuffle_epi8(a.v1, b.v1);
	return x;
}
#ifdef XSSE_HAS_MACRO_EXTENSION
#define _mm256_shuffle_epi32(x, imm) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_shuffle_epi32(x.v0, imm); \
		__xsse_tmp.v1 = _mm_shuffle_epi32(x.v1, imm); \
		__xsse_tmp; \
	})
#define _mm256_shufflehi_epi16(x, imm) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_shufflehi_epi16(x.v0, imm); \
		__xsse_tmp.v1 = _mm_shufflehi_epi16(x.v1, imm); \
		__xsse_tmp; \
	})
#define _mm256_shufflelo_epi16(x, imm) __extension__({ \
		__m256i __xsse_tmp; \
		__xsse_tmp.v0 = _mm_shufflelo_epi16(x.v0, imm); \
		__xsse_tmp.v1 = _mm_shufflelo_epi16(x.v1, imm); \
		__xsse_tmp; \
	})
#else
static XSSE_FORCE_INLINE __m256i _mm256_shuffle_epi32(__m256i a, const int imm8)
{
	__m256i x;
	x.v0 = _mm_shuffle_epi32(a.v0, imm8);
	x.v1 = _mm_shuffle_epi32(a.v1, imm8);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_shufflehi_epi16(__m256i a, const int imm8)
{
	__m256i x;
	x.v0 = _mm_shufflehi_epi16(a.v0, imm8);
	x.v1 = _mm_shufflehi_epi16(a.v1, imm8);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_shufflelo_epi16(__m256i a, const int imm8)
{
	__m256i x;
	x.v0 = _mm_shufflelo_epi16(a.v0, imm8);
	x.v1 = _mm_shufflelo_epi16(a.v1, imm8);
	return x;
}
#endif

static XSSE_FORCE_INLINE int _mm256_movemask_epi8(__m256i x)
{
	return _mm_movemask_epi8(x.v0) | (_mm_movemask_epi8(x.v1) << 16);
}

#define _mm256_permute2x128_si256(a, b, imm8) _mm256_permute2f128_si256(a, b, imm8)
static XSSE_FORCE_INLINE __m256i _mm256_permute4x64_epi64(__m256i a, const int imm8)
{
	__m256i x;
	int64_t low, high;
	switch (imm8 & 0x03) {
		case 0: low = vgetq_lane_s64(vreinterpretq_s64_s8(a.v0), 0); break;
		case 1: low = vgetq_lane_s64(vreinterpretq_s64_s8(a.v0), 1); break;
		case 2: low = vgetq_lane_s64(vreinterpretq_s64_s8(a.v1), 0); break;
		case 3: low = vgetq_lane_s64(vreinterpretq_s64_s8(a.v1), 1); break;
		default: XSSE_UNREACHABLE();
	}
	switch ((imm8 >> 2) & 0x03) {
		case 0: high = vgetq_lane_s64(vreinterpretq_s64_s8(a.v0), 0); break;
		case 1: high = vgetq_lane_s64(vreinterpretq_s64_s8(a.v0), 1); break;
		case 2: high = vgetq_lane_s64(vreinterpretq_s64_s8(a.v1), 0); break;
		case 3: high = vgetq_lane_s64(vreinterpretq_s64_s8(a.v1), 1); break;
		default: XSSE_UNREACHABLE();
	}
	x.v0 = vreinterpretq_s8_s64((int64x2_t) { low, high });

	switch ((imm8 >> 4) & 0x03) {
		case 0: low = vgetq_lane_s64(vreinterpretq_s64_s8(a.v0), 0); break;
		case 1: low = vgetq_lane_s64(vreinterpretq_s64_s8(a.v0), 1); break;
		case 2: low = vgetq_lane_s64(vreinterpretq_s64_s8(a.v1), 0); break;
		case 3: low = vgetq_lane_s64(vreinterpretq_s64_s8(a.v1), 1); break;
		default: XSSE_UNREACHABLE();
	}
	switch ((imm8 >> 6) & 0x03) {
		case 0: high = vgetq_lane_s64(vreinterpretq_s64_s8(a.v0), 0); break;
		case 1: high = vgetq_lane_s64(vreinterpretq_s64_s8(a.v0), 1); break;
		case 2: high = vgetq_lane_s64(vreinterpretq_s64_s8(a.v1), 0); break;
		case 3: high = vgetq_lane_s64(vreinterpretq_s64_s8(a.v1), 1); break;
		default: XSSE_UNREACHABLE();
	}
	x.v1 = vreinterpretq_s8_s64((int64x2_t) { low, high });
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_permutevar8x32_epi32(__m256i a, __m256i idx)
{
	/* 32x4[1,2,3,4] is 8x16[1,0,0,0,2,0,0,0,3,0,0,0,4,0,0,0] */
	uint8x16_t idx_0 = vreinterpretq_u8_u32(vmulq_n_u32(vandq_u32(vreinterpretq_u32_s8(idx.v0), vdupq_n_u32(0x07)), 4));
	uint8x16_t idx_1 = vreinterpretq_u8_u32(vmulq_n_u32(vandq_u32(vreinterpretq_u32_s8(idx.v1), vdupq_n_u32(0x07)), 4));
	uint8x16_t copy_map = (uint8x16_t) {0, 0, 0, 0, 4, 4, 4, 4, 8, 8, 8, 8, 12, 12, 12, 12};

	idx_0 = vqtbl1q_u8(idx_0, copy_map);
	idx_1 = vqtbl1q_u8(idx_1, copy_map);

	uint8x16_t add_vals = (uint8x16_t) {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
	idx_0 = vaddq_u8(idx_0, add_vals);
	idx_1 = vaddq_u8(idx_1, add_vals);

	int8x16x2_t as;
	as.val[0] = a.v0;
	as.val[1] = a.v1;

	__m256i x;
	x.v0 = vqtbl2q_s8(as, idx_0);
	x.v1 = vqtbl2q_s8(as, idx_1);
	return x;
}

static XSSE_FORCE_INLINE __m256i _mm256_unpackhi_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_unpackhi_epi8(a.v0, b.v0);
	x.v1 = _mm_unpackhi_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_unpackhi_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_unpackhi_epi16(a.v0, b.v0);
	x.v1 = _mm_unpackhi_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_unpackhi_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_unpackhi_epi32(a.v0, b.v0);
	x.v1 = _mm_unpackhi_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_unpackhi_epi64(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_unpackhi_epi64(a.v0, b.v0);
	x.v1 = _mm_unpackhi_epi64(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_unpacklo_epi8(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_unpacklo_epi8(a.v0, b.v0);
	x.v1 = _mm_unpacklo_epi8(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_unpacklo_epi16(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_unpacklo_epi16(a.v0, b.v0);
	x.v1 = _mm_unpacklo_epi16(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_unpacklo_epi32(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_unpacklo_epi32(a.v0, b.v0);
	x.v1 = _mm_unpacklo_epi32(a.v1, b.v1);
	return x;
}
static XSSE_FORCE_INLINE __m256i _mm256_unpacklo_epi64(__m256i a, __m256i b)
{
	__m256i x;
	x.v0 = _mm_unpacklo_epi64(a.v0, b.v0);
	x.v1 = _mm_unpacklo_epi64(a.v1, b.v1);
	return x;
}

#endif /* AVX2 */

#endif /* XSSE_AVX_H */
