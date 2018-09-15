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
        include/stdbool.h
        include/stddef.h
        include/stdint.h

        include/stdlib.h

        include/string.h
        src/string/strcmp.c
        src/string/strncmp.c
        src/string/strlen.c
        src/string/strnlen.c
        src/string/strcpy.c
        src/string/strncpy.c
        src/string/stpcpy.c
        src/string/strcat.c
        src/string/strncat.c
        src/string/memcmp.c
        src/string/memcpy.c
        src/string/memchr.c
        src/string/mempcpy.c
        src/string/memmove.c
        src/string/memset.c

        include/ctype.h
        src/ctype/ctype.c
        )

add_library(for_libc SHARED ${LIB_SOURCES})
add_library(for_libc-static STATIC ${LIB_SOURCES})

target_include_directories(for_libc SYSTEM PUBLIC include include/x86_64)
target_include_directories(for_libc-static SYSTEM PUBLIC include include/x86_64)

add_executable(for_libc-tests
        tests/test_helpers/ut_utils.c
        tests/test_helpers/start.c
        tests/test_helpers/ut_assert.h
        tests/test_helpers/ut_utils.h
        tests/test_helpers/ut_tests.h
        tests/test_helpers/ut_config.h
        tests/tests-main.c
        tests/tests-x86_64.c
        tests/tests-limits.c
        tests/tests-stddef.c
        tests/tests-stdint.c
        tests/tests-string.c
        tests/tests-ctype.c
        )

target_include_directories(for_libc-tests SYSTEM PUBLIC include include/x86_64 tests)
target_link_libraries(for_libc-tests for_libc-static)
