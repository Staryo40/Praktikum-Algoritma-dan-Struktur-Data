#include <stdio.h>
#include <stdlib.h>
#include "queue_bfs.h"
#include "boolean.h"

const int MXN = 100;

// NILAI 100

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
    // visited matrix
    int visited[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] == '#'){
                visited[i][j] = 1;
            } else {
                visited[i][j] = 0;
            }
        }
    }

    // search for start and end
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

    Queue que;
    CreateQueue(&que);
    enqueue(&que, start);
    visited[start.row][start.col] = 1;

    int steps = 0;
    boolean endpointFound = false;
    while (!isEmpty(que)){
        int size = length(que);
        for (int i = 0; i < size; i++){
            ElType current;
            dequeue(&que, &current);
            // moving
            // up
            if (current.row-1 >= 0 && visited[current.row-1][current.col] != 1){
                visited[current.row-1][current.col] = 1;
                ElType up = {current.row-1,current.col};
                enqueue(&que, up);
            }
            // left
            if (current.col-1 >= 0 && visited[current.row][current.col-1] != 1){
                visited[current.row][current.col-1] = 1;
                ElType left = {current.row,current.col-1};
                enqueue(&que, left);
            }
            // down
            if (current.row+1 < N && visited[current.row+1][current.col] != 1){
                visited[current.row+1][current.col] = 1;
                ElType down = {current.row+1,current.col};
                enqueue(&que, down);
            }
            // right
            if (current.col+1 < N && visited[current.row][current.col+1] != 1){
                visited[current.row][current.col+1] = 1;
                ElType right = {current.row,current.col+1};
                enqueue(&que, right);
            }
        }
        steps++;
        if (visited[end.row][end.col] == 1){
            endpointFound = true;
            break;
        }
    }

    if (endpointFound){
        printf("Ya\n");
        printf("%d\n", steps);
    } else {
        printf("Tidak\n");
    }
    
    return 0;
}