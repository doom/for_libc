/*
** Created by doom on 12/09/18.
*/

#include <string.h>
#include <stdint.h>

#define ALIGN_PTR_UP(x, al)     (((uintptr_t)(x) + ((al) - 1)) & ~((al) - 1))

/**
 * Handwritten unrolling using uint32_t's instead of byte-by-byte
 *
 * - We find the number of bytes to copy until s is properly aligned and copy them one by one
 * - Then we create a uint32_t by OR-ing the byte to set on each of byte of the uint32_t
 * - We loop uint32_t by uint32_t until the remaining number of bytes to copy is below the number of bytes in a uint32_t
 * - We do byte-by-byte again until there is nothing more to copy
 */
void *memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    unsigned char cp_byte = (unsigned char)(c & 0xFF);

    if (!n)
        return s;

    if (n > 4) {
        size_t off = ALIGN_PTR_UP(s, sizeof(uint32_t)) - (uintptr_t)s;
        uint32_t cp32 = (cp_byte << 24) | (cp_byte << 16) | (cp_byte << 8) | cp_byte;
        uint32_t *dwp;
        size_t dwn;

        switch (off) {
            case 3:
                *p++ = cp_byte;
                /* FALLTHROUGH */
            case 2:
                *p++ = cp_byte;
                /* FALLTHROUGH */
            case 1:
                *p++ = cp_byte;
                break;
            default:
                break;
        }
        n -= off;
        dwn = n / 4;
        n %= 4;
        dwp = (uint32_t *)p;
        while (dwn--) {
            *dwp++ = cp32;
        }
        p = (unsigned char *)dwp;
    }

    while (n--) {
        *p++ = cp_byte;
    }
    return s;
}
