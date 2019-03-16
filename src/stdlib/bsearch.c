/*
** Created by doom on 15/03/19.
*/

#include <stddef.h>

void *bsearch(const void *key, const void *base,
              size_t nmemb, size_t size,
              int (*compar)(const void *, const void *))
{
    while (nmemb > 0) {
        const void *middle = (const char *)base + nmemb / 2 * size;
        int cmp = compar(key, middle);

        if (cmp == 0) {
            return (void *)middle;
        }
        if (cmp > 0) {
            base = (const char *)middle + size;
            nmemb -= 1;
        }
        nmemb /= 2;
    }
    return NULL;
}
