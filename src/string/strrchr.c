/*
** Created by doom on 07/10/18.
*/

#include <string.h>

char *strrchr(const char *str, char c)
{
    const char *prev_result = NULL;
    const char *last_result;

    while ((last_result = strchr(str, c)) != NULL) {
        prev_result = last_result;
        str = last_result + 1;
    }
    return (char *)prev_result;
}
