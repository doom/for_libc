/*
** Created by doom on 15/03/19.
*/

#include <ut_config.h>

#include <limits.h>
#include <stdlib.h>

ut_test(atoi)
{
    ut_assert_eq(atoi("1"), 1);
    ut_assert_eq(atoi("-1"), -1);
    ut_assert_eq(atoi("0"), 0);
    ut_assert_eq(atoi("123"), 123);
    ut_assert_eq(atoi("-123"), -123);
    ut_assert_eq(atoi("1612"), 1612);
    ut_assert_eq(atoi("      -10"), -10);
#if INT_MAX == 2147483647
    ut_assert_eq(atoi("-2147483648"), INT_MIN);
    ut_assert_eq(atoi("2147483647"), INT_MAX);
#endif
}

ut_test(atol)
{
    ut_assert_eq(atol("1"), 1);
    ut_assert_eq(atol("-1"), -1);
    ut_assert_eq(atol("0"), 0);
    ut_assert_eq(atol("123"), 123);
    ut_assert_eq(atol("-123"), -123);
    ut_assert_eq(atol("1612"), 1612);
    ut_assert_eq(atol("      -10"), -10);
#if LONG_MAX >= 2147483647
    ut_assert_eq(atol("-2147483648"), INT_MIN);
    ut_assert_eq(atol("2147483647"), INT_MAX);
#endif
#if LONG_MAX >= 9223372036854775807
    ut_assert_eq(atol("-9223372036854775808"), LONG_MIN);
    ut_assert_eq(atol("9223372036854775807"), LONG_MAX);
#endif
}

ut_group(stdlib,
         ut_get_test(atoi),
         ut_get_test(atol)
);

void run_stdlib_tests(void)
{
    ut_run_group(ut_get_group(stdlib));
}
