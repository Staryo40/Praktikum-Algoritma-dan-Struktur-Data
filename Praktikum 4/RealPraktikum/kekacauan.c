#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

long countKekacauan(Matrix m, int r, int c){
    int i, j;
    long kekacauan = 0;
    if (ELMT(m, r, c) == 0){
        return kekacauan;
    }

    for (i = 0; i < ROW_EFF(m); i++){
        if (i != r && ELMT(m, i, c) != 0){
            kekacauan += ELMT(m, i, c);
        }
        // printf("row iteration %d: %d\n", i, kekacauan);
    }
    for (i = 0; i < COL_EFF(m); i++){
        if (i != c && ELMT(m, r, i) != 0){
            kekacauan += ELMT(m, r, i);
        }
        // printf("col iteration %d: %d\n", i, kekacauan);
    }
    return kekacauan;
}

int main(){
    int N;
    scanf("%d", &N);
    Matrix papan;
    readMatrix(&papan, N, N);

    int i, j;
    long kekacauan = 0;
    for (i = 0; i < ROW_EFF(papan); i++){
        for (j = 0; j < COL_EFF(papan); j++){
            // printf("cek row %d col %d\n", i, j);
            kekacauan += countKekacauan(papan, i, j);
        }
    }

    long res = kekacauan % 1000000007;
    printf("%ld\n", res);
    return 0;
}