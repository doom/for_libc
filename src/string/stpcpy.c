/*
** Created by doom on 12/09/18.
*/

#include <string.h>

char *stpcpy(char *dest, const char *src)
{
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}
