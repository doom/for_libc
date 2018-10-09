/*
** Created by doom on 09/09/18.
*/

#ifndef FOR_LIBC_UT_CONFIG_H
#define FOR_LIBC_UT_CONFIG_H

#include "ut_utils.h"

int ut_printf_impl(const char *fmt, ...);

#define ut_printf(fmt, ...)         ut_printf_impl(fmt, ##__VA_ARGS__)

#define PRINT_RED                   "\033[31m"
#define PRINT_GREEN                 "\033[32m"
#define PRINT_CYAN                  "\033[36m"
#define PRINT_WHITE                 "\033[0m"

#define ut_set_color(color)         ut_printf(PRINT_##color)

#define ut_on_fail(x)                                                       \
    do {                                                                    \
        ut_printf("Test failed, exiting.\n");                               \
        ut_exit(1);                                                         \
    } while (0)

#include "ut_tests.h"

#endif /* !FOR_LIBC_UT_CONFIG_H */
