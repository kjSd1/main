#include "string_.h"

void assertString(const char *expected, char *got, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

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

    return ptrS;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

int getWordBack(char *rBeginSource, const char *rEndSource, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rBeginSource, rEndSource);

    if (word->end == rEndSource)
        return 0;

    word->begin = findSpaceReverse(word->end, rEndSource) + 1;
    word->end++;
    return 1;
}

int wordCmp(WordDescriptor leftWord, WordDescriptor rightWord) {
    int leftWordSize = leftWord.end - leftWord.begin;
    int rightWordSize = rightWord.end - rightWord.begin;
    if (leftWordSize != rightWordSize)
        return leftWordSize - rightWordSize;

    char *readWord1 = leftWord.begin;
    char *readWord2 = rightWord.begin;
    while (readWord1 < leftWord.end - 1 && *readWord1 == *readWord2) {
        readWord1++;
        readWord2++;
    }

    return *readWord1 - *readWord2;
}

void getBagOfWords(BagOfWords *bagWords, char *s) {
    bagWords->size = 0;
    char *ptr = s;
    while (getWord(ptr, &bagWords->words[bagWords->size])) {
        ptr = bagWords->words[bagWords->size].end;
        bagWords->size++;
    }
}

int isPalindrome(WordDescriptor word) {
    char *left = word.begin;
    char *right = word.end - 1;
    while (left < right)
        if (*left++ != *right--)
            return 0;
    return 1;
}

void outputWord(WordDescriptor word) {
    char *ptrBegin = word.begin;
    while (ptrBegin != word.begin)
        printf("%c", *ptrBegin++);
    printf(" ");
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    char *ptr = copy(word.begin, word.end, destination);
    *ptr = '\0';
}