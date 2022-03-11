#ifndef VSE_MATRIX_H
#define VSE_MATRIX_H

#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include "D:\_Work\_GitHub\main\algorithms\universal\universal.h"
#include "D:\_Work\_GitHub\main\algorithms\array\array.h"

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
}matrix;

typedef struct position{
    size_t rowIndex;
    size_t colIndex;
}position;

// Возвращает матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

// Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
matrix* getMemArrayOfMatrices(size_t nMatrices, int nRows, int nCols);

// Возвращает матрицу состоящую из элементов массива array
matrix getMatrixFromArray(const int *array, int nRows, int nCols);

matrix* getArrayOfMatricesFromArray(const int *array, size_t n, int nRows, int nCols);

/* Записывает в массив arrayCol элементы колонки indexCol матрицы m */
void getArrayFromColum(int *arrayCol, matrix m, size_t indexCol);

// Освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix *m);

// Освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

// Ввод матрицы m
void inputMatrix(matrix *m);

// Ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// Вывод матрицы m
void outputMatrix(matrix m);

// Вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

// Обмен строк с порядковыми номерами i1 и i2 в матрице m
void swapRows(matrix m, size_t i1, size_t i2);

// Обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, size_t j1, size_t j2);

// Выполняет сортировку вставками строк матрицы m по не убыванию значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(const int*, size_t));

// Выполняет сортировку выбором столбцов матрицы m по не убыванию значения функции criteria применяемой для столбцов
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int*, size_t));

// Возвращает значение 'истина', если матрица m является квадратной,
// 'ложь' – в противном случае
bool isSquareMatrix(matrix *m);

// Возвращает значение 'истина', если матрицы m1 и m2 равны,
// 'ложь' – в противном случае
bool areTwoMatricesEqual(matrix *m1, matrix *m2);

// Возвращает значение 'истина', если матрица m является единичной,
// 'ложь' – в противном случае
bool isEMatrix(matrix *m);

// Возвращает значение 'истина', если матрица m является симметричной,
// 'ложь' – в противном случае
bool isSymmetricMatrix(matrix *m);

// Транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix *m);

// Транспонирует матрицу m
void transposeMatrix(matrix *m);

/* Сбрасывает все значения матрицы m в 0 */
void doZeroMatrix(matrix *m);

/* Возвращает позицию минимального по рядам элемента матрицы m */
position searchMinValuePosByRows(matrix m);

/* Возвращает позицию минимального по столбцам элемента матрицы m */
position searchMinValuePosByCols(matrix m);

/* Возвращает позицию первого по рядам максимального элемента матрицы m */
position searchMaxValuePosByRows(matrix m);

/* Возвращает позицию первого по столбцам максимального элемента матрицы m */
position searchMaxValuePosByCols(matrix m);

/* Возвращает матрицу - результат умножения матрицы m1 и m2 */
matrix mulMatrices(matrix m1, matrix m2);

/* Возвращает сумму по диагонали матрицы m начиная с позиции pos*/
int getMaxElementDiagonalFrom(matrix m1, position pos);

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(const int*, size_t));

bool isRowsCorrectByPredicate(matrix m, bool (*predicate) (const int, const int));

#endif //VSE_MATRIX_H
