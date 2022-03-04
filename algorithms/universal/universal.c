#include "universal.h"

void universalSwap(int *a, int *b, int sizeOf) {
    char *ptrA = a;
    char *ptrB = b;
    for (int size = 1; size < sizeOf; size++) {
        char *t = ptrA;
        ptrA = ptrB;
        ptrB = t;
        ptrA++;
        ptrB++;
    }
}

