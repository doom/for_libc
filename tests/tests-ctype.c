/*
** Created by doom on 13/09/18.
*/

#include <test_helpers/ut_config.h>

#include <ctype.h>

ut_test(islower)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(islower(c), 'a' <= c && c <= 'z');
    }
}

ut_test(isupper)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isupper(c), 'A' <= c && c <= 'Z');
    }
}

ut_test(tolower)
{
    const char *lowcase = "abcdefghijklmnopqrstuvwxyz";

    for (int c = 0; c < 128; ++c) {
        if (isupper(c)) {
            ut_assert_eq(tolower(c), lowcase[c - 'A']);
        } else {
            ut_assert_eq(tolower(c), c);
        }
    }
}

ut_test(toupper)
{
    const char *upcase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int c = 0; c < 128; ++c) {
        if (islower(c)) {
            ut_assert_eq(toupper(c), upcase[c - 'a']);
        } else {
            ut_assert_eq(toupper(c), c);
        }
    }
}

ut_test(iscntrl)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(iscntrl(c), c < 32 || c == 127);
    }
}

ut_test(isdigit)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isdigit(c), '0' <= c && c <= '9');
    }
}

ut_test(isalpha)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isalpha(c), ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
    }
}

ut_test(isxdigit)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isxdigit(c), ('0' <= c && c <= '9')
                                  || ('A' <= c && c <= 'F')
                                  || ('a' <= c && c <= 'f'));
    }
}

ut_test(isalnum)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isalnum(c), ('0' <= c && c <= '9')
                                 || ('A' <= c && c <= 'Z')
                                 || ('a' <= c && c <= 'z'));
    }
}

ut_test(isgraph)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isgraph(c), '!' <= c && c <= '~');
    }
}

ut_test(isprint)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isprint(c), ' ' <= c && c <= '~');
    }
}

ut_test(ispunct)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(ispunct(c), ('!' <= c && c <= '~')
                                 && !(('0' <= c && c <= '9')
                                      || ('A' <= c && c <= 'Z')
                                      || ('a' <= c && c <= 'z')));
    }
}

ut_test(isspace)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isspace(c), c == ' ' || c == '\t'
                                 || c == '\n' || c == '\v'
                                 || c == '\f' || c == '\r');
    }
}

ut_test(isblank)
{
    for (int c = 0; c < 128; ++c) {
        ut_assert_eq(isblank(c), c == ' ' || c == '\t');
    }
}

ut_group(ctype,
         ut_get_test(islower),
         ut_get_test(isupper),
         ut_get_test(tolower),
         ut_get_test(toupper),
         ut_get_test(iscntrl),
         ut_get_test(isdigit),
         ut_get_test(isalpha),
         ut_get_test(isxdigit),
         ut_get_test(isalnum),
         ut_get_test(isgraph),
         ut_get_test(isprint),
         ut_get_test(ispunct),
         ut_get_test(isspace)
);

void run_ctype_tests(void)
{
    ut_run_group(ut_get_group(ctype));
}
