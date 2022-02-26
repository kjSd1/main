#ifndef VSE_UNORDERED_ARRAY_SET_H
#define VSE_UNORDERED_ARRAY_SET_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>
#include "D:\_Work\_GitHub\main\algorithms\array\array.h"

typedef struct unordered_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
}unordered_array_set;

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set, иначе - n
size_t unordered_array_set_in(unordered_array_set set, int value);

// возвращает значение 'истина', если множество subset является подмножеством set
// иначе - 'ложь'
bool unordered_array_set_isSubset(unordered_array_set set, unordered_array_set subset);

// возвращает значение 'истина', если элементы множеств set1 и set2 равны
// иначе - 'ложь'
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2);

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2);

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2);

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2);

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2);

// Возвращает дополнение до универсума universumSet множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet);

// Возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity);

// Возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size);

// Возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set);

// Добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value);

// Удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value);

// Вывод множества set
void unordered_array_set_print(unordered_array_set set);

// Освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set);

// Изменяет максимальное количество элементов в множестве если оно больше чем текущий размер
void unordered_array_set_changeCapacityIf(unordered_array_set *set);

#endif //VSE_UNORDERED_ARRAY_SET_H
