#include "boolean.h"
#include "matrix.h"
#include <stdio.h>

/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */
    return ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */
    return COL_EFF(m)-1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0 && i < ROW_EFF(m)) && (j >= 0 && j < COL_EFF(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
/* Mengirimkan elemen m(i,i) */
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
/* Melakukan assignment mOut <- mIn */
    int i, j;
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);
    for (i = 0; i < ROW_EFF(mIn); i++){
        for (j = 0; j < COL_EFF(mIn); j++){
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            if (j == COL_EFF(m)-1){
                printf("%d", ELMT(m, i, j));
                if (i != ROW_EFF(m)-1){
                    printf("\n");
                }
            } else {
                printf("%d ", ELMT(m, i, j));
            }
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    int i, j;
    Matrix mResult;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &mResult);
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            ELMT(mResult, i, j) = ELMT(m1, i, j) + ELMT(m2, i ,j);
        }
    }
    return mResult;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    int i, j;
    Matrix mResult;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &mResult);
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            ELMT(mResult, i, j) = ELMT(m1, i, j) - ELMT(m2, i ,j);
        }
    }
    return mResult;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    int i, j, k, elmtResult;
    Matrix mResult;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mResult);
    for (i = 0; i < ROW_EFF(mResult); i++){
        for (j = 0; j < COL_EFF(mResult); j++){
            elmtResult = 0;
            for (k = 0; k < COL_EFF(m1); k++){
                elmtResult += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(mResult, i, j) = elmtResult;
        }
    }
    return mResult;
}
Matrix multiplyByConst(Matrix m, ElType x){
/* Mengirim hasil perkalian setiap elemen m dengan x */
    int i, j;
    Matrix mResult;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mResult);
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(mResult, i, j) = ELMT(m, i, j) * x;
        }
    }
    return mResult;
}

void pMultiplyByConst(Matrix *m, ElType k){
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))){
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            if (ELMT(m1, i, j) != ELMT(m2, i, j)){
                return false;
            }
        }
    }
    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))){
        return true;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++){
        for (j = 0; j < COL_EFF(m1); j++){
            if (ELMT(m1, i, j) != ELMT(m2, i, j)){
                return true;
            }
        }
    }
    return false;
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
/* Mengirimkan banyaknya elemen m */
    return COL_EFF(m) * ROW_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m){
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (isSquare(m)){
        int i, j;
        for (i = 0; i < ROW_EFF(m); i++){
            for (j = 0; j < COL_EFF(m); j++){
                if (ELMT(m, i, j) != ELMT(m, j, i)){
                    return false;
                } 
            }
        }
        return true;
    } else {
        return false;
    }
}

boolean isIdentity(Matrix m){
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (isSquare(m)){
        int i, j;
        for (i = 0; i < ROW_EFF(m); i++){
            for (j = 0; j < COL_EFF(m); j++){
                if (i == j){
                    if (ELMT(m, i, j) != 1){
                        return false;
                    }
                } else { // i != j
                    if (ELMT(m, i, j) != 0){
                        return false;
                    }
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

boolean isSparse(Matrix m){
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int i, j;
    int notZeroCount = 0;
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            if (ELMT(m, i, j) != 0){
                notZeroCount++;
            }
        }
    }
    float percent = (float) notZeroCount / (float) countElmt(m);
    if (percent <= 0.05){
        return true;
    } else {
        return false;
    }
}

Matrix negation(Matrix m){
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    int i, j;
    Matrix mResult;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mResult);
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(mResult, i, j) = ELMT(m, i, j) * -1;
        }
    }
    return mResult;
}

void pNegation(Matrix *m){
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) = ELMT(*m, i, j) * -1;
        }
    }
}

// Fungsi tambahan untuk determinant
Matrix subMatrix(Matrix m, int rowIndex, int colIndex){
    Matrix sub;
    createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &sub);
    int rowOriID = 0;
    int colOriID = 0;
    int i, j;
    for (i = 0; i < ROW_EFF(sub); i++){
        if (rowOriID == rowIndex){
            rowOriID++;
        }
        for (j = 0; j < COL_EFF(sub); j++){
            if (colOriID == colIndex){
                colOriID++;
            }
            ELMT(sub, i, j) = ELMT(m, rowOriID, colOriID);
            colOriID++;
        }
        colOriID = 0;
        rowOriID++;
    }
    return sub;
}

float determinant(Matrix m){
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
    if (ROW_EFF(m) == 2){
        return ELMT(m, 0, 0) * ELMT(m, 1, 1) - (ELMT(m, 0, 1) * ELMT(m, 1, 0));
    } else {
        int j;
        float det = 0.0;
        for (j = 0; j < ROW_EFF(m); j++){
            float sign = (j % 2 == 0) ? 1 : -1;
            det += sign * ELMT(m, 0, j) * determinant(subMatrix(m, 0, j));
        }
        return det;
    }
}

Matrix transpose(Matrix m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    int i, j;
    Matrix mResult;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mResult);
    for (i = 0; i < ROW_EFF(m); i++){
        for (j = 0; j < COL_EFF(m); j++){
            ELMT(mResult, i, j) = ELMT(m, j, i);
        }
    }
    return mResult;
}
void pTranspose(Matrix *m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    int i, j;
    Matrix copy;
    copyMatrix(*m, &copy);
    for (i = 0; i < ROW_EFF(*m); i++){
        for (j = 0; j < COL_EFF(*m); j++){
            ELMT(*m, i, j) = ELMT(copy, j, i);
        }
    }
}