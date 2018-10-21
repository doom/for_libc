/*
** Created by doom on 09/09/18.
*/

#ifndef FOR_LIBC_TESTS_H
#define FOR_LIBC_TESTS_H

#ifndef ut_printf
#define ut_printf(x, ...)   0
#endif

#ifndef ut_set_color
#define ut_set_color(x)
#endif

#ifndef ut_on_fail
#define ut_on_fail(x)
#endif

#define __ut_unused__               __attribute__((unused))

#define ut_sizeof_array(x)          (sizeof(x) / sizeof((x)[0]))

#define __ut_STR2(x)                #x
#define __ut_STR(x)                 __ut_STR2(x)

#ifdef __FILENAME__
#define __ut_FILE                   __ut_STR(__FILENAME__)
#else
#define __ut_FILE                   __FILE__
#endif

#define __ut_LINE                   __ut_STR(__LINE__)

typedef struct ut_test_s
{
    const char *name;
    void (*run)(struct ut_test_s *);
    unsigned int passed;
    unsigned int err;
} ut_test_t;

typedef struct
{
    const char *name;
    unsigned int nbtests;
    ut_test_t *const *tests;
} ut_group_t;

#define __ut_testimpl(name)         __testimpl_##name
#define __ut_testname(name)         __test_##name

#define ut_test(name)                                                       \
    static void __ut_testimpl(name)(ut_test_t *);                           \
                                                                            \
    static __ut_unused__ ut_test_t __ut_testname(name) = {                  \
        #name,                                                              \
        &__ut_testimpl(name),                                               \
        0, 0,                                                               \
    };                                                                      \
                                                                            \
    static void __ut_testimpl(name)(__ut_unused__ ut_test_t *__test)

#define ut_get_test(name)           (&__ut_testname(name))

#define ut_run_test(t)                                                      \
    (t)->passed = 0;                                                        \
    (t)->err = 0;                                                           \
    (t)->run(t);

#define __ut_test_failed(msg)                                               \
    __test->err += 1;                                                       \
    ut_set_color(RED);                                                      \
    ut_printf("\nfailure: ");                                               \
    ut_set_color(WHITE);                                                    \
    ut_printf("%14s", __ut_FILE ":" __ut_LINE ": expected " msg "\n");      \
    return;

#define __ut_test_passed()                                                  \
    __test->passed += 1;

#define __ut_test_failed_if(cond, errmsg)                                   \
    if (cond) {                                                             \
        __ut_test_failed(errmsg);                                           \
    } else {                                                                \
        __ut_test_passed();                                                 \
    }

#define __ut_assert_rel(a, rel, b, err)                                     \
    __ut_test_failed_if(!((a) rel (b)), #a " " #rel " " #b);

#define ut_assert(x)                                                        \
    __ut_test_failed_if(!(x), #x " to be true");

#define ut_assert_false(x)                                                  \
    __ut_test_failed_if(x, #x " to be false");

#define ut_assert_eq(a, b)                                                  \
    __ut_assert_rel(a, ==, b, " to be equal to ")

#define ut_assert_streq(a, b)                                               \
    __ut_assert_rel(strcmp(a, b), ==, 0, " to be equal to ")

#define ut_assert_memeq(a, b, sz)                                           \
    __ut_assert_rel(memcmp(a, b, sz), ==, 0, " to be equal to ")

#define ut_assert_ne(a, b)                                                  \
    __ut_assert_rel(a, !=, b, " to be different from ")

#define ut_assert_gt(a, b)                                                  \
    __ut_assert_rel(a, >, b, " to be greater than ")

#define ut_assert_ge(a, b)                                                  \
    __ut_assert_rel(a, >=, b, " to be greater or equal than ")

#define ut_assert_lt(a, b)                                                  \
    __ut_assert_rel(a, <, b, " to be less than ")

#define ut_assert_le(a, b)                                                  \
    __ut_assert_rel(a, <=, b, " to be lesser than or equal to ")

#define ut_assert_throw(expr, ex)                                           \
    ({                                                                      \
        bool __did_throw = false;                                           \
        try {                                                               \
            expr;                                                           \
        } catch (const ex &) {                                              \
            __did_throw = true;                                             \
        } catch (...) {                                                     \
                                                                            \
        }                                                                   \
        __ut_test_failed_if(!__did_throw, #expr " to throw " #ex);          \
    })

#define __ut_groupname(name)        __group_##name

#define ut_declare_group(name)      extern ut_group_t __ut_groupname(name);

#define ut_group(name, ...)                                                 \
    ut_test_t *const name##_tests_array[] = {__VA_ARGS__};                  \
                                                                            \
    const ut_group_t __ut_groupname(name) = {                               \
        #name,                                                              \
        ut_sizeof_array(name##_tests_array),                                \
        name##_tests_array,                                                 \
    }

#define ut_get_group(name)          (&__ut_groupname(name))

#define ut_run_group(g)                                                     \
    ({                                                                      \
        int __n = ut_printf("Running group: ");                             \
                                                                            \
        ut_set_color(CYAN);                                                 \
        __n += ut_printf("%s", (g)->name);                                  \
        ut_set_color(WHITE);                                                \
        for (unsigned int __i = 0; __i < (g)->nbtests; ++__i) {             \
            ut_run_test((g)->tests[__i]);                                   \
            if ((g)->tests[__i]->err != 0) {                                \
                ut_on_fail("Test failed\n");                                \
            }                                                               \
        }                                                                   \
        ut_printf("%*s", 80 - 4 - __n, "[");                                \
        ut_set_color(GREEN);                                                \
        ut_printf("OK");                                                    \
        ut_set_color(WHITE);                                                \
        ut_printf("]\n");                                                   \
    })

#endif /* !FOR_LIBC_TESTS_H */
