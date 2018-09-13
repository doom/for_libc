/*
** Created by doom on 12/09/18.
*/

#include <string.h>

void *mempcpy(void *dest, const void *src, size_t n)
{
    unsigned char *to = dest;
    const unsigned char *from = src;

    while (n--) {
        *to++ = *from++;
    }
    return to;
}
