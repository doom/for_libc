/*
** Created by doom on 11/09/18.
*/

#include <string.h>

char *strcpy(char *dest, const char *src)
{
    char *save = dest;

    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return save;
}
