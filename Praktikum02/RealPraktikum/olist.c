#include "liststatik.h"
#include <stdio.h>

int main()
{
    ListStatik l, lv, lc;
    CreateListStatik(&lv);
    CreateListStatik(&lc);
    readList(&l);

    int i, idxVal;
    for (i = 0; i < listLength(l); i++) {
        idxVal = indexOf(lv, ELMT(l, i));
        if (idxVal == IDX_UNDEF) {
            insertLast(&lv, ELMT(l, i));
            insertLast(&lc, 1);
        }
        else {
            ELMT(lc, idxVal) += 1;
        }
    }

    printList(lv);
    printf("\n");

    for (i = 0; i < listLength(lv); i++)
    {
        printf("%d %d\n", ELMT(lv, i), ELMT(lc, i));
    }
    return 0;
}