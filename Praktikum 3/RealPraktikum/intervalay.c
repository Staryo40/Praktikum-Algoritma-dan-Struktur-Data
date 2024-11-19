#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

void deleteAt(ListDin *l, int idx){
    int i;
    for (i = idx; i < listLength(*l)-1; i++){
        ELMT(*l, i) = ELMT(*l, i+1);
    }
    NEFF(*l)-=1;
}

boolean minExist (ListDin *l, int start){
    int i;
    for (i = 0; i < listLength(*l); i++){
        if (ELMT(*l, i) < start){
            return true;
        }
    }
    return false;
}

boolean maxExist (ListDin *l, int stop){
    int i;
    for (i = 0; i < listLength(*l); i++){
        if (ELMT(*l, i) > stop){
            return true;
        }
    }
    return false;
}

void insertIDX(ListDin *l, int idx, int val){
    int i;
    NEFF(*l)+=1;
    for (i = listLength(*l)-1; i > idx; i--){
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, idx) = val;
}

int main() {
    // Start code here...
    ListDin l;
    CreateListDin(&l, 1000);
    readList(&l);

    int newStart, newStop;
    scanf("%d %d", &newStart, &newStop);
    
    int startEnd = -1;
    int stopEnd = -1;
    int i = 0; 
    int j = 1;
    boolean delete;
    while (i < listLength(l) && j < listLength(l)){
        delete = false;
        // interval ori ada di interval baru
        if (ELMT(l, i) >= newStart && ELMT(l, j) <= newStop){
            deleteAt(&l, j);
            deleteAt(&l, i);
            delete = true;
            // printf("both in new \n");
            // printList(l);
            // printf("\n");
        } else if (ELMT(l, i) <= newStop && ELMT(l, i) >= newStart){ // start interval ori ada di dalam interval baru
            stopEnd = ELMT(l, j);
            deleteAt(&l, j);
            deleteAt(&l, i);
            delete = true;
            // printf("start in new \n");
            // printList(l);
            // printf("\n");
        } else if (ELMT(l, j) >= newStart && ELMT(l, j) <= newStop){ // stop interval ori ada di dalam interval baru
            startEnd = ELMT(l, i);
            deleteAt(&l, j);
            deleteAt(&l, i);
            delete = true;
            // printf("stop in new \n");
            // printList(l);
            // printf("\n");
        }
        if (!delete){
            i+=2;
            j+=2;
        }
    }

    if (startEnd == -1){
        startEnd = newStart;
    }
    if (stopEnd == -1){
        stopEnd = newStop;
    }
    
    int k;
    if (listLength(l) == 0){
        ELMT(l, 0) = startEnd;
        ELMT(l, 1) = stopEnd;
    }

    if (minExist(&l, startEnd)){
        int lastMin = 0;
        for (k = 0; k < listLength(l); k++){
            if (ELMT(l, k) < startEnd){
                lastMin = k;
            }
        }
        insertIDX(&l, lastMin+1, startEnd);
    } else {
        insertIDX(&l, 0, startEnd);
    }

    if (maxExist(&l, stopEnd)){
        int firstMax = 0;
        for (k = 0; k < listLength(l); k++){
            if (ELMT(l, k) > stopEnd){
                firstMax = k;
                break;
            }
        }
        insertIDX(&l, firstMax, stopEnd);
    } else {
        insertIDX(&l, listLength(l), stopEnd);
    }

    // printing output
    for (k = 0; k < listLength(l); k++){
        if (k == listLength(l)-1){
            printf("%d", ELMT(l, k));
        } else {
            printf("%d ", ELMT(l, k));
        }
    }
    printf("\n");

    dealocateList(&l);
    
    return 0;
}