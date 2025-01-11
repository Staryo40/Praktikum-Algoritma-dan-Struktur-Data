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

    int j, length;
    ElType temp;
    length = listLength(lc);
    for (i = 0; i + 1 < length; i++)
    {
        for (j = 0; j + 1 < length; j++)
        {
            if (ELMT(lc, j) < ELMT(lc, j + 1))
            {
                temp = ELMT(lc, j);
                ELMT(lc, j) = ELMT(lc, j + 1);
                ELMT(lc, j + 1) = temp;
                temp = ELMT(lv, j);
                ELMT(lv, j) = ELMT(lv, j + 1);
                ELMT(lv, j + 1) = temp;
            }
        }
    }

    if (listLength(lc) > 1) {
        i = 0;
        while (i < listLength(lc) && ELMT(lc, i) == ELMT(lc, 0))
        {
            i++;
        }
        int idxTarget = i;
        while (i < listLength(lc) && ELMT(lc, i) == ELMT(lc, idxTarget)) {
            if (ELMT(lv, i) < ELMT(lv, idxTarget)) {
                idxTarget = i;
            }
            i++;
        }
        if (idxTarget < listLength(lc)) {
            printf("%d\n", ELMT(lv, idxTarget));
            return 0;
        }
    }

    printf("Tidak ada elemen kedua yang paling sering muncul\n");
    return 0;
}