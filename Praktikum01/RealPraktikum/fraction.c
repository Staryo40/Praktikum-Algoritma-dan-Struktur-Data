#include <stdio.h>
#include <math.h>

#include "boolean.h"
#include "fraction.h"

#define boolean unsigned char
#define TRUE 1
#define FALSE 0


/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsFRACTIONValid(int N, int D){
/* Mengirim TRUE jika pecahan valid */
    return (D != 0);
}

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R){
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */
    Numerator(*F) = N;
    Denominator(*F) = R;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadFRACTION(FRACTION *F){
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */
    scanf("%d %d", &Numerator(*F), &Denominator(*F));
    while (!IsFRACTIONValid(Numerator(*F), Denominator(*F))){
        if (!IsFRACTIONValid(Numerator(*F), Denominator(*F))){
            printf("FRACTION tidak valid\n");
        }
        scanf("%d %d", &Numerator(*F), &Denominator(*F));
    }
}

void WriteFRACTION(FRACTION F){
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE: hasil dalam bentuk paling sederhana
 */
    F = SimplifyFRACTION(F);
    printf("%d/%d", Numerator(F), Denominator(F));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI DASAR TERHADAP TYPE                              */
/* ***************************************************************** */
/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */

FRACTION AddFRACTION(FRACTION F1, FRACTION F2){
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION result;
    // int common = Denominator(F1) * Denominator(F2);
    // int new_num = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
    Numerator(result) = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
    Denominator(result) = Denominator(F1) * Denominator(F2);
    result = SimplifyFRACTION(result);
    return result; 
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2){
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION result;
    int common = Denominator(F1) * Denominator(F2);
    int new_num = Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator(F1);
    Numerator(result) = new_num;
    Denominator(result) = common;
    result = SimplifyFRACTION(result);
    return result; 
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2){
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION result;
    int common = Denominator(F1) * Denominator(F2);
    int new_num = Numerator(F1) * Numerator(F2);
    Numerator(result) = new_num;
    Denominator(result) = common;
    result = SimplifyFRACTION(result);
    return result; 
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2){
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION result;
    int common = Denominator(F1) * Numerator(F2);
    int new_num = Numerator(F1) * Denominator(F2);
    Numerator(result) = new_num;
    Denominator(result) = common;
    result = SimplifyFRACTION(result);
    return result; 
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1){
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */
    FRACTION result;

    Numerator(result) = Numerator(F1) * n;
    Denominator(result) = Denominator(F1);
    result = SimplifyFRACTION(result);
    return result; 
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F){
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */
    int divider = gcd(Numerator(F), Denominator(F));
    Numerator(F) /= divider;
    Denominator(F) /= divider;
    // WriteFRACTION(F);
    if (Numerator(F) > 0 && Denominator(F) < 0){
        Numerator(F) *= -1;
        Denominator(F) *= -1;
    }
    return F;
}

float ToDecimal(FRACTION F){
/* Mengonversi FRACTION ke bentuk desimal */
    float result = (float) Numerator(F) / Denominator(F);
    return result;
}