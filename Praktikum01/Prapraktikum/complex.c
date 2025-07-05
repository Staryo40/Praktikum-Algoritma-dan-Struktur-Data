#include <stdio.h>

#include "boolean.h"
#include <math.h>
#include "complex.h"

#define boolean unsigned char
#define TRUE 1
#define FALSE 0 

boolean IsCOMPLEXValid(float Re, float Im){
/* Mengirim true jika Re dan Im valid untuk membentuk COMPLEX */
/* Dalam konteks kompleks, semua bilangan real adalah valid */
    return TRUE;
}

/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im){
/* Membentuk sebuah COMPLEX dari komponen-komponennya */
    Real(*C) = Re;
    Imag(*C) = Im;  
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaCOMPLEX(COMPLEX *C){
/* I.S. : C tidak terdefinisi */
/* F.S. : C terdefinisi */
/* Proses : Membaca komponen Re dan Im dari pengguna */
    scanf("%f %f", &Real(*C), &Imag(*C));
}

void TulisCOMPLEX(COMPLEX C){
/* I.S. : C sembarang */
/* F.S. : Nilai C ditulis dengan format "a + bi" atau "a - bi" (tanpa spasi) dan diakhiri newline */
/* Proses : Menulis nilai Re dan Im ke layar */
    if (Imag(C) < 0){
        printf("%.2f-%.2fi\n", Real(C), -Imag(C));
    } else {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
}

/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil penjumlahan C1 + C2 */
    // KAMUS LOKAL
    COMPLEX new;

    // ALGORITMA
    Real(new) = Real(C1) + Real(C2);
    Imag(new) = Imag(C1) + Imag(C2);
    return new;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil pengurangan C1 - C2 */
    // KAMUS LOKAL
    COMPLEX new;

    // ALGORITMA
    Real(new) = Real(C1) - Real(C2);
    Imag(new) = Imag(C1) - Imag(C2);
    return new;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil perkalian C1 * C2 */
/* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */
    // KAMUS LOKAL
    COMPLEX new;

    // ALGORITMA
    Real(new) = Real(C1) * Real(C2) - Imag(C1) * Imag(C2);
    Imag(new) = Real(C1) * Imag(C2) + Real(C2) * Imag(C1);
    return new;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
/* Mengirim hasil pembagian C1 / C2 */
/* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
/* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/
    // KAMUS LOKAL
    COMPLEX new;
    float denominator = pow(Real(C2), 2) + pow((Imag(C2)), 2);

    // ALGORITMA
    if (denominator == 0){
        Real(new) = 0;
        Imag(new) = 0;
        return new;
    } else {
        C2 = ConjugateCOMPLEX(C2);
        Real(new) = Real(MultiplyCOMPLEX(C1, C2)) / denominator;
        Imag(new) = Imag(MultiplyCOMPLEX(C1, C2)) / denominator;
        return new;
    }
}
/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
float AbsCOMPLEX(COMPLEX C){
/* Mengirim nilai absolut (modulus) dari C */
/* Rumus: |C| = sqrt(Re^2 + Im^2) */
    float result = sqrt(pow(Real(C), 2) + pow(Imag(C), 2));
    return result;
}
COMPLEX ConjugateCOMPLEX(COMPLEX C){
/* Mengirim hasil konjugasi dari C */
/* Rumus: Conj(C) = Re - i*Im */
    Imag(C) = -Imag(C);
    return C;
}
/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2){
/* Mengirimkan true jika C1 = C2 (Re dan Im sama) */
    if ((Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2))){
        return TRUE;
    } else {
        return FALSE;
    }
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
/* Mengirimkan true jika C1 tidak sama dengan C2 */
    if ((Real(C1) != Real(C2)) || (Imag(C1) != Imag(C2))){
        return TRUE;
    } else {
        return FALSE;
    }
}

