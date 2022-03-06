#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int**)malloc(sizeof(int*) * nRows);
    for (size_t i = 0; i < nRows; i ++)
        values[i] = (int*)malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix* getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *matrixArray = (matrix*)calloc(nMatrices, sizeof(matrix));
    for (size_t index = 0; index < nMatrices; index++)
        matrixArray[index] = getMemMatrix(nRows, nCols);
    return matrixArray;
}

matrix getMatrixFromArray(const int *array, int nRows, int nCols) {
    matrix newMatrix = getMemMatrix(nRows, nCols);
    for (size_t indexRow = 0; indexRow < newMatrix.nRows; indexRow++)
        copyArray_(&array[indexRow * newMatrix.nCols], newMatrix.values[indexRow], newMatrix.nCols);
    return newMatrix;
}

void freeMemMatrix(matrix *m) {
    for (size_t index = 0; index < m->nRows; index++)
        free(m->values[index]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (size_t index = 0; index < nMatrices; index++)
        freeMemMatrix(ms++);
}

void reserveMemMatrix(matrix *m, int newRowsTotal, int newColsTotal) {
    /*int **values = (int**) malloc(sizeof(int*) * newRowsTotal);
    for (size_t i = 0; i < newRowsTotal; i ++)
        values[i] = (int*)malloc(sizeof(int) * newColsTotal);
    m->values = values;
    m->nRows = newRowsTotal;
    m->nCols = newColsTotal;
    printf("%d\n", m->values);
    printf("%d\n", &m->values);
    printf("%d\n", *m->values);*/
    m->values = (int **)realloc(m->values, sizeof(int *) * newRowsTotal);
    for (size_t index = 0; index < newRowsTotal; index++)
        m->values[index] = (int *)realloc(m->values[index], newColsTotal * sizeof(int));
    m->nRows = newRowsTotal;
    m->nCols = newColsTotal;
}

void inputMatrix(matrix *m) {
    for (size_t indexRows = 0; indexRows < m->nRows; indexRows++)
        for (size_t indexCols = 0; indexCols < m->nCols; indexCols++)
            scanf("%d", &m->values[indexRows][indexCols]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (size_t index = 0; index < nMatrices; index++)
        inputMatrix(&ms[index]);
}

void outputMatrix(matrix m) {
    for (size_t indexRows = 0; indexRows < m.nRows; indexRows++) {
        for (size_t indexCols = 0; indexCols < m.nCols; indexCols++)
            printf("%d ", m.values[indexRows][indexCols]);
        printf("\n");
    }
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (size_t index = 0; index < nMatrices; index++) {
        printf("------------------------ Matrix number is %d\n", index);
        outputMatrix(ms[index]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    assert(i1 >= 0 && i1 < m.nRows && i2 >= 0 && i2 < m.nRows);
    universalSwap(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapColumns(matrix m, int j1, int j2) {
    assert(j1 >= 0 && j1 < m.nCols && j2 >= 0 && j2 < m.nCols);
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        universalSwap(&m.values[indexRow][j1], &m.values[indexRow][j2], sizeof(int));

}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int*, size_t)) {
    int *valueRows = (int *)calloc(m.nRows, sizeof(int));
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        valueRows[indexRow] = criteria(m.values[indexRow], m.nCols);
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++) {
        for (size_t indexInsert = indexRow; indexInsert > 0 && valueRows[indexInsert - 1] > valueRows[indexInsert]; indexInsert--) {
            universalSwap(&valueRows[indexInsert - 1], &valueRows[indexInsert], sizeof(int));
            swapRows(m, indexInsert, indexInsert - 1);
        }
    }
    free(valueRows);
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, size_t)) {
    int *valueCols = (int *)calloc(m.nCols, sizeof(int));
    int *dimensionArray = (int *)calloc(m.nRows, sizeof(int));
    for (size_t indexColumn = 0; indexColumn < m.nCols; indexColumn++) {
        for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
            dimensionArray[indexRow] = m.values[indexColumn][indexRow];
        valueCols[indexColumn] = criteria(dimensionArray, m.nRows);
    }
    free(dimensionArray);

    for (size_t index = 0; index < m.nCols; index++) {
        size_t minIndex = index;
        for (size_t indexCheck = minIndex + 1; indexCheck < m.nCols; indexCheck++)
            if (valueCols[minIndex] > valueCols[indexCheck])
                minIndex = indexCheck;
        swapColumns(m, index, minIndex);
        universalSwap(&valueCols[minIndex], &valueCols[index], sizeof(int));
    }
}

bool isSquareMatrix(matrix *m) {
    return m->nRows == m->nCols;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if(m1->nRows != m2->nRows && m1->nCols != m2->nCols)
        return 0;

    for (size_t index = 0; index < m1->nRows; index++)
        if (memcmp(m1->values[index], m2->values[index], m1->nCols * sizeof(int)) != 0)
            return 0;
    return 1;
}

bool isEMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return 0;
    for (size_t indexRow = 0; indexRow < m->nRows; indexRow++) {
        for (size_t indexCol = 0; indexCol < m->nCols; indexCol++) {
            if (indexRow != indexCol) {
                if (m->values[indexRow][indexCol] != 0)
                    return 0;
            }
            else if (m->values[indexRow][indexCol] != 1)
                return 0;
        }
    }
    return 1;
}

bool isSymmetricMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return 0;
    for (size_t indexRow = 0; indexRow < m->nRows; indexRow++) {
        for (size_t indexCol = 0; indexCol < m->nCols; indexCol++)
            if (m->values[indexCol][indexRow] != m->values[indexRow][indexCol])
                return 0;
    }
    return 1;
}

void transposeSquareMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = i + 1; j < m->nCols; ++j) {
            universalSwap(&m->values[i][j], &m->values[j][i], sizeof(int));
        }
    }
}

void transposeMatrix(matrix *m) {
    int array[m->nRows][m->nCols];
    for (size_t indexRow = 0; indexRow < m->nRows; indexRow++)
        for (size_t indexCol = 0; indexCol < m->nCols; indexCol++)
            array[indexRow][indexCol] = m->values[indexRow][indexCol];

    reserveMemMatrix(m, m->nCols, m->nRows);

    for (size_t indexRow = 0; indexRow < m->nRows; indexRow++)
        for (size_t indexCol = 0; indexCol < m->nCols; indexCol++)
            m->values[indexRow][indexCol] = array[indexCol][indexRow];
}
