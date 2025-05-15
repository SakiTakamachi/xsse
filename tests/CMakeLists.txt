file(GLOB_RECURSE TEST_SRCS CONFIGURE_DEPENDS *.c)

set(TEST_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

foreach(test_src ${TEST_SRCS})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src})

    if (CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
        target_compile_options(${test_name} PRIVATE -Wall -Wextra -O0 -g)
        target_link_libraries(${test_name} PRIVATE cmocka)
    elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
        find_package(cmocka REQUIRED)
        target_compile_options(${test_name} PRIVATE /W4 /Zi)
        target_link_libraries(${test_name} PRIVATE cmocka::cmocka)
    endif()

    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
