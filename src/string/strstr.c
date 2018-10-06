/*
** Created by doom on 05/10/18.
*/

#include <string.h>

char *strstr(const char *haystack, const char *needle)
{
    size_t needle_len;
    size_t haystack_len;
    const char *haystack_end;

    if (*needle == '\0' || haystack == needle)
        return (char *)haystack;

    needle_len = strlen(needle);
    haystack_len = strlen(haystack);
    if (haystack_len < needle_len)
        return NULL;

    haystack_end = haystack + haystack_len - needle_len;
    while (haystack <= haystack_end) {
        if (strncmp(haystack, needle, needle_len) == 0)
            return (char *)haystack;
        ++haystack;
    }
    return NULL;
}
