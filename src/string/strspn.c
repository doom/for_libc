/*
** Created by doom on 06/10/18.
*/

#include <limits.h>
#include <string.h>

size_t strspn(const char *s, const char *accept)
{
    unsigned char values[1 << CHAR_BIT] = {0};
    const char *save = s;

    /** We build a tiny lookup table with each possible value in reject */
    while (*accept)
        values[(unsigned char)*accept++] = 1;

    while (*s) {
        if (values[(unsigned char)*s] != 1)
            break;
        ++s;
    }
    return s - save;
}
