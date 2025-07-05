#include "listrec.h"
#include <stdio.h>

// int lastValue(List l){
//     if (NEXT(l) = NIL){
//         return INFO(l);
//     }

//     return lastValue(NEXT(l));
// }

int main(){
    int n;
    scanf("%d", &n);

    List l = NIL;
    int temp;
    for (int i = 0; i < n; i++){
        scanf("%d", &temp);
        l = konsb(l, temp);
    }

    List res = NIL;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            res = konsb(res, INFO(l));
            l = deleteFirst(l);
        } else {
            Address p = l;
            while (NEXT(p) != NIL){
                p = NEXT(p);
            }
            res = konsb(res, INFO(p));
            l = deleteLast(l);
        }
    }

    displayList(res);
    return 0;
}