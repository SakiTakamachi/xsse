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
	return _mm_testc_si128(a.v0, b.v0) && _mm_testc_si128(a.v1, b.v1);
}
static XSSE_FORCE_INLINE int _mm256_testnzc_si256(__m256i x, __m256i mask)
{
	int8x16_t and_1 = vandq_s8(mask.v0, x.v0);
	int8x16_t and_2 = vandq_s8(mask.v1, x.v1);
	uint64x2_t and64_1 = vreinterpretq_u64_s8(and_1);
	uint64x2_t and64_2 = vreinterpretq_u64_s8(and_2);
	int has_ones = (
		vgetq_lane_u64(and64_1, 0) | vgetq_lane_u64(and64_1, 1) |
		vgetq_lane_u64(and64_2, 0) | vgetq_lane_u64(and64_2, 1)
	) != 0;

	int8x16_t andnot_1 = vbicq_s8(mask.v0, x.v0);
	int8x16_t andnot_2 = vbicq_s8(mask.v1, x.v1);
	uint64x2_t andnot64_1 = vreinterpretq_u64_s8(andnot_1);
	uint64x2_t andnot64_2 = vreinterpretq_u64_s8(andnot_2);
	int has_zeros = (
		vgetq_lane_u64(andnot64_1, 0) | vgetq_lane_u64(andnot64_1, 1) |
		vgetq_lane_u64(andnot64_2, 0) | vgetq_lane_u64(andnot64_2, 1)
	) != 0;

	return has_ones && has_zeros;
}
static XSSE_FORCE_INLINE int _mm256_testz_si256(__m256i mask, __m256i x)
{
	return _mm_testz_si128(mask.v0, x.v0) && _mm_testz_si128(mask.v1, x.v1);
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

#endif /* XSSE_AVX_H */
