#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val){
    Address new_node = (Address)malloc(sizeof(Node));
    
    if (new_node == NULL) {
        return NULL;
    }
    
    new_node->info = val;
    new_node->next = NULL;
    
    return new_node;
}
/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return (FIRST(l) == NULL);
}
/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    Address p = FIRST(l);
    int i = 0;
    while (i < idx){ // setting p to be the i-th element
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}
void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    Address p = FIRST(*l);
    int i = 0;
    while (i < idx){ // setting p to be the i-th element
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}
int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    Address p = FIRST(l);
    boolean found = false;
    int i = 0;
    while (p != NULL && !found){
        if (INFO(p) == val){
            found = true;
        } else {
            p = NEXT(p);
            i++;
        }
    }

    if (p == NULL){
        return IDX_UNDEF;
    } else {
        return i;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address x = newNode(val);
    if (x != NULL){
        if (isEmpty(*l)){
            FIRST(*l) = x;
        } else {
            NEXT(x) = FIRST(*l);
            FIRST(*l) = x;
        }
    }
}
void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address p = FIRST(*l);
    Address x = newNode(val);
    if (x != NULL){
        if (p == NULL){
            FIRST(*l) = x;
        } else {
            while (NEXT(p) != NULL){
                p = NEXT(p);
            }
            NEXT(p) = x;
        }
    }
}
void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address p = FIRST(*l);
    Address x = newNode(val);
    int i = 0;
    if (x != NULL){
        while (i < idx-1){
            p = NEXT(p);
            i++;
        }
        
        if (idx == 0){
            insertFirst(l, val);
        } else {
            NEXT(x) = NEXT(p);
            NEXT(p) = x;
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = FIRST(*l);
    *val = INFO(p);
    if (NEXT(p) == NULL){
        FIRST(*l) = NULL;
    } else {
        FIRST(*l) = NEXT(p);
    }
    free(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address p = FIRST(*l);
    Address last = NEXT(p);
    if (NEXT(p) == NULL){ // cuma satu elemen
        *val = INFO(p);
        FIRST(*l) = NULL;
        free(p);
    } else {
        while (NEXT(last) != NULL){ //finding the second to last element
            last = NEXT(last);
            p = NEXT(p);
        }
        *val = INFO(last);
        free(last);
        NEXT(p) = NULL;
    }
}
void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    Address p = FIRST(*l);
    Address target = NEXT(p);
    int i = 0;
    if (idx == 0){ // cuma satu elemen
        if (NEXT(p) == NULL){
            *val = INFO(p);
            FIRST(*l) = NULL;
            free(p);
        } else {
            deleteFirst(l, val);
        }
    } else {
        while (i < idx-1){ //finding the i-th element
            target = NEXT(target);
            p = NEXT(p);
            i++;
        }
        *val = INFO(target);
        NEXT(p) = NEXT(target);
        free(target);
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    Address p = FIRST(l);
    while (p != NULL){
        printf("%d", INFO(p));
        if (NEXT(p) != NULL){
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}
int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    Address p = FIRST(l);
    int len = 0;
    while (p != NULL){
        p = NEXT(p);
        len++;
    }
    return len;
}
/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    List l3;
    CreateList(&l3);
    Address p = FIRST(l1);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}