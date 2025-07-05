# include "queue.h"
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    Queue q;
    CreateQueue(&q);

    for(int i = 0; i < n; i++){
        int opt;
        int x;
        scanf("%d", &opt);

        if (opt == 1){
            scanf("%d", &x);
            if (isFull(q)){
                printf("Queue Penuh\n");
            } else {
                enqueue(&q, x);
                printf("Enqueue %d Berhasil\n", x);
            }
        }
        if (opt == 2){
            if (isEmpty(q)){
                printf("Queue Kosong\n");
            } else {
                int val;
                dequeue(&q, &val);
                printf("Dequeue %d Berhasil\n", val);
            }
        }
        if (opt == 3){
            if (isEmpty(q)){
                printf("Queue Kosong\n");
            } else {
                printf("Elemen Awal Queue adalah %d\n", HEAD(q));
            }
        }
        if (opt == 4){
            printf("Ukuran Queue saat ini adalah %d\n", length(q));
        }
    }
    displayQueue(q);
    return 0;
}