#include "string_.h"

size_t strLen(const char *s) {
    char *end = s;
    while (*end != '\0')
        end++;

    return end - s;
}

char *find(char *begin, const char *end, const int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char* findNonSpace(const char *begin) {
    char *copyPtr = begin;
    while (*copyPtr != '\0' && isspace(*copyPtr))
        copyPtr++;

    return copyPtr;
}

char* findSpace(const char *begin) {
    char *copyPtr = begin;
    while (*copyPtr != '\0' && !isspace(*copyPtr))
        copyPtr++;

    return copyPtr;
}

char* findNonSpaceReverse(char *rBegin, const char *rEnd) {
    while (rBegin != rEnd && isspace(*rBegin))
        rBegin--;

    return rBegin;
}

char* findSpaceReverse(char *rBegin, const char *rEnd) {
    while (rBegin != rEnd && !isspace(*rBegin))
        rBegin--;

    return rBegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}

char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    return beginDestination + (endSource - beginSource);
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource))
            *beginDestination++ = *beginSource;
        beginSource++;
    }

    return beginDestination;
}

char* copyIfReverse(char *rBeginSource, const char *rEndSource, char *beginDestination, int (*f)(int)) {
    while (rBeginSource != rEndSource) {
        if (f(*rBeginSource))
            *beginDestination++ = *rBeginSource;
        rBeginSource--;
    }
    return beginDestination;
}

char* getEndOfString(char *s) {
    char *ptrS = s;
    while (*ptrS != '\0')
        ptrS++;

    return --ptrS;
}