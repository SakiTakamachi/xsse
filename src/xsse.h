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


#ifndef XSSE_H
#define XSSE_H

#define XSSE_VERSION 10300

#ifdef _MSC_VER
#  define XSSE_FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#  define XSSE_FORCE_INLINE inline __attribute__((always_inline))
#  define XSSE_HAS_MACRO_EXTENSION
#else
#  define XSSE_FORCE_INLINE inline
#endif

#if defined(__aarch64__) || defined(_M_ARM64)
#include <arm_neon.h>
#include <string.h>
typedef int8x16_t __m128i;
#endif


/*****************************************************************************
 *                                                                           *
 * SSE2                                                                      *
 *                                                                           *
 *****************************************************************************/

#if defined(__SSE2__) || defined(_M_X64) || defined(_M_AMD64)
#include <emmintrin.h>
#define XSSE2


#elif defined(__aarch64__) || defined(_M_ARM64)
#define XSSE2

/*****************************************************************************
 * Load / Store                                                              *
 *****************************************************************************/

#define _mm_set_epi8(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15) \
	((int8x16_t) { \
		(int8_t) (x15), (int8_t) (x14), (int8_t) (x13), (int8_t) (x12), \
		(int8_t) (x11), (int8_t) (x10), (int8_t) (x9),  (int8_t) (x8), \
		(int8_t) (x7),  (int8_t) (x6),  (int8_t) (x5),  (int8_t) (x4), \
		(int8_t) (x3),  (int8_t) (x2),  (int8_t) (x1),  (int8_t) (x0) })
#define _mm_set_epi16(x0, x1, x2, x3, x4, x5, x6, x7) \
	(vreinterpretq_s8_s16((int16x8_t) { \
		(int16_t) (x7), (int16_t) (x6), (int16_t) (x5), (int16_t) (x4), \
		(int16_t) (x3), (int16_t) (x2), (int16_t) (x1), (int16_t) (x0) }))
#define _mm_set_epi32(x0, x1, x2, x3) \
	(vreinterpretq_s8_s32((int32x4_t) { (int32_t) (x3), (int32_t) (x2), (int32_t) (x1), (int32_t) (x0) }))
#define _mm_set_epi64x(x0, x1) (vreinterpretq_s8_s64((int64x2_t) { (int64_t) (x1), (int64_t) (x0) }))
#define _mm_set1_epi8(x) (vdupq_n_s8((int8_t) (x)))
#define _mm_set1_epi16(x) (vreinterpretq_s8_s16(vdupq_n_s16((int16_t) (x))))
#define _mm_set1_epi32(x) (vreinterpretq_s8_s32(vdupq_n_s32((int32_t) (x))))
#define _mm_set1_epi64x(x) (vreinterpretq_s8_s64(vdupq_n_s64((int64_t) (x))))

#define _mm_setr_epi8(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15) \
	((int8x16_t) { \
		(int8_t) (x0), (int8_t) (x1), (int8_t) (x2), (int8_t) (x3), \
		(int8_t) (x4), (int8_t) (x5), (int8_t) (x6), (int8_t) (x7), \
		(int8_t) (x8), (int8_t) (x9), (int8_t) (x10), (int8_t) (x11), \
		(int8_t) (x12), (int8_t) (x13), (int8_t) (x14), (int8_t) (x15) })
#define _mm_setr_epi16(x0, x1, x2, x3, x4, x5, x6, x7) \
	(vreinterpretq_s8_s16((int16x8_t) { \
		(int16_t) (x0), (int16_t) (x1), (int16_t) (x2), (int16_t) (x3), \
		(int16_t) (x4), (int16_t) (x5), (int16_t) (x6), (int16_t) (x7) }))
#define _mm_setr_epi32(x0, x1, x2, x3) \
	(vreinterpretq_s8_s32((int32x4_t) { (int32_t) (x0), (int32_t) (x1), (int32_t) (x2), (int32_t) (x3) }))

#define _mm_setzero_si128() (vdupq_n_s8(0))
static XSSE_FORCE_INLINE __m128i _mm_undefined_si128(void)
{
	int8x16_t x;
	__asm__ __volatile__ ("" : "=w" (x));
	return x;
}

#define _mm_load_si128(x) (vld1q_s8((const int8_t*) (x)))
static XSSE_FORCE_INLINE __m128i _mm_loadu_si16(const void *ptr)
{
	int16x8_t blank;
	__asm__ __volatile__ ("" : "=w" (blank));

	int16_t val;
	memcpy(&val, ptr, 2);
	return vreinterpretq_s8_s16(vsetq_lane_s16(val, blank, 0));
}
static XSSE_FORCE_INLINE __m128i _mm_loadu_si32(const void *ptr)
{
	int32x4_t blank;
	__asm__ __volatile__ ("" : "=w" (blank));

	int32_t val;
	memcpy(&val, ptr, 4);
	return vreinterpretq_s8_s32(vsetq_lane_s32(val, blank, 0));
}
static XSSE_FORCE_INLINE __m128i _mm_loadu_si64(const void *ptr)
{
	int64x2_t blank;
	__asm__ __volatile__ ("" : "=w" (blank));

	int64_t val;
	memcpy(&val, ptr, 8);
	return vreinterpretq_s8_s64(vsetq_lane_s64(val, blank, 0));
}
#define _mm_loadu_si128(x) _mm_load_si128(x)
static XSSE_FORCE_INLINE __m128i _mm_loadl_epi64(__m128i const *x)
{
	int64x1_t zero = vdup_n_s64(0);
	int64x1_t x64 = vld1_s64((const int64_t*) x);
	return vreinterpretq_s8_s64(vcombine_s64(x64, zero));
}

#define _mm_storel_epi64(to, x) (vst1_u64((uint64_t*) (to), vget_low_u64(vreinterpretq_u64_s8(x))))
#define _mm_store_si128(to, x) (vst1q_s8((int8_t*) (to), x))
static XSSE_FORCE_INLINE void _mm_storeu_si16(void *ptr, __m128i x)
{
	int16_t val = (int16_t) vgetq_lane_s16(vreinterpretq_s16_s8(x), 0);
#if defined(__GNUC__) || defined(__clang__)
	__builtin_memcpy(ptr, &val, sizeof(val));
#else
	memcpy(ptr, &val, sizeof(val));
#endif
}
static XSSE_FORCE_INLINE void _mm_storeu_si32(void *ptr, __m128i x)
{
	int32_t val = (int32_t) vgetq_lane_s32(vreinterpretq_s32_s8(x), 0);
#if defined(__GNUC__) || defined(__clang__)
	__builtin_memcpy(ptr, &val, sizeof(val));
#else
	memcpy(ptr, &val, sizeof(val));
#endif
}
static XSSE_FORCE_INLINE void _mm_storeu_si64(void *ptr, __m128i x)
{
	int64_t val = (int64_t) vgetq_lane_s64(vreinterpretq_s64_s8(x), 0);
#if defined(__GNUC__) || defined(__clang__)
	__builtin_memcpy(ptr, &val, sizeof(val));
#else
	memcpy(ptr, &val, sizeof(val));
#endif
}
#define _mm_storeu_si128(to, x) _mm_store_si128(to, x)
#define _mm_stream_si128(to, x) _mm_store_si128(to, x)
#define _mm_stream_si32(to, x) (*(volatile int32_t*) (to) = (int32_t) (x))
#define _mm_stream_si64(to, x) (*(volatile int64_t*) (to) = (int64_t) (x))


/*****************************************************************************
 * Bit shift / Bit wise                                                      *
 *****************************************************************************/

#define _mm_or_si128(a, b) (vorrq_s8((a), (b)))
#define _mm_xor_si128(a, b) (veorq_s8((a), (b)))
#define _mm_and_si128(a, b) (vandq_s8((a), (b)))
#define _mm_andnot_si128(a, b) (vbicq_s8((b), (a)))

#define _mm_slli_epi16(x, count) (vreinterpretq_s8_u16(vshlq_n_u16(vreinterpretq_u16_s8(x), (count))))
#define _mm_slli_epi32(x, count) (vreinterpretq_s8_u32(vshlq_n_u32(vreinterpretq_u32_s8(x), (count))))
#define _mm_slli_epi64(x, count) (vreinterpretq_s8_u64(vshlq_n_u64(vreinterpretq_u64_s8(x), (count))))
static XSSE_FORCE_INLINE __m128i _mm_sll_epi16(__m128i x, __m128i count)
{
	uint16x8_t x16 = vreinterpretq_u16_s8(x);
	uint16_t shift = (uint16_t) (vgetq_lane_s64(vreinterpretq_s64_s8(count), 0) & 0xFFFF);
	int16x8_t shifts = vdupq_n_s16((int16_t) shift);
	return vreinterpretq_s8_u16(vshlq_u16(x16, shifts));
}
static XSSE_FORCE_INLINE __m128i _mm_sll_epi32(__m128i x, __m128i count)
{
	uint32x4_t x32 = vreinterpretq_u32_s8(x);
	uint32_t shift = (uint32_t) (vgetq_lane_s64(vreinterpretq_s64_s8(count), 0) & 0xFFFFFFFF);
	int32x4_t shifts = vdupq_n_s32((int32_t) shift);
	return vreinterpretq_s8_u32(vshlq_u32(x32, shifts));
}
static XSSE_FORCE_INLINE __m128i _mm_sll_epi64(__m128i x, __m128i count)
{
	uint64x2_t x64 = vreinterpretq_u64_s8(x);
	uint64_t shift = (uint64_t) vgetq_lane_s64(vreinterpretq_s64_s8(count), 0);
	int64x2_t shifts = vdupq_n_s64((int64_t) shift);
	return vreinterpretq_s8_u64(vshlq_u64(x64, shifts));
}

static XSSE_FORCE_INLINE __m128i _mm_slli_si128(__m128i x, int imm)
{
	switch (imm) {
		case 0:;
			int8x16_t x2 = x;
			return x2;
		case 1: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 15));
		case 2: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 14));
		case 3: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 13));
		case 4: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 12));
		case 5: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 11));
		case 6: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 10));
		case 7: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 9));
		case 8: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 8));
		case 9: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 7));
		case 10: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 6));
		case 11: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 5));
		case 12: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 4));
		case 13: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 3));
		case 14: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 2));
		case 15: return vreinterpretq_s8_u8(vextq_u8(vdupq_n_u8(0), vreinterpretq_u8_s8(x), 1));
		default: return vreinterpretq_s8_u8(vdupq_n_u8(0));
	}
}
#define _mm_bslli_si128(x, imm) _mm_slli_si128(x, imm)

#define _mm_srai_epi16(x, count) (vreinterpretq_s8_s16(vshrq_n_s16(vreinterpretq_s16_s8(x), (count))))
#define _mm_srai_epi32(x, count) (vreinterpretq_s8_s32(vshrq_n_s32(vreinterpretq_s32_s8(x), (count))))
static XSSE_FORCE_INLINE __m128i _mm_sra_epi16(__m128i x, __m128i count)
{
	int16x8_t x16 = vreinterpretq_s16_s8(x);
	uint16_t shift = (uint16_t) (vgetq_lane_s64(vreinterpretq_s64_s8(count), 0) & 0xFFFF);
	int16x8_t shifts = vdupq_n_s16(-(int16_t) shift);
	return vreinterpretq_s8_s16(vshlq_s16(x16, shifts));
}
static XSSE_FORCE_INLINE __m128i _mm_sra_epi32(__m128i x, __m128i count)
{
	int32x4_t x32 = vreinterpretq_s32_s8(x);
	uint32_t shift = (uint32_t) (vgetq_lane_s64(vreinterpretq_s64_s8(count), 0) & 0xFFFFFFFF);
	int32x4_t shifts = vdupq_n_s32(-(int32_t) shift);
	return vreinterpretq_s8_s32(vshlq_s32(x32, shifts));
}

#define _mm_srli_epi16(x, count) (vreinterpretq_s8_u16(vshrq_n_u16(vreinterpretq_u16_s8(x), (count))))
#define _mm_srli_epi32(x, count) (vreinterpretq_s8_u32(vshrq_n_u32(vreinterpretq_u32_s8(x), (count))))
#define _mm_srli_epi64(x, count) (vreinterpretq_s8_u64(vshrq_n_u64(vreinterpretq_u64_s8(x), (count))))
static XSSE_FORCE_INLINE __m128i _mm_srl_epi16(__m128i x, __m128i count)
{
	uint16x8_t x16 = vreinterpretq_u16_s8(x);
	uint16_t shift = (uint16_t) (vgetq_lane_s64(vreinterpretq_s64_s8(count), 0) & 0xFFFF);
	int16x8_t shifts = vdupq_n_s16(-(int16_t) shift);
	return vreinterpretq_s8_u16(vshlq_u16(x16, shifts));
}
static XSSE_FORCE_INLINE __m128i _mm_srl_epi32(__m128i x, __m128i count)
{
	uint32x4_t x32 = vreinterpretq_u32_s8(x);
	uint32_t shift = (uint32_t) (vgetq_lane_s64(vreinterpretq_s64_s8(count), 0) & 0xFFFFFFFF);
	int32x4_t shifts = vdupq_n_s32(-(int32_t) shift);
	return vreinterpretq_s8_u32(vshlq_u32(x32, shifts));
}
static XSSE_FORCE_INLINE __m128i _mm_srl_epi64(__m128i x, __m128i count)
{
	uint64x2_t x64 = vreinterpretq_u64_s8(x);
	uint64_t shift = (uint64_t) vgetq_lane_s64(vreinterpretq_s64_s8(count), 0);
	int64x2_t shifts = vdupq_n_s64(-(int64_t) shift);
	return vreinterpretq_s8_u64(vshlq_u64(x64, shifts));
}

static XSSE_FORCE_INLINE __m128i _mm_srli_si128(__m128i x, int imm)
{
	switch (imm) {
		case 0: return x;
		case 1: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 1));
		case 2: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 2));
		case 3: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 3));
		case 4: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 4));
		case 5: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 5));
		case 6: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 6));
		case 7: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 7));
		case 8: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 8));
		case 9: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 9));
		case 10: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 10));
		case 11: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 11));
		case 12: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 12));
		case 13: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 13));
		case 14: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 14));
		case 15: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(x), vdupq_n_u8(0), 15));
		default: return vreinterpretq_s8_u8(vdupq_n_u8(0));
	}
}
#define _mm_bsrli_si128(x, imm) _mm_srli_si128(x, imm)


/*****************************************************************************
 * Integer Arithmetic Operations                                             *
 *****************************************************************************/

/**
 * In practice, there is no problem, but a runtime error for signed integer overflow is triggered by UBSAN,
 * so perform the calculation as unsigned. Since it is optimized at compile time, there are no unnecessary casts at runtime.
 */
#define _mm_add_epi8(a, b) (vreinterpretq_s8_u8(vaddq_u8(vreinterpretq_u8_s8(a), vreinterpretq_u8_s8(b))))
#define _mm_add_epi16(a, b) (vreinterpretq_s8_u16(vaddq_u16(vreinterpretq_u16_s8(a), vreinterpretq_u16_s8(b))))
#define _mm_add_epi32(a, b) (vreinterpretq_s8_u32(vaddq_u32(vreinterpretq_u32_s8(a), vreinterpretq_u32_s8(b))))
#define _mm_add_epi64(a, b) (vreinterpretq_s8_u64(vaddq_u64(vreinterpretq_u64_s8(a), vreinterpretq_u64_s8(b))))

#define _mm_adds_epi8(a, b) (vqaddq_s8((a), (b)))
#define _mm_adds_epi16(a, b) (vreinterpretq_s8_s16(vqaddq_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))
#define _mm_adds_epu8(a, b) (vreinterpretq_s8_u8(vqaddq_u8(vreinterpretq_u8_s8(a), vreinterpretq_u8_s8(b))))
#define _mm_adds_epu16(a, b) (vreinterpretq_s8_u16(vqaddq_u16(vreinterpretq_u16_s8(a), vreinterpretq_u16_s8(b))))

#define _mm_avg_epu8(a, b) (vreinterpretq_s8_u8(vrhaddq_u8(vreinterpretq_u8_s8(a), vreinterpretq_u8_s8(b))))
#define _mm_avg_epu16(a, b) (vreinterpretq_s8_u16(vrhaddq_u16(vreinterpretq_u16_s8(a), vreinterpretq_u16_s8(b))))

static XSSE_FORCE_INLINE __m128i _mm_madd_epi16(__m128i a, __m128i b)
{
	int16x8_t a16 = vreinterpretq_s16_s8(a);
	int16x8_t b16 = vreinterpretq_s16_s8(b);

	int16x4_t a_lo = vget_low_s16(a16);
	int16x4_t a_hi = vget_high_s16(a16);
	int16x4_t b_lo = vget_low_s16(b16);
	int16x4_t b_hi = vget_high_s16(b16);

	int32x4_t mul_lo = vmull_s16(a_lo, b_lo);
	int32x4_t mul_hi = vmull_s16(a_hi, b_hi);

	int32x2_t mul_lo_lo = vget_low_s32(mul_lo);
	int32x2_t mul_lo_hi = vget_high_s32(mul_lo);
	int32x2_t mul_hi_lo = vget_low_s32(mul_hi);
	int32x2_t mul_hi_hi = vget_high_s32(mul_hi);

	int32x2_t mul_lo_sum = vpadd_s32(mul_lo_lo, mul_lo_hi);
	int32x2_t mul_hi_sum = vpadd_s32(mul_hi_lo, mul_hi_hi);

	return vreinterpretq_s8_s32(vcombine_s32(mul_lo_sum, mul_hi_sum));
}

#define _mm_max_epu8(a, b) (vreinterpretq_s8_u8(vmaxq_u8(vreinterpretq_u8_s8(a), vreinterpretq_u8_s8(b))))
#define _mm_max_epi16(a, b) (vreinterpretq_s8_s16(vmaxq_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))
#define _mm_min_epu8(a, b) (vreinterpretq_s8_u8(vminq_u8(vreinterpretq_u8_s8(a), vreinterpretq_u8_s8(b))))
#define _mm_min_epi16(a, b) (vreinterpretq_s8_s16(vminq_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))

static XSSE_FORCE_INLINE __m128i _mm_mulhi_epi16(__m128i a, __m128i b)
{
	int16x8_t a16 = vreinterpretq_s16_s8(a);
	int16x8_t b16 = vreinterpretq_s16_s8(b);

	int16x4_t a_lo = vget_low_s16(a16);
	int16x4_t a_hi = vget_high_s16(a16);
	int16x4_t b_lo = vget_low_s16(b16);
	int16x4_t b_hi = vget_high_s16(b16);

	int32x4_t mul_lo = vmull_s16(a_lo, b_lo);
	int32x4_t mul_hi = vmull_s16(a_hi, b_hi);

	int16x4_t narrowed_lo = vshrn_n_s32(mul_lo, 16);
	int16x4_t narrowed_hi = vshrn_n_s32(mul_hi, 16);

	return vreinterpretq_s8_s16(vcombine_s16(narrowed_lo, narrowed_hi));
}
static XSSE_FORCE_INLINE __m128i _mm_mulhi_epu16(__m128i a, __m128i b)
{
	uint16x8_t a16 = vreinterpretq_u16_s8(a);
	uint16x8_t b16 = vreinterpretq_u16_s8(b);

	uint16x4_t a_lo = vget_low_u16(a16);
	uint16x4_t a_hi = vget_high_u16(a16);
	uint16x4_t b_lo = vget_low_u16(b16);
	uint16x4_t b_hi = vget_high_u16(b16);

	uint32x4_t mul_lo = vmull_u16(a_lo, b_lo);
	uint32x4_t mul_hi = vmull_u16(a_hi, b_hi);

	uint16x4_t narrowed_lo = vshrn_n_u32(mul_lo, 16);
	uint16x4_t narrowed_hi = vshrn_n_u32(mul_hi, 16);

	return vreinterpretq_s8_u16(vcombine_u16(narrowed_lo, narrowed_hi));
}
static XSSE_FORCE_INLINE __m128i _mm_mullo_epi16(__m128i a, __m128i b)
{
	int16x8_t a16 = vreinterpretq_s16_s8(a);
	int16x8_t b16 = vreinterpretq_s16_s8(b);

	int16x4_t a_lo = vget_low_s16(a16);
	int16x4_t a_hi = vget_high_s16(a16);
	int16x4_t b_lo = vget_low_s16(b16);
	int16x4_t b_hi = vget_high_s16(b16);

	int32x4_t mul_lo = vmull_s16(a_lo, b_lo);
	int32x4_t mul_hi = vmull_s16(a_hi, b_hi);

	int16x4_t narrowed_lo = vmovn_s32(mul_lo);
	int16x4_t narrowed_hi = vmovn_s32(mul_hi);

	return vreinterpretq_s8_s16(vcombine_s16(narrowed_lo, narrowed_hi));
}
static XSSE_FORCE_INLINE __m128i _mm_mul_epu32(__m128i a, __m128i b)
{
	uint32x4_t a32 = vreinterpretq_u32_s8(a);
	uint32x4_t b32 = vreinterpretq_u32_s8(b);
	uint32x4_t evens = vuzp1q_u32(a32, b32);
	uint32x2_t lo = vget_low_u32(evens);
	uint32x2_t hi = vget_high_u32(evens);

	return vreinterpretq_s8_u64(vmull_u32(lo, hi));
}
static XSSE_FORCE_INLINE __m128i _mm_sad_epu8(__m128i a, __m128i b)
{
	uint8x16_t ua = vreinterpretq_u8_s8(a);
	uint8x16_t ub = vreinterpretq_u8_s8(b);
	uint16x8_t abs_diffs_16 = vpaddlq_u8(vabdq_u8(ua, ub));
	uint32x4_t abs_diffs_32 = vpaddlq_u16(abs_diffs_16);
	uint64x2_t abs_diffs_64 = vpaddlq_u32(abs_diffs_32);

	return vreinterpretq_s8_u16((uint16x8_t) {
		(int16_t) vgetq_lane_u64(abs_diffs_64, 0), 0, 0, 0,
		(int16_t) vgetq_lane_u64(abs_diffs_64, 1), 0, 0, 0
	});
}

#define _mm_sub_epi8(a, b) (vreinterpretq_s8_u8(vsubq_u8(vreinterpretq_u8_s8(a), vreinterpretq_u8_s8(b))))
#define _mm_sub_epi16(a, b) (vreinterpretq_s8_u16(vsubq_u16(vreinterpretq_u16_s8(a), vreinterpretq_u16_s8(b))))
#define _mm_sub_epi32(a, b) (vreinterpretq_s8_u32(vsubq_u32(vreinterpretq_u32_s8(a), vreinterpretq_u32_s8(b))))
#define _mm_sub_epi64(a, b) (vreinterpretq_s8_u64(vsubq_u64(vreinterpretq_u64_s8(a), vreinterpretq_u64_s8(b))))

#define _mm_subs_epi8(a, b) (vqsubq_s8((a), (b)))
#define _mm_subs_epi16(a, b) (vreinterpretq_s8_s16(vqsubq_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))
#define _mm_subs_epu8(a, b) (vreinterpretq_s8_u8(vqsubq_u8(vreinterpretq_u8_s8(a), vreinterpretq_u8_s8(b))))
#define _mm_subs_epu16(a, b) (vreinterpretq_s8_u16(vqsubq_u16(vreinterpretq_u16_s8(a), vreinterpretq_u16_s8(b))))


/*****************************************************************************
 * Comparison                                                                *
 *****************************************************************************/

#define _mm_cmpeq_epi8(a, b) (vreinterpretq_s8_u8(vceqq_s8((a), (b))))
#define _mm_cmpeq_epi16(a, b) (vreinterpretq_s8_u16(vceqq_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))
#define _mm_cmpeq_epi32(a, b) (vreinterpretq_s8_u32(vceqq_s32(vreinterpretq_s32_s8(a), vreinterpretq_s32_s8(b))))

#define _mm_cmplt_epi8(a, b) (vreinterpretq_s8_u8(vcltq_s8((a), (b))))
#define _mm_cmplt_epi16(a, b) (vreinterpretq_s8_u16(vcltq_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))
#define _mm_cmplt_epi32(a, b) (vreinterpretq_s8_u32(vcltq_s32(vreinterpretq_s32_s8(a), vreinterpretq_s32_s8(b))))

#define _mm_cmpgt_epi8(a, b) (vreinterpretq_s8_u8(vcgtq_s8((a), (b))))
#define _mm_cmpgt_epi16(a, b) (vreinterpretq_s8_u16(vcgtq_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))
#define _mm_cmpgt_epi32(a, b) (vreinterpretq_s8_u32(vcgtq_s32(vreinterpretq_s32_s8(a), vreinterpretq_s32_s8(b))))


/*****************************************************************************
 * Convert                                                                   *
 *****************************************************************************/

#define _mm_cvtsi32_si128(x) (vreinterpretq_s8_s32((int32x4_t) { (int32_t) (x), 0, 0, 0 }))
#define _mm_cvtsi64_si128(x) (vreinterpretq_s8_s64((int64x2_t) { (int64_t) (x), 0 }))
#define _mm_cvtsi128_si32(x) (vgetq_lane_s32(vreinterpretq_s32_s8(x), 0))
#define _mm_cvtsi128_si64(x) (vgetq_lane_s64(vreinterpretq_s64_s8(x), 0))


/*****************************************************************************
 * Others                                                                    *
 *****************************************************************************/

#define _mm_packs_epi16(a, b) (vcombine_s8(vqmovn_s16(vreinterpretq_s16_s8(a)), vqmovn_s16(vreinterpretq_s16_s8(b))))
#define _mm_packs_epi32(a, b) \
	(vreinterpretq_s8_s16(vcombine_s16(vqmovn_s32(vreinterpretq_s32_s8(a)), vqmovn_s32(vreinterpretq_s32_s8(b)))))
#define _mm_packus_epi16(a, b) \
	(vreinterpretq_s8_u8(vcombine_u8(vqmovun_s16(vreinterpretq_s16_s8(a)), vqmovun_s16(vreinterpretq_s16_s8(b)))))

#define _mm_extract_epi16(x, imm) (vgetq_lane_s16(vreinterpretq_s16_s8(x), (imm)))
#define _mm_insert_epi16(x, val, imm) (vreinterpretq_s8_s16(vsetq_lane_s16((int16_t) (val), vreinterpretq_s16_s8(x), (imm))))

static XSSE_FORCE_INLINE void _mm_maskmoveu_si128(__m128i x, __m128i mask, char* dest)
{
	uint8x16_t origin = vld1q_u8((uint8_t*) dest);

	uint8x16_t repeat_0x00 = vdupq_n_u8(0);
	uint8x16_t repeat_0x80 = vdupq_n_u8(0x80);
	uint8x16_t umask = vreinterpretq_u8_s8(mask);
	uint8x16_t ux = vreinterpretq_u8_s8(x);

	uint8x16_t mask_bits = vandq_u8(umask, repeat_0x80);
	uint8x16_t mask_bytes = vsubq_u8(repeat_0x00, vshrq_n_u8(mask_bits, 7));
	vst1q_u8((uint8_t*) dest, vbslq_u8(mask_bytes, ux, origin));
}
static XSSE_FORCE_INLINE int _mm_movemask_epi8(__m128i x)
{
	/**
	 * based on code from
	 * https://community.arm.com/arm-community-blogs/b/servers-and-cloud-computing-blog/posts/porting-x86-vector-bitmask-optimizations-to-arm-neon
	 */
	uint16x8_t high_bits = vreinterpretq_u16_u8(vshrq_n_u8(vreinterpretq_u8_s8(x), 7));
	uint32x4_t paired16 = vreinterpretq_u32_u16(vsraq_n_u16(high_bits, high_bits, 7));
	uint64x2_t paired32 = vreinterpretq_u64_u32(vsraq_n_u32(paired16, paired16, 14));
	uint8x16_t paired64 = vreinterpretq_u8_u64(vsraq_n_u64(paired32, paired32, 28));
	return vgetq_lane_u8(paired64, 0) | ((int) vgetq_lane_u8(paired64, 8) << 8);
}

#define _MM_SHUFFLE(a, b, c, d) (((a) << 6) | ((b) << 4) | ((c) << 2) | (d))
#ifdef XSSE_HAS_MACRO_EXTENSION
#define _mm_shuffle_epi32(x, imm) __extension__({ \
		int32x4_t __xsse_tmp = vreinterpretq_s32_s8(x); \
		vreinterpretq_s8_s32((int32x4_t) { \
			(int32_t) vgetq_lane_s32(__xsse_tmp, ((imm) >> 0) & 0x3), \
			(int32_t) vgetq_lane_s32(__xsse_tmp, ((imm) >> 2) & 0x3), \
			(int32_t) vgetq_lane_s32(__xsse_tmp, ((imm) >> 4) & 0x3), \
			(int32_t) vgetq_lane_s32(__xsse_tmp, ((imm) >> 6) & 0x3) \
		}); \
	})
#define _mm_shufflehi_epi16(x, imm) __extension__({ \
		int16x8_t __xsse_tmp = vreinterpretq_s16_s8(x); \
		vreinterpretq_s8_s16(vcombine_s16( \
			vget_low_s16(__xsse_tmp), \
			(int16x4_t) { \
				(int16_t) vgetq_lane_s16(__xsse_tmp, (((imm) >> 0) & 0x3) + 4), \
				(int16_t) vgetq_lane_s16(__xsse_tmp, (((imm) >> 2) & 0x3) + 4), \
				(int16_t) vgetq_lane_s16(__xsse_tmp, (((imm) >> 4) & 0x3) + 4), \
				(int16_t) vgetq_lane_s16(__xsse_tmp, (((imm) >> 6) & 0x3) + 4) \
			} \
		)); \
	})
#define _mm_shufflelo_epi16(x, imm) __extension__({ \
		int16x8_t __xsse_tmp = vreinterpretq_s16_s8(x); \
		vreinterpretq_s8_s16(vcombine_s16( \
			(int16x4_t) { \
				(int16_t) vgetq_lane_s16(__xsse_tmp, (((imm) >> 0) & 0x3)), \
				(int16_t) vgetq_lane_s16(__xsse_tmp, (((imm) >> 2) & 0x3)), \
				(int16_t) vgetq_lane_s16(__xsse_tmp, (((imm) >> 4) & 0x3)), \
				(int16_t) vgetq_lane_s16(__xsse_tmp, (((imm) >> 6) & 0x3)) \
			}, \
			vget_high_s16(__xsse_tmp) \
		)); \
	})
#else
static XSSE_FORCE_INLINE __m128i _mm_shuffle_epi32(__m128i x, int imm)
{
	int32x4_t vec = vreinterpretq_s32_s8(x);
	int32_t arr[4];
	vst1q_s32(arr, vec);

	return vreinterpretq_s8_s32((int32x4_t) {
		arr[(imm >> 0) & 0x3],
		arr[(imm >> 2) & 0x3],
		arr[(imm >> 4) & 0x3],
		arr[(imm >> 6) & 0x3]
	});
}
static XSSE_FORCE_INLINE __m128i _mm_shufflehi_epi16(__m128i x, int imm)
{
	int16x8_t vec = vreinterpretq_s16_s8(x);
	int16_t arr[8];
	vst1q_s16(arr, vec);

	return vreinterpretq_s8_s16((int16x8_t) {
		arr[0], arr[1], arr[2], arr[3],
		arr[((imm >> 0) & 0x3) + 4],
		arr[((imm >> 2) & 0x3) + 4],
		arr[((imm >> 4) & 0x3) + 4],
		arr[((imm >> 6) & 0x3) + 4]
	});
}
static XSSE_FORCE_INLINE __m128i _mm_shufflelo_epi16(__m128i x, int imm)
{
	int16x8_t vec = vreinterpretq_s16_s8(x);
	int16_t arr[8];
	vst1q_s16(arr, vec);

	return vreinterpretq_s8_s16((int16x8_t) {
		arr[((imm >> 0) & 0x3)],
		arr[((imm >> 2) & 0x3)],
		arr[((imm >> 4) & 0x3)],
		arr[((imm >> 6) & 0x3)],
		arr[4], arr[5], arr[6], arr[7]
	});
}
#endif

#define _mm_unpackhi_epi8(a, b) (vzip2q_s8((a), (b)))
#define _mm_unpackhi_epi16(a, b) (vreinterpretq_s8_s16(vzip2q_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))
#define _mm_unpackhi_epi32(a, b) (vreinterpretq_s8_s32(vzip2q_s32(vreinterpretq_s32_s8(a), vreinterpretq_s32_s8(b))))
#define _mm_unpackhi_epi64(a, b) (vreinterpretq_s8_s64(vzip2q_s64(vreinterpretq_s64_s8(a), vreinterpretq_s64_s8(b))))

#define _mm_unpacklo_epi8(a, b) (vzip1q_s8((a), (b)))
#define _mm_unpacklo_epi16(a, b) (vreinterpretq_s8_s16(vzip1q_s16(vreinterpretq_s16_s8(a), vreinterpretq_s16_s8(b))))
#define _mm_unpacklo_epi32(a, b) (vreinterpretq_s8_s32(vzip1q_s32(vreinterpretq_s32_s8(a), vreinterpretq_s32_s8(b))))
#define _mm_unpacklo_epi64(a, b) (vreinterpretq_s8_s64(vzip1q_s64(vreinterpretq_s64_s8(a), vreinterpretq_s64_s8(b))))

#define _mm_move_epi64(x) (vreinterpretq_s8_s64((int64x2_t) { vgetq_lane_s64(vreinterpretq_s64_s8(x), 0), 0 }))

#define _mm_clflush(x) ((void) 0)
static XSSE_FORCE_INLINE void _mm_mfence(void)
{
	__asm__ __volatile__("dsb sy" ::: "memory");
}
static XSSE_FORCE_INLINE void _mm_lfence(void)
{
	__asm__ __volatile__("dsb ld" ::: "memory");
}
static XSSE_FORCE_INLINE void _mm_pause(void)
{
	__asm__ __volatile__("yield");
}

#endif /* SSE2 */


/*****************************************************************************
 *                                                                           *
 * SSE3                                                                      *
 *                                                                           *
 *****************************************************************************/

#if defined(__SSE3__)
#include <pmmintrin.h>
#define XSSE3


#elif defined(__aarch64__) || defined(_M_ARM64)
#define XSSE3

/*****************************************************************************
 * Load / Store                                                              *
 *****************************************************************************/

#define _mm_lddqu_si128(x) _mm_load_si128(x)

#endif /* SSE3 */


/*****************************************************************************
 *                                                                           *
 * SSSE3                                                                     *
 *                                                                           *
 *****************************************************************************/

#if defined(__SSSE3__)
#include <tmmintrin.h>
#define XSSSE3


#elif defined(__aarch64__) || defined(_M_ARM64)
#define XSSSE3

/*****************************************************************************
 * Integer Arithmetic Operations                                             *
 *****************************************************************************/

#define _mm_abs_epi8(x) (vabsq_s8(x))
#define _mm_abs_epi16(x) (vreinterpretq_s8_s16(vabsq_s16(vreinterpretq_s16_s8(x))))
#define _mm_abs_epi32(x) (vreinterpretq_s8_s32(vabsq_s32(vreinterpretq_s32_s8(x))))
static XSSE_FORCE_INLINE __m128i _mm_alignr_epi8(__m128i a, __m128i b, int imm)
{
	switch (imm) {
		case 0:;
			int8x16_t b2 = b;
			return b2;
		case 1: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 1));
		case 2: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 2));
		case 3: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 3));
		case 4: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 4));
		case 5: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 5));
		case 6: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 6));
		case 7: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 7));
		case 8: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 8));
		case 9: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 9));
		case 10: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 10));
		case 11: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 11));
		case 12: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 12));
		case 13: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 13));
		case 14: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 14));
		case 15: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(b), vreinterpretq_u8_s8(a), 15));
		case 16:;
			int8x16_t a2 = a;
			return a2;
		case 17: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 1));
		case 18: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 2));
		case 19: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 3));
		case 20: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 4));
		case 21: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 5));
		case 22: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 6));
		case 23: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 7));
		case 24: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 8));
		case 25: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 9));
		case 26: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 10));
		case 27: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 11));
		case 28: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 12));
		case 29: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 13));
		case 30: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 14));
		case 31: return vreinterpretq_s8_u8(vextq_u8(vreinterpretq_u8_s8(a), vdupq_n_u8(0), 15));
		default: return vdupq_n_s8(0);
	}
}

#define _mm_hadd_epi16(a, b) (vreinterpretq_s8_u16(vpaddq_u16(vreinterpretq_u16_s8(a), vreinterpretq_u16_s8(b))))
#define _mm_hadd_epi32(a, b) (vreinterpretq_s8_u32(vpaddq_u32(vreinterpretq_u32_s8(a), vreinterpretq_u32_s8(b))))
static XSSE_FORCE_INLINE __m128i _mm_hadds_epi16(__m128i a, __m128i b)
{
	int16x8_t a16 = vreinterpretq_s16_s8(a);
	int16x8_t b16 = vreinterpretq_s16_s8(b);
	int16x8_t evens = vuzp1q_s16(a16, b16);
	int16x8_t odds = vuzp2q_s16(a16, b16);
	return vreinterpretq_s8_s16(vqaddq_s16(evens, odds));
}

static XSSE_FORCE_INLINE __m128i _mm_hsub_epi16(__m128i a, __m128i b)
{
	uint16x8_t a16 = vreinterpretq_u16_s8(a);
	uint16x8_t b16 = vreinterpretq_u16_s8(b);
	uint16x8_t evens = vuzp1q_u16(a16, b16);
	uint16x8_t odds = vuzp2q_u16(a16, b16);
	return vreinterpretq_s8_u16(vsubq_u16(evens, odds));
}
static XSSE_FORCE_INLINE __m128i _mm_hsub_epi32(__m128i a, __m128i b)
{
	uint32x4_t a32 = vreinterpretq_u32_s8(a);
	uint32x4_t b32 = vreinterpretq_u32_s8(b);
	uint32x4_t evens = vuzp1q_u32(a32, b32);
	uint32x4_t odds = vuzp2q_u32(a32, b32);
	return vreinterpretq_s8_u32(vsubq_u32(evens, odds));
}
static XSSE_FORCE_INLINE __m128i _mm_hsubs_epi16(__m128i a, __m128i b)
{
	int16x8_t a16 = vreinterpretq_s16_s8(a);
	int16x8_t b16 = vreinterpretq_s16_s8(b);
	int16x8_t evens = vuzp1q_s16(a16, b16);
	int16x8_t odds = vuzp2q_s16(a16, b16);
	return vreinterpretq_s8_s16(vqsubq_s16(evens, odds));
}

static XSSE_FORCE_INLINE __m128i _mm_maddubs_epi16(__m128i a, __m128i b)
{
	uint8x16_t ua = vreinterpretq_u8_s8(a);
	uint8x8_t ua_lo = vget_low_u8(ua);
	uint8x8_t ua_hi = vget_high_u8(ua);

	uint16x8_t wide_ua_lo = vmovl_u8(ua_lo);
	uint16x8_t wide_ua_hi = vmovl_u8(ua_hi);

	int16x8_t wide_a_lo = vreinterpretq_s16_u16(wide_ua_lo);
	int16x8_t wide_a_hi = vreinterpretq_s16_u16(wide_ua_hi);

	int8x8_t b_lo = vget_low_s8(b);
	int8x8_t b_hi = vget_high_s8(b);

	int16x8_t wide_b_lo = vmovl_s8(b_lo);
	int16x8_t wide_b_hi = vmovl_s8(b_hi);

	int16x8_t mul_lo = vmulq_s16(wide_a_lo, wide_b_lo);
	int16x8_t mul_hi = vmulq_s16(wide_a_hi, wide_b_hi);

	uint16x8_t umul_lo = vreinterpretq_u16_s16(mul_lo);
	uint16x8_t umul_hi = vreinterpretq_u16_s16(mul_hi);

	return vreinterpretq_s8_u16(vpaddq_u16(umul_lo, umul_hi));
}

static XSSE_FORCE_INLINE __m128i _mm_mulhrs_epi16(__m128i a, __m128i b)
{
	int16x8_t a16 = vreinterpretq_s16_s8(a);
	int16x8_t b16 = vreinterpretq_s16_s8(b);

	int16x4_t a_lo = vget_low_s16(a16);
	int16x4_t a_hi = vget_high_s16(a16);
	int16x4_t b_lo = vget_low_s16(b16);
	int16x4_t b_hi = vget_high_s16(b16);

	int32x4_t mul_lo = vmull_s16(a_lo, b_lo);
	int32x4_t mul_hi = vmull_s16(a_hi, b_hi);

	int32x4_t repeat_0x4000 = vdupq_n_s32(0x4000);

	int32x4_t add_lo = vaddq_s32(mul_lo, repeat_0x4000);
	int32x4_t add_hi = vaddq_s32(mul_hi, repeat_0x4000);

	int32x4_t lo = vshrq_n_s32(add_lo, 15);
	int32x4_t hi = vshrq_n_s32(add_hi, 15);

	int16x4_t narrowed_lo = vqmovn_s32(lo);
	int16x4_t narrowed_hi = vqmovn_s32(hi);

	return vreinterpretq_s8_s16(vcombine_s16(narrowed_lo, narrowed_hi));
}

static XSSE_FORCE_INLINE __m128i _mm_sign_epi8(__m128i a, __m128i b)
{
	int8x16_t repeat_0x00 = vdupq_n_s8(0);
	int8x16_t repeat_0x01 = vdupq_n_s8(1);

	uint8x16_t upos_cmp_ret = vcltq_s8(repeat_0x00, b);
	uint8x16_t uneg_cmp_ret = vcltq_s8(b, repeat_0x00);

	int8x16_t pos_cmp_ret = vreinterpretq_s8_u8(upos_cmp_ret);
	int8x16_t pos_mask = vandq_s8(pos_cmp_ret, repeat_0x01);
	int8x16_t neg_mask = vreinterpretq_s8_u8(uneg_cmp_ret);

	int8x16_t mask = vorrq_s8(pos_mask, neg_mask);

	return vmulq_s8(a, mask);
}
static XSSE_FORCE_INLINE __m128i _mm_sign_epi16(__m128i a, __m128i b)
{
	int16x8_t a16 = vreinterpretq_s16_s8(a);
	int16x8_t b16 = vreinterpretq_s16_s8(b);

	int16x8_t repeat_0x00 = vdupq_n_s16(0);
	int16x8_t repeat_0x01 = vdupq_n_s16(1);

	uint16x8_t upos_cmp_ret = vcltq_s16(repeat_0x00, b16);
	uint16x8_t uneg_cmp_ret = vcltq_s16(b16, repeat_0x00);

	int16x8_t pos_cmp_ret = vreinterpretq_s16_u16(upos_cmp_ret);
	int16x8_t pos_mask = vandq_s16(pos_cmp_ret, repeat_0x01);
	int16x8_t neg_mask = vreinterpretq_s16_u16(uneg_cmp_ret);

	int16x8_t mask = vorrq_s16(pos_mask, neg_mask);

	return vreinterpretq_s8_s16(vmulq_s16(a16, mask));
}
static XSSE_FORCE_INLINE __m128i _mm_sign_epi32(__m128i a, __m128i b)
{
	int32x4_t a32 = vreinterpretq_s32_s8(a);
	int32x4_t b32 = vreinterpretq_s32_s8(b);

	int32x4_t repeat_0x00 = vdupq_n_s32(0);
	int32x4_t repeat_0x01 = vdupq_n_s32(1);

	uint32x4_t upos_cmp_ret = vcltq_s32(repeat_0x00, b32);
	uint32x4_t uneg_cmp_ret = vcltq_s32(b32, repeat_0x00);

	int32x4_t pos_cmp_ret = vreinterpretq_s32_u32(upos_cmp_ret);
	int32x4_t pos_mask = vandq_s32(pos_cmp_ret, repeat_0x01);
	int32x4_t neg_mask = vreinterpretq_s32_u32(uneg_cmp_ret);

	int32x4_t mask = vorrq_s32(pos_mask, neg_mask);

	return vreinterpretq_s8_s32(vmulq_s32(a32, mask));
}


/*****************************************************************************
 * Others                                                                    *
 *****************************************************************************/

static XSSE_FORCE_INLINE __m128i _mm_shuffle_epi8(__m128i a, __m128i b)
{
	uint8x16_t index = vreinterpretq_u8_s8(b);
	uint8x16_t repeat_0x0F = vdupq_n_u8(0x0F);
	uint8x16_t repeat_0x80 = vdupq_n_u8(0x80);

	uint8x16_t and_mask = vandq_u8(index, repeat_0x0F);
	uint8x16_t cmp_mask = vcgeq_u8(index, repeat_0x80);
	uint8x16_t masked_index = vorrq_u8(and_mask, cmp_mask);
	return vqtbl1q_s8(a, masked_index);
}


#endif /* SSSE3 */


/*****************************************************************************
 *                                                                           *
 * SSE4.1                                                                    *
 *                                                                           *
 *****************************************************************************/

#if defined(__SSE4_1__)
#include <immintrin.h>
#define XSSE4_1


#elif defined(__aarch64__) || defined(_M_ARM64)
#define XSSE4_1

/*****************************************************************************
 * Load / Store                                                              *
 *****************************************************************************/

#define _mm_stream_load_si128(x) _mm_load_si128(x)


/*****************************************************************************
 * Integer Arithmetic Operations                                             *
 *****************************************************************************/

#define _mm_max_epi8(a, b) (vmaxq_s8((a), (b)))
#define _mm_max_epi32(a, b) (vreinterpretq_s8_s32(vmaxq_s32(vreinterpretq_s32_s8(a), vreinterpretq_s32_s8(b))))
#define _mm_max_epu16(a, b) (vreinterpretq_s8_u16(vmaxq_u16(vreinterpretq_u16_s8(a), vreinterpretq_u16_s8(b))))
#define _mm_max_epu32(a, b) (vreinterpretq_s8_u32(vmaxq_u32(vreinterpretq_u32_s8(a), vreinterpretq_u32_s8(b))))

#define _mm_min_epi8(a, b) (vminq_s8((a), (b)))
#define _mm_min_epi32(a, b) (vreinterpretq_s8_s32(vminq_s32(vreinterpretq_s32_s8(a), vreinterpretq_s32_s8(b))))
#define _mm_min_epu16(a, b) (vreinterpretq_s8_u16(vminq_u16(vreinterpretq_u16_s8(a), vreinterpretq_u16_s8(b))))
#define _mm_min_epu32(a, b) (vreinterpretq_s8_u32(vminq_u32(vreinterpretq_u32_s8(a), vreinterpretq_u32_s8(b))))

static XSSE_FORCE_INLINE __m128i _mm_minpos_epu16(__m128i x)
{
	uint16x8_t x16 = vreinterpretq_u16_s8(x);

	uint16x4_t lo = vget_low_u16(x16);
	uint16x4_t hi = vget_high_u16(x16);
	uint16x4_t min4 = vmin_u16(lo, hi);

	uint16x4_t min2 = vpmin_u16(min4, min4);
	uint16x4_t min1 = vpmin_u16(min2, min2);

	uint16_t min = (uint16_t) vget_lane_u16(min1, 0);
	uint16x8_t repeat_min = vdupq_n_u16(min);

	uint16x8_t cmp = vceqq_u16(x16, repeat_min);
	uint8x8_t narrowed_cmp = vmovn_u16(cmp);
	uint64x1_t cmp_64 = vreinterpret_u64_u8(narrowed_cmp);

	uint64_t index_mask8 = (uint64_t) vget_lane_u64(cmp_64, 0);

	uint16_t index = 0;
#if (defined(__has_builtin) && __has_builtin(__builtin_ctzll)) || defined(__GNUC__) || defined(__clang__)
	index = (uint16_t) __builtin_ctzll(index_mask8) / 8;
#else
	for (int i = 0; i < 8; i++) {
		if (index_mask8 & 1) {
			index = (uint16_t) i;
			break;
		}
		index_mask8 >>= 8;
	}
#endif
	return 	vreinterpretq_s8_u16((uint16x8_t) { min, index, 0, 0, 0, 0, 0, 0 });
}

static XSSE_FORCE_INLINE __m128i _mm_mul_epi32(__m128i a, __m128i b)
{
	int32x4_t a32 = vreinterpretq_s32_s8(a);
	int32x4_t b32 = vreinterpretq_s32_s8(b);
	int32x4_t evens = vuzp1q_s32(a32, b32);
	int32x2_t lo = vget_low_s32(evens);
	int32x2_t hi = vget_high_s32(evens);
	return vreinterpretq_s8_s64(vmull_s32(lo, hi));
}
static XSSE_FORCE_INLINE __m128i _mm_mullo_epi32(__m128i a, __m128i b)
{
	int32x2_t a_lo = vget_low_s32(vreinterpretq_s32_s8(a));
	int32x2_t a_hi = vget_high_s32(vreinterpretq_s32_s8(a));
	int32x2_t b_lo = vget_low_s32(vreinterpretq_s32_s8(b));
	int32x2_t b_hi = vget_high_s32(vreinterpretq_s32_s8(b));

	int64x2_t mul_lo = vmull_s32(a_lo, b_lo);
	int64x2_t mul_hi = vmull_s32(a_hi, b_hi);
	int32x2_t lo = vmovn_s64(mul_lo);
	int32x2_t hi = vmovn_s64(mul_hi);
	return vreinterpretq_s8_s32(vcombine_s32(lo, hi));
}

static XSSE_FORCE_INLINE __m128i _mm_mpsadbw_epu8(__m128i a, __m128i b, const int imm8)
{
	uint8x16_t ua = vreinterpretq_u8_s8(a);

	uint8x8_t a_sliced_0_4;
	uint8x8_t a_sliced_1_5;
	uint8x8_t a_sliced_2_6;
	uint8x8_t a_sliced_3_7;
	uint8x16_t a_pre_sliced_0_4;
	uint8x16_t a_pre_sliced_1_5;
	uint8x16_t a_pre_sliced_2_6;
	uint8x16_t a_pre_sliced_3_7;
	if ((imm8 >> 2) & 1) {
		a_pre_sliced_0_4 = vextq_u8(ua, ua, 4);
		a_pre_sliced_1_5 = vextq_u8(ua, ua, 5);
		a_pre_sliced_2_6 = vextq_u8(ua, ua, 6);
		a_pre_sliced_3_7 = vextq_u8(ua, ua, 7);
		a_sliced_0_4 = vget_low_u8(a_pre_sliced_0_4);
	} else {
		a_pre_sliced_1_5 = vextq_u8(ua, ua, 1);
		a_pre_sliced_2_6 = vextq_u8(ua, ua, 2);
		a_pre_sliced_3_7 = vextq_u8(ua, ua, 3);
		a_sliced_0_4 = vget_low_u8(ua);
	}
	a_sliced_1_5 = vget_low_u8(a_pre_sliced_1_5);
	a_sliced_2_6 = vget_low_u8(a_pre_sliced_2_6);
	a_sliced_3_7 = vget_low_u8(a_pre_sliced_3_7);

	uint32x4_t b32 = vreinterpretq_u32_s8(b);
	uint8x8_t b_slicedx2;
	switch (imm8 & 0x03) {
		case 0:
			b_slicedx2 = vreinterpret_u8_u32(vdup_n_u32(vgetq_lane_u32(b32, 0)));
			break;
		case 1:
			b_slicedx2 = vreinterpret_u8_u32(vdup_n_u32(vgetq_lane_u32(b32, 1)));
			break;
		case 2:
			b_slicedx2 = vreinterpret_u8_u32(vdup_n_u32(vgetq_lane_u32(b32, 2)));
			break;
		case 3:
			b_slicedx2 = vreinterpret_u8_u32(vdup_n_u32(vgetq_lane_u32(b32, 3)));
			break;
	}

	uint16x8_t abs_diffs_0_4 = vabdl_u8(a_sliced_0_4, b_slicedx2);
	uint16x8_t abs_diffs_1_5 = vabdl_u8(a_sliced_1_5, b_slicedx2);
	uint16x8_t abs_diffs_2_6 = vabdl_u8(a_sliced_2_6, b_slicedx2);
	uint16x8_t abs_diffs_3_7 = vabdl_u8(a_sliced_3_7, b_slicedx2);

	uint16x8_t abs_diffs_0_4_2_6 = vpaddq_u16(abs_diffs_0_4, abs_diffs_2_6);
	uint16x8_t abs_diffs_1_5_3_7 = vpaddq_u16(abs_diffs_1_5, abs_diffs_3_7);

	uint32x4_t abs_diffs_0_4_2_6x32 = vreinterpretq_u32_u16(abs_diffs_0_4_2_6);
	uint32x4_t abs_diffs_1_5_3_7x32 = vreinterpretq_u32_u16(abs_diffs_1_5_3_7);
	uint32x4_t abs_diffs_0_1_2_3x32 = vtrn1q_u32(abs_diffs_0_4_2_6x32, abs_diffs_1_5_3_7x32);
	uint32x4_t abs_diffs_4_5_6_7x32 = vtrn2q_u32(abs_diffs_0_4_2_6x32, abs_diffs_1_5_3_7x32);

	uint16x8_t abs_diffs_0_1_2_3 = vreinterpretq_u16_u32(abs_diffs_0_1_2_3x32);
	uint16x8_t abs_diffs_4_5_6_7 = vreinterpretq_u16_u32(abs_diffs_4_5_6_7x32);

	return vreinterpretq_s8_u16(vpaddq_u16(abs_diffs_0_1_2_3, abs_diffs_4_5_6_7));
}


/*****************************************************************************
 * Comparison                                                                *
 *****************************************************************************/

#define _mm_cmpeq_epi64(a, b) (vreinterpretq_s8_u64(vceqq_s64(vreinterpretq_s64_s8(a), vreinterpretq_s64_s8(b))))


/*****************************************************************************
 * Convert                                                                   *
 *****************************************************************************/

#define _mm_cvtepi8_epi16(x) (vreinterpretq_s8_s16(vmovl_s8(vget_low_s8(x))))
#define _mm_cvtepi8_epi32(x) (vreinterpretq_s8_s32(vmovl_s16(vget_low_s16(vmovl_s8(vget_low_s8(x))))))
#define _mm_cvtepi8_epi64(x) \
	(vreinterpretq_s8_s64(vmovl_s32(vget_low_s32(vmovl_s16(vget_low_s16(vmovl_s8(vget_low_s8(x))))))))
#define _mm_cvtepi16_epi32(x) (vreinterpretq_s8_s32(vmovl_s16(vget_low_s16(vreinterpretq_s16_s8(x)))))
#define _mm_cvtepi16_epi64(x) \
	(vreinterpretq_s8_s64(vmovl_s32(vget_low_s32(vmovl_s16(vget_low_s16(vreinterpretq_s16_s8(x)))))))
#define _mm_cvtepi32_epi64(x) (vreinterpretq_s8_s64(vmovl_s32(vget_low_s32(vreinterpretq_s32_s8(x)))))

#define _mm_cvtepu8_epi16(x) (vreinterpretq_s8_u16(vmovl_u8(vget_low_u8(vreinterpretq_u8_s8(x)))))
#define _mm_cvtepu8_epi32(x) (vreinterpretq_s8_u32(vmovl_u16(vget_low_u16(vmovl_u8(vget_low_u8(vreinterpretq_u8_s8(x)))))))
#define _mm_cvtepu8_epi64(x) \
	(vreinterpretq_s8_u64(vmovl_u32(vget_low_u32(vmovl_u16(vget_low_u16(vmovl_u8(vget_low_u8(vreinterpretq_u8_s8(x)))))))))
#define _mm_cvtepu16_epi32(x) (vreinterpretq_s8_u32(vmovl_u16(vget_low_u16(vreinterpretq_u16_s8(x)))))
#define _mm_cvtepu16_epi64(x) \
	(vreinterpretq_s8_u64(vmovl_u32(vget_low_u32(vmovl_u16(vget_low_u16(vreinterpretq_u16_s8(x)))))))
#define _mm_cvtepu32_epi64(x) (vreinterpretq_s8_u64(vmovl_u32(vget_low_u32(vreinterpretq_u32_s8(x)))))


/*****************************************************************************
 * Tests                                                                     *
 *****************************************************************************/

static XSSE_FORCE_INLINE int _mm_test_all_ones(__m128i x)
{
	uint64x2_t x64 = vreinterpretq_u64_s8(x);
	return (vgetq_lane_u64(x64, 0) == ~0ULL) & (vgetq_lane_u64(x64, 1) == ~0ULL);
}
static XSSE_FORCE_INLINE int _mm_test_all_zeros(__m128i mask, __m128i x)
{
	int8x16_t masked = vandq_s8(mask, x);
	uint64x2_t masked64 = vreinterpretq_u64_s8(masked);
	return (vgetq_lane_u64(masked64, 0) == 0) & (vgetq_lane_u64(masked64, 1) == 0);
}
static XSSE_FORCE_INLINE int _mm_test_mix_ones_zeros(__m128i x, __m128i mask)
{
	int8x16_t and = vandq_s8(mask, x);
	uint64x2_t and64 = vreinterpretq_u64_s8(and);
	int has_ones = (vgetq_lane_u64(and64, 0) | vgetq_lane_u64(and64, 1)) != 0;

	int8x16_t andnot = vbicq_s8(mask, x);
	uint64x2_t andnot64 = vreinterpretq_u64_s8(andnot);
	int has_zeros = (vgetq_lane_u64(andnot64, 0) | vgetq_lane_u64(andnot64, 1)) != 0;

	return has_ones & has_zeros;
}
static XSSE_FORCE_INLINE int _mm_testc_si128(__m128i a, __m128i b)
{
	int8x16_t andnot = vbicq_s8(b, a);
	uint64x2_t andnot64 = vreinterpretq_u64_s8(andnot);
	return (vgetq_lane_u64(andnot64, 0) == 0) & (vgetq_lane_u64(andnot64, 1) == 0);
}
#define _mm_testnzc_si128(a, b) _mm_test_mix_ones_zeros(a, b)
#define _mm_testz_si128(a, b) _mm_test_all_zeros(a, b)


/*****************************************************************************
 * Others                                                                    *
 *****************************************************************************/

#define _mm_packus_epi32(a, b) \
	(vreinterpretq_s8_u16(vcombine_u16(vqmovun_s32(vreinterpretq_s32_s8(a)), vqmovun_s32(vreinterpretq_s32_s8(b)))))

#define _mm_extract_epi8(x, imm) (vgetq_lane_s8((x), (imm)))
#define _mm_extract_epi32(x, imm) (vgetq_lane_s32(vreinterpretq_s32_s8(x), (imm)))
#define _mm_extract_epi64(x, imm) (vgetq_lane_s64(vreinterpretq_s64_s8(x), (imm)))

#define _mm_insert_epi8(x, val, imm) (vsetq_lane_s8((int8_t) (val), (x), (imm)))
#define _mm_insert_epi32(x, val, imm) (vreinterpretq_s8_s32(vsetq_lane_s32((int32_t) (val), vreinterpretq_s32_s8(x), (imm))))
#define _mm_insert_epi64(x, val, imm) (vreinterpretq_s8_s64(vsetq_lane_s64((int64_t) (val), vreinterpretq_s64_s8(x), (imm))))

#define _mm_blend_epi16(a, b, imm8) \
	(vreinterpretq_s8_s16(vbslq_s16( \
		(uint16x8_t){ \
			(imm8 & (1 << 0)) ? 0xFFFF : 0x0000, \
			(imm8 & (1 << 1)) ? 0xFFFF : 0x0000, \
			(imm8 & (1 << 2)) ? 0xFFFF : 0x0000, \
			(imm8 & (1 << 3)) ? 0xFFFF : 0x0000, \
			(imm8 & (1 << 4)) ? 0xFFFF : 0x0000, \
			(imm8 & (1 << 5)) ? 0xFFFF : 0x0000, \
			(imm8 & (1 << 6)) ? 0xFFFF : 0x0000, \
			(imm8 & (1 << 7)) ? 0xFFFF : 0x0000 \
		}, \
		vreinterpretq_s16_s8(b), \
		vreinterpretq_s16_s8(a) \
	)))
static XSSE_FORCE_INLINE __m128i _mm_blendv_epi8(__m128i a, __m128i b, __m128i mask)
{
	uint8x16_t umask = vreinterpretq_u8_s8(mask);
	uint8x16_t repeat_0x80 = vdupq_n_u8(0x80);
	uint8x16_t mask_fill = vcgeq_u8(umask, repeat_0x80);
	return 	vbslq_s8(mask_fill, b, a);
}


#endif /* SSE4_1 */

#endif /* XSSE_H */
