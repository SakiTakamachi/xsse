# XSSE

[![Push](https://github.com/SakiTakamachi/xsse/actions/workflows/push.yml/badge.svg)](https://github.com/SakiTakamachi/xsse/actions/workflows/push.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

XSSE is a C header-only library consisting of macros and inline functions that allow SSE2 instructions to be used in ARM NEON environments.
It supports both x86_64 (SSE2) and ARM NEON, enabling developers to write portable SIMD code without worrying about platform differences.

- Floating-point operations, SSE3 and SSE4 instructions are currently not supported.

- Support for older APIs that rely on `_m64` is not provided.

- Functions that are difficult to replicate in NEON, such as `_mm_stream_si128`, are substituted with regular store instructions.

Recommended: C99 or later

## Installation

No special installation is required.
Simply add `xsse.h` from the repository to your project.

```
#include "xsse.h"
```

## Usage

You can write NEON code just like SSE2, using familiar instructions.

```
#include "xsse.h"

#ifdef XSSE2
__m128i a = _mm_set1_epi32(42);
__m128i b = _mm_set1_epi32(10);
__m128i c = _mm_add_epi32(a, b);
#endif
```

When SSE2 or NEON is available, the `XSSE2` macro is automatically defined, enabling platform-aware conditional builds.
