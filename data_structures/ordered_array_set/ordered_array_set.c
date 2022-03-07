#include "ordered_array_set.h"

size_t ordered_array_set_in(ordered_array_set set, int value) {
    return binarySearch_(set.data, set.size, value);
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    assert(set1.size == set2.size);
    return memcmp(set1.data, set2.data, set1.size * sizeof(int)) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set set, ordered_array_set subset) {
    // ?
    //for (size_t index = 0; index < subset.size; index++)
        //if (ordered_array_set_in(set, subset.data[index]) == set.size)
            //return 0;
    //return 1;
    size_t indexSet = 0;
    size_t indexSubset = 0;
    while (indexSet != set.size && indexSubset != subset.size) {
        if (set.data[indexSet] == subset.data[indexSubset]) {
            indexSet++;
            indexSubset++;
        }
        else if (set.data[indexSet] < subset.data[indexSubset])
            indexSet++;
        else
            return 0;
    }
    return indexSubset == subset.size;
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set unionSet = ordered_array_set_create(set1.size + set2.size);
    copyArray_(set1.data, unionSet.data, set1.size);
    unionSet.size = set1.size;
    for (size_t index = 0; index < set2.size; index++)
        if (ordered_array_set_in(set1, set2.data[index]) == set1.size)
            ordered_array_set_insert(&unionSet, set2.data[index]);
    ordered_array_set_changeCapacityIf(&unionSet);
    return unionSet;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set intersectionSet = ordered_array_set_create(set1.size + set2.size);
    size_t indexSet1 = 0;
    size_t indexSet2 = 0;
    while (indexSet1 != set1.size && indexSet2 != set2.size) {
        if (set1.data[indexSet1] == set2.data[indexSet2]) {
            append_(intersectionSet.data, &intersectionSet.size, set1.data[indexSet1]);
            indexSet1++;
            indexSet2++;
        }
        else if (set1.data[indexSet1] < set2.data[indexSet2])
            indexSet1++;
        else
            indexSet2++;
    }
    ordered_array_set_changeCapacityIf(&intersectionSet);
    return intersectionSet;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set differenceSet = ordered_array_set_create(set1.size + set2.size);
    for (size_t index = 0; index < set1.size; index++)
        if (ordered_array_set_in(set2, set1.data[index]) == set2.size)
            ordered_array_set_insert(&differenceSet, set1.data[index]);
    ordered_array_set_changeCapacityIf(&differenceSet);
    return differenceSet;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set diffSet1 = ordered_array_set_difference(set1, set2);
    ordered_array_set diffSet2 = ordered_array_set_difference(set2, set1);
    ordered_array_set unitedSet = ordered_array_set_union(diffSet1, diffSet2);
    ordered_array_set_delete(diffSet1);
    ordered_array_set_delete(diffSet2);
    return unitedSet;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    assert(ordered_array_set_isSubset(universumSet, set));
    return ordered_array_set_difference(universumSet, set);
}

//---
ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {(int*)calloc(capacity, sizeof(int)), 0, capacity};
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set newSet = ordered_array_set_create(size);
    for (size_t index = 0; index < size; index++)
        ordered_array_set_insert(&newSet, a[index]);
    ordered_array_set_changeCapacityIf(&newSet);
    return newSet;
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(*set, value) == set->size) {
        int index = binarySearchNearestLeft(set->data, set->size, value);
        insert_(set->data, &set->size, binarySearchNearestLeft(set->data, set->size, value) + 1, value);
    }
}

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t index = ordered_array_set_in(*set, value);
    if (index < set->size)
        deleteByPosSaveOrder_(set->data, &set->size, index);
}

void ordered_array_set_changeCapacityIf(ordered_array_set *set) {
    if (set->size != set->capacity) {
        set->data = (int*)realloc(set->data,  set->size * sizeof(int));
        set->capacity = set->size;
    }
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->capacity > set->size);
}

void ordered_array_set_print(ordered_array_set set) {
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

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}