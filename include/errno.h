/*
** Created by doom on 15/03/19.
*/

#ifndef FOR_LIBC_ERRNO_H
#define FOR_LIBC_ERRNO_H

extern __thread int __errno;

#define errno       __errno

#define EDOM        1        /** Numerical argument out of domain */
#define EILSEQ      2        /** Invalid or incomplete multibyte or wide character */
#define ERANGE      3        /** Numerical result out of range */

#endif /* !FOR_LIBC_ERRNO_H */
