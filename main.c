#include <stdio.h>
#include <assert.h>
#include "D:\_Work\_GitHub\main\algorithms\array\array.h"
#include "D:\_Work\_GitHub\main\data_structures\bitset\bitset.h"
#include "D:\_Work\_GitHub\main\data_structures\unordered_array_set\unordered_array_set.h"
#include "D:\_Work\_GitHub\main\data_structures\ordered_array_set\ordered_array_set.h"
#include "D:\_Work\_GitHub\main\data_structures\matrix\matrix.h"

void test_bitset_in1() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    assert(bitset_in(set1, 5) == 1);
}

void test_bitset_in2() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    assert(bitset_in(set1, 4) == 0);
}

void test_bitset_in() {
    test_bitset_in1();
    test_bitset_in2();
}

void test_bitset_isEqual1() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 5);
    assert(bitset_isEqual(set1, set2) == 1);
}

void test_bitset_isEqual2() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 4);
    bitset_insert(&set2, 1);
    assert(bitset_isEqual(set1, set2) == 0);
}

void test_bitset_isEqual() {
    test_bitset_isEqual1();
    test_bitset_isEqual2();
}

void test_bitset_isSubset1() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 4);
    bitset_insert(&set1, 1);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 4);
    assert(bitset_isSubset(set2, set1));
}

void test_bitset_isSubset2() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 4);
    bitset_insert(&set1, 1);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 5);
    assert(bitset_isSubset(set1, set2) == 0);
}

void test_bitset_isSubset() {
    test_bitset_isSubset1();
    test_bitset_isSubset2();
}

void test_bitset_union1() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset_insert(&set1, 0);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 0);
    bitset resultSet = bitset_union(set1, set2);
    bitset expectedSet = bitset_create(31);
    bitset_insert(&expectedSet, 0);
    bitset_insert(&expectedSet, 5);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_union2() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset_insert(&set1, 0);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 3);
    bitset resultSet = bitset_union(set1, set2);
    bitset expectedSet = bitset_create(31);
    bitset_insert(&expectedSet, 0);
    bitset_insert(&expectedSet, 5);
    bitset_insert(&expectedSet, 3);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_union() {
    test_bitset_union1();
    test_bitset_union2();
}

void test_bitset_intersection1() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset_insert(&set1, 0);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 3);
    bitset resultSet = bitset_intersection(set1, set2);
    bitset expectedSet = bitset_create(31);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_intersection2() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset_insert(&set1, 0);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 0);
    bitset resultSet = bitset_intersection(set1, set2);
    bitset expectedSet = bitset_create(31);
    bitset_insert(&expectedSet, 0);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_intersection() {
    test_bitset_intersection1();
    test_bitset_intersection2();
}

void test_bitset_difference1() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset_insert(&set1, 0);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 0);
    bitset resultSet = bitset_difference(set1, set2);
    bitset expectedSet = bitset_create(31);
    bitset_insert(&expectedSet, 5);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_difference2() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset_insert(&set1, 1);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 0);
    bitset resultSet = bitset_difference(set1, set2);
    bitset expectedSet = bitset_create(31);
    bitset_insert(&expectedSet, 5);
    bitset_insert(&expectedSet, 1);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_difference3() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 5);
    bitset_insert(&set1, 1);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 0);
    bitset_insert(&set2, 5);
    bitset_insert(&set2, 1);
    bitset resultSet = bitset_difference(set1, set2);
    bitset expectedSet = bitset_create(31);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_difference() {
    test_bitset_difference1();
    test_bitset_difference2();
    test_bitset_difference3();
}

void test_bitset_symmetricDifference1() {
    bitset set1 = bitset_create(31);
    bitset_insert(&set1, 2);
    bitset_insert(&set1, 3);
    bitset set2 = bitset_create(31);
    bitset_insert(&set2, 1);
    bitset_insert(&set2, 2);
    bitset resultSet = bitset_symmetricDifference(set1, set2);
    bitset expectedSet = bitset_create(31);
    bitset_insert(&expectedSet, 1);
    bitset_insert(&expectedSet, 3);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_symmetricDifference() {
    test_bitset_symmetricDifference1();
}

void test_bitset_complement1() {
    bitset set1 = bitset_create(5);
    bitset_insert(&set1, 2);
    bitset_insert(&set1, 3);
    bitset resultSet = bitset_complement(set1);
    bitset expectedSet = bitset_create(5);
    bitset_insert(&expectedSet, 1);
    bitset_insert(&expectedSet, 4);
    bitset_insert(&expectedSet, 0);
    bitset_insert(&expectedSet, 5);
    assert(bitset_isEqual(expectedSet, resultSet));
}

void test_bitset_complement() {
    test_bitset_complement1();
}

void test_bitset() {
    test_bitset_in();
    test_bitset_isEqual();
    test_bitset_isSubset();
    test_bitset_union();
    test_bitset_intersection();
    test_bitset_difference();
    test_bitset_symmetricDifference();
    test_bitset_complement();
}

void test_unordered_array_set_in1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    size_t resultIndex = set.size;
    assert(unordered_array_set_in(set, 0) == resultIndex);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    size_t resultIndex = 0;
    assert(unordered_array_set_in(set, 1) == resultIndex);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
}

void test_unordered_array_set_isSubset1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);

    assert(unordered_array_set_isSubset(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2}, 1);

    assert(unordered_array_set_isSubset(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(unordered_array_set_isSubset(set1, set2) == 0);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset4() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);

    assert(unordered_array_set_isSubset(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset5() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3}, 1);

    assert(unordered_array_set_isSubset(set1, set2) == 0);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isSubset() {
    test_unordered_array_set_isSubset1();
    test_unordered_array_set_isSubset2();
    test_unordered_array_set_isSubset3();
    test_unordered_array_set_isSubset4();
    test_unordered_array_set_isSubset5();
}

void test_unordered_array_set_isEqual1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);

    assert(unordered_array_set_isEqual(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isEqual2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 3}, 2);

    assert(unordered_array_set_isEqual(set1, set2) == 0);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isEqual3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 3}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, 1}, 2);

    assert(unordered_array_set_isEqual(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isEqual4() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, 3, 2, 5, 1}, 5);

    assert(unordered_array_set_isEqual(set1, set2));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isEqual() {
    test_unordered_array_set_isEqual1();
    test_unordered_array_set_isEqual2();
    test_unordered_array_set_isEqual3();
    test_unordered_array_set_isEqual4();
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set resultSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resultSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3}, 2);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set resultSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2}, 1);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resultSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {}, 0);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set resultSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {3}, 1);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 1, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resultSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set resultSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {3, 1}, 2);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 1, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resultSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();

}

void test_unordered_array_set_complement1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 1}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);
    unordered_array_set resultSet = unordered_array_set_complement(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {4}, 1);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2}, 1);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);
    unordered_array_set resultSet = unordered_array_set_complement(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {4, 1}, 2);

    assert(unordered_array_set_isEqual(resultSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
}

void test_unordered_array_set() {
    test_unordered_array_set_in();
    test_unordered_array_set_isSubset();
    test_unordered_array_set_isEqual();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}

void test_ordered_array_set_in1() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 4, 5, 6, 10}, 6);

    assert(ordered_array_set_in(set, 0) == set.size);
    assert(ordered_array_set_in(set, 1) == 0);
    assert(ordered_array_set_in(set, 3) == set.size);
    assert(ordered_array_set_in(set, 6) == 4);
    assert(ordered_array_set_in(set, 7) == set.size);
    assert(ordered_array_set_in(set, 8) == set.size);
    assert(ordered_array_set_in(set, 9) == set.size);
    assert(ordered_array_set_in(set, 10) == 5);
    assert(ordered_array_set_in(set, 11) == set.size);
    assert(ordered_array_set_in(set, 12) == set.size);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_in2() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {}, 0);

    assert(ordered_array_set_in(set, 12) == 0);
    assert(ordered_array_set_in(set, 0) == 0);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
}

void test_ordered_array_set_isEqual1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {3, 2, 1}, 3);

    assert(ordered_array_set_isEqual(set1, set2));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isEqual2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {}, 0);

    assert(ordered_array_set_isEqual(set1, set2));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isEqual3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 10}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    assert(ordered_array_set_isEqual(set1, set2) == 0);
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isEqual() {
    test_ordered_array_set_isEqual1();
    test_ordered_array_set_isEqual2();
    test_ordered_array_set_isEqual3();
}

void test_ordered_array_set_isSubset1() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(ordered_array_set_isSubset(set, subset));
    ordered_array_set_delete(set);
    ordered_array_set_delete(subset);
}

void test_ordered_array_set_isSubset2() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {2, 1}, 2);

    assert(ordered_array_set_isSubset(set, subset));
    ordered_array_set_delete(set);
    ordered_array_set_delete(subset);
}

void test_ordered_array_set_isSubset3() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {2, 4}, 2);

    assert(ordered_array_set_isSubset(set, subset) == 0);
    ordered_array_set_delete(set);
    ordered_array_set_delete(subset);
}

void test_ordered_array_set_isSubset4() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 5}, 3);
    ordered_array_set subset = ordered_array_set_create_from_array((int[]) {2, 4}, 2);

    assert(ordered_array_set_isSubset(set, subset) == 0);
    ordered_array_set_delete(set);
    ordered_array_set_delete(subset);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
    test_ordered_array_set_isSubset3();
    test_ordered_array_set_isSubset4();
}

void test_ordered_array_set_union1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resultSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(ordered_array_set_isEqual(resultSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resultSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resultSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    assert(ordered_array_set_isEqual(resultSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resultSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
}

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resultSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2}, 1);

    assert(ordered_array_set_isEqual(resultSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resultSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resultSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {}, 0);

    assert(ordered_array_set_isEqual(resultSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resultSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
}

void test_ordered_array_set_difference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resultSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1}, 1);

    assert(ordered_array_set_isEqual(resultSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resultSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resultSet = ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    assert(ordered_array_set_isEqual(resultSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resultSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
}

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resultSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 3}, 2);

    assert(ordered_array_set_isEqual(resultSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resultSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resultSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    assert(ordered_array_set_isEqual(resultSet, expectedSet));
    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resultSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
}

void test_ordered_array_set() {
    test_ordered_array_set_in();
    test_ordered_array_set_isEqual();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();

}

void test_matrix_inputOutput() {
    matrix *matrix1 = getMemArrayOfMatrices(3, 3, 3);

    inputMatrices(matrix1, 3);

    outputMatrices(matrix1, 3);
}

void test_matrix_inputOutputFromArray() {
    matrix matrix1 = getMatrixFromArray((int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5, 2);

    outputMatrix(matrix1);
}

void test_matrix_swapRows() {
    matrix matrix1 = getMemMatrix(3, 3);

    inputMatrix(&matrix1);

    outputMatrix(matrix1);

    swapRows(matrix1, 1, 2);

    outputMatrix(matrix1);
}

void test_matrix_swapCols() {
    matrix matrix1 = getMemMatrix(3, 3);

    inputMatrix(&matrix1);

    outputMatrix(matrix1);

    swapColumns(matrix1, 1, 2);

    outputMatrix(matrix1);
}

void test_matrix_insertionSortRowsMatrixByRowCriteria() {
    matrix matrix1 = getMatrixFromArray((int[]){9, 8, 7, 6, 5, 4, 3, 2, 1}, 3, 3);
    //matrix matrix1 = getMatrixFromArray((int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5, 2);

    outputMatrix(matrix1);

    insertionSortRowsMatrixByRowCriteria(matrix1, getSum);

    outputMatrix(matrix1);

}

void test_matrix_selectionSortColsMatrixByColCriteria() {
    matrix matrix1 = getMatrixFromArray((int[]){9, 8, 7, 6, 5, 4, 3, 2, 1}, 3, 3);
    //matrix matrix1 = getMatrixFromArray((int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5, 2);

    outputMatrix(matrix1);

    selectionSortColsMatrixByColCriteria(matrix1, getSum);

    outputMatrix(matrix1);

}

void test_matrix() {
    //test_matrix_inputOutput();
    //test_matrix_inputOutputFromArray();
    //test_matrix_swapRows();
    //test_matrix_swapCols();
    //test_matrix_swapCols();
    test_matrix_insertionSortRowsMatrixByRowCriteria();
    test_matrix_selectionSortColsMatrixByColCriteria();
}

void test() {
    test_bitset();
    test_unordered_array_set();
    test_ordered_array_set();
    test_matrix();
}

int main() {
    test();

    return 0;
}