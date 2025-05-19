cmake_minimum_required(VERSION 3.10)
project(xsse_tests C)

set(CMAKE_C_STANDARD 99)

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64|arm64)")
        link_directories("/opt/homebrew/lib")
    endif()
    include_directories("/opt/homebrew/include")
endif()

enable_testing()
add_subdirectory(tests)
