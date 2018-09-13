/*
** Created by doom on 12/09/18.
*/

#include <string.h>

void *memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *pdest = dest;
    const unsigned char *psrc = src;

    while (n--) {
        *pdest++ = *psrc++;
    }
    return dest;
}
