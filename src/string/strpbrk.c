/*
** Created by doom on 06/10/18.
*/

#include <limits.h>
#include <string.h>

char *strpbrk(const char *s, const char *accept)
{
    unsigned char values[1 << CHAR_BIT] = {0};

    while (*accept)
        values[(unsigned char)*accept++] = 1;

    while (*s) {
        if (values[(unsigned char)*s] == 1)
            return (char *)s;
        ++s;
    }
    return NULL;
}
