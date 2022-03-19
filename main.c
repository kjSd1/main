#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "D:\_Work\_GitHub\main\algorithms\array\array.h"
#include "D:\_Work\_GitHub\main\data_structures\bitset\bitset.h"
#include "D:\_Work\_GitHub\main\data_structures\unordered_array_set\unordered_array_set.h"
#include "D:\_Work\_GitHub\main\data_structures\ordered_array_set\ordered_array_set.h"
#include "D:\_Work\_GitHub\main\data_structures\matrix\matrix.h"
#include "D:\_Work\_GitHub\main\data_structures\string_\string_.h"

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
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(expectedSet);
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

void test_matrix_isSquareMatrix_SquareMatrix_Size3x3() {
    matrix m = getMemMatrix(3, 3);
    assert(isSquareMatrix(&m));
    freeMemMatrix(&m);
}

void test_matrix_isSquareMatrix_SquareMatrrix_Size1x1() {
    matrix m = getMemMatrix(1, 1);
    assert(isSquareMatrix(&m));
    freeMemMatrix(&m);
}

void test_matrix_isSquareMatrix_ErorrSize3x4() {
    matrix m = getMemMatrix(3, 4);
    assert(isSquareMatrix(&m));
    freeMemMatrix(&m);
}

void test_matrix_isSquareMatrix() {
    test_matrix_isSquareMatrix_SquareMatrix_Size3x3();
    test_matrix_isSquareMatrix_SquareMatrrix_Size1x1();
    //test_matrix_isSquareMatrix_ErorrSize3x4();
}

void test_matrix_areTwoMatricesEqual_Size1x1and1x1() {
    matrix matrix1 = getMatrixFromArray((int[]) {1}, 1, 1);
    matrix matrix2 = getMatrixFromArray((int[]) {1}, 1, 1);

    assert(areTwoMatricesEqual(&matrix1, &matrix2));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrix2);
}

void test_matrix_areTwoMatricesEqual_Size3x3and3x3() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix matrix2 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);

    assert(areTwoMatricesEqual(&matrix1, &matrix2));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrix2);
}

void test_matrix_areTwoMatricesEqual_Erorr1_Size3x3and3x3() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix matrix2 = getMatrixFromArray((int[]) {1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, 3);

    assert(!areTwoMatricesEqual(&matrix1, &matrix2));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrix2);
}

void test_matrix_areTwoMatricesEqual_Erorr2_Size3x3and3x3() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix matrix2 = getMatrixFromArray((int[]) {1, 2, 3, 4, 1, 6, 7, 8, 9}, 3, 3);

    assert(!areTwoMatricesEqual(&matrix1, &matrix2));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrix2);
}

void test_matrix_areTwoMatricesEqual_Erorr_Size3x3and3x2() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix matrix2 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 3, 2);

    assert(!areTwoMatricesEqual(&matrix1, &matrix2));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrix2);
}

void test_matrix_areTwoMatricesEqual_Size1x4and1x4() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4}, 1, 4);
    matrix matrix2 = getMatrixFromArray((int[]) {1, 2, 3, 4}, 1, 4);

    assert(areTwoMatricesEqual(&matrix1, &matrix2));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrix2);
}

void test_matrix_areTwoMatricesEqual_Size1x4and4x1() {
    matrix matrix1 = getMatrixFromArray((int[]) {4, 3, 2, 1}, 4, 1);
    matrix matrix2 = getMatrixFromArray((int[]) {4, 3, 2, 1}, 4, 1);

    assert(areTwoMatricesEqual(&matrix1, &matrix2));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrix2);
}

void test_matrix_areTwoMatricesEqual() {
    test_matrix_areTwoMatricesEqual_Erorr1_Size3x3and3x3();
    test_matrix_areTwoMatricesEqual_Erorr2_Size3x3and3x3();
    test_matrix_areTwoMatricesEqual_Erorr_Size3x3and3x2();
    test_matrix_areTwoMatricesEqual_Size1x1and1x1();
    test_matrix_areTwoMatricesEqual_Size1x4and1x4();
    test_matrix_areTwoMatricesEqual_Size3x3and3x3();
    test_matrix_areTwoMatricesEqual_Size1x4and4x1();
}

void test_matrix_isEMatrix_EMatrix() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 0, 0, 1}, 2, 2);

    assert(isEMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isEMatrix_ErrorEMatrix() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 1, 0, 1}, 2, 2);

    assert(!isEMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isEMatrix_DioganalNot1() {
    matrix matrix1 = getMatrixFromArray((int[]) {0, 0, 0, 1}, 2, 2);

    assert(!isEMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isEMatrix_Size2x1() {
    matrix matrix1 = getMatrixFromArray((int[]) {0, 0}, 2, 1);

    assert(!isEMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isEMatrix() {
    test_matrix_isEMatrix_EMatrix();
    test_matrix_isEMatrix_ErrorEMatrix();
    test_matrix_isEMatrix_DioganalNot1();
    test_matrix_isEMatrix_Size2x1();
}

void test_matrix_isSymmetricMatrix_EMatrix() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 0, 0, 1}, 2, 2);

    assert(isSymmetricMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isSymmetricMatrix_1digitOnDioganal() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 0, 0, 0}, 2, 2);

    assert(isSymmetricMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isSymmetricMatrix_Error() {
    matrix matrix1 = getMatrixFromArray((int[]) {0, 1, 0, 0}, 2, 2);

    assert(!isSymmetricMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isSymmetricMatrix_True() {
    matrix matrix1 = getMatrixFromArray((int[]) {0, 1, 1, 0}, 2, 2);

    assert(isSymmetricMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isSymmetricMatrix_2x1() {
    matrix matrix1 = getMatrixFromArray((int[]) {0, 1}, 2, 1);

    assert(!isSymmetricMatrix(&matrix1));

    freeMemMatrix(&matrix1);
}

void test_matrix_isSymmetricMatrix() {
    test_matrix_isSymmetricMatrix_EMatrix();
    test_matrix_isSymmetricMatrix_True();
    test_matrix_isSymmetricMatrix_Error();
    test_matrix_isSymmetricMatrix_1digitOnDioganal();
    test_matrix_isSymmetricMatrix_2x1();
}

void test_matrix_transposeMatrix_Square() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix resultMatrix = getMatrixFromArray((int[]) {1, 4, 7, 2, 5, 8, 3, 6, 9}, 3, 3);

    transposeSquareMatrix(&matrix1);

    assert(areTwoMatricesEqual(&matrix1, &resultMatrix));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&resultMatrix);
}

void test_matrix_transposeMatrix_Size3x4() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, 3, 4);
    matrix resultMatrix = getMatrixFromArray((int[]) {1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12}, 4, 3);

    transposeMatrix(&matrix1);

    assert(areTwoMatricesEqual(&matrix1, &resultMatrix));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&resultMatrix);
}

void test_matrix_transposeMatrix_Square_() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix resultMatrix = getMatrixFromArray((int[]) {1, 4, 7, 2, 5, 8, 3, 6, 9}, 3, 3);

    transposeMatrix(&matrix1);

    assert(areTwoMatricesEqual(&matrix1, &resultMatrix));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&resultMatrix);
}

void test_matrix_transposeMatrix() {
    test_matrix_transposeMatrix_Square();
    test_matrix_transposeMatrix_Square_();
    test_matrix_transposeMatrix_Size3x4();
}

void test_matrix_MinMax1() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);

    position posMax = searchMaxValuePosByRows(matrix1);
    position posMin = searchMinValuePosByRows(matrix1);

    assert(posMax.rowIndex == 2 && posMax.colIndex == 2 && posMin.rowIndex == 0 && posMin.colIndex == 0);

    freeMemMatrix(&matrix1);
}

void test_matrix_MinMax2() {
    matrix matrix1 = getMatrixFromArray((int[]) {5, 2, 8, 4, 5, 1, 7, 8}, 4, 2);

    position posMax = searchMaxValuePosByRows(matrix1);
    position posMin = searchMinValuePosByRows(matrix1);

    assert(posMax.rowIndex == 1 && posMax.colIndex == 0 && posMin.rowIndex == 2 && posMin.colIndex == 1);

    freeMemMatrix(&matrix1);
}

void test_matrix_MinMax() {
    test_matrix_MinMax1();
    test_matrix_MinMax2();
}

void matrix_task1(matrix m) {
    position posMax = searchMaxValuePosByRows(m);
    position posMin = searchMinValuePosByRows(m);
    swapRows(m, posMax.rowIndex, posMin.rowIndex);
}

void matrix_task1_test() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 4, 2);

    matrix_task1(matrix1);

    matrix matrixResult = getMatrixFromArray((int[]) {7, 8, 3, 4, 5, 6, 1, 2}, 4, 2);
    assert(areTwoMatricesEqual(&matrix1, &matrixResult));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrixResult);
}

void matrix_task2(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMaxElement);
}

void matrix_task2_test() {
    matrix matrix1 = getMatrixFromArray((int[]) {3, 3, 1, 1, 2, 2, 8, 8}, 4, 2);

    matrix_task2(matrix1);

    matrix matrixResult = getMatrixFromArray((int[]) {1, 1, 2, 2, 3, 3, 8, 8}, 4, 2);
    assert(areTwoMatricesEqual(&matrix1, &matrixResult));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrixResult);
}

void matrix_task3(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMinElement);
}

void matrix_task3_test() {
    matrix matrix1 = getMatrixFromArray((int[]) {3, 2, 4, 1, 3, 2, 4, 1}, 2, 4);

    matrix_task3(matrix1);

    matrix matrixResult = getMatrixFromArray((int[]) {1, 2, 3, 4, 1, 2, 3, 4}, 2, 4);
    assert(areTwoMatricesEqual(&matrix1, &matrixResult));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrixResult);
}

matrix matrix_task4(matrix m) {
    if (isSymmetricMatrix(&m))
        return mulMatrices(m, m);
    return m;
}

void matrix_task4_test() {
    matrix matrix1 = getMatrixFromArray((int[]) {0, 2, 3, 2, 0, 4, 3, 4, 0}, 3, 3);

    matrix1 = matrix_task4(matrix1);

    matrix matrixResult = getMatrixFromArray((int[]) {13, 12, 8, 12, 20, 6, 8, 6, 25}, 3, 3);
    assert(areTwoMatricesEqual(&matrix1, &matrixResult));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrixResult);
}

void matrix_task5(matrix m) {
    int *sum = (int*)calloc(m.nCols, sizeof(int));
    for (size_t index = 0; index < m.nCols; index++)
        sum[index] = getSum(m.values[index], m.nCols);

    if (isUnique(sum, m.nCols))
        transposeSquareMatrix(&m);
}

void matrix_task5_test1() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    matrix_task5(matrix1);

    matrix matrixResult = getMatrixFromArray((int[]) {1, 3, 2, 4}, 2, 2);
    assert(areTwoMatricesEqual(&matrixResult, &matrix1));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrixResult);
}

void matrix_task5_test2() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 0}, 2, 2);

    matrix_task5(matrix1);

    matrix matrixResult = getMatrixFromArray((int[]) {1, 2, 3, 0}, 2, 2);
    assert(areTwoMatricesEqual(&matrixResult, &matrix1));

    freeMemMatrix(&matrix1);
    freeMemMatrix(&matrixResult);
}

void matrix_task5_test() {
    matrix_task5_test1();
    matrix_task5_test2();
}

bool matrix_task6(matrix m1, matrix m2) {
    matrix mulMatrix = mulMatrices(m1, m2);

    bool flagEMatrix = 0;
    if (isEMatrix(&mulMatrix))
        flagEMatrix = 1;

    freeMemMatrix(&mulMatrix);

    return flagEMatrix;
}

void matrix_task6_test() {
    matrix m1 = getMatrixFromArray((int[]) {2, 5, 7, 6, 3, 4, 5, -2, -3}, 3, 3);
    matrix m2 = getMatrixFromArray((int[]) {1, -1, 1, -38, 41, -34, 27, -29, 24}, 3, 3);

    assert(matrix_task6(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

int matrix_task7(matrix m) {
    ordered_array_set setMax = ordered_array_set_create(m.nCols + m.nRows);

    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        ordered_array_set_insert(&setMax, getMaxElementDiagonalFrom(m, (position) {indexRow, 0}));
    for (size_t indexCol = 1; indexCol < m.nCols; indexCol++)
        ordered_array_set_insert(&setMax, getMaxElementDiagonalFrom(m, (position) {0, indexCol}));

    int sum = getSum(setMax.data, setMax.size);
    ordered_array_set_delete(setMax);

    return sum;
}

void matrix_task7_test() {
    matrix matrix1 = getMatrixFromArray((int[]) {3, 2, 5, 4, 1, 3, 6, 3, 3, 2, 1, 2}, 3, 4);

    assert(matrix_task7(matrix1) == 20);

    freeMemMatrix(&matrix1);
}

int min2 (const int a, const int b) {
    return a < b ? a : b;
}

int matrix_task8(matrix m) {
    position posMax = searchMaxValuePosByRows(m);

    int min = m.values[posMax.rowIndex][posMax.colIndex];

    posMax.rowIndex--;
    posMax.colIndex--;

    size_t size = 3;
    while (posMax.rowIndex != -1) {
        int minOnCouch = getMinElement(&m.values[posMax.rowIndex][posMax.colIndex], size);
        min = min2(min, minOnCouch);
        if (posMax.colIndex) {
            posMax.colIndex--;
            size++;
        }
        if (size + posMax.colIndex < m.nCols)
            size++;
        posMax.rowIndex--;
    }

    return min;
}

void matrix_task8_testCheckCenter() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 10, -1, -2, -3, -4}, 3, 3);

    assert(matrix_task8(matrix1) == 1);

    freeMemMatrix(&matrix1);
}

void matrix_task8_testCheckLeft() {
    matrix matrix1 = getMatrixFromArray((int[]) {9, 2, 3, 4, 1, 100, -1, -2, -3, -4, -5, -6}, 3, 4);

    assert(matrix_task8(matrix1) == 2);

    freeMemMatrix(&matrix1);
}

void matrix_task8_testCheckRight() {
    matrix matrix1 = getMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 100, -1, -2, -3, -4, -5}, 3, 4);

    assert(matrix_task8(matrix1) == 2);

    freeMemMatrix(&matrix1);
}

void matrix_task8_test() {
    matrix_task8_testCheckCenter();
    matrix_task8_testCheckLeft();
    matrix_task8_testCheckRight();
}

float getDistance(const int *a, size_t size) {
    int distance = 0;
    for (size_t index = 0; index < size; index++) {
        distance += a[index];
    }

    return sqrtf(distance);
}

void matrix_task9(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void matrix_task9_test() {
    matrix m = getMatrixFromArray((int[]) {20, 10, 5, 6, 4, 11, 12, 9, 4, 1, 1, 2}, 3, 4);

    matrix_task9(m);

    matrix resultMatrix = getMatrixFromArray((int[]) {4, 1, 1, 2, 4, 11, 12, 9, 20, 10, 5, 6}, 3, 4);
    assert(areTwoMatricesEqual(&m, &resultMatrix));

    freeMemMatrix(&m);
    freeMemMatrix(&resultMatrix);
}

int matrix_task10(matrix m) {
    int *sum = (int*)calloc(m.nRows, sizeof(int));
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        sum[indexRow] = getSum(m.values[indexRow], m.nCols);

    int uniqueTotal = getUniqueTotal(sum, m.nRows);
    free(sum);

    return uniqueTotal;
}

void matrix_task10_test() {
    matrix m = getMatrixFromArray((int[]){1, 2, 3, 0, 1, 1, 2, 0, 0, 0, 1, 10}, 6, 2);

    assert(matrix_task10(m) == 2);

    freeMemMatrix(&m);
}

int matrix_task11(matrix m) {
    int specialTotal  = 0;
    int *arrayCol = (int*)calloc(m.nRows, sizeof(int));
    for (size_t indexCol = 0; indexCol < m.nCols; indexCol++) {
        getArrayFromColum(arrayCol, m, indexCol);
        int max = getMaxElement(arrayCol, m.nRows);
        specialTotal += (getSum(arrayCol, m.nRows) - max) < max;
    }
    return specialTotal;
}

void matrix_task11_test1() {
    matrix m = getMatrixFromArray((int[]){3, 10, 11, 6, 3, 5, 5, 7, 3, 5, 5, 2}, 3, 4);

    assert(matrix_task11(m) == 1);

    freeMemMatrix(&m);
}

void matrix_task11_test2() {
    matrix m = getMatrixFromArray((int[]){3, 5, 5, 4, 2, 3, 6, 7, 12, 2, 1, 2}, 3, 4);

    assert(matrix_task11(m) == 2);

    freeMemMatrix(&m);
}

void matrix_task11_test() {
    matrix_task11_test1();
    matrix_task11_test2();
}

void matrix_task12(matrix *m) {
    assert(m->nRows > 1);
    position posMinByCols = searchMinValuePosByCols(*m);
    int* arrayCol = (int*) calloc(m->nRows, sizeof(int));
    getArrayFromColum(arrayCol, *m, posMinByCols.colIndex);
    copyArray_(arrayCol, m->values[m->nRows - 2], m->nRows);
}

void matrix_task12_test() {
    matrix m = getMatrixFromArray((int[]){1, 2, 2, 1, 2, 2, 1, 2, 2}, 3, 3);
    matrix_task12(&m);

    matrix matrixResult = getMatrixFromArray((int[]){1, 2, 2, 1, 1, 1, 1, 2, 2}, 3, 3);
    assert(areTwoMatricesEqual(&matrixResult, &m));

    freeMemMatrix(&m);
    freeMemMatrix(&matrixResult);
}

bool leftMinOrEqual(const int a, const int b) {
    return a <= b;
}

int matrix_task13(matrix *m, size_t n) {
    int count = 0;
    for (size_t index = 0; index < n; index++) {
        count += isRowsCorrectByPredicate(m[index], leftMinOrEqual);
    }
    return count;
}

void matrix_task13_test() {
    matrix* arrayMatrix = getArrayOfMatricesFromArray((int[]) {7, 1, 1, 1,
                                                               1, 6, 2, 2,
                                                               5, 4, 2, 3,
                                                               1, 3, 7, 9}, 4, 2, 2);

    assert(matrix_task13(arrayMatrix, 4) == 2);
    freeMemMatrices(arrayMatrix, 4);
}

int isZero(int x) {
    return x == 0;
}

int getZeroRows(matrix m) {
    int count = 0;
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        count += all_(m.values[indexRow], m.nCols, isZero);
    return count;
}

void matrix_task14(matrix *m, size_t n) {
    int *maxTotalZeroRows = calloc(n, sizeof(int));
    for (size_t index = 0; index < n; index++) {
        maxTotalZeroRows[index] =  getZeroRows(m[index]);
    }
    int max = getMaxElement(maxTotalZeroRows, n);
    /*for (int i = 0; i < n; i++)
        if (maxTotalZeroRows[i] == max)
            outputMatrix(m[i]); // для правильной работы task14 раскоментить
    */free(maxTotalZeroRows);
}

void matrix_task14_test() {
    matrix *m = getArrayOfMatricesFromArray((int[]) {0, 1, 1, 0, 0, 0,
                                                    1, 1, 2, 1, 1, 1,
                                                    0, 0, 0, 0, 4, 7,
                                                    0, 0, 0, 1, 0, 0,
                                                    0, 1, 0, 2, 0, 3}, 5, 3, 2);
    matrix_task14(m, 5);
    freeMemMatrices(m, 5);
}



void matrix_task() {
    matrix_task1_test();
    matrix_task2_test();
    matrix_task3_test();
    matrix_task4_test();
    matrix_task5_test();
    matrix_task6_test();
    matrix_task7_test();
    matrix_task8_test();
    matrix_task9_test();
    matrix_task10_test();
    matrix_task10_test();
    matrix_task11_test();
    matrix_task12_test();
    matrix_task13_test();
    matrix_task14_test();
}

void test_matrix() {
    //test_matrix_inputOutput();
    //test_matrix_inputOutputFromArray();
    //test_matrix_swapRows();
    //test_matrix_swapCols();
    //test_matrix_swapCols();
    //test_matrix_insertionSortRowsMatrixByRowCriteria();
    //test_matrix_selectionSortColsMatrixByColCriteria();
    test_matrix_isSquareMatrix();
    test_matrix_areTwoMatricesEqual();
    test_matrix_isEMatrix();
    test_matrix_isSymmetricMatrix();
    test_matrix_transposeMatrix();
    test_matrix_MinMax();
    matrix_task();
}

void test_string_StrLen_() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";

    assert(strLen(s1) == 2);
    assert(strLen(s2) == 7);
}

void test_string_StrLen_Empty() {
    char *s1 = "";

    assert(strLen(s1) == 0);
}

void test_string_StrLen() {
    test_string_StrLen_Empty();
    test_string_StrLen_();
}

void test_string_find() {
    char s[12] = "C++IamGOING";
    char ch = '+';
    char *symbol = find(&s[0], &s[11], ch);

    assert(*symbol == s[1]);
}

void test_string_findNonSpace_NotSpace() {
    char s[5] = "O(n)";
    char *symbol = findNonSpace(s);

    assert(*symbol == s[0]);
}

void test_string_findNonSpace_Space() {
    char s[9] = " O(n ^ 2)";
    char *symbol = findNonSpace(s);

    assert(*symbol == s[1]);
}

void test_string_findNonSpace() {
    test_string_findNonSpace_NotSpace();
    test_string_findNonSpace_Space();
}

void test_string_findSpace_NotSpace() {
    char s[5] = "O(n)";
    char *symbol = findSpace(s);

    assert(*symbol == s[4]);
}

void test_string_findSpace_Space() {
    char s[9] = "O(n ^ 2)";
    char *symbol = findSpace(s);

    assert(*symbol == s[3]);
}

void test_string_findSpace() {
    test_string_findSpace_NotSpace();
    test_string_findSpace_Space();
}

void test_string_findNonSpaceReverse_NotSpace() {
    char s[5] = "O(n)";
    char *symbol = findNonSpaceReverse(&s[3], &s[-1]);

    assert(*symbol == s[3]);
}

void test_string_findNonSpaceReverse_Space() {
    char s[10] = "O(n ^ 2) ";
    char *symbol = findNonSpaceReverse(&s[8], &s[-1]);

    assert(*symbol == s[7]);
}

void test_string_findNonSpaceReverse() {
    test_string_findNonSpaceReverse_NotSpace();
    test_string_findNonSpaceReverse_Space();
}

void test_string_findSpaceReverse_NotSpace() {
    char s[5] = "O(n)";
    char *symbol = findSpaceReverse(&s[3], &s[-1]);

    assert(*symbol == s[-1]);
}

void test_string_findSpaceReverse_Space() {
    char s[9] = "O(n ^ 2)";
    char *symbol = findSpaceReverse(&s[8], &s[-1]);

    assert(*symbol == s[5]);
}

void test_string_findSpaceReverse() {
    test_string_findSpaceReverse_NotSpace();
    test_string_findSpaceReverse_Space();
}

void test_string_strcmp_Negative() {
    char s1[5] = "ABCC";
    char s2[5] = "ABCD";

    assert(strcmp_(s1, s2) < 0);
}

void test_string_strcmp_Zero() {
    char s1[5] = "ABCD";
    char s2[5] = "ABCD";

    assert(!strcmp_(s1, s2));
}

void test_string_strcmp_Positive() {
    char s1[5] = "ABCD";
    char s2[5] = "ABCC";

    assert(strcmp_(s1, s2) > 0);
}

void test_string_strcmp_() {
    test_string_strcmp_Negative();
    test_string_strcmp_Zero();
    test_string_strcmp_Positive();
}

void test_string_copy() {
    char s1[6] = "Hello";
    char s2[6];

    char *ptr = copy(s1, &s1[5], s2);
    *ptr = '\0';

    assert(!strcmp_(s1, s2));
}

int isNotSpace(int x) {
    if (isspace(x))
        return 0;
    return 1;
}

void test_string_copyIf() {
    char s1[6] = "1 2 3";
    char s2[6];

    char sResult[4] = "123";

    char *ptr = copyIf(s1, &s1[5], s2, isNotSpace);
    *ptr = '\0';

    assert(!strcmp_(sResult, s2));
}

void test_string_copyIfReverse() {
    char s1[6] = "1 2 3";
    char s2[6];

    char sResult[4] = "321";

    char *ptr = copyIfReverse(&s1[4], &s1[-1], s2, isNotSpace);
    *ptr = '\0';

    assert(!strcmp_(sResult, s2));
}

void test_string_getEndOfString() {
    char s1[6] = "1 2 3";
    char *ptrEnd = getEndOfString(s1);

    assert(*ptrEnd == '\0');
}

void task_string1(char *s) {
    char *ptrEnd = getEndOfString(s);
    char *destination = copyIf(s, ptrEnd, s, isNotSpace);
    *destination = '\0';
}

void test_string_task1_WithSpace() {
    char s[6] = "1 2\t3";
    task_string1(s);

    ASSERT_STRING("123", s);
}

void task_string2(char *s) {
    char *read = s + 1;
    char *write = s;
    while (*read != '\0') {
        if (*read != *write)
            *(++write) = *read;
        read++;
    }
    *(++write) = '\0';
}

void test_string_task2() {
    char s[10] = "12  344\n\n";
    task_string2(s);

    ASSERT_STRING("12 34\n", s);
}

void task_string3(char *s) {
    char *beginString = s;
    WordDescriptor word;

    while (getWord(beginString, &word)) {
        char *endBuffer = copy(word.begin, word.end, stringBuffer);
        beginString = copyIfReverse(endBuffer, stringBuffer - 1, beginString, isdigit);
        beginString = copyIf(stringBuffer, endBuffer, beginString, isalpha);
        beginString++;
    }
}

void test_string_task3_WordAndDigit() {
    char s[11] = "AB21 AB3C1";
    task_string3(s);

    ASSERT_STRING("12AB 13ABC", s);
}

void test_string_task3_empty() {
    char s[1] = "";
    task_string3(s);

    ASSERT_STRING("", s);
}

void test_string_task3_OneSpace() {
    char s[2] = " ";
    task_string3(s);

    ASSERT_STRING(" ", s);
}

void test_string_task3() {
    test_string_task3_WordAndDigit();
    test_string_task3_empty();
    test_string_task3_OneSpace();
}

void task_string4(char *s) {
    char *posWrite = s;
    char *endReadBuffer = copy(posWrite, posWrite + strLen(s), stringBuffer);
    char *posReadBuffer = stringBuffer;
    while (posReadBuffer != endReadBuffer) {
        if (isdigit(*posReadBuffer))
            for (char count = *posReadBuffer; count != '0'; count--)
                *posWrite++ = ' ';
        else
            *posWrite++ = *posReadBuffer;
        posReadBuffer++;
    }
    *posWrite = '\0';
}

void test_string_task4Universal() {
    char s[7] = "AB2 AB";
    task_string4(s);

    ASSERT_STRING("AB   AB", s);
}

void task_string5(char *s, char *w1, char *w2) {
    size_t w1Size = strLen(w1);
    size_t w2Size = strLen(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr = s;
    char *recPtr = s;
    if (w2Size > w1Size) {
        copy(s, getEndOfString(s), stringBuffer);
        readPtr = stringBuffer;
    }

    WordDescriptor word;
    while (getWord(readPtr, &word)) {
        char *firstNonSpace = findNonSpace(readPtr);
        recPtr = copy(readPtr, firstNonSpace, recPtr);
        readPtr += word.end - word.begin + firstNonSpace - readPtr;
        if (!wordCmp(word1, word)) {
            word.begin = word2.begin;
            word.end = word2.end;
        }
        recPtr = copy(word.begin, word.end, recPtr);
    }
    *recPtr = '\0';
}

void test_string_task5_W1LessW2() {
    char w1[2] = "1";
    char w2[3] = "22";
    char string[] = "ABC ABC1 1ABC 1 11";

    task_string5(string, w1, w2);

    ASSERT_STRING("ABC ABC1 1ABC 22 11", string);
}

void test_string_task5_W2LessW1() {
    char w1[3] = "11";
    char w2[2] = "2";

    char string[] = "ABC ABC1 1ABC 1 11";

    task_string5(string, w1, w2);

    ASSERT_STRING("ABC ABC1 1ABC 1 2", string);
}

void test_string_task5_MoreSpace() {
    char w1[4] = "123";
    char w2[4] = "   ";

    char string[] = "123 123 123 1234 123 1";
    task_string5(string, w1, w2);

    ASSERT_STRING("            1234     1", string);
}

void test_string_task5() {
    test_string_task5_W1LessW2();
    test_string_task5_W2LessW1();
    test_string_task5_MoreSpace();
}

int task_string6(char *s) {
    char *readPtr = s;

    WordDescriptor word1;
    if (!getWord(readPtr, &word1))
        return 1;
    readPtr = word1.end;

    WordDescriptor word2;
    while (getWord(readPtr, &word2)) {
        if (wordCmp(word1, word2) > 0)
            return 0;
        readPtr = word2.end;
        word1.begin = word2.begin;
        word1.end = word2.end;
    }
    return 1;
}

void test_string_task6_ManyWord() {
    char s[] = "123AB 124AB 124AB 124ABB   124ABC";

    assert(task_string6(s));
}

void test_string_task6_ErrorLenWords() {
    char s[] = "11 1";

    assert(!task_string6(s));
}

void test_string_task6() {
    test_string_task6_ManyWord();
    test_string_task6_ErrorLenWords();
}

int isAlwaysTrue(int x) {
    return 1;
}

void task_string7(char *s) {
    char *ptr = copy(s, getEndOfString(s), stringBuffer);
    *ptr = '\0';

    getBagOfWords(&bag, stringBuffer);

    char *wordOutput = s;
    for (size_t index = 0; index < bag.size; index++) {
        ptr = copyIfReverse(bag.words[index].end - 1, bag.words[index].begin - 1, wordOutput, isAlwaysTrue);
        *ptr = '\0';
        printf("%s\n", wordOutput);
    }
}

// divoc
// dab
void test_task_string7() {
    char s[] = "covid bad";
    task_string7(s);
}

int task_string8(char *s) {
    int count = 0;
    char *ptrString = s;

    WordDescriptor word;
    while (getWord(ptrString, &word)) {
        if (isPalindrome(word))
            count++;
        ptrString = word.end;
    }
    return count;
}

void test_task_string8() {
    char s[] = "pop oppo aa   a 123";
    assert(task_string8(s) == 4);
}

//----------------------------------------------------------------------------------------
void task_string9(char *s) {

}

void test_task_string9() {

}

void task_string10(char *s) {
    char *readBuffer = copy(s, getEndOfString(s), stringBuffer);
    readBuffer--;

    char *writeString = s;
    WordDescriptor word;
    while (getWordBack(readBuffer, stringBuffer - 1, &word)) {
        writeString = copy(word.end, readBuffer + 1, writeString);
        readBuffer = word.begin - 1;
        writeString = copy(word.begin, word.end, writeString);
    }
    writeString = copy(stringBuffer, readBuffer + 1, writeString);
    *writeString = '\0';
}

void test_string_task10_RandomString() {
    char s[9] = "123 1233";
    task_string10(s);

    ASSERT_STRING("1233 123", s);
}

void test_string_task10_TwoSpace() {
    char s[17] = " 123 1233  12345";

    task_string10(s);

    ASSERT_STRING("12345  1233 123 ", s);
}

void test_string_task10_MORESpace() {
    char s[14] = "  123  1233  ";

    task_string10(s);

    ASSERT_STRING("  1233  123  ", s);
}

void test_task_string10() {
    test_string_task10_RandomString();
    test_string_task10_TwoSpace();
    test_string_task10_MORESpace();
}

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode task_string11(char *s) {
    WordDescriptor word;
    if (!getWord(s, &word))
        return EMPTY_STRING;

    char *endString = getEndOfString(s);
    char *firsSymbolA = find(s, endString, 'A');
    if (firsSymbolA == endString)
        return NOT_FOUND_A_WORD_WITH_A;
    getWordBack(firsSymbolA, s - 1, &word);

    if (!getWordBack(word.begin - 1, s - 1, &word))
        return FIRST_WORD_WITH_A;
    else {
        outputWord(word);
        return WORD_FOUND;
    }
}

void test_string_task11() {
    char s1[] = "";
    assert(task_string11(s1) == EMPTY_STRING);

    char s2[] = " ABC";
    assert(task_string11(s2) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(task_string11(s3) == WORD_FOUND);

    char s4[] = "BC";
    assert(task_string11(s4) == NOT_FOUND_A_WORD_WITH_A);

    char s5[] = "B Q WE YR OW IUWR ";
    assert (task_string11(s4) == NOT_FOUND_A_WORD_WITH_A);

    char s6[] = "B Q WE YR OWO IUAR ";
    assert (task_string11(s6) == WORD_FOUND);
}

WordDescriptor string_task12(char *string1, char *string2) {
    getBagOfWords(&bag, string1);
    getBagOfWords(&bag2, string2);
    for (size_t indexCheckReverse = bag.size - 1; indexCheckReverse != SIZE_MAX; indexCheckReverse--)
        for (size_t indexCmp = 0; indexCmp < bag2.size; indexCmp++)
            if (!wordCmp(bag.words[indexCheckReverse], bag2.words[indexCmp]))
                return bag.words[indexCheckReverse];

    WordDescriptor word = {NULL, NULL};
    return word;
}

void test_string_task12() {
    char s1test1[] = "";
    char s2test1[] = "";
    char sTestResult1[] = "";
    wordDescriptorToString(string_task12(s1test1, s2test1), sTestResult1);
    ASSERT_STRING("", sTestResult1);

    char s1test2[] = "ABC";
    char s2test2[] = "CBA";
    char sTestResult2[] = "";
    wordDescriptorToString(string_task12(s1test2, s2test2), sTestResult2);
    ASSERT_STRING("", sTestResult2);

    char s1test3[] = "ABC1 ABC ABC1";
    char s2test3[] = "ABC";
    char sTestResult3[] = "";
    wordDescriptorToString(string_task12(s1test3, s2test3), sTestResult3);
    ASSERT_STRING("ABC", sTestResult3);

    char s1test4[] = "ABC ABC1 ABC2";
    char s2test4[] = "ABC1 ABC1 ABC";
    char sTestResult4[] = "";
    wordDescriptorToString(string_task12(s1test4, s2test4), sTestResult4);
    ASSERT_STRING("ABC1", sTestResult4);

    char s1test5[] = "  ABC  ";
    char s2test5[] = "123 ABC 123";
    char sTestResult5[] = "";
    wordDescriptorToString(string_task12(s1test5, s2test5), sTestResult5);
    ASSERT_STRING("ABC", sTestResult5);
}

int task_string13(char *s) {
    getBagOfWords(&bag, s);
    for (size_t index = 0; index < bag.size; index++)
        for (size_t indexCheck = index + 1; indexCheck < bag.size; indexCheck++)
            if (!wordCmp(bag.words[index], bag.words[indexCheck]))
                return 1;
    return 0;
}

void test_string_task13() {
    char s[] = "123 1233 12345 123";
    assert(task_string13(s));

    char s1[] = "123 1233 12345 1234";
    assert(!task_string13(s1));

    char s2[] = "   123 1233 12345 1234          123   ";
    assert(task_string13(s2));
}

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}

int string_task14(char *s) {
    *copy(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&bag, stringBuffer);

    for (size_t index = 0; index < bag.size; ++index)
        qsort(bag.words[index].begin, bag.words[index].end - bag.words[index].begin, sizeof(char), cmp);

    return task_string13(stringBuffer);
}

void test_string_task14_IsEmpty() {
    char s[] = "";
    assert(!string_task14(s));
}

void test_string_task14_oneWordInString() {
    char s[] = "ABC";
    assert(!string_task14(s));
}

void test_string_task14_IsSameLettersInWords() {
    char s[] = "ABC CAB";
    assert(string_task14(s));
}

void test_string_task14_NotSameLettersInWord() {
    char s[] = "ABC CAD";
    assert(!string_task14(s));
}

void test_areWordsFromSameLetters_MoreIsSameLettersInWords() {
    char s[] = "ABC CAD BAC CAB DAC";
    assert(string_task14(s));
}

void test_string_task14() {
    test_string_task14_IsEmpty();
    test_string_task14_oneWordInString();
    test_string_task14_IsSameLettersInWords();
    test_string_task14_NotSameLettersInWord();
    test_areWordsFromSameLetters_MoreIsSameLettersInWords();
}

// Так как в задании сказано получить строку из слов не равных последнему, то в качестве разделителя слов использовался пробел
void string_task15(char *s) {
    char *write = s;
    getBagOfWords(&bag, s);

    for (size_t index = 0; index < bag.size - 1; index++) {
        if (wordCmp(bag.words[index], bag.words[bag.size - 1])) {
            write = copy(bag.words[index].begin, bag.words[index].end, write);
            *write++ = ' ';
        }
    }
    if (write == s)
        *write = '\0';
    else
        *(--write) = '\0';
}

void test_string_task15_TwoPrint() {
    char s[] = "abc abc1 abc";
    string_task15(s);

    ASSERT_STRING("abc1", s);
}

void test_string_task15_Empty() {
    char s[] = "abc abc";
    string_task15(s);

    ASSERT_STRING("", s);
}

void test_string_task15() {
    test_string_task15_Empty();
    test_string_task15_TwoPrint();
}

WordDescriptor string_task16(char *string1, char *string2) {
    getBagOfWords(&bag, string1);
    getBagOfWords(&bag2, string2);
    for (size_t indexCheckReverse = bag.size - 1; indexCheckReverse != SIZE_MAX; indexCheckReverse--)
        for (size_t indexCmp = 0; indexCmp < bag2.size; indexCmp++)
            if (!wordCmp(bag.words[indexCheckReverse], bag2.words[indexCmp]))
                return bag.words[indexCheckReverse];

    WordDescriptor word = {NULL, NULL};
    return word;
}

void test_string_task16() {
    char s1test1[] = "";
    char s2test1[] = "";
    char sTestResult1[] = "";
    wordDescriptorToString(string_task16(s1test1, s2test1), sTestResult1);
    ASSERT_STRING("", sTestResult1);

    char s1test2[] = "ABC";
    char s2test2[] = "CBA";
    char sTestResult2[] = "";
    wordDescriptorToString(string_task16(s1test2, s2test2), sTestResult2);
    ASSERT_STRING("", sTestResult2);

    char s1test3[] = "ABC1 ABC ABC1";
    char s2test3[] = "ABC";
    char sTestResult3[] = "";
    wordDescriptorToString(string_task16(s1test3, s2test3), sTestResult3);
    ASSERT_STRING("ABC", sTestResult3);

    char s1test4[] = "ABC ABC1 ABC2";
    char s2test4[] = "ABC1 ABC1 ABC";
    char sTestResult4[] = "";
    wordDescriptorToString(string_task16(s1test4, s2test4), sTestResult4);
    ASSERT_STRING("ABC1", sTestResult4);

    char s1test5[] = "  ABC  ";
    char s2test5[] = "123 ABC 123";
    char sTestResult5[] = "";
    wordDescriptorToString(string_task16(s1test5, s2test5), sTestResult5);
    ASSERT_STRING("ABC", sTestResult5);
}

// Удаление слов палиндромов
void string_task17(char *s) {
    char *read = s;
    char *write = s;

    WordDescriptor word;
    while (getWord(read, &word)) {
        if (!isPalindrome(word))
            write = copy(read, word.end, write);
        read = word.end;
    }
    if (write != s)
        write = copy(word.end, getEndOfString(s), write);
    *write = '\0';
}

void test_string_task17_RandomString() {
    char s[] = " abc aba abba a  abc ";

    string_task17(s);

    ASSERT_STRING(" abc  abc ", s);
}

void test_string_task17_CheckSpace() {
    char s[] = "  abc a  abc";

    string_task17(s);

    ASSERT_STRING("  abc  abc", s);
}

void test_string_task17_Empty() {
    char s[] = " aba ";

    string_task17(s);

    ASSERT_STRING("", s);
}

void test_string_task17() {
    test_string_task17_RandomString();
    test_string_task17_CheckSpace();
    test_string_task17_Empty();
}

void string_task18(char *string1, char *string2) {
    getBagOfWords(&bag, string1);
    getBagOfWords(&bag2, string2);

    int des = (int)bag.size - bag2.size;
    char *endString1 = getEndOfString(string1);
    char *endString2 = getEndOfString(string2);
    char *write;
    if (des < 0)
        write = copy(bag2.words[bag.size - 1].end, endString2, endString1);
    else if (des > 0)
        write = copy(bag.words[bag2.size - 1].end, endString1, endString2);
    else
        return;
    *write = '\0';
}

void test_string_task18() {
    char s1[MAX_STRING_SIZE] = " abc  abcc  ";
    char s2[MAX_STRING_SIZE] = "abc abc abc ";
    string_task18(s1, s2);

    ASSERT_STRING(" abc  abcc   abc ", s1);
    ASSERT_STRING("abc abc abc ", s2);

    char s1_2[MAX_STRING_SIZE] = "      abc abc     abc ";
    char s2_2[MAX_STRING_SIZE] = " abc  abcc  ";
    string_task18(s1_2, s2_2);

    ASSERT_STRING("      abc abc     abc ", s1_2);
    ASSERT_STRING(" abc  abcc       abc ", s2_2);

}

void test_string_task() {
    test_string_task1_WithSpace();
    test_string_task2();
    test_string_task3();
    test_string_task4Universal();
    test_string_task5();
    test_string_task6();
    //test_task_string7();
    test_task_string8();

    test_task_string10();
    test_string_task11();
    test_string_task12();
    test_string_task13();
    test_string_task14();
    test_string_task15();
    test_string_task16();
    test_string_task17();
    test_string_task18();
}

void test_string_() {
    test_string_StrLen();
    test_string_find();
    test_string_findNonSpace();
    test_string_findSpace();
    test_string_findNonSpaceReverse();
    test_string_findSpaceReverse();
    test_string_strcmp_();
    test_string_copy();
    test_string_copyIf();
    test_string_copyIfReverse();
    test_string_task();
}

void test() {
    test_bitset();
    test_unordered_array_set();
    test_ordered_array_set();
    test_matrix();
    test_string_();
}

int main() {
    test();

    return 0;
}