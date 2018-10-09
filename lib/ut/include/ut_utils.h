/*
** Created by doom on 09/09/18.
*/

#ifndef FOR_LIBC_UT_UTILS_H
#define FOR_LIBC_UT_UTILS_H

#ifdef __cplusplus
extern "C"
{
#endif

long ut_write(int fd, const void *data, unsigned long size);

void ut_exit(int status);

#ifdef __cplusplus
}
#endif

#endif /* !FOR_LIBC_UT_UTILS_H */
