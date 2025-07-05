#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list_circular.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (FIRST(l) == NULL);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FIRST(*l) = NULL;
}
/****************** Manajemen Memori ******************/
Address allocate(ElType val)
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    Address p = (Address) malloc(sizeof(ElmtList)); 
    if (p == NULL) {
        return NULL;
    } else {
        INFO(p) = val;  
        NEXT(p) = NULL;  
        return p;        
    }
}
void deallocate(Address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
{
    if (P != NULL){
        free(P);
    }
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    if (isEmpty(l)){
        return NULL;
    }

    Address p = FIRST(l);
    while (NEXT(p) != FIRST(l) && INFO(p) != val){ // won't check if last element is val or not
        p = NEXT(p);
    }

    if (INFO(p) == val){ // returns address where val is located, even if it is at the end of list
        return p;
    } else {
        return NULL;
    }
}
boolean addrSearch(List l, Address p)
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    if (isEmpty(l)){
        return false;
    }

    Address q = FIRST(l);
    while (q != p && NEXT(q) != FIRST(l)){
        q = NEXT(q);
    }

    if (q == p){
        return true;
    } else {
        return false;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
{
    if (isEmpty(*l)){ // empty case
        Address newNode = allocate(val);
        FIRST(*l) = newNode;
        NEXT(newNode) = FIRST(*l);
    } else {
        // search for last element
        Address last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }  

        Address newNode = allocate(val);
        NEXT(newNode) = FIRST(*l);
        FIRST(*l) = newNode;
        NEXT(last) = FIRST(*l);
    }
}
void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (isEmpty(*l)){ // empty case
        Address newNode = allocate(val);
        NEXT(newNode) = newNode;
        FIRST(*l) = newNode;
    } else {
        // search for last element
        Address last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }  

        Address newNode = allocate(val);
        NEXT(newNode) = FIRST(*l);
        NEXT(last) = newNode;
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val)
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama list l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Alamat elemen terakhir di-dealokasi */
{
    // search for last element
    Address last = FIRST(*l);
    while (NEXT(last) != FIRST(*l)){
        last = NEXT(last);
    }  
    Address first = FIRST(*l);
    if (first == last){ // if there is only one element
        *val = INFO(FIRST(*l));
        FIRST(*l) = NULL;
        deallocate(first);
    } else {
        NEXT(last) = NEXT(first);   // make last point to the second element
        FIRST(*l) = NEXT(first);    // make the second element as the first element
        *val = INFO(first);         // assigning first's value to val
        deallocate(first);          // freeing the previous first
    }
}
void deleteLast(List *l, ElType * val)
/* I.S. list tidak kosong */
/* F.S. x adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen pertama yg lama, jika ada */
/*      Alamat elemen terakhir di-dealokasi */
{
    // search for last element
    Address p = FIRST(*l);
    Address q = NEXT(p);
    if (q == FIRST(*l)){ // if there is only one element
        *val = INFO(FIRST(*l));
        FIRST(*l) = NULL;
        deallocate(q);
    } else {
         while (NEXT(q) != FIRST(*l)){
            p = NEXT(p);
            q = NEXT(q);
        }  
        *val = INFO(q);             // assigning last's value to val
        NEXT(p) = FIRST(*l);        // make second to last point to the first element
        deallocate(q);              // deallocate last
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
    if (!isEmpty(l)){
        Address p = FIRST(l);
        while (NEXT(p) != FIRST(l)){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }

        if (NEXT(p) == FIRST(l)){
            printf("%d", INFO(p));
        }
    }
     printf("]");
}