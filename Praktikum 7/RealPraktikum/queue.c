#include <stdio.h>
#include "boolean.h"
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return ((IDX_HEAD(q) == IDX_UNDEF) || (IDX_TAIL(q) == IDX_UNDEF));
}
boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return ((IDX_HEAD(q) - IDX_TAIL(q) == 1) || (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY-1));
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (isEmpty(q)){
        return 0;
    }

    int length;
    if (IDX_HEAD(q) <= IDX_TAIL(q)){
        length = IDX_TAIL(q) - IDX_HEAD(q) + 1;
    } else {
        length = (CAPACITY - IDX_HEAD(q)) + IDX_TAIL(q) + 1;
    }
    return length;
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q) = val;
    }
}
void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
{
    *val = HEAD(*q);
    IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % 100;
    if (IDX_HEAD(*q) == IDX_TAIL(*q) + 1){ //becomes empty
        IDX_HEAD(*q) = IDX_UNDEF; 
        IDX_TAIL(*q) = IDX_UNDEF;
    } 
}
/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", dan diakhiri dengan
   enter atau newline '\n' */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    printf("[");
    if (!isEmpty(q)){
        int i = IDX_HEAD(q)-1;
        do {
            i = (i + 1) % CAPACITY;

            printf("%d", q.buffer[i]);

            if (i != IDX_TAIL(q)){
                printf(",");
            }
        } while (i != IDX_TAIL(q));
    }
    printf("]\n");
}