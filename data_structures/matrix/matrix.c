#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int**)malloc(sizeof(int*) * nRows);
    for (size_t i = 0; i < nRows; i ++)
        values[i] = (int*)malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix* getMemArrayOfMatrices(size_t nMatrices, int nRows, int nCols) {
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

matrix* getArrayOfMatricesFromArray(const int *array, size_t n, int nRows, int nCols) {
    matrix *arrayMatrices = getMemArrayOfMatrices(n, nRows, nCols);
    for (size_t indexMatrices = 0; indexMatrices < n; indexMatrices++)
        arrayMatrices[indexMatrices] = getMatrixFromArray(&array[nCols * nRows * indexMatrices], nRows, nCols);
    return arrayMatrices;
}


void getArrayFromColum(int* arrayCol, matrix m, size_t indexCol) {
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        arrayCol[indexRow] = m.values[indexRow][indexCol];
}

matrix getZeroMatrix(int nRows, int nCols) {
    matrix newMatrix = getMemMatrix(nRows, nCols);
    doZeroMatrix(&newMatrix);
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

void swapRows(matrix m, size_t i1, size_t i2) {
    assert(i1 >= 0 && i1 < m.nRows && i2 >= 0 && i2 < m.nRows);
    universalSwap(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapColumns(matrix m, size_t j1, size_t j2) {
    assert(j1 >= 0 && j1 < m.nCols && j2 >= 0 && j2 < m.nCols);
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        universalSwap(&m.values[indexRow][j1], &m.values[indexRow][j2], sizeof(int));

}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(const int*, size_t)) {
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

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int*, const size_t)) {
    int *valueCols = (int *)calloc(m.nCols, sizeof(int));
    int *dimensionArray = (int *)calloc(m.nRows, sizeof(int));
    for (size_t indexColumn = 0; indexColumn < m.nCols; indexColumn++) {
        getArrayFromColum(dimensionArray, m, indexColumn);
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

    for (size_t indexRow = 0; indexRow < m->nRows; indexRow++)
        free(m->values[indexRow]);
    free(m->values);

    universalSwap(&m->nCols, &m->nRows, sizeof(int));

    m->values = calloc(m->nRows, sizeof(int *));
    for (size_t indexRow = 0; indexRow < m->nRows; indexRow++)
        m->values[indexRow] = calloc(m->nCols, sizeof(int));

    for (size_t indexRow = 0; indexRow < m->nRows; indexRow++)
        for (size_t indexCol = 0; indexCol < m->nCols; indexCol++)
            m->values[indexRow][indexCol] = array[indexCol][indexRow];
}

void doZeroMatrix(matrix *m) {
    for (size_t indexRow = 0; indexRow < m->nRows; indexRow++)
        for (size_t indexCol = 0; indexCol < m->nCols; indexCol++)
            m->values[indexRow][indexCol] = 0;
}

position searchMinValuePosByRows(matrix m) {
    position minPos = {0, 0};
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++) {
        size_t minIndex = getIndexMinElement(m.values[indexRow], m.nCols);
        if (m.values[minPos.rowIndex][minPos.colIndex] > m.values[indexRow][minIndex]) {
            minPos.rowIndex = indexRow;
            minPos.colIndex = minIndex;
        }
    }
    return minPos;
}

position searchMinValuePosByCols(matrix m){
    position minPos = {0, 0};
    int *arrayCol = calloc(m.nRows, sizeof(int));
    for (size_t indexCol = 0; indexCol < m.nCols; indexCol++) {
        getArrayFromColum(arrayCol, m, indexCol);
        size_t minIndex = getIndexMinElement(arrayCol, m.nRows);
        if (m.values[minPos.rowIndex][minPos.colIndex] > arrayCol[minIndex]) {
            minPos.rowIndex = minIndex;
            minPos.colIndex = indexCol;
        }
    }
    return minPos;

}

position searchMaxValuePosByRows(matrix m) {
    position maxPos = {0, 0};
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++) {
        size_t maxIndex = getIndexMaxElement(m.values[indexRow], m.nCols);
        if (m.values[maxPos.rowIndex][maxPos.colIndex] < m.values[indexRow][maxIndex]) {
            maxPos.rowIndex = indexRow;
            maxPos.colIndex = maxIndex;
        }
    }
    return maxPos;
}

position searchMaxValuePosByCols(matrix m) {
    position maxPos = {0, 0};
    int *arrayCol = calloc(m.nRows, sizeof(int));
    for (size_t indexCol = 0; indexCol < m.nCols; indexCol++) {
        getArrayFromColum(arrayCol, m, indexCol);
        size_t maxIndex = getIndexMinElement(arrayCol, m.nRows);
        if (m.values[maxPos.rowIndex][maxPos.colIndex] < arrayCol[maxIndex]) {
            maxPos.rowIndex = maxIndex;
            maxPos.colIndex = indexCol;
        }
    }
    return maxPos;
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(isSquareMatrix(&m1) && isSquareMatrix(&m2) && m1.nRows == m2.nRows);

    matrix resultMulMatrices = getMemMatrix(m1.nRows, m1.nCols);
    doZeroMatrix(&resultMulMatrices);

    int *dimensionArray = calloc(m1.nRows, sizeof(int));
    for (size_t indexColWrite = 0; indexColWrite < m1.nCols; indexColWrite++) {
        getArrayFromColum(dimensionArray, m2, indexColWrite);
        for (size_t indexRowWrite = 0; indexRowWrite < m1.nRows; indexRowWrite++)
            for (size_t indexMul = 0; indexMul < m1.nRows; indexMul++)
                resultMulMatrices.values[indexRowWrite][indexColWrite] += dimensionArray[indexMul] * m1.values[indexRowWrite][indexMul];
    }
    free(dimensionArray);

    return resultMulMatrices;
}

int getMaxElementDiagonalFrom(matrix m1, position pos) {
    int max = m1.values[pos.rowIndex][pos.colIndex];
    for (size_t indexRow = pos.rowIndex + 1, indexCol = pos.colIndex + 1; indexRow < m1.nRows && indexCol < m1.nCols; indexCol++, indexRow++)
        if (max < m1.values[indexRow][indexCol])
            max = m1.values[indexRow][indexCol];
    return max;
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(const int*, size_t)) {
    float *valueRows = (float *)calloc(m.nRows, sizeof(float));
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        valueRows[indexRow] = criteria(m.values[indexRow], m.nCols);
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++) {
        for (size_t indexInsert = indexRow; indexInsert > 0 && valueRows[indexInsert - 1] > valueRows[indexInsert]; indexInsert--) {
            universalSwap(&valueRows[indexInsert - 1], &valueRows[indexInsert], sizeof(float));
            swapRows(m, indexInsert, indexInsert - 1);
        }
    }
    free(valueRows);
}

bool isRowsCorrectByPredicate(matrix m, bool (*predicate) (const int, const int)) {
    for (size_t indexRow = 0; indexRow < m.nRows; indexRow++)
        if (!isOrderByPredicate(m.values[indexRow], m.nCols, predicate))
            return false;
    return true;
}

bool isColsCorrectByPredicate(matrix m, bool (*predicate) (const int, const int)) {
    int *arrayCol = (int*)calloc(m.nRows, sizeof(int));
    bool isCorrect = true;
    for (size_t indexCol = 0; indexCol < m.nCols; indexCol++) {
        getArrayFromColum(arrayCol, m, indexCol);
        if(!isOrderByPredicate(arrayCol, m.nRows, predicate))
            isCorrect = false;
    }
    return isCorrect;
}
