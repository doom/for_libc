/*
** Created by doom on 15/09/18.
*/

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <pfmt/pfmt.h>

typedef enum
{
    FLAG_NONE = 0,
    FLAG_MINUS = 1 << 0,
    FLAG_LEFT_ALIGN = FLAG_MINUS,
    FLAG_ZERO = 1 << 1,
    FLAG_PLUS = 1 << 2,
    FLAG_BLANK = 1 << 3,
    FLAG_HASH = 1 << 4,
    FLAG_HAS_PRECISION = 1 << 5,
    FLAG_HAS_WIDTH = 1 << 6,
    FLAG_LONG = 1 << 7,
    FLAG_LONG_LONG = 1 << 8,
    FLAG_HALF = 1 << 9,
    FLAG_HALF_HALF = 1 << 10,
    FLAG_HEX_UPPERCASE = 1 << 11,
} format_flags_t;

#define MIN(x, y)       (((x) < (y)) ? (x) : (y))

static inline void output_n_times(pf_context_t *ctx, pf_writer_t writer, unsigned int nb, char c)
{
    char buffer[256];

    memset(buffer, c, MIN(sizeof(buffer), nb));

    while (nb >= sizeof(buffer)) {
        writer(ctx, buffer, sizeof(buffer));
        nb -= sizeof(buffer);
    }
    writer(ctx, buffer, nb);
}

#undef MIN

static inline unsigned int strtou(const char *str, const char **endptr)
{
    unsigned int ret = 0;

    while (isdigit(*str)) {
        ret = 10 * ret + (*str - '0');
        ++str;
    }
    *endptr = str;
    return ret;
}

static inline void output_string(pf_context_t *ctx, pf_writer_t writer,
                                 format_flags_t flags, unsigned int width, unsigned int precision,
                                 const char *str)
{
    unsigned int out_len = (unsigned int)strlen(str);
    unsigned int pad = 0;

    if (flags & FLAG_HAS_PRECISION && precision < out_len) {
        out_len = precision;
    }

    if (flags & FLAG_HAS_WIDTH && width > out_len) {
        pad = width - out_len;
    }

    /** If we align to the right, we pad left */
    if (!(flags & FLAG_LEFT_ALIGN))
        output_n_times(ctx, writer, pad, ' ');

    writer(ctx, str, out_len);

    /** If we align to the left, we pad right */
    if (flags & FLAG_LEFT_ALIGN)
        output_n_times(ctx, writer, pad, ' ');
}

#define HEX_PREFIX          "0x"
#define HEX_UPPER_PREFIX    "0X"
#define HEX_PREFIX_LEN      (sizeof(HEX_PREFIX) - 1)

#define OCT_PREFIX          "0"
#define OCT_PREFIX_LEN      (sizeof(OCT_PREFIX) - 1)

static inline void output_number(pf_context_t *ctx, pf_writer_t writer,
                                 format_flags_t flags, unsigned int width, unsigned int precision,
                                 bool neg, unsigned int base, const char *str_repr, unsigned int repr_len)
{
    unsigned int out_len;
    unsigned int pad = 0;

    out_len = (repr_len > precision ? repr_len : precision) + (neg || flags & FLAG_PLUS);

    if (flags & FLAG_HASH) {
        if (base == 16)
            out_len += HEX_PREFIX_LEN; /** "0x" prefix */
        else if (base == 8)
            out_len += OCT_PREFIX_LEN; /** "0" prefix */
    }

    if (flags & FLAG_HAS_WIDTH && width > out_len) {
        pad = width - out_len;
    }

    /** If we align to the right, we pad left */
    if (!(flags & FLAG_LEFT_ALIGN)) {
        char lpad_chr = ' ';

        if (flags & FLAG_ZERO) {
            /** When padding with zeroes, we print the base prefix before padding */
            if (flags & FLAG_HASH) {
                if (base == 16)
                    writer(ctx, flags & FLAG_HEX_UPPERCASE ? HEX_UPPER_PREFIX : HEX_PREFIX, HEX_PREFIX_LEN);
                else if (base == 8)
                    writer(ctx, OCT_PREFIX, OCT_PREFIX_LEN);
            }
            lpad_chr = '0';
        }

        output_n_times(ctx, writer, pad, lpad_chr);
    }

    if (flags & FLAG_HASH) {
        if (base == 16)
            writer(ctx, flags & FLAG_HEX_UPPERCASE ? HEX_UPPER_PREFIX : HEX_PREFIX, HEX_PREFIX_LEN);
        else if (base == 8)
            writer(ctx, OCT_PREFIX, OCT_PREFIX_LEN);
    }

    /** Precision padding (leading zeros) */
    if (precision > repr_len)
        output_n_times(ctx, writer, precision - repr_len, '0');

    if (neg)
        writer(ctx, "-", 1);
    else if (flags & FLAG_PLUS)
        writer(ctx, "+", 1);

    /** Actual number printing */
    writer(ctx, str_repr, repr_len);

    /** If we align to the left, we pad right */
    if (flags & FLAG_LEFT_ALIGN) {
        /** FLAG_ZERO is ignored here (adding 0's to the right changes the number) */
        output_n_times(ctx, writer, pad, ' ');
    }
}

#undef HEX_PREFIX_LEN
#undef HEX_UPPER_PREFIX
#undef HEX_PREFIX
#undef OCT_PREFIX_LEN
#undef OCT_PREFIX

static inline void output_int(pf_context_t *ctx, pf_writer_t writer,
                              format_flags_t flags, unsigned int width, unsigned int precision,
                              unsigned int i, bool neg, unsigned int base)
{
    char str_repr[12];
    char *ptr = str_repr + sizeof(str_repr) - 1;
    unsigned int repr_len;
    const char a = flags & FLAG_HEX_UPPERCASE ? 'A' : 'a';

    do {
        char digit = i % base;

        *--ptr = digit > 9 ? a + digit - 10 : '0' + digit;
        i /= base;
    } while (i != 0);
    repr_len = sizeof(str_repr) - 1 - (ptr - str_repr);
    output_number(ctx, writer, flags, width, precision, neg, base, ptr, repr_len);
}

static inline void output_long(pf_context_t *ctx, pf_writer_t writer,
                               format_flags_t flags, unsigned int width, unsigned int precision,
                               unsigned long l, bool neg, unsigned int base)
{
    char str_repr[24];
    char *ptr = str_repr + sizeof(str_repr) - 1;
    unsigned int repr_len;
    const char a = flags & FLAG_HEX_UPPERCASE ? 'A' : 'a';

    do {
        char digit = l % base;

        *--ptr = digit > 9 ? a + digit - 10 : '0' + digit;
        l /= base;
    } while (l != 0);
    repr_len = sizeof(str_repr) - 1 - (ptr - str_repr);
    output_number(ctx, writer, flags, width, precision, neg, base, ptr, repr_len);
}

static const char *pf_strchrnul(const char *s, char c)
{
    while (*s && *s != c) {
        ++s;
    }
    return s;
}

#define FLAG_CASE(chr, val)                                                 \
    case chr:                                                               \
        flags |= (val);                                                     \
        break;

#define UNSIGNED_CASE(base)                                                                             \
    if (flags & (FLAG_LONG_LONG | FLAG_LONG)) {                                                         \
        output_long(&context, writer, flags, width, precision, va_arg(ap, unsigned long), false, base); \
    } else {                                                                                            \
        output_int(&context, writer, flags, width, precision, va_arg(ap, unsigned int), false, base);   \
    }

/**
 * This macro computes the absolute value of a signed integer type, in the corresponding unsigned integer type
 * - As per C11's 6.3.1.3, when casting the negative value to unsigned we (mathematically) add TYPE_MAX + 1 to the value
 * - After that, we take the opposite of the new value, which for unsigned types, is just (TYPE_MAX + 1 - new_value)
 *
 * Example with int/unsigned int:
 * - For a number such as -2147483646, we cast, obtaining 2147483650
 * - We take the "opposite" of that, which is 2147483646
 */
#define UNSIGNED_ABS(type, x)       (unsigned type)(((x) < 0) ? -((unsigned type)(x)) : (unsigned type)(x))

int pf_vformat(pf_data_t user_data, pf_writer_t writer, const char *fmt, va_list ap)
{
    pf_context_t context = {
        .status = 0,
        .user_data = user_data
    };

    while (*fmt) {
        const char *next = pf_strchrnul(fmt, '%');

        writer(&context, fmt, (size_t)(next - fmt));
        fmt = next;
        if (*fmt == '%') {
            format_flags_t flags = FLAG_NONE;
            bool got_flag = true;
            unsigned int width = 0;
            unsigned int precision = 0;

            /** Check for optional flags */
            do {
                switch (*++fmt) {
                    FLAG_CASE('0', FLAG_ZERO);
                    FLAG_CASE('-', FLAG_MINUS);
                    FLAG_CASE('+', FLAG_PLUS);
                    FLAG_CASE('#', FLAG_HASH);
                    FLAG_CASE(' ', FLAG_BLANK);
                    default:
                        got_flag = false;
                        break;
                }
            } while (got_flag);

            /** Check for optional width field */
            if (*fmt == '*') {
                int value = va_arg(ap, int);

                if (value < 0) {
                    width = UNSIGNED_ABS(int, value);
                    flags |= FLAG_LEFT_ALIGN;
                } else {
                    width = (unsigned int)value;
                }
                flags |= FLAG_HAS_WIDTH;
                ++fmt;
            } else if (isdigit(*fmt)) {
                width = strtou(fmt, &fmt);
                flags |= FLAG_HAS_WIDTH;
            }

            /** Check for optional precision field */
            if (*fmt == '.') {
                ++fmt;
                if (*fmt == '*') {
                    precision = (unsigned int)va_arg(ap, int);
                    flags |= FLAG_HAS_PRECISION;
                    ++fmt;
                } else if (isdigit(*fmt)) {
                    precision = strtou(fmt, &fmt);
                    flags |= FLAG_HAS_PRECISION;
                }
            }

            /** Check optional length field */
            switch (*fmt) {
                case 'h':
                    ++fmt;
                    if (*fmt == 'h') {
                        flags |= FLAG_HALF_HALF;
                        ++fmt;
                    } else {
                        flags |= FLAG_HALF;
                    }
                    break;
                case 'l':
                    ++fmt;
                    if (*fmt == 'l') {
                        flags |= FLAG_LONG_LONG;
                        ++fmt;
                    } else {
                        flags |= FLAG_LONG;
                    }
                    break;
                case 'z':
                    ++fmt;
                    flags |= FLAG_LONG;
                    break;
                case 'L':
                case 'j':
                case 't':
                    ++fmt;
                    break;
                default:
                    break;
            }

            /** Type specifier */
            switch (*fmt) {
                case 'X':
                    flags |= FLAG_HEX_UPPERCASE;
                    /* FALLTHROUGH */
                case 'x':
                    UNSIGNED_CASE(16);
                    break;
                case 'u':
                    UNSIGNED_CASE(10);
                    break;
                case 'o':
                    UNSIGNED_CASE(8);
                    break;
                case 'd':
                case 'i':
                    if (flags & (FLAG_LONG_LONG | FLAG_LONG)) {
                        long value = va_arg(ap, long);

                        output_long(&context, writer, flags, width, precision,
                                    UNSIGNED_ABS(long, value), value < 0, 10);
                    } else {
                        int value = va_arg(ap, int);

                        output_int(&context, writer, flags, width, precision,
                                   UNSIGNED_ABS(int, value), value < 0, 10);
                    }
                    break;
                case 'c': {
                    char c = (char)va_arg(ap, int);
                    writer(&context, &c, 1);
                    break;
                }
                case 's':
                    output_string(&context, writer, flags, width, precision, va_arg(ap, const char *));
                    break;
                case 'p':
                    output_long(&context, writer, flags | FLAG_HASH, width, precision,
                                (uintptr_t)va_arg(ap, const void *), false, 16);
                    break;
                case 'n':
                    *va_arg(ap, int *) = context.status;
                    break;
                default:
                    writer(&context, "%", 1);
                    break;
            }
            ++fmt;
        }
    }
    return context.status;
}

#undef UNSIGNED_ABS
#undef UNSIGNED_CASE
#undef FLAG_CASE

int pf_format(pf_data_t user_data, pf_writer_t writer, const char *fmt, ...)
{
    va_list ap;
    int ret;

    va_start(ap, fmt);
    ret = pf_vformat(user_data, writer, fmt, ap);
    va_end(ap);
    return ret;
}
