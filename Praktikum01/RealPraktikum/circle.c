#include <stdio.h>
#include <math.h>

#include "point.h"
#include "boolean.h"
#include "circle.h"

#define boolean unsigned char
#define TRUE 1
#define FALSE 0

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCIRCLEValid(float X, float Y, float R){
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */
    return (R > 0);
}

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;

    Center(*C) = P;
    Radius(*C) = R;

}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C){
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */ 
    scanf("%f %f %f", &Absis(Center(*C)), &Ordinat(Center(*C)), &Radius(*C));
    while (!IsCIRCLEValid(Absis(Center(*C)), Ordinat(Center(*C)), Radius(*C))){
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f", &Absis(Center(*C)), &Ordinat(Center(*C)), &Radius(*C));
    }
}

void WriteCIRCLE(CIRCLE C){
/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C){
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */
    float pi = 3.14;
    float kel = 2 * pi * Radius(C);
    return kel;
}

float Area(CIRCLE C){
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */
    float pi = 3.14;
    float area = pi * Radius(C) * Radius(C);
    return area;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
/* Mengirim true jika titik P berada di dalam lingkaran C */
    float PCdistance = sqrt(pow( (Absis(Center(C))-Absis(P)), 2 ) + pow( (Ordinat(Center(C))-Ordinat(P)), 2 ));
    return PCdistance < Radius(C);
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */
    float PCdistance = sqrt(pow((Absis(Center(C))-Absis(P)), 2) + pow((Ordinat(Center(C))-Ordinat(P)), 2));
    return PCdistance == Radius(C);
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){
/* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
/* NOTE: Tidak berpotongan/ bersinggungan */
    float CCdistance = sqrt(pow((Absis(Center(C1))-Absis(Center(C2))), 2) + pow((Ordinat(Center(C1))-Ordinat(Center(C2))), 2));
    return (CCdistance + Radius(C1)) < Radius(C2);
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT: Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */
    boolean singgungdalam = (sqrt(pow((Absis(Center(C1))-Absis(Center(C2))), 2) + pow((Ordinat(Center(C1))-Ordinat(Center(C2))), 2)) + Radius(C1)) == Radius(C2);
    boolean singgungluar = sqrt(pow(Absis(Center(C1))-Absis(Center(C2)), 2) + pow(Ordinat(Center(C1))-Ordinat(Center(C2)), 2)) == Radius(C1) + Radius(C2);
    return singgungdalam || singgungluar;
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */
    float CCdistance = sqrt(pow(Absis(Center(C1))-Absis(Center(C2)), 2) + pow(Ordinat(Center(C1))-Ordinat(Center(C2)), 2));
    return CCdistance < Radius(C1) + Radius(C2) && CCdistance + Radius(C1) != Radius(C2);
}