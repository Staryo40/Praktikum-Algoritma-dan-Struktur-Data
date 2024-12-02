#include "list_circular.h"
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int temp;
    List l;
    CreateList(&l);

    for (int i = 0; i < n; i++){
        scanf("%d", &temp);
        insertLast(&l, temp);
    }

    // cek clockwise
    Address p = FIRST(l);
    boolean clockwise = true;
    while (NEXT(p) != FIRST(l)){
        if (INFO(NEXT(p)) != INFO(p) + 1 && INFO(NEXT(p)) != 1){
            clockwise = false;
            // printf("clockwise: %d\n", INFO(p));
        }
        p = NEXT(p);
    }
    if (INFO(NEXT(p)) != INFO(p) + 1 && INFO(NEXT(p)) != 1){ // elemen terakhir
        clockwise = false;
        // printf("clockwise last: %d\n", INFO(p));
    }

    // cek counterclockwise
    p = FIRST(l);
    boolean counterclockwise = true;
    while (NEXT(p) != FIRST(l)){
        if (INFO(NEXT(p)) + 1 != INFO(p) && INFO(NEXT(p)) != n){
            counterclockwise = false;
            // printf("counter clockwise: %d\n", INFO(p));
        }
        p = NEXT(p);
    }
    if (INFO(NEXT(p)) + 1 != INFO(p) && INFO(NEXT(p)) != 1){ // elemen terakhir
        counterclockwise = false;
        // printf("counter clockwise last: %d\n", INFO(p));
    }

    if (counterclockwise || clockwise){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    
    return 0;
}