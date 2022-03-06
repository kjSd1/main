#ifndef VSE_MATRIX_H
#define VSE_MATRIX_H

#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include "D:\_Work\_GitHub\main\algorithms\universal\universal.h"
#include "D:\_Work\_GitHub\main\algorithms\array\array.h"

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
}matrix;

typedef struct position{
    int rowIndex;
    int colIndex;
}position;

// Возвращает матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

// Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
matrix* getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// Ввод матрицу состоящую из элементов массива array
matrix getMatrixFromArray(const int *array, int nRows, int nCols);

// Освобождает память, выделенную под хранение матрицы m. Процесс освобождения изображен на рисунке
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
void swapRows(matrix m, int i1, int i2);

// Обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

// Выполняет сортировку вставками строк матрицы m по неубыванию значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int*, size_t));

// Выполняет сортировку выбором столбцов матрицы m по неубыванию значения функции criteria применяемой для столбцов
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, size_t));

#endif //VSE_MATRIX_H
