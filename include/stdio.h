/*
** Created by doom on 15/09/18.
*/

#ifndef FOR_LIBC_STDIO_H
#define FOR_LIBC_STDIO_H

#include <stddef.h>
#include <stdarg.h>
#include "_config.h"

C_LINKAGE_BEGIN

#if 0
int vprintf(const char *format, va_list ap);

int printf(const char *format, ...);
#endif

int vsprintf(char *str, const char *format, va_list ap);

int sprintf(char *str, const char *format, ...);

int vsnprintf(char *str, size_t size, const char *format, va_list ap);

int snprintf(char *str, size_t size, const char *format, ...);

C_LINKAGE_END

#endif /* !FOR_LIBC_STDIO_H */
