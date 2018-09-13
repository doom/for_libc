/*
** Created by doom on 10/09/18.
*/

#include <string.h>

int strcmp(const char *s1, const char *s2)
{
    /** Short-circuiting: if the pointers are equal then so are the strings */
    if (s1 == s2)
        return 0;

    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
