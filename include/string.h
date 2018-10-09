/*
** Created by doom on 10/09/18.
*/

#ifndef FOR_LIBC_STRING_H
#define FOR_LIBC_STRING_H

#include <stddef.h>
#include "_config.h"

C_LINKAGE_BEGIN

void *memcpy(void *dest, const void *src, size_t n);

void *mempcpy(void *dest, const void *src, size_t n);

void *memmove(void *dest, const void *src, size_t n);

void *memchr(const void *s, int c, size_t n);

void *memrchr(const void *haystack, int c, size_t n);

void *rawmemchr(const void *haystack, int c);

void *memmem(const void *haystack, size_t hlen, const void *needle, size_t nlen);

void *memset(void *s, int c, size_t n);

int memcmp(const void *p1, const void *p2, size_t n);

char *stpcpy(char *dest, const char *src);

char *strcat(char *dest, const char *src);

char *strncat(char *dest, const char *src, size_t n);

size_t strlen(const char *str);

size_t strnlen(const char *str, size_t n);

char *strcpy(char *dest, const char *src);

char *strncpy(char *dest, const char *src, size_t n);

int strcmp(const char *s1, const char *s2);

int strncmp(const char *s1, const char *s2, size_t n);

char *strchr(const char *str, int c);

char *strrchr(const char *str, int c);

char *strstr(const char *haystack, const char *needle);

size_t strcspn(const char *s, const char *reject);

size_t strspn(const char *s, const char *accept);

char *strpbrk(const char *s, const char *accept);

C_LINKAGE_END

#endif /* !FOR_LIBC_STRING_H */
