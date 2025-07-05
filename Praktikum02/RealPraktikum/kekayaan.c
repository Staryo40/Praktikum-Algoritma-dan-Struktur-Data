#include "liststatik.h"
#include <stdio.h>

void incrementIndex(ListStatik *l, IdxType i)
{
    ELMT(*l, i) += 1;

    if (ELMT(*l, i) >= 10)
    {
        ELMT(*l, i) = 0;
        if (i == 0)
        {
            insertFirst(l, 1);
        }
        else
        {
            incrementIndex(l, i-1);
        }
    }
}

int main()
{
    ListStatik l;
    readList(&l);

    incrementIndex(&l, getLastIdx(l));

    int i, length;
    length = listLength(l);

    for (i = 0; i < length - 1; i++)
    {
        printf("%d ", ELMT(l, i));
    }
    printf("%d\n", ELMT(l, length - 1));

}