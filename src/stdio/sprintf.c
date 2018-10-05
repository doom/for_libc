/*
** Created by doom on 15/09/18.
*/

#include <string.h>
#include <pfmt/pfmt.h>

typedef struct
{
    char *buffer;
    size_t size;
} out_buffer_t;

static void buffer_writer(pf_context_t *ctx, const char *s, size_t n)
{
    out_buffer_t *outbuf = ctx->user_data.ptr;

    /** Increment disregarding the available buffer space */
    ctx->status += n;

    if (outbuf->size < n)
        n = outbuf->size;
    memcpy(outbuf->buffer, s, n);
    outbuf->buffer += n;
    outbuf->size -= n;
}

int vsprintf(char *str, const char *format, va_list ap)
{
    out_buffer_t outbuf;
    int ret;

    outbuf.buffer = str;
    outbuf.size = (size_t)-1;
    ret = pf_vformat((pf_data_t){.ptr = &outbuf}, &buffer_writer, format, ap);
    *outbuf.buffer = '\0';
    return ret;
}

int vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
    out_buffer_t outbuf;
    int ret;

    outbuf.buffer = str;
    outbuf.size = size;
    ret = pf_vformat((pf_data_t){.ptr = &outbuf}, &buffer_writer, format, ap);
    if (size) {
        size_t min = size - 1 < (size_t)ret ? size - 1 : (size_t)ret;
        str[min] = '\0';
    }
    return ret;
}

int sprintf(char *str, const char *format, ...)
{
    va_list ap;
    int ret;

    va_start(ap, format);
    ret = vsprintf(str, format, ap);
    va_end(ap);
    return ret;
}

int snprintf(char *str, size_t size, const char *format, ...)
{
    va_list ap;
    int ret;

    va_start(ap, format);
    ret = vsnprintf(str, size, format, ap);
    va_end(ap);
    return ret;
}
