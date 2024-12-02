#include "list_circular.h"
#include <stdio.h>

void removeAt(List *l, int geser){
    Address p = NEXT(FIRST(*l));
    int dummy;

    if (p == NEXT(p)){ // one element
        deleteFirst(l, &dummy);
    } else {
        Address last = FIRST(*l);

        if (geser == 0){ // delete first element
            deleteFirst(l, &dummy);
        } else {
            for (int i = 1; i < geser; i++){
                 p = NEXT(p);
            }
            FIRST(*l) = p;
            deleteFirst(l, &dummy);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    List l;
    CreateList(&l);
    for (int i = 1; i < n+1; i++){
        insertLast(&l, i);
    }

    int pass;
    int length = n;
    boolean firstpass = true;
    while (INFO(FIRST(l)) != INFO(NEXT(FIRST(l)))){
        scanf("%d", &pass);
        if (pass > 0 && !firstpass){
            pass--;
        }
        pass = ((pass % length) + length) % length;
        firstpass = false;
        // printf("iteration %d\n", n-length);
        // printf("pass %d\n", pass);
        // displayList(l);
        // printf("\n");
        // printf("\n");
        removeAt(&l, pass);
        // displayList(l);
        // printf("\n");
        length--;
    }

    printf("%d\n", INFO(FIRST(l)));

    // List l;
    // CreateList(&l);
    // insertLast(&l, 1);
    // insertLast(&l, 2);
    // insertLast(&l, 3);
    // insertLast(&l, 4);
    // insertLast(&l, 5);
    // displayList(l);
    // printf("\n");
    // removeAt(&l, 0);
    // displayList(l);
    // printf("\n");
    // removeAt(&l, 1);
    // displayList(l);
    // printf("\n");
    // removeAt(&l, 2);
    // displayList(l);
    // printf("\n");
    return 0;
}