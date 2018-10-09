/*
** Created by doom on 05/10/18.
*/

#include <string.h>
#include <stdint.h>

#define IS_ALIGNED(ptr, al)     (!((uintptr_t)(ptr) & ((al) - 1)))

/**
 * This works just like strlen (see strlen.c), but also XORs the searched character to make it a zero.
 * That way, we match '\0' and the searched character at once.
 */
char *strchr(const char *str, int c)
{
    const uint32_t mask = 0x80808080;
    const uint32_t sub = 0x01010101;
    const uint32_t *cur32;
    const uint32_t xor_c = (c << 24) | (c << 16) | (c << 8) | c;

    while (!IS_ALIGNED(str, sizeof(uint32_t))) {
        if (*str == c)
            return (char *)str;
        else if (*str == '\0')
            return NULL;
        ++str;
    }

    cur32 = (const uint32_t *)str;
    while (1) {
        if (((*cur32 - sub) & mask) || (((*cur32 ^ xor_c) - sub) & mask)) {
            str = (const char *)cur32;

            if (str[0] == c)
                return (char *)str;
            if (str[0] == '\0')
                return NULL;
            if (str[1] == c)
                return (char *)str + 1;
            if (str[1] == '\0')
                return NULL;
            if (str[2] == c)
                return (char *)str + 2;
            if (str[2] == '\0')
                return NULL;
            if (str[3] == c)
                return (char *)str + 3;
            if (str[3] == '\0')
                return NULL;
            /** Note: we can end up here if one of the bytes already had its MSB set */
        }
        ++cur32;
    }
}
