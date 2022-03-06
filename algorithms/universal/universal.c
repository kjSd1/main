#include "universal.h"

void universalSwap(void *a, void *b, int sizeOf) {
    char *ptrA = a;
    char *ptrB = b;
    for (int size = 0; size < sizeOf; size++) {
        char t = *ptrA;
        *ptrA = *ptrB;
        *ptrB = t;
        ptrA++;
        ptrB++;
    }
}

void swap_(void *a, void *b, int size) {
    char *pa = a;
    char *pb = b;
    for (int i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}