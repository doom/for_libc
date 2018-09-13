/*
** Created by doom on 12/09/18.
*/

#include <stdint.h>
#include <string.h>

#define IS_ALIGNED(ptr, al)     (!((uintptr_t)(ptr) & ((al) - 1)))

/** See strlen.c */
size_t strnlen(const char *str, size_t n)
{
    const char *max = str + n;
    const char *cur = str;
    const uint32_t mask = 0x80808080;
    const uint32_t sub = 0x01010101;
    const uint32_t *cur32;

    while (!IS_ALIGNED(cur, sizeof(uint32_t))) {
        if (*cur == '\0' || cur == max)
            return cur - str;
        ++cur;
    }
    cur32 = (const uint32_t *)cur;
    while ((const char *)cur32 + 4 < max) {
        const uint32_t result = (*cur32 - sub) & mask;

        if (result != 0) {
            cur = (const char *)cur32;

            if (cur[0] == '\0')
                return cur - str;
            if (cur[1] == '\0')
                return cur - str + 1;
            if (cur[2] == '\0')
                return cur - str + 2;
            if (cur[3] == '\0')
                return cur - str + 3;
        }
        ++cur32;
    }
    cur = (const char *)cur32;
    while (cur < max) {
        if (*cur == '\0')
            return cur - str;
        ++cur;
    }
    return n;
}
