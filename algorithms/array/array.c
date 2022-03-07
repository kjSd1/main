#include "array.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>

void inputArray_(int *const data, const size_t n) {
    for (size_t index = 0; index < n ; index++)
        scanf("%d", &data[index]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf ("\n") ;
}

void copyArray_(const int *data, int *data2, size_t size) {
    for (int index = 0; index < size; index++)
        data2[index] = data[index];
}

void append_(int *const a, size_t *const n, const int value) {
    a[*n] = value;
    (*n)++;
}

void insert_(int *const a, size_t *const n, const size_t pos, const int value) {
    assert(pos <= *n);
    if (*n == pos)
        a[*n] = value;
    else if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    }
    else
        a[pos] = value;
    (*n)++;
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void deleteByPosUnSaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

int all_(const int *a, size_t n, int (*predicate) (int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;
    return 1;
}

int any_(const int *a, size_t n, int (*predicate) (int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;
    return 0;
}

int countIf_(const int *const a, const size_t n, int (*predicate) (int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);
    return count;
}

void deleteIf_ (int *const a, size_t *const n, int (*deletePredicate) (int)) {
    size_t indexRead = 0;
    while (indexRead < *n && !deletePredicate(a[indexRead]))
        indexRead++;
    size_t indexWrite = indexRead ;
    while(indexRead < *n) {
        if (!deletePredicate(a[indexRead])) {
            a[indexWrite] = a[indexRead];
            indexWrite++;
        }
        indexRead++;
    }
    *n = indexWrite;
}

void forEach_(const int *source, int *dest, const size_t n, const int (*predicate) (int)) {
    for (size_t index = 0; index < n; index++)
        dest[index] = predicate(source[index]);
}

size_t linearSearch_(const int *a, const size_t n, int x) {
    for (size_t i = 0; i < n ; i++)
        if (a[i] == x)
            return i;
    return n;
}

size_t binarySearch_(const int *a, size_t n, int x) {
    if (n == 0)
        return 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return n;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle ;
        else
            right = middle ;
    }
    return right;
}

int binarySearchNearestLeft(const int *a, const size_t n, int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (right + left) / 2;
        if (x <= a[middle])
            right = middle;
        else
            left = middle;
    }

    return left;
}

int compare_ints (const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int getSum(const int *a, size_t n) {
    int result = 0;
    for (int i = 0; i < n; i++)
        result += a[i];
    return result;
}
size_t getMaxElement(const int *a, const size_t n) {
    size_t maxIndex = 0;
    for (size_t index = 1; index < n; index++)
        if (a[maxIndex] < a[index])
            maxIndex = index;
    return maxIndex;
}

size_t getMinElement(const int *a, size_t n) {
    size_t minIndex = 0;
    for (size_t index = 0; index < n; index++)
        if (a[minIndex] > a[index])
            minIndex = index;
    return minIndex;
}

