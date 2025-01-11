#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
    int i;
    for (i = 0; i < CAPACITY; i++){
        ELMT(*l,i) = MARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
    int i, nEff;
    nEff = 0;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(l, i) != MARK){
            nEff += 1;
        }
    }
    return nEff;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    int i;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(l, i) != MARK){
            return i;
        }
    }
}

IdxType getLastIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    int i;
    int idxLast;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(l, i) != MARK){
            idxLast = i;
        }
    }
    return idxLast;     
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return 0 <= i && i <= (CAPACITY-1);
}

boolean isIdxEff(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    return 0 <= i && i <= (listLength(l)-1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    int i;
    boolean kosong = true;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(l, i) != MARK){
            kosong = false;
        }
    }
    return kosong;  
}

/* *** Test List penuh *** */
boolean isFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    int i;
    boolean penuh = true;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(l, i) == MARK){
            penuh = false;
        }
    }
    return penuh;  
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    int n, i;
    scanf("%d", &n);
    while (0 > n || n > CAPACITY){
        scanf("%d", &n);
    }
    CreateListStatik(l);
    if (0 < n && n <= CAPACITY){
        for (i = 0; i < n; i++){
            scanf("%d", &ELMT(*l, i));
        }
    }
}

void printList(ListStatik l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    int i;
    if (isEmpty(l)){
        printf("[]");
    } else {
        printf("[");
        for (i = getFirstIdx(l); i < listLength(l); i++){
            printf("%d", ELMT(l, i));
            if (i != listLength(l)-1){
                printf(",");
            }
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    int i;
    ListStatik newl;
    CreateListStatik(&newl);
    if (plus){
        for (i = getFirstIdx(l1); i < listLength(l1); i++){
            ELMT(newl, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        for (i = getFirstIdx(l1); i < listLength(l1); i++){
            ELMT(newl, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return newl;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
    int i;
    boolean sama = true;
    if (listLength(l1) != listLength(l2)){
        sama = false;
    } else {
        for (i = getFirstIdx(l1); i < listLength(l1); i++){
            if (ELMT(l1, i) != ELMT(l2, i)){
                sama = false;
            }
        }
    }
    return sama;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i;
    if (listLength(l) == 0){
        return IDX_UNDEF;
    } else {
        for (i = getFirstIdx(l); i < listLength(l); i++){
            if (ELMT(l, i) == val){
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = getFirstIdx(l); i < listLength(l); i++){
        if (ELMT(l, i) > *max){
            *max = ELMT(l,i);
        }
        if (ELMT(l, i) < *min){
            *min = ELMT(l,i);
        }
    }

}

void geserkanan(ListStatik l){
    int j;
    for (j = listLength(l); j > getFirstIdx(l); j--){
        ELMT(l,j) = ELMT(l,j-1);
    }
    ELMT(l,getFirstIdx(l)) = MARK;
}

void geserkiri(ListStatik l){
    int j;
    for (j = getFirstIdx(l); j < listLength(l)-2; j++){
        ELMT(l,j) = ELMT(l,j+1);
    }
    ELMT(l,getLastIdx(l)) = MARK;
}
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
    geserkanan(*l);
    ELMT(*l, 0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
    int i;
    for (i=listLength(*l); i > idx; i--){
        ELMT(*l,i) = ELMT(*l,i-1);
    }
    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l, listLength(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
    *val = ELMT(*l, 0);
    geserkiri(*l);
}
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
    *val = ELMT(*l, idx);
    int j;
    for (j = idx; j <= listLength(*l)-2; j++){
        ELMT(*l,j) = ELMT(*l,j+1);
    }
    ELMT(*l, listLength(*l)-1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT(*l, listLength(*l)-1);
    ELMT(*l, listLength(*l)-1) = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    int temp, i, j;
    if (asc){
    for (i = 0; i < listLength(*l); i++){
        for (j = 0; j < listLength(*l)-1; j++){
            if (ELMT(*l, i) > ELMT(*l, i+1)){
                temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, j+1);
                ELMT(*l, j+1) = temp;
            }
        }
    }
    } else {
        for (i = 0; i < listLength(*l); i++){
            for (j = 0; j < listLength(*l)-1; j++){
                if (ELMT(*l, i) < ELMT(*l, i+1)){
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j+1);
                    ELMT(*l, j+1) = temp;
                }
            }
        }
    }
}
    