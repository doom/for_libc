/*
** Created by doom on 13/09/18.
*/

#ifndef FOR_LIBC_CTYPE_H
#define FOR_LIBC_CTYPE_H

#include "_config.h"

C_LINKAGE_BEGIN

#ifndef __CTYPE_FUNCTION_STORAGE
#define __CTYPE_FUNCTION_STORAGE    static inline
#endif

__CTYPE_FUNCTION_STORAGE int iscntrl(int c)
{
    return (unsigned)c < 0x20 || c == 0x7f;
}

__CTYPE_FUNCTION_STORAGE int isdigit(int c)
{
    return (unsigned)c - '0' < 10;
}

__CTYPE_FUNCTION_STORAGE int isupper(int c)
{
    return (unsigned)c - 'A' < 26;
}

__CTYPE_FUNCTION_STORAGE int islower(int c)
{
    return (unsigned)c - 'a' < 26;
}

__CTYPE_FUNCTION_STORAGE int isalpha(int c)
{
    /** Since lower characters have the 5th bit set, set it (32 is 0b00100000) */
    return islower((unsigned)c | 32);
}

__CTYPE_FUNCTION_STORAGE int isxdigit(int c)
{
    /** Either it's a digit, or one of the first six letters of the alphabet */
    return isdigit(c) || ((unsigned)c | 32) - 'a' < 6;
}

__CTYPE_FUNCTION_STORAGE int isalnum(int c)
{
    return isdigit(c) || isalpha(c);
}

__CTYPE_FUNCTION_STORAGE int isgraph(int c)
{
    /* The characters ranging from 0x21 ('!') to 0x7e ('~') */
    return (unsigned)c - 0x21 < 0x5e;
}

__CTYPE_FUNCTION_STORAGE int isprint(int c)
{
    /* The characters ranging from 0x20 (' ') to 0x7e ('~') */
    return (unsigned)c - 0x20 < 0x5f;
}

__CTYPE_FUNCTION_STORAGE int ispunct(int c)
{
    return isgraph(c) && !isalnum(c);
}

__CTYPE_FUNCTION_STORAGE int isspace(int c)
{
    return c == ' ' || (unsigned)c - '\t' < 5;
}

__CTYPE_FUNCTION_STORAGE int isblank(int c)
{
    return c == ' ' || c == '\t';
}

__CTYPE_FUNCTION_STORAGE int tolower(int c)
{
    if (isupper(c)) {
        return c | 32;
    }
    return c;
}

__CTYPE_FUNCTION_STORAGE int toupper(int c)
{
    if (islower(c)) {
        /** Keep all bits but the 5th (0x5f is 0b01011111, which is ~32) */
        return c & 0x5f;
    }
    return c;
}

#undef __CTYPE_FUNCTION_STORAGE

C_LINKAGE_END

#endif /* !FOR_LIBC_CTYPE_H */
