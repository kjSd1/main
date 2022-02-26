#include "bitset.h"

bool checkValue(bitset set, unsigned value) {
    return value >= 0 && value <= set.maxValue;
}

bitset bitset_create(unsigned maxValue) {
    assert(maxValue < sizeof(unsigned int) * 8 && maxValue >= 0);
    return (bitset) {0, maxValue};
}

bool bitset_in(bitset set, unsigned int value) {
    assert(checkValue(set, value));
    return 1 << value & set.values;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    assert(subset.maxValue == subset.maxValue);
    return (subset.values & set.values) == subset.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    assert(checkValue(*set, value));
    set->values |= 1 << value;
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    assert(checkValue(*set, value));
    set->values &= ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

bitset bitset_complement(bitset set) {
    int bites = sizeof(unsigned int) * 8 - set.maxValue - 1;
    return (bitset) {(~set.values << bites) >> bites, set.maxValue};
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}
