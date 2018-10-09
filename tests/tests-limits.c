/*
** Created by doom on 09/09/18.
*/

#include <ut_config.h>

#include <limits.h>

ut_test(min_max)
{
    ut_assert_eq(CHAR_BIT, 8);
    ut_assert_eq(SCHAR_MIN, -128);
    ut_assert_eq(SCHAR_MAX, 127);
    ut_assert_eq(UCHAR_MAX, 255);

    /** TODO: add tests for other limits */
}

ut_group(limits,
         ut_get_test(min_max)
);

void run_limits_tests(void)
{
    ut_run_group(ut_get_group(limits));
}
