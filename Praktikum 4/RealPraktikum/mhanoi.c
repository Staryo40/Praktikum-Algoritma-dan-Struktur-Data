#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

void putarMatrix(Matrix *m){
    int temp;
    temp = ELMT(*m, 0, 0);
    ELMT(*m, 0, 0) =  ELMT(*m, 1, 0);
    ELMT(*m, 1, 0) = ELMT(*m, 1, 1);
    ELMT(*m, 1, 1) = ELMT(*m, 0, 1);
    ELMT(*m, 0, 1) = temp;
}

int main(){
    int N;
    scanf("%d", &N);
    Matrix hanoi;
    readMatrix(&hanoi, N, N);
    Matrix farr;
    readMatrix(&farr, 2,2 );
    Matrix copyOriFarr;
    copyMatrix(farr, &copyOriFarr);

    int confCount = 0;
    int p, i, j;
    for (i = 0; i < ROW_EFF(hanoi)-1; i++){
        for (j = 0; j < COL_EFF(hanoi)-1; j++){
            p = 0;
            while (p < 4){
                if (ELMT(hanoi, i, j) > ELMT(farr, 0, 0) && ELMT(hanoi, i+1, j) > ELMT(farr, 1, 0) && ELMT(hanoi, i, j+1) > ELMT(farr, 0,1) && ELMT(hanoi, i+1, j+1) > ELMT(farr, 1, 1)){
                    confCount++;
                    break;
                }
                p++;
                putarMatrix(&farr);
            }
            farr = copyOriFarr;
        }
    }

    printf("%d\n", confCount);
    return 0;
}