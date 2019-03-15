/*
** Created by doom on 15/03/19.
*/

#include <stddef.h>
#include <string.h>

char *strtok_r(char *str, const char *delim, char **saveptr)
{
    char *end;

    /** If this is not the first iteration, restore the saved pointer */
    if (str == NULL) {
        str = *saveptr;
    }

    /** Skip delimiters at the beginning of the string */
    str += strspn(str, delim);

    /** If we found the NUL byte, there are no more tokens */
    if (*str == '\0') {
        *saveptr = str;
        return NULL;
    }

    /** Find the next delimiter (or NUL) */
    end = str + strcspn(str, delim);

    if (*end != '\0') {
        /** We found a delimiter, save the pointer for the next iteration */
        *saveptr = end + 1;

        /** NUL-terminate the returned string */
        *end = '\0';
    } else {
        /** We found the NUL byte, so there won't be a next iteration */
        *saveptr = end;
    }

    return str;
}

char *strtok(char *str, const char *delim)
{
    static char *save;

    return strtok_r(str, delim, &save);
}
