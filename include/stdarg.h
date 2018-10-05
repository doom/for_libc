/*
** Created by doom on 15/09/18.
*/

#ifndef FOR_LIBC_STDARG_H
#define FOR_LIBC_STDARG_H

typedef __builtin_va_list va_list;

#define va_start(v, l)      __builtin_va_start(v, l)
#define va_arg(v, t)        __builtin_va_arg(v, t)
#define va_copy(v1, v2)     __builtin_va_copy(v1, v2)
#define va_end(v)           __builtin_va_end(v)


#endif /* !FOR_LIBC_STDARG_H */
