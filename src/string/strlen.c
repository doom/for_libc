/*
** Created by doom on 11/09/18.
*/

#include <string.h>
#include <stdint.h>

#define IS_ALIGNED(ptr, al)     (!((uintptr_t)(ptr) & ((al) - 1)))

/**
 * Handwritten unrolling using uint32_t combined with binary masking (inspired from glibc)
 *
 * - We find the number of characters to scan until str is properly aligned and scan them one by one
 * - We loop using uint32_t's, processing 4 bytes at each iteration
 * - For each uint32_t, we substract 1 to each contained byte
 * - We create a bitmask to detect if the MSB is set in any of the bytes of a given uint32_t
 * - If it is set, we potentially found a zero byte (because the substraction made it underflow and its MSB is now set)
 */
size_t strlen(const char *str)
{
    const char *cur = str;
    const uint32_t mask = 0x80808080;
    const uint32_t sub = 0x01010101;
    const uint32_t *cur32;

    while (!IS_ALIGNED(cur, sizeof(uint32_t))) {
        if (*cur == '\0')
            return cur - str;
        ++cur;
    }

    cur32 = (const uint32_t *)cur;
    while (1) {
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
            /** Note: we can end up here if one of the bytes already had its MSB set */
        }
        ++cur32;
    }
}
