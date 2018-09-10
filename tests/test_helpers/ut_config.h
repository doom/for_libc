/*
** Created by doom on 09/09/18.
*/

#ifndef FOR_LIBC_UT_CONFIG_H
#define FOR_LIBC_UT_CONFIG_H

#include <test_helpers/ut_utils.h>

#define ut_on_fail(x)           ut_write(1, x, sizeof(x) - 1)

#include <test_helpers/ut_tests.h>

#endif /* !FOR_LIBC_UT_CONFIG_H */
