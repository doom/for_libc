/*
** Created by doom on 10/09/18.
*/

#ifndef FOR_LIBC_STDBOOL_H
#define FOR_LIBC_STDBOOL_H

/** C++ already has a built-in bool type */
#ifndef __cplusplus

#define true    1
#define false   0

typedef _Bool bool;

#endif /* !__cplusplus */

#endif /* !FOR_LIBC_STDBOOL_H */
