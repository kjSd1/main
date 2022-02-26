#include "unordered_array_set.h"

size_t unordered_array_set_in(unordered_array_set set, int value) {
    return linearSearch_(set.data, set.size, value);
}

bool unordered_array_set_isSubset(unordered_array_set set, unordered_array_set subset) {
    for (size_t index = 0; index < subset.size; index++)
        if (unordered_array_set_in(set, subset.data[index]) == set.size)
            return 0;
    return 1;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return set1.size == set2.size && memcmp(set1.data, set2.data, set1.size * sizeof(int)) == 0;
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set newSet = unordered_array_set_create(set1.size + set2.size);
    for (size_t index = 0; index < set1.size; index++)
        unordered_array_set_insert(&newSet, set1.data[index]);
    for (size_t index = 0; index < set2.size; index++)
        unordered_array_set_insert(&newSet, set2.data[index]);
    unordered_array_set_changeCapacityIf(&newSet);
    return newSet;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set newSet = unordered_array_set_create(set1.size + set2.size);
    for (size_t index = 0; index < set1.size; index++)
        if (unordered_array_set_in(set2, set1.data[index]) < set2.size)
            unordered_array_set_insert(&newSet, set1.data[index]);
    unordered_array_set_changeCapacityIf(&newSet);
    return newSet;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set newSet = unordered_array_set_create(set1.size);
    for (size_t index = 0; index < set1.size; index++)
        if (unordered_array_set_in(set2, set1.data[index]) == set2.size || set2.size == 0)
            unordered_array_set_insert(&newSet, set1.data[index]);
    unordered_array_set_changeCapacityIf(&newSet);
    return newSet;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set diffSet1 = unordered_array_set_difference(set1, set2);
    unordered_array_set diffSet2 = unordered_array_set_difference(set2, set1);
    unordered_array_set unitedSet = unordered_array_set_union(diffSet1, diffSet2);
    unordered_array_set_delete(diffSet1);
    unordered_array_set_delete(diffSet2);
    return unitedSet;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    assert(unordered_array_set_isSubset(universumSet, set));
    return unordered_array_set_difference(universumSet, set);
}

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {calloc(capacity, sizeof(int)), 0, capacity};
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set newUnordered_array_set = unordered_array_set_create(size);
    for (size_t index = 0; index < size; index++)
        unordered_array_set_insert(&newUnordered_array_set, a[index]);
    unordered_array_set_changeCapacityIf(&newUnordered_array_set);
    return newUnordered_array_set;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    if (unordered_array_set_in(*set, value) == set->size)
        append_(set->data, &set->size, value);
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t index = unordered_array_set_in(*set, value);
    if (index < set->size)
        deleteByPosUnSaveOrder_(set->data, &set->size, index);
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    bool isEmpty = true;
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
        isEmpty = false;
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}

void unordered_array_set_changeCapacityIf(unordered_array_set *set) {
    if (set->size < set->capacity) {
        set->data = (int*)realloc(set->data, sizeof(int) * set->size);
        set->capacity = set->size;
    }
}