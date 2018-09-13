/*
** Created by doom on 12/09/18.
*/

#include <string.h>

void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char *pdest;
    const unsigned char *psrc;

    if (dest < src) {
        pdest = dest;
        psrc = src;
        while (n--) {
            *pdest++ = *psrc++;
        }
    } else {
        pdest = (unsigned char *)dest + n;
        psrc = (const unsigned char *)src + n;
        while (n--) {
            *--pdest = *--psrc;
        }
    }
    return dest;
}
