#include <stdio.h>
#include "matrix.c"

Matrix horizontalFlip(Matrix m){
    int i, j;
    Matrix result;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result);

    int resultIndexRow = 0;
    int resultIndexCol;
    for (i = 0; i < ROW_EFF(m); i++){
        resultIndexCol = 0;
        for (j = COL_EFF(m)-1; j >= 0; j--){
            ELMT(result, resultIndexRow, resultIndexCol) = ELMT(m, i, j);
            resultIndexCol += 1;
        }
        resultIndexRow += 1;
    }
    return result;
}

Matrix invert(Matrix m){
    int i, j;
    Matrix result;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result);

    for (i = 0; i < ROW_EFF(m); i++){
        // printf("display inver: \n");
        // displayMatrix(m);
        // printf("\n");
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(result, i, j) = (ELMT(m, i, j) == 0) ? 1 : 0;
        }
    }
    return result;
}

Matrix horizontalInvertMatrix(Matrix m){
    int i, j;
    Matrix result;
    createMatrix(ROW_EFF(m), COL_EFF(m), &result);  
    result = invert(horizontalFlip(m));
    return result;
}