#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

int main(){
    int N;
    scanf("%d", &N);
    Matrix grid;
    readMatrix(&grid, N, N);

    long mod = 1000000007;

    if (ELMT(grid, 0, 0) == 1) {
        printf("%d\n", 0);
        return 0;
    }

    if (ELMT(grid, ROW_EFF(grid) - 1, COL_EFF(grid) - 1) == 1) {
        printf("%d\n", 0);
        return 0;
    }

    Matrix pathMatrix;
    createMatrix(N, N, &pathMatrix);
    ELMT(pathMatrix, ROW_EFF(grid) - 1, COL_EFF(grid) - 1) = 1;
    int diagonal, i, j;
    for (diagonal = ROW_EFF(grid) * 2 - 3; diagonal >= 0; diagonal--) {
        for (i = 0; i <= diagonal && i < ROW_EFF(grid); i++) {
            j = diagonal - i;
            if (j >= COL_EFF(grid)) continue;
            
            ELMT(pathMatrix, i, j) = 0;
            if (ELMT(grid, i, j) == 1) continue;
            
            if (i + 1 < ROW_EFF(grid))
                ELMT(pathMatrix, i, j) = ((ELMT(pathMatrix, i, j) % mod) + (ELMT(pathMatrix, i + 1, j) % mod)) % mod;
            if (j + 1 < COL_EFF(grid))
                ELMT(pathMatrix, i, j) = ((ELMT(pathMatrix, i, j) % mod) + (ELMT(pathMatrix, i, j + 1) % mod)) % mod;
        }
    }

    printf("%d\n", ELMT(pathMatrix, 0, 0));
    return 0;
}