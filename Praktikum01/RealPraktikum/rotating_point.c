#include "point.h"
#include "complex.h"
#include "stdio.h"

/* Catatan: Hasil perkalian float dan int adalah float*/

/* Fungsi untuk menghitung perpangkatan bilangan kompleks */
/* Formula: Bilangan kompleks dikalikan dirinya sendiri sebanyak P kali */
COMPLEX PowerCOMPLEX(COMPLEX C, int p){
    int i;
    for (i = 1; i < p; i++){
        C = MultiplyCOMPLEX(C, C);
    }
    return C;

}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n){
    int i, outCounter;
    boolean outOfUnit = 0;
    COMPLEX newC;
    for (i = 1;i <= n; i++){
        newC = PowerCOMPLEX(C,i);
        Absis(*P) = Absis(*P) * Real(newC) - Ordinat(*P) * Imag(newC);
        Ordinat(*P) = Absis(*P) * Imag(newC) + Ordinat(*P) * Real(newC);
        if (Absis(*P)*Absis(*P) + Ordinat(*P)*Ordinat(*P) > 1){
            outOfUnit = 1;
            outCounter= i;
            break;
        }
        
    }
    if (outOfUnit) {
        printf("Titik keluar dari lingkaran pada iterasi ke %d", outCounter);
    } else{
        printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
    }
}

