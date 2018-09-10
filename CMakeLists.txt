cmake_minimum_required(VERSION 3.9)

project(for_libc)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Wextra -nostdlib -nostdinc -fno-builtin")

set(LIB_SOURCES
        include/x86_64/_types/_ptrdiff_t.h
        include/x86_64/_types/_max_align_t.h
        include/x86_64/_types/_int8_t.h include/x86_64/_types/_int16_t.h
        include/x86_64/_types/_int32_t.h include/x86_64/_types/_int64_t.h
        include/x86_64/_types/_uint8_t.h include/x86_64/_types/_uint16_t.h
        include/x86_64/_types/_uint32_t.h include/x86_64/_types/_uint64_t.h
        include/x86_64/_types/_intptr_t.h include/x86_64/_types/_uintptr_t.h
        include/x86_64/_types/_ssize_t.h include/x86_64/_types/_size_t.h
        include/x86_64/_endian.h include/x86_64/_limits.h

        include/limits.h
        include/endian.h
        )

add_executable(for_libc-tests
        ${LIB_SOURCES}
        tests/test_helpers/ut_utils.c
        tests/test_helpers/start.c
        tests/test_helpers/ut_assert.h
        tests/test_helpers/ut_utils.h
        tests/test_helpers/ut_tests.h
        tests/test_helpers/ut_config.h
        tests/tests-main.c
        tests/tests-x86_64.c
        tests/tests-limits.c
        )

target_include_directories(for_libc-tests SYSTEM PUBLIC include include/x86_64 tests)
