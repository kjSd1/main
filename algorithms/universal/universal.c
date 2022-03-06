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