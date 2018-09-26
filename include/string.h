/*
** Created by doom on 10/09/18.
*/

#ifndef FOR_LIBC_STRING_H
#define FOR_LIBC_STRING_H

#include <stddef.h>

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

#endif /* !FOR_LIBC_STRING_H */