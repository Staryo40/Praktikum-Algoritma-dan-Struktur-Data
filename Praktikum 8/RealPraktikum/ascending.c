#include "listlinier.h"
#include <stdio.h>

int main(){
    List l;
    CreateList(&l);

    int x;
    do {
        scanf("%d", &x);
        if (x != -9999){
            Address p = l;
            if (isEmpty(l)){
                insertFirst(&l, x);
            } else {
                int i = 0;
                while (p != NULL && p->info < x){
                    i++;
                    p = p->next;
                }
                insertAt(&l, x, i);
            }
            // displayList(l);
            //  printf("\n");
        }
    } while (x != -9999);

    displayList(l);
    return 0;
}