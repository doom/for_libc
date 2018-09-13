/*
** Created by doom on 12/09/18.
*/

#include <string.h>

void *memchr(const void *s, int c, size_t n)
{
    const unsigned char *p = s;

    while (n--) {
        if (*p == c)
            return (void *)p;
        ++p;
    }
    return NULL;
}
