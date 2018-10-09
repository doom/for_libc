/*
** Created by doom on 10/09/18.
*/

#include <ut_config.h>

#include <limits.h>
#include <stdint.h>

#define bitsizeof(x)    (sizeof(x) * CHAR_BIT)

ut_test(types)
{
    ut_assert_eq(bitsizeof(int8_t), 8u);
    ut_assert_eq(bitsizeof(int16_t), 16u);
    ut_assert_eq(bitsizeof(int32_t), 32u);
    ut_assert_eq(bitsizeof(int64_t), 64u);

    ut_assert_eq(bitsizeof(uint8_t), 8u);
    ut_assert_eq(bitsizeof(uint16_t), 16u);
    ut_assert_eq(bitsizeof(uint32_t), 32u);
    ut_assert_eq(bitsizeof(uint64_t), 64u);

    int var;
    const int *ptr = &var;
    ut_assert_eq(ptr, (const int *)(uintptr_t)(ptr));
    ut_assert_eq(ptr, (const int *)(intptr_t)(ptr));
}

ut_group(stdint,
         ut_get_test(types)
);

void run_stdint_tests(void)
{
    ut_run_group(ut_get_group(stdint));
}
