/*
** Created by doom on 10/09/18.
*/

#ifndef FOR_LIBC_STDDEF_H
#define FOR_LIBC_STDDEF_H

#include <_types/_size_t.h>
#include <_types/_ptrdiff_t.h>

#ifndef __cplusplus
#define NULL    ((void *)0)
#else
#define NULL    0u
#endif /* !__cplusplus */

#define offsetof(type, member)  ((size_t)(&(((type *)NULL)->member)))

#endif /* !FOR_LIBC_STDDEF_H */
