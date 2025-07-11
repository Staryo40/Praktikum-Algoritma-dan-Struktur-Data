#include "prioqueue.h"
#include "boolean.h"
#include <stdio.h>

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq)
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
{
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}
/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq)
/* Mengirim true jika pq kosong: lihat definisi di atas */
{
    return ((IDX_HEAD(pq) == IDX_UNDEF) || (IDX_TAIL(pq) == IDX_UNDEF));
}
boolean isFull(PrioQueue pq)
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return ((IDX_HEAD(pq) - IDX_TAIL(pq) == 1) || (IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == CAPACITY-1));
}
int length(PrioQueue pq)
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */
{
    if (isEmpty(pq)){
        return 0;
    }

    int length;
    if (IDX_HEAD(pq) <= IDX_TAIL(pq)){
        length = IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    } else {
        length = (CAPACITY - IDX_HEAD(pq)) + IDX_TAIL(pq) + 1;
    }
    return length;
}

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val)
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */
{
    int i = IDX_HEAD(*pq);
    int arr[CAPACITY];
    int idx = 0;
    if (isEmpty(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        HEAD(*pq) = val;
    } else if (IDX_HEAD(*pq) == IDX_TAIL(*pq)) {
        // Special case for when the queue has only one element
        if (val < HEAD(*pq)) {
            // Insert the new element at the front
            int temp = HEAD(*pq);
            HEAD(*pq) = val;
            IDX_HEAD(*pq) = (IDX_HEAD(*pq) - 1 + CAPACITY) % CAPACITY;
            HEAD(*pq) = temp;
        } else {
            // Insert at the end
            IDX_HEAD(*pq) = (IDX_HEAD(*pq) - 1 + CAPACITY) % CAPACITY;
            HEAD(*pq) = val;
        } 
    } else {
        // taking all elements in front of target area
        while (i != (IDX_TAIL(*pq) + 1) % CAPACITY && val < HEAD(*pq)) {
            dequeue(pq, &arr[idx]);  
            i = (i + 1) % CAPACITY;  
            idx++;
        }

        // Insert the new element at the correct spot
        if (isEmpty(*pq)) {
            IDX_HEAD(*pq) = 0;
            IDX_TAIL(*pq) = 0;
        } else {
            IDX_HEAD(*pq) = (IDX_HEAD(*pq) - 1 + CAPACITY) % CAPACITY;
        }
        HEAD(*pq) = val;

        // Put back the dequeued elements after the new value
        for (int j = idx - 1; j >= 0; j--) {
            IDX_HEAD(*pq) = (IDX_HEAD(*pq) - 1 + CAPACITY) % CAPACITY;
            HEAD(*pq) = arr[j];
        }
    }
}
void dequeue(PrioQueue *pq, ElType *val)
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        pq mungkin kosong */
{
    *val = HEAD(*pq);
    IDX_HEAD(*pq) = (IDX_HEAD(*pq) + 1) % 100;
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq) + 1){ //becomes empty
        IDX_HEAD(*pq) = IDX_UNDEF; 
        IDX_TAIL(*pq) = IDX_UNDEF;
    } 
}
/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq)
/* Proses : Menuliskan isi PrioQueue dengan traversal, PrioQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq boleh kosong */
/* F.S. Jika pq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 30, 20, 1 akan dicetak: [30,20,1] */
/* Jika Queue kosong : menulis [] */
{
    printf("[");
    if (!isEmpty(pq)){
        int i = IDX_HEAD(pq)-1;
        do {
            i = (i + 1) % CAPACITY;

            printf("%d", pq.buffer[i]);

            if (i != IDX_TAIL(pq)){
                printf(",");
            }
        } while (i != IDX_TAIL(pq));
    }
    printf("]\n");
}