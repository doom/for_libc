/*
** Created by doom on 11/09/18.
*/

#include <string.h>

char *strncpy(char *dest, const char *src, size_t n)
{
    char *save = dest;

    while (n && *src) {
        *dest++ = *src++;
        n--;
    }
    while (n--) {
        *dest++ = '\0';
    }
    return save;
}
