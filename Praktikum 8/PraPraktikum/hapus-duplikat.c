#include "listlinier.h"
#include <stdio.h>

List hapusDuplikat(List l)
/**
 * Menerima masukan sebuah list l yang terurut mengecil
 * Mengembalikan list yang merupakan hasil penghapusan elemen yang mempunyai duplikat pada list l, terurut membesar
 * Contoh: hapusDuplikat(3->3->2->1) = 1->2 (-> adalah panah next pada list linear)
 */
{
    // Deleting duplicates
    Address p = FIRST(l);
    int dummy;
    while (p != NULL){ // finding duplicates
        int current = INFO(p);
        int currentCount = 0;
        int currentIDX = indexOf(l, current);
        // displayList(l);
        // printf("\n");
        while (currentIDX < length(l)){
            // printf("%d\n", q);
            if (getElmt(l, currentIDX) == current){
                currentCount++;
            }
            currentIDX++;
        }

        boolean delete = false;
        // printf("current: %d, count: %d\n", current, currentCount);
        if (currentCount > 1){ // deleting all duplicates of current
            delete = true;
            while (indexOf(l, current) != -1){
                // printf("index of deleted: %d\n", indexOf(l, current));
                deleteAt(&l, indexOf(l, current), &dummy);
                // printf("deleted: %d\n", dummy);
            }
        }
        
        if (!delete){
            p = NEXT(p);
        } else {
            p = FIRST(l);
        }
    }

    // returning sorted list
    List res;
    CreateList(&res);
    if (l == NULL){
        return res;
    } else {
        while (!isEmpty(l)){
            p = FIRST(l);
            int min = INFO(p);
            while (p != NULL){ // finding min
                if (INFO(p) < min){
                    min = INFO(p);
                }
                p = NEXT(p);
            }

            insertLast(&res, min);
            deleteAt(&l, indexOf(l, min), &dummy);
        }
    }

    return res;
}