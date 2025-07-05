#include "listlinier.h"
#include <stdio.h>

int main(){
    List l;
    CreateList(&l);

    char in;
    int num;
    while (in != 'X') {
        scanf("%c", &in);
        if (in == 'C'){
            if (!isEmpty(l)){
                ElType dummy;
                deleteFirst(&l, &dummy);
            }
        }
        if (in == 'P'){
            scanf("%d", &num);
            insertFirst(&l, num);
        }
        if (in == 'I'){
            scanf("%d", &num);
            insertLast(&l, num);
        }
        if (in == 'D'){
            scanf("%d", &num);
            int i = 0;
            Address p = l;
            if (!isEmpty(l)){
                while (p != NULL && p->info != num){
                    i++;
                    p = p->next;
                }
                if (p != NULL){
                    ElType dummy;
                    deleteAt(&l, i, &dummy);
                }
            }
        }
    } 

    displayList(l);
    return 0;
}