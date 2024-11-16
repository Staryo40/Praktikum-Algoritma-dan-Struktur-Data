#include <stdio.h>
#include <stdlib.h>
#include "queue_bfs.h"
#include "boolean.h"

// NILAI 90 (TC 7 TIME LIMIT EXCEEDED)

const int MXN = 100;
boolean inQueue(Queue q, ElType x){
    int i = IDX_HEAD(q);
    while (i != IDX_TAIL(q)+1){
        if (x.col == q.buffer[i].col && x.row == q.buffer[i].row){
            return true;
        }

        i = (i+1) % CAPACITY;

        if (i == 0 && IDX_TAIL(q) == CAPACITY-1){
            break;
        }
    }
    return false;
}

// void displayElTypeQueue(Queue q)
// {
//     printf("[");
//     if (!isEmpty(q)){
//         int i = IDX_HEAD(q)-1;
//         do {
//             i = (i + 1) % CAPACITY;

//             printf("(%d,%d)", q.buffer[i].row, q.buffer[i].col);

//             if (i != IDX_TAIL(q)){
//                 printf(",");
//             }
//         } while (i != IDX_TAIL(q));
//     }
//     printf("]\n");
// }

int main()
{
    int N;
    char arr[MXN][MXN];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &arr[i][j]);
        }
    }

    // Start code here...
    // getting start and end
    ElType start = {0,0};
    ElType end = {0,0};
    for (int i = 0; i < N; i++){ 
        for (int j = 0; j < N; j++){
           if (arr[i][j] == 'A'){
                start = (ElType) {i,j};
           }
           if (arr[i][j] == 'B'){
                end = (ElType) {i,j};
           }
        }
    }
    // printf("start = (%d,%d)\n", start.col, start.row);
    // printf("end = (%d,%d)\n", end.col, end.row);

    Queue visited;
    CreateQueue(&visited);
    Queue que;
    CreateQueue(&que);
    Queue prevStep;
    CreateQueue(&prevStep);
    enqueue(&visited, start);
    enqueue(&que, start);
    enqueue(&prevStep, start);

    boolean endfound = false;
    boolean adv;
    int steps = 0;
    while (!isEmpty(que)){
        ElType current;
        dequeue(&que, &current);
        if (!inQueue(visited, current)){
            enqueue(&visited, current);
        }
        // movement
        ElType down = (ElType) {current.row+1, current.col};
        ElType up = (ElType) {current.row-1, current.col};
        ElType right = (ElType) {current.row, current.col+1};
        ElType left = (ElType) {current.row, current.col-1};
        if (!inQueue(que, down) && !inQueue(visited, down) && down.row < N && arr[down.row][down.col] != '#'){
            enqueue(&que, down);
        }
        if (!inQueue(que, up) && !inQueue(visited, up) && up.row >= 0 && arr[up.row][up.col] != '#'){
            enqueue(&que, up);
        }
        if (!inQueue(que, right) && !inQueue(visited, right) && right.col < N && arr[right.row][right.col] != '#'){
            enqueue(&que, right);
        }
        if (!inQueue(que, left) && !inQueue(visited, left) && left.col >= 0 && arr[left.row][left.col] != '#'){
            enqueue(&que, left);
        }

        // printf("visited:\n");
        // displayElTypeQueue(visited);
        // printf("que:\n");
        // displayElTypeQueue(que);
        // printf("prevVisited:\n");
        // displayElTypeQueue(prevStep);
        // printf("\n");

        adv = true;

        if (inQueue(prevStep, que.buffer[IDX_HEAD(que)])){
            // printf("ran = (%d,%d)\n", que.buffer[i].col, que.buffer[i].row);
            adv = false;
        }

        if (adv){
            steps++;
            CreateQueue(&prevStep);
            for (int i = IDX_HEAD(que); i != IDX_TAIL(que)+1; (i++)%CAPACITY){
                enqueue(&prevStep, que.buffer[i]);
            }
        }

        if (adv && inQueue(que, end)){
            endfound = true;
            break;
        }
    }
    
    if (endfound){
        printf("Ya\n");
        printf("%d\n", steps);
    } else {
        printf("Tidak\n");
    }

    return 0;
}