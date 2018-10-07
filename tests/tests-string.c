/*
** Created by doom on 10/09/18.
*/

#include <test_helpers/ut_config.h>

#include <string.h>

ut_test(strcmp)
{
    ut_assert_eq(strcmp("lalala", "lalala"), 0);
    ut_assert_gt(strcmp("lalbla", "lalala"), 0);
    ut_assert_lt(strcmp("lalala", "lalalal"), 0);
    ut_assert_gt(strcmp("lalala", ""), 0);
    ut_assert_lt(strcmp("", "lalala"), 0);
    ut_assert_eq(strcmp("", ""), 0);
}

ut_test(strncmp)
{
    ut_assert_gt(strncmp("lalbla", "lalala", 200), 0);
    ut_assert_lt(strncmp("lalala", "lalalal", 200), 0);
    ut_assert_gt(strncmp("lalala", "", 200), 0);
    ut_assert_lt(strncmp("", "lalala", 200), 0);
    ut_assert_eq(strncmp("", "", 200), 0);

    ut_assert_eq(strncmp("lalala", "lalalal", 6), 0);
    ut_assert_lt(strncmp("lalala", "lalalal", 7), 0);

    ut_assert_eq(strncmp("a", "b", 0), 0);
}

ut_test(strchr)
{
    const char *str = "abcdefghijklmnopqrstuvwxyz";
    const char *ptr = str;

    while (*ptr) {
        const char *ptr2 = ptr;
        while (*ptr2) {
            ut_assert_eq(strchr(ptr, *ptr2), ptr2);
            ++ptr2;
        }
        ut_assert_eq(strchr(ptr, '\0'), ptr2);
        ut_assert_eq(strchr(ptr, '_'), NULL);
        ++ptr;
    }
}

ut_test(strrchr)
{
    const char *str = "Hellohellohellohello";

    ut_assert_eq(strrchr(str, 'o'), str + 19);
    ut_assert_eq(strrchr(str, 'l'), str + 18);
    ut_assert_eq(strrchr(str, 'H'), str);
    ut_assert_eq(strrchr(str, 'O'), NULL);
}

ut_test(strstr)
{
    const char *str = "abcdefghijklmnopqrstuvwxyz";
    const char *ptr = str;

    while (*ptr) {
        const char *ptr2 = str;
        while (*ptr2) {
            if (ptr2 < ptr) {
                ut_assert_eq(strstr(ptr, ptr2), NULL);
            } else {
                ut_assert_eq(strstr(ptr, ptr2), ptr2);
            }
            ++ptr2;
        }
        ut_assert_eq(strstr(ptr, ""), ptr);
        ut_assert_eq(strstr(ptr, "_"), NULL);
        ++ptr;
    }
    ut_assert_eq(strstr("lala", "lalala"), NULL);
    str = "lalalalalalalab";
    ut_assert_eq(strstr(str, "ab"), str + 13);
}


ut_test(strlen)
{
    const char s[] = "abcdefghijklmn";
    const char *ptr = s;

    ut_assert_eq(strlen(ptr), 14);
    ut_assert_eq(strlen(ptr + 1), 13);
    ut_assert_eq(strlen(ptr + 2), 12);
    ut_assert_eq(strlen(ptr + 3), 11);
    ut_assert_eq(strlen(ptr + 4), 10);
    ut_assert_eq(strlen(ptr + 5), 9);
    ut_assert_eq(strlen(ptr + 6), 8);
    ut_assert_eq(strlen(ptr + 7), 7);
    ut_assert_eq(strlen(ptr + 8), 6);
    ut_assert_eq(strlen(ptr + 14), 0);
}

ut_test(strnlen)
{
    ut_assert_eq(strnlen("lalala", 200), 6);
    ut_assert_eq(strnlen("lalala", 7), 6);
    ut_assert_eq(strnlen("lalala", 6), 6);
    ut_assert_eq(strnlen("lalala", 5), 5);
    ut_assert_eq(strnlen("lalala", 0), 0);
    ut_assert_eq(strnlen("lalala", 1), 1);
    ut_assert_eq(strnlen("", 20), 0);
    ut_assert_eq(strnlen("", 0), 0);
}

ut_test(strcpy)
{
    char s[15];
    char *ptr;

    ut_assert_eq(strcpy(s, ""), s);
    ut_assert_eq(s[0], '\0');

    ptr = s + 2;
    ut_assert_eq(strcpy(ptr, "Lala"), ptr);
    ut_assert_eq(ptr[0], 'L');
    ut_assert_eq(ptr[1], 'a');
    ut_assert_eq(ptr[2], 'l');
    ut_assert_eq(ptr[3], 'a');
    ut_assert_eq(ptr[4], '\0');
}

ut_test(strncpy)
{
    char s[15];

    ut_assert_eq(strncpy(s, "", 3), s);
    ut_assert_eq(s[0], '\0');
    ut_assert_eq(s[1], '\0');
    ut_assert_eq(s[2], '\0');

    s[5] = '.';
    ut_assert_eq(strncpy(s, "hello", 5), s);
    ut_assert_eq(s[0], 'h');
    ut_assert_eq(s[1], 'e');
    ut_assert_eq(s[2], 'l');
    ut_assert_eq(s[3], 'l');
    ut_assert_eq(s[4], 'o');
    ut_assert_eq(s[5], '.');
}

ut_test(stpcpy)
{
    char s[15];
    char *ptr;

    ut_assert_eq(stpcpy(s, ""), s);
    ut_assert_eq(s[0], '\0');

    ptr = s + 2;
    ut_assert_eq(stpcpy(ptr, "Lala"), ptr + 4);
    ut_assert_eq(ptr[0], 'L');
    ut_assert_eq(ptr[1], 'a');
    ut_assert_eq(ptr[2], 'l');
    ut_assert_eq(ptr[3], 'a');
    ut_assert_eq(ptr[4], '\0');
}

ut_test(strcat)
{
    char s[20] = "";

    ut_assert_eq(strcat(s, "lala"), s);
    ut_assert_eq(s[0], 'l');
    ut_assert_eq(s[1], 'a');
    ut_assert_eq(s[2], 'l');
    ut_assert_eq(s[3], 'a');
    ut_assert_eq(s[4], '\0');

    ut_assert_eq(strcat(s, "lala"), s);
    ut_assert_eq(s[0], 'l');
    ut_assert_eq(s[1], 'a');
    ut_assert_eq(s[2], 'l');
    ut_assert_eq(s[3], 'a');
    ut_assert_eq(s[4], 'l');
    ut_assert_eq(s[5], 'a');
    ut_assert_eq(s[6], 'l');
    ut_assert_eq(s[7], 'a');
    ut_assert_eq(s[8], '\0');
}

ut_test(strncat)
{
    char s[20] = "";

    ut_assert_eq(strncat(s, "lala", 2), s);
    ut_assert_eq(s[0], 'l');
    ut_assert_eq(s[1], 'a');
    ut_assert_eq(s[2], '\0');

    ut_assert_eq(strncat(s, "lala", 6), s);
    ut_assert_eq(s[0], 'l');
    ut_assert_eq(s[1], 'a');
    ut_assert_eq(s[2], 'l');
    ut_assert_eq(s[3], 'a');
    ut_assert_eq(s[4], 'l');
    ut_assert_eq(s[5], 'a');
    ut_assert_eq(s[6], '\0');
}

ut_test(strspn)
{
    ut_assert_eq(strspn("1234abc213", "0123456789"), 4);
    ut_assert_eq(strspn("1234abc213", "abc"), 0);
    ut_assert_eq(strspn("", ""), 0);
    ut_assert_eq(strspn("", "azerty"), 0);
    ut_assert_eq(strspn("azerty", ""), 0);
}

ut_test(strcspn)
{
    ut_assert_eq(strcspn("1234abc213", "abcdef"), 4);
    ut_assert_eq(strcspn("1234abc213", ""), 10);
    ut_assert_eq(strcspn("1234abc213", "zzzzzv"), 10);
    ut_assert_eq(strcspn("1234abc213", "1234"), 0);
    ut_assert_eq(strcspn("", ""), 0);
    ut_assert_eq(strcspn("", "azerty"), 0);
}

ut_test(strpbrk)
{
    const char *str = "1234abc2135";

    ut_assert_eq(strpbrk(str, "0123456789"), str);
    ut_assert_eq(strpbrk(str, "abc"), str + 4);
    ut_assert_eq(strpbrk(str, "()"), NULL);
    ut_assert_eq(strpbrk(str, "5"), str + 10);

    ut_assert_eq(strpbrk("", ""), NULL);
    ut_assert_eq(strpbrk("", "azer"), NULL);
}

ut_test(memcmp)
{
    ut_assert_lt(memcmp("abcde", "abcdz", 5), 0);
    ut_assert_eq(memcmp("abcde", "abcdz", 4), 0);
    ut_assert_eq(memcmp("abcde", "edcba", 0), 0);
    ut_assert_gt(memcmp("edcba", "abcde", 1), 0);
}

ut_test(memchr)
{
    const char s[] = "abcdefghi";

    ut_assert_eq(memchr(s, 'j', 9), NULL);
    ut_assert_eq(memchr(s, 'c', 9), s + 2);
    ut_assert_eq(memchr(s, 'c', 2), NULL);
    ut_assert_eq(memchr(s, 'a', 0), NULL);
    ut_assert_eq(memchr(s, 'i', 9), s + 8);
}

ut_test(memcpy)
{
    char s[] = "...........";

    ut_assert_eq(memcpy(s, "abcde", 5), s);
    ut_assert_eq(s[4], 'e');
    ut_assert_eq(s[5], '.');

    ut_assert_eq(memcpy(s + 5, "abcde", 5), s + 5);
    ut_assert_eq(s[4], 'e');
    ut_assert_eq(s[9], 'e');
    ut_assert_eq(s[10], '.');
}

ut_test(mempcpy)
{
    char s[] = "...........";

    ut_assert_eq(mempcpy(s, "abcde", 5), s + 5);
    ut_assert_eq(s[4], 'e');
    ut_assert_eq(s[5], '.');

    ut_assert_eq(mempcpy(s + 5, "abcde", 5), s + 10);
    ut_assert_eq(s[4], 'e');
    ut_assert_eq(s[9], 'e');
    ut_assert_eq(s[10], '.');
}

ut_test(memmove)
{
    char s[] = "....abcde";

    ut_assert_eq(memmove(s, s + 4, 5), s);
    ut_assert_eq(s[0], 'a');
    ut_assert_eq(s[4], 'e');
    ut_assert_eq(s[5], 'b');

    ut_assert_eq(memmove(s + 4, s, 5), s + 4);
    ut_assert_eq(s[4], 'a');
}

ut_test(memset)
{
    char s[] = {0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7};
    char *ptr;

    ut_assert_eq(memset(s, 1, 4), s);
    ut_assert_eq(s[0], 1);
    ut_assert_eq(s[1], 1);
    ut_assert_eq(s[2], 1);
    ut_assert_eq(s[3], 1);
    ut_assert_eq(s[4], 0);

    ptr = s + 2;
    ut_assert_eq(memset(ptr, 2, 4), ptr);
    ut_assert_eq(ptr[0], 2);
    ut_assert_eq(ptr[1], 2);
    ut_assert_eq(ptr[2], 2);
    ut_assert_eq(ptr[3], 2);
    ut_assert_eq(ptr[-1], 1);
    ut_assert_eq(ptr[4], 0);

    for (int i = 0; i < 4; ++i) {
        ptr = s + i;
        ut_assert_eq(memset(ptr, i, 8), ptr);
        ut_assert_eq(ptr[0], i);
        ut_assert_eq(ptr[1], i);
        ut_assert_eq(ptr[2], i);
        ut_assert_eq(ptr[3], i);
        ut_assert_eq(ptr[4], i);
        ut_assert_eq(ptr[5], i);
        ut_assert_eq(ptr[6], i);
        ut_assert_eq(ptr[7], i);
        ut_assert_eq(ptr[8], 7);
    }

    ut_assert_eq(memset(NULL, '\0', 0), NULL);
}

ut_group(string,
         ut_get_test(strcmp),
         ut_get_test(strncmp),
         ut_get_test(strchr),
         ut_get_test(strrchr),
         ut_get_test(strstr),
         ut_get_test(strlen),
         ut_get_test(strnlen),
         ut_get_test(strcpy),
         ut_get_test(strncpy),
         ut_get_test(stpcpy),
         ut_get_test(strcat),
         ut_get_test(strncat),
         ut_get_test(strspn),
         ut_get_test(strcspn),
         ut_get_test(strpbrk),
         ut_get_test(memcmp),
         ut_get_test(memchr),
         ut_get_test(memcpy),
         ut_get_test(mempcpy),
         ut_get_test(memmove),
         ut_get_test(memset),
);

void run_string_tests(void)
{
    ut_run_group(ut_get_group(string));
}
