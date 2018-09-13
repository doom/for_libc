/*
** Created by doom on 12/09/18.
*/

#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1;
    const unsigned char *p2;

    /** Short-circuiting: if the pointers are equal then so are the bytes */
    if (s1 == s2)
        return 0;

    p1 = s1;
    p2 = s2;
    while (n > 0 && *p1 == *p2) {
        ++p1;
        ++p2;
        --n;
    }
    return n == 0 ? 0 : *p1 - *p2;
}
