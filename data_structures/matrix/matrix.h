#ifndef VSE_MATRIX_H
#define VSE_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
}matrix;

typedef struct position{
    int rowIndex;
    int colIndex;
}position;

#endif //VSE_MATRIX_H
