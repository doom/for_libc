/*
** Created by doom on 15/09/18.
*/

#include <test_helpers/ut_config.h>

#include <string.h>
#include <stdio.h>
#include <limits.h>

ut_test(sprintf)
{
    char s[4] = {1, 1, 1, 1};
    char buf[100];
    int ret;

    ret = sprintf(s, "%d", 123);
    ut_assert_eq(ret, 3);
    ut_assert_eq(s[0], '1');
    ut_assert_eq(s[1], '2');
    ut_assert_eq(s[2], '3');
    ut_assert_eq(s[3], '\0');

    ret = snprintf(s, 2, "%d", 123);
    ut_assert_eq(ret, 3);
    ut_assert_eq(s[0], '1');
    ut_assert_eq(s[1], '\0');

    ret = sprintf(s, "%+d", 0);
    ut_assert_eq(ret, 2);
    ut_assert_eq(s[0], '+');
    ut_assert_eq(s[1], '0');
    ut_assert_eq(s[2], '\0');

    ret = sprintf(buf, "%.*s", 5, "abcdefghi");
    ut_assert_eq(ret, 5);
    ut_assert_streq("abcde", buf);

    ret = sprintf(buf, "%*.*s", 10, 5, "abcdefghi");
    ut_assert_eq(ret, 10);
    ut_assert_streq("     abcde", buf);

    ret = sprintf(buf, "%-*.*s", 10, 5, "abcdefghi");
    ut_assert_eq(ret, 10);
    ut_assert_streq("abcde     ", buf);

    ret = sprintf(buf, "%010d", 1);
    ut_assert_eq(ret, 10);
    ut_assert_streq("0000000001", buf);

    ret = sprintf(buf, "%d", INT_MIN);
    ut_assert_eq(ret, 11);
    ut_assert_streq("-2147483648", buf);
}

ut_test(snprintf)
{
    char s[8];
    int ret;

    ret = snprintf(NULL, 0, "%d:%d", 123, 456);
    ut_assert_eq(ret, 7);

    ret = snprintf(s, 8, "%d:%d", 123, 456);
    ut_assert_eq(ret, 7);
    ut_assert_eq(s[0], '1');
    ut_assert_eq(s[1], '2');
    ut_assert_eq(s[2], '3');
    ut_assert_eq(s[3], ':');
    ut_assert_eq(s[4], '4');
    ut_assert_eq(s[5], '5');
    ut_assert_eq(s[6], '6');
    ut_assert_eq(s[7], '\0');

    ret = snprintf(s, 8, "%d", 1);
    ut_assert_eq(ret, 1);
    ut_assert_eq(s[0], '1');
    ut_assert_eq(s[1], '\0');
}

ut_group(stdio,
         ut_get_test(sprintf),
         ut_get_test(snprintf)
);

void run_stdio_tests(void)
{
    ut_run_group(ut_get_group(stdio));
}
