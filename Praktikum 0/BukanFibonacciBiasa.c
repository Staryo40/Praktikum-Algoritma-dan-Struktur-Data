#include <stdio.h>

int func(int n, int a, int b){
    if (n == 1){
        return a;
    } else if (n == 2){
        return b;
    } else {
        return func(n-1, a, b) + func(n-2, a, b);
    }
}
int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d\n", func(n, a, b));
    return 0;   
}