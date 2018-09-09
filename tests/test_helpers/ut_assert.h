/*
** Created by doom on 09/09/18.
*/

#ifndef FOR_LIBC_UT_ASSERT_H
#define FOR_LIBC_UT_ASSERT_H

#include "ut_utils.h"

#define _ut_fail_msg(x)     "Assertion \"" #x "\" failed\n"

#define ut_assert(x)                                                        \
    do {                                                                    \
        if (!(x)) {                                                         \
            ut_write(1, _ut_fail_msg(x), sizeof(_ut_fail_msg(x)) - 1);      \
            ut_exit(1);                                                     \
        }                                                                   \
    } while(0)                                                              \

#endif /* !FOR_LIBC_UT_ASSERT_H */
