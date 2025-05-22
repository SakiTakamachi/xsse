# XSSE

[![Push](https://github.com/SakiTakamachi/xsse/actions/workflows/push.yml/badge.svg)](https://github.com/SakiTakamachi/xsse/actions/workflows/push.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

XSSE is a C header-only library consisting of macros and inline functions that allow selected SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX, and AVX2 SIMD instructions to be used in ARM NEON environments.
It supports both x86_64 and ARM NEON, enabling developers to write portable SIMD code without worrying about platform differences.
Note: The original SSE (pre-SSE2) is not supported due to its age and limited adoption in modern environments.

- Support for floating-point APIs that rely on `__m128`, `__m128d`, `__m256` or `__m256d` is not provided.

- Support for legacy APIs that rely on `__m64` is not provided.

- Functions that are difficult to replicate in NEON, such as `_mm_stream_si128`, are substituted with regular store instructions.

- APIs like `_mm_clflush`, which cannot be reproduced on NEON, are replaced with no-op macros.

- Some cryptographic APIs are not supported (e.g. `_mm256_sha512msg1_epi64`).

Recommended: C99 or later

## SSE Support Status

### ✅ Supported

- SSE2
- SSE3
- SSSE3
- SSE4.1
- SSE4.2
- AVX
- AVX2

### ❌ Not Supported

- SSE
- AVX512

## Installation

No special installation is required.
Simply add `xsse.h` from the repository to your project.

```c
#include "xsse.h"
```

To use the AVX and AVX2 APIs, make sure to include the following header file.

```c
#include "xsse_avx.h"
```

Since `xsse_avx.h` includes `xsse.h`, you don't need to include both header files.

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

#ifdef XSSE4_2
#endif
```

- ARM:
If a macro like `XSSE4_2` is defined, it guarantees that `XSSE4_1`, `XSSSE3`, `XSSE3`, and `XSSE2` are also defined.

- x86-64:
The corresponding `XSSE*` macros are automatically defined based on the availability of compiler intrinsics such as `__SSE2__`, `__SSE4_1__`, or `__SSE4_2__`.

Similarly, AVX and AVX2 can be used through the following macros.

```c
#ifdef XSSE_AVX
#endif

#ifdef XSSE_AVX2
#endif
```

- ARM:
If `XSSE_AVX2` is defined, `XSSE_AVX` and every other `XSSE_*` will be defined.

- x86-64:
In the same way as the other `XSSE_*` macros, the appropriate `XSSE_AVX*` macro is defined whenever the compiler defines `__AVX__` or `__AVX2__`.
