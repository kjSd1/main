#ifndef VSE_ARRAY_H
#define VSE_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

// Ввод массива data размера n
void inputArray_(int *data, size_t n);

// Вывод массива data размера n
void outputArray_(const int *data, size_t n);

// Копирует массив data размера size в массив data2 размера
void copyArray_(const int *data, int *data2, size_t size);

// Добавление элемента value в конец массива data размера n
void append_(int *data, size_t *n, int value);

// Вставка элемента со значением value
// в массив data размера n на позицию pos
void insert_(int *data, size_t *n, size_t pos, int value);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder_(int *data, size_t *n, size_t pos);

// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void deleteByPosUnSaveOrder_(int *data, size_t *n, size_t pos);

// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int all_( const int *a, size_t n, int (*predicate) (int));

// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int any_(const int *a, size_t n, int (*predicate) (int));

// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int countIf_(const int *a, size_t n, int (*predicate) (int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void deleteIf_(int *a, size_t *n, int (*deletePredicate) (int));

// применяет функцию predicate ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void forEach_(const int *source, int *dest, size_t n, const int (*predicate) (int));

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t linearSearch_(const int *a, size_t n, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - n
size_t binarySearch_(const int *a, size_t n, int x);

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x);

// Возвращает индекс ближайшего слева от X в массиве a размера n,
// иначе, если такого нет - -1
int binarySearchNearestLeft(const int *a, size_t n, int x);

// Компоратор для целых чисел функции qsort
int compare_ints(const void *a, const void *b);

// Возвращает сумму всех элементов массива a размера n
int getSum(const int *a, size_t n);

// Возвращает позицию первого максимального элемента массива a размера n
size_t getIndexMaxElement(const int *a, size_t n);

// Возвращает позицию первого минимального элемента массива a размера n
size_t getIndexMinElement(const int *a, size_t n);

// Возвращает максимальный элемент массива a размера n
int getMaxElement(const int *a, size_t n);

// Возвращает минимальный элемент массива a размера n
int getMinElement(const int *a, size_t n);

/* Возвращает 'истина' - если все элементы уникальные,
 * иначе - 'ложь' */
bool isUnique(const int *a, size_t n);

/* Возвращает количество вхождений элемента number в массиве a размера n */
int getValueCount(const int *a, size_t n, int value);

/* Возвращает количество уникальных элементов в массиве a размера n */
int getUniqueTotal(const int *a, size_t n);

bool isOrderByPredicate(const int *a, size_t n, bool (*predicate) (const int a, const int b));


/* Возвращает 'истина' - если массив a размера n упорядочен по не убыванию,
 * иначе - 'ложь' *//*
bool isAscendingOrder(const int *a, size_t n);

*//* Возвращает 'истина' - если массив a размера n упорядочен по не возрастанию,
 * иначе - 'ложь'*//*
bool isDescendingOrder(const int *a, size_t n);*/

#endif //VSE_ARRAY_H
