/*
** Created by doom on 10/09/18.
*/

#include <string.h>

char *strcat(char *dest, const char *src)
{
    strcpy(dest + strlen(dest), src);
    return dest;
}
