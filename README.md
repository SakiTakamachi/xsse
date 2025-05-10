# XSSE

[![Push](https://github.com/SakiTakamachi/xsse/actions/workflows/push.yml/badge.svg)](https://github.com/SakiTakamachi/xsse/actions/workflows/push.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

XSSE is a C header-only library consisting of macros and inline functions that allow selected SSE2 and later SIMD instructions to be used in ARM NEON environments.
It supports both x86_64 (SSE2 and newer) and ARM NEON, enabling developers to write portable SIMD code without worrying about platform differences.
Note: SSE (original) is not supported due to its age and limited adoption in modern environments.

- Support for floating-point APIs that rely on __m128 or __m128d is not provided.

- Support for legacy APIs that rely on _m64 is not provided.

- Functions that are difficult to replicate in NEON, such as `_mm_stream_si128`, are substituted with regular store instructions.

- APIs like `_mm_clflush`, which cannot be reproduced on NEON, are replaced with no-op macros.

Recommended: C99 or later

## SSE Support Status

### ✅ Supported

- SSE2
- SSE3
- SSSE3
- SSE4.1

#### 🚧 Planned Support

- SSE4.2 (planned)

### ❌ Not Supported

- SSE
- AVX
- AVX2

## Installation

No special installation is required.
Simply add `xsse.h` from the repository to your project.

```
#include "xsse.h"
```

## Usage

You can write NEON code just like SSE2, using familiar instructions.

```c
#include "xsse.h"

#ifdef XSSE2
__m128i a = _mm_set1_epi32(42);
__m128i b = _mm_set1_epi32(10);
__m128i c = _mm_add_epi32(a, b);
#endif
```

When SSE2 or NEON is available, the `XSSE2` macro is automatically defined, enabling platform-aware conditional builds.

XSSE also supports selected instructions from SSE3 and SSSE3. For example:

```c
#ifdef XSSE3
#endif

#ifdef XSSSE3
#endif

#ifdef XSSE4_1
#endif
```

On ARM platforms, if a macro like `XSSE4_1` is defined, it guarantees that `XSSSE3`, `XSSE3` and `XSSE2` are also defined.
On x86_64, the corresponding `XSSE*` macros are defined automatically when compiler intrinsics like `__SSE2__`, `__SSE3__`, or `__SSE4_1__` are available.
