#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
    // printf("ran\n");
    if (l1 == NIL && l2 == NIL){
        return;
    } 

     if (l1 == NIL) {
        if (!isMember(*res, INFO(l2))) {
            *res = konsb(*res, INFO(l2));
        }
        mergeSortedUnique(l1, NEXT(l2), res);
        return;
    }

    if (l2 == NIL) {
        if (!isMember(*res, INFO(l1))) {
            *res = konsb(*res, INFO(l1));
        }
        mergeSortedUnique(NEXT(l1), l2, res);
        return;
    }

    if (INFO(l1) < INFO(l2)) {
        if (!isMember(*res, INFO(l1))) {
            *res = konsb(*res, INFO(l1));
        }
        mergeSortedUnique(NEXT(l1), l2, res);
    } 
    else if (INFO(l2) < INFO(l1)) {
        if (!isMember(*res, INFO(l2))) {
            *res = konsb(*res, INFO(l2));
        }
        mergeSortedUnique(l1, NEXT(l2), res);
    } 
    else { // INFO(l1) == INFO(l2)
        if (!isMember(*res, INFO(l1))) {
            *res = konsb(*res, INFO(l1));
        }
        mergeSortedUnique(NEXT(l1), NEXT(l2), res);
    }
}
