/*
** Created by doom on 15/09/18.
*/

#include <ut_config.h>

#include <strings.h>

ut_test(strcasecmp)
{
    ut_assert_eq(strcasecmp("lalala", "lalala"), 0);
    ut_assert_gt(strcasecmp("lalbla", "lalala"), 0);
    ut_assert_lt(strcasecmp("lalala", "lalalal"), 0);
    ut_assert_gt(strcasecmp("lalala", ""), 0);
    ut_assert_lt(strcasecmp("", "lalala"), 0);
    ut_assert_eq(strcasecmp("", ""), 0);

    ut_assert_eq(strcasecmp("lalAla", "lalala"), 0);
    ut_assert_eq(strcasecmp("A", "a"), 0);
}

ut_test(strncasecmp)
{
    ut_assert_gt(strncasecmp("lalbla", "lalala", 200), 0);
    ut_assert_lt(strncasecmp("lalala", "lalalal", 200), 0);
    ut_assert_gt(strncasecmp("lalala", "", 200), 0);
    ut_assert_lt(strncasecmp("", "lalala", 200), 0);
    ut_assert_eq(strncasecmp("", "", 200), 0);

    ut_assert_eq(strncasecmp("lalala", "lalalal", 6), 0);
    ut_assert_lt(strncasecmp("lalala", "lalalal", 7), 0);

    ut_assert_eq(strncasecmp("a", "b", 0), 0);

    ut_assert_eq(strncasecmp("lalAla", "lalala", 8), 0);
    ut_assert_eq(strncasecmp("A", "a", 1), 0);
}


ut_group(strings,
         ut_get_test(strcasecmp),
         ut_get_test(strncasecmp)
);

void run_strings_tests(void)
{
    ut_run_group(ut_get_group(strings));
}
