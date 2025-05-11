cmake_minimum_required(VERSION 3.10)
project(xsse_tests C)

set(CMAKE_C_STANDARD 99)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    add_compile_options(-msse3)
    add_compile_options(-mssse3)
    add_compile_options(-msse4.1)
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64|arm64|arm)")
        link_directories("/opt/homebrew/lib")
    endif()
    include_directories("/opt/homebrew/include")
endif()

enable_testing()
add_subdirectory(tests)
