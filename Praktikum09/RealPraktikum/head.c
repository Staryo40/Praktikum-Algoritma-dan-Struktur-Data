#include "list_circular.h"
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int max = -9999;
    List l;
    CreateList(&l);

    int temp;
    for (int i = 0; i < n; i++){
        scanf("%d", &temp);
        if (temp > max){
            max = temp;
        }
        insertLast(&l, temp);
    }

    Address p = FIRST(l);
    while (INFO(p )!= max){
        p = NEXT(p);
    }

    FIRST(l) = p;

    displayList(l);
    return 0;
}