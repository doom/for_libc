/*
** Created by doom on 12/09/18.
*/

#include <string.h>

char *strncat(char *dest, const char *src, size_t n)
{
    char *save = dest;

    dest += strlen(dest);
    *(char *)mempcpy(dest, src, strnlen(src, n)) = '\0';
    return save;
}
