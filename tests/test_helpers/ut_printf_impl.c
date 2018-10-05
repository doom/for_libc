/*
** Created by doom on 15/09/18.
*/

#include <pfmt/pfmt.h>
#include "ut_utils.h"

static void stdout_writer(pf_context_t *out, const char *s, size_t n)
{
    out->status += ut_write(1, s, n);
}

int ut_printf_impl(const char *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap, fmt);
    ret = pf_vformat((pf_data_t){.ptr = NULL}, &stdout_writer, fmt, ap);
    va_end(ap);
    return ret;
}
