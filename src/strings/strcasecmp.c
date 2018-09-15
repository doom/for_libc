/*
** Created by doom on 14/09/18.
*/

#include <strings.h>
#include <ctype.h>

int strcasecmp(const char *s1, const char *s2)
{
    int diff;

    if (s1 == s2)
        return 0;

    while ((diff = tolower(*s1) - tolower(*s2)) == 0 && *s1) {
        s1++;
        s2++;
    }
    return diff;
}
