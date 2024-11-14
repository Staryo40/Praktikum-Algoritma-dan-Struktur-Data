#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    while (a <= b){
        printf("%d", a);
        if (a % 2 == 0){
            a *= 2;
        } else {
            a += 1;
        }
        if (a < b){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}