/*
** Created by doom on 09/09/18.
*/

#include "../lib/ut/include/ut_config.h"

#include <x86_64/_types/_uint8_t.h>
#include <x86_64/_types/_uint16_t.h>
#include <x86_64/_types/_uint32_t.h>
#include <x86_64/_types/_uint64_t.h>
#include <x86_64/_types/_uintptr_t.h>
#include <x86_64/_types/_int8_t.h>
#include <x86_64/_types/_int16_t.h>
#include <x86_64/_types/_int32_t.h>
#include <x86_64/_types/_int64_t.h>
#include <x86_64/_types/_intptr_t.h>

#define is_unsigned(type_t)     (((type_t)-1) > (type_t)0)
#define is_signed(type_t)       (!is_unsigned(type_t))

ut_test(types)
{
    ut_assert(is_unsigned(uint8_t));
    ut_assert(is_unsigned(uint16_t));
    ut_assert(is_unsigned(uint32_t));
    ut_assert(is_unsigned(uint64_t));
    ut_assert(is_unsigned(uintptr_t));
    ut_assert(is_signed(int8_t));
    ut_assert(is_signed(int16_t));
    ut_assert(is_signed(int32_t));
    ut_assert(is_signed(int64_t));
    ut_assert(is_signed(intptr_t));
}

ut_group(x86_64,
         ut_get_test(types)
);

void run_x86_64_tests(void)
{
    ut_run_group(ut_get_group(x86_64));
}
