/*
** Created by doom on 15/09/18.
*/

#include <strings.h>
#include <ctype.h>

int strncasecmp(const char *s1, const char *s2, size_t n)
{
    int diff = 0;

    if (s1 == s2 || n == 0)
        return 0;

    while (n && (diff = tolower(*s1) - tolower(*s2)) == 0) {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
        n--;
    }
    return diff;
}
