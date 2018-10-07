/*
** Created by doom on 06/10/18.
*/

#include <limits.h>
#include <string.h>

size_t strcspn(const char *s, const char *reject)
{
    unsigned char values[1 << CHAR_BIT] = {0};
    const char *save = s;

    /** We build a tiny lookup table with each possible value in reject */
    while (*reject)
        values[(unsigned char)*reject++] = 1;

    while (*s) {
        if (values[(unsigned char)*s] == 1)
            break;
        ++s;
    }
    return s - save;
}
