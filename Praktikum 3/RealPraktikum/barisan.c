#include "listdin.h"
#include "boolean.h"
#include <stdio.h>

int countHigher(ListDin l, int currentIDX){
    int i;
    int count = 0;
    for (i = 0; i < currentIDX; i++){
        if (ELMT(l, i) > ELMT(l, currentIDX)){
            count++;
        }
    }
    return count;
}
int main(){
    ListDin l;
    CreateListDin(&l, 1000);
    readList(&l);

    int i;
    int count = 0;
    for (i = 0; i < listLength(l); i++){
        count += countHigher(l, i);
    }

    printf("%d\n", count);

    return 0;
}