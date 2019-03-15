/*
** Created by doom on 15/03/19.
*/

#include <ctype.h>

int atoi(const char *nptr)
{
    int result = 0;

    while (isspace(*nptr)) {
        ++nptr;
    }

    if (*nptr == '-') {
        ++nptr;

        while (isdigit(*nptr)) {
            result = result * 10 - (*nptr - '0');
            ++nptr;
        }
    } else {
        if (*nptr == '+') {
            ++nptr;
        }

        while (isdigit(*nptr)) {
            result = result * 10 + *nptr - '0';
            ++nptr;
        }
    }
    return result;
}

long int atol(const char *nptr)
{
    long int result = 0;

    while (isspace(*nptr)) {
        ++nptr;
    }

    if (*nptr == '-') {
        ++nptr;

        while (isdigit(*nptr)) {
            result = result * 10 - (*nptr - '0');
            ++nptr;
        }
    } else {
        if (*nptr == '+') {
            ++nptr;
        }

        while (isdigit(*nptr)) {
            result = result * 10 + *nptr - '0';
            ++nptr;
        }
    }
    return result;
}

long long atoll(const char *nptr)
{
    long long result = 0;

    while (isspace(*nptr)) {
        ++nptr;
    }

    if (*nptr == '-') {
        ++nptr;

        while (isdigit(*nptr)) {
            result = result * 10 - (*nptr - '0');
            ++nptr;
        }
    } else {
        if (*nptr == '+') {
            ++nptr;
        }

        while (isdigit(*nptr)) {
            result = result * 10 + *nptr - '0';
            ++nptr;
        }
    }
    return result;
}
