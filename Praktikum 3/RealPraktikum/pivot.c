#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

int minKananFunc (ListDin l, int idAwal){
    int i;
    int min = ELMT(l, idAwal);
    for (i = idAwal; i < listLength(l)-1; i++){
        if (ELMT(l, i) < min){
            min = ELMT(l, i);
        }
    }
    return min;
}

int main(){
    ListDin l;
    CreateListDin(&l, 1000000);
    readList(&l);

    int maxKiri = ELMT(l, 0);
    int i;
    int pivotCount = 0;
    int length = listLength(l);

    int minKanan[length];
    minKanan[length - 1] = ELMT(l, length - 1);

    for (int i = length - 2; i >= 0; i--) {
        minKanan[i] = (ELMT(l, i) < minKanan[i + 1]) ? ELMT(l, i) : minKanan[i + 1];
    }

    for (i = 0; i < length; i++){
        if (ELMT(l, i) > maxKiri) {
            maxKiri = ELMT(l, i);
        }
        if (ELMT(l, i) >= maxKiri && ELMT(l, i) <= minKanan[i]) {
            pivotCount++;
        }
    }

    printf("%d\n", pivotCount);
    return 0;
}