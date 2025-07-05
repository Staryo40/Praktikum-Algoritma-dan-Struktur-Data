#include "listlinier.h"
#include <stdio.h>

int main (){
    List l1;
    CreateList(&l1);
    List l2;
    CreateList(&l2);

    // input
    int in1;
    int in2;
    do {
        scanf("%d", &in1);
        if (in1 != -1){
            insertFirst(&l1, in1);
        }
    } while (in1 != -1);

    do {
        scanf("%d", &in2);
        if (in2 != -1){
            insertFirst(&l2, in2);
        }
    } while (in2 != -1);

    // adding l1 and l2 while putting in one list
    List l3;
    CreateList(&l3);
    Address p = l1;
    Address q = l2;
    int carry = 0;

    while (p != NULL || q != NULL){
        if (p == NULL && q != NULL){
            // only adding l2
            int sum = q->info + carry;
            boolean over = false;
            if (sum >= 10){
                sum = sum % 10;
                over = true;
            }
            insertFirst(&l3, sum);
            q = q->next;
            carry = 0;
            if (over){
                carry = 1;
            }
        } else if (q == NULL && p != NULL){
            // only adding l1
            int sum = p->info + carry;
            boolean over = false;
            if (sum >= 10){
                sum = sum % 10;
                over = true;
            }
            insertFirst(&l3, sum);
            p = p->next;
            carry = 0;
            if (over){
                carry = 1;
            }
        } else {
            // adding the addition of l1 and l2
            int sum = p->info + q->info + carry;
            boolean over = false;
            if (sum >= 10){
                sum = sum % 10;
                over = true;
            }
            insertFirst(&l3, sum);
            p = p->next;
            q = q->next;
            carry = 0;
            if (over){
                carry = 1;
            }
        }
    }

    if (carry == 1){
        insertFirst(&l3, 1);
    }

    // displaying list
    p = l3;
    if (isEmpty(l3)){
        printf("%d", 0);
    } else {
        for (int i = 0; i < length(l3); i++){
            printf("%d", p->info);
            if (p->next != NULL){
                printf(" ");
            }
            p = p->next;
        }
    }
    printf("\n");
    

    return 0;
}