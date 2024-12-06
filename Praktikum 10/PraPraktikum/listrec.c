#include "listrec.h"
#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>

Address newNode(ElType x)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
{
    Address p = (Address) malloc(sizeof(Node));
    if (p == NIL){
        return NIL;
    }
    INFO(p) = x;
    NEXT(p) = NIL;
    return p;
}
/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    return (l == NIL);
}

boolean isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    return (l != NIL && NEXT(l) == NIL);
}
/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    return INFO(l);
}
List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    List cl = copy(l);
    Address p = cl;
    cl = NEXT(p);
    free(p);
    return cl;
}
List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
{
    Address p = newNode(e);
    if (p == NIL){
        return l;
    }

    if (l == NIL){ //empty list
        return p;
    }

    NEXT(p) = l;
    l = p;
    return l;
}
List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
{
    Address p = newNode(e);
    if (p == NIL){ // failed allocation
        return l;
    }

    if (l == NIL){ //empty list
        return p;
    }

    NEXT(l) = konsb(NEXT(l), e);
    return l;
}
List copy(List l)
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
{
    if (l == NIL) {
        return NIL;  
    }

    Address currentNode = newNode(INFO(l));
    if (currentNode == NIL) {
        return NIL;  
    }

    NEXT(currentNode) = copy(NEXT(l));
    return currentNode;
}
List concat(List l1, List l2)
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
{
    if (l1 == NIL){
        return copy(l2);
    }

    Address currentNode = newNode(INFO(l1));
    if(currentNode == NIL){
        return NIL;
    }

    NEXT(currentNode) = concat(NEXT(l1), l2);
    return currentNode;
}
/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    if (l == NIL){
        return 0;
    }

    return 1 + length(NEXT(l));
}
boolean isMember(List l, ElType x)
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
{
    if (l == NIL){
        return false;
    }

    if (INFO(l) == x){
        return true;
    }

    isMember(NEXT(l), x);
}
void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    if(!isEmpty(l)){
        printf("%d\n", INFO(l));
        displayList(NEXT(l));
    }
}