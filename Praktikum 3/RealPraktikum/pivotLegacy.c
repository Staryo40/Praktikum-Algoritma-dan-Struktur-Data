#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

boolean cekKiri(ListDin l, int currentIDX){
    int i;
    for (i = 0; i < currentIDX; i++){
        if (ELMT(l, i) > ELMT(l, currentIDX)){
            return false;
        }
    }
    return true;
}

boolean cekKanan(ListDin l, int currentIDX){
    int i;
    for (i = currentIDX+1; i < listLength(l); i++){
        if (ELMT(l, i) < ELMT(l, currentIDX)){
            return false;
        }
    }
    return true;
}

int main() {
    // Start code here...
    ListDin l;
    CreateListDin(&l, 1000000);
    readList(&l);

    int i;
    int pivotCount = 0;
    for (i = 0; i < listLength(l); i++){
        if (cekKiri(l, i) && cekKanan(l, i)){
            pivotCount++;
        }
    }
    
    printf("%d\n", pivotCount);

    return 0;
}