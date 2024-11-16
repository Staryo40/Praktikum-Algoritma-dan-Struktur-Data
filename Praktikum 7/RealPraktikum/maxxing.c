#include "prioqueue.h"
#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    // Tambahkan inisialisasi yang dibutuhkan
    PrioQueue karakter;
    PrioQueue senjata;
    CreatePrioQueue(&karakter);
    CreatePrioQueue(&senjata);

    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        // Tambahkan inisialisasi yang dibutuhkan
        enqueue(&karakter, a);
    }

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        // Tambahkan inisialisasi yang dibutuhkan
        enqueue(&senjata, b);
    }

    long long ans = 0;
    // Lanjutkan kode perhitungan disini
    int k = 0;
    int kar, sen;
    while (k < n) {
        dequeue(&karakter, &kar);
        dequeue(&senjata, &sen);
        ans += (long long) kar*sen;
        
        k++;
    }

    printf("%lld\n", ans);
}