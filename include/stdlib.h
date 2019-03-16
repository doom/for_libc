/*
** Created by doom on 10/09/18.
*/

#ifndef FOR_LIBC_STDLIB_H
#define FOR_LIBC_STDLIB_H

#include <stddef.h>

int atoi(const char *nptr);

long atol(const char *nptr);

long long atoll(const char *nptr);

void *bsearch(const void *key, const void *base,
              size_t nmemb, size_t size,
              int (*compar)(const void *, const void *));

#endif /* !FOR_LIBC_STDLIB_H */
