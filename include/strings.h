/*
** Created by doom on 15/09/18.
*/

#ifndef FOR_LIBC_STRINGS_H
#define FOR_LIBC_STRINGS_H

#include <stddef.h>
#include "_config.h"

C_LINKAGE_BEGIN

int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);

C_LINKAGE_END

#endif /* !FOR_LIBC_STRINGS_H */
