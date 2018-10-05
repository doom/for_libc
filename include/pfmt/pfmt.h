/*
** Created by doom on 15/09/18.
*/

#ifndef FOR_LIBC_PFMT_H
#define FOR_LIBC_PFMT_H

#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

/**
 * Tiny library for printf-like formatting
 */

typedef union
{
    uint32_t u32;
    uint64_t u64;
    void *ptr;
} pf_data_t;

typedef struct
{
    pf_data_t user_data;
    int status;
} pf_context_t;

typedef void (*pf_writer_t)(pf_context_t *, const char *s, size_t n);

/**
 * @param user_data     user data that will be passed to the writer function as part of the context
 * @param writer        writer function, will be called to output chunks of the resulting string
 * @param fmt           the format string
 * @param ap            the va_list representing the arguments to use for formatting
 *
 * @return              a status, as set by the writer function
 */
int pf_vformat(pf_data_t user_data, pf_writer_t writer, const char *fmt, va_list ap);

/**
 * @param user_data     user data that will be passed to the writer function as part of the context
 * @param writer        writer function, will be called to output chunks of the resulting string
 * @param fmt           the format string
 *
 * @return              a status, as set by the writer function
 */
int pf_format(pf_data_t user_data, pf_writer_t writer, const char *fmt, ...);

#endif /* !FOR_LIBC_PFMT_H */
