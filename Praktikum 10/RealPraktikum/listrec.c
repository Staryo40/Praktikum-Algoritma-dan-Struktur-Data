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

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx)
/* Fungsi untuk menambahkan e sebagai elemen pada posisi/index idx sebuah list l */
{
    Address new = newNode(e); 
    if (idx == 0) {
        NEXT(new) = l;
        l = new;
        return l;
    }

    if (l == NULL) {
        return new; 
    }

    NEXT(l) = insertAt(NEXT(l), e, idx-1);
    return l;
}
List deleteFirst(List l)
/* Fungsi untuk menghapus elemen pertama sebuah list l */
{
    if (l == NIL) {
        return NIL;
    }

    l = NEXT(l);
    return l;
}
List deleteAt(List l, int idx)
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */
{
    if (l == NIL) {
        return NIL;
    }

    if (idx == 0){
        l = NEXT(l);
        return l;
    }

    NEXT(l) = deleteAt(NEXT(l), idx-1);
    return l;
}
List deleteLast(List l)
/* Fungsi untuk menghapus elemen terakhir sebuah list l */
{
    if (l == NIL || NEXT(l) == NIL) {
        return NIL; 
    }

    // Recurse until the second-to-last node
    if (NEXT(NEXT(l)) == NIL) {
        NEXT(l) = NIL; 
        return l;
    }

    NEXT(l) = deleteLast(NEXT(l)); 
    return l;
}
/*** Operasi-Operasi Lain ***/
List reverseList (List l)
/* Mengirimkan list baru, list l yang dibalik dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    if (l == NIL) {
        return NIL;  
    }

    if (NEXT(l) == NIL) {
        return l;
    }

    // Rekursi
    List reversedRest = reverseList(NEXT(l));

    // Alokasi
    Address new = newNode(INFO(l)); 
    if (new == NIL) {
        return NIL; 
    }

    Address temp = reversedRest;
    while (NEXT(temp) != NIL) {
        temp = NEXT(temp);
    }
    NEXT(temp) = new;  

    return reversedRest;  
}
void splitOddEven (List l, List *l1, List *l2)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang genap, sedangkan l2 berisi
semua elemen l yang ganjil; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
{
    if (l == NIL){
        return;
    }

    if (INFO(l) % 2 == 0){
        *l1 = konsb(*l1, INFO(l));
    }

    if (INFO(l) % 2 != 0){
        *l2 = konsb(*l2, INFO(l));
    }
    splitOddEven(NEXT(l), l1, l2);
}
void splitOnX (List l, ElType x, List *l1, List *l2)
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang sebelum indeks ke-x 
      l2 berisi semua elemen l setelah indeks ke-x (termasuk indeks ke-x)
*/
{
    *l1 = NIL;
    *l2 = NIL;

    if (l == NIL) {
        return;
    }

    if (x == 0) {
        *l2 = l;
        return;
    }

    List temp = l;
    int idx = 0;

    while (temp != NIL && idx < x - 1) {
        temp = NEXT(temp);
        idx++;
    }

    if (temp != NIL && NEXT(temp) != NIL) {
        *l1 = l; 
        *l2 = NEXT(temp);  

        NEXT(temp) = NIL;
    }
}
ElType getMiddle(List l)
/* I.S. l terdefinisi, bukan list kosong */
/* F.S. Mengembalikan elemen tengah dari List l */
/* Jika jumlah elemen dalam List l ganjil, elemen tengah adalah elemen yang berada di posisi tengah.
   Jika jumlah elemen dalam List l genap, elemen tengah adalah elemen di posisi tengah kedua. */
/* Contoh:
   l = [1, 2, 3, 4, 5]
   elemen tengah = 3

   l = [1, 6, 3, 10]
   elemen tengah = 3 (6 dan 3 berada di tengah, dikembalikan elemen tengah kedua, yaitu 3) */
{
    if (l == NIL) {
        return NIL;  
    }

    Address slow = l;
    Address fast = l;

    while (fast != NIL && NEXT(fast) != NIL) {
        slow = NEXT(slow);
        fast = NEXT(NEXT(fast));
    }

    return INFO(slow);
}
