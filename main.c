#include <stdio.h>
#include <math.h>
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

/*bool matrix_aaaaaa(matrix m) {

}

void matrix_task13(matrix *m, size_t n) {
    int count = 0;
    for (size_t index = 0; index < n; index++) {
        m[index];
    }
}*/

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
    matrix_task11_test();
    matrix_task12_test();
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