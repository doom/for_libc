/*
** Created by doom on 10/09/18.
*/

#include <test_helpers/ut_config.h>

#include <stddef.h>

ut_test(null)
{
    ut_assert_false(NULL);
}

struct offsetof_test
{
    int a;
    char b;
    char c;
};

ut_test(offsetof)
{
    ut_assert_eq(offsetof(struct offsetof_test, a), 0u);
    ut_assert_eq(offsetof(struct offsetof_test, b), sizeof(int));
    ut_assert_eq(offsetof(struct offsetof_test, c), sizeof(int) + 1);
}

ut_group(stddef,
         ut_get_test(null),
         ut_get_test(offsetof)
);

void run_stddef_tests(void)
{
    ut_run_group(ut_get_group(stddef));
}
