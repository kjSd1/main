cmake_minimum_required(VERSION 3.20)
project(Vse C)

set(CMAKE_C_STANDARD 11)

add_executable(Vse main.c
        algorithms/array/array.h algorithms/array/array.c
        data_structures/bitset/bitset.h data_structures/bitset/bitset.c
        data_structures/unordered_array_set/unordered_array_set.h
        data_structures/unordered_array_set/unordered_array_set.c
        data_structures/ordered_array_set/ordered_array_set.h
        data_structures/ordered_array_set/ordered_array_set.c
        )
