#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int i;
    int a[n];
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int jumlah = 0;
    for (i=0; i<n; i++){\
        if (a[i] % k != 0){
            jumlah += a[i];
        }
    }

    printf("%d\n", jumlah);
    return 0;
}