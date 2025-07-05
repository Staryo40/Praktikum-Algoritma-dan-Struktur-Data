#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree)
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
     BinTree p = (Address) malloc(sizeof(TreeNode));

     if (p == NULL){
        return p;
     } else {
        ROOT(p) = root;
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;

        return p;
     }
}
void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
{
    *p = NewTree(root, left_tree, right_tree);
}
Address newTreeNode(ElType val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
{
    Address p = (Address) malloc(sizeof(ElType));

    if (p == NULL){
        return p;
    }  else {
        ROOT(p) = val;
        RIGHT(p) = NULL;
        LEFT(p) = NULL;
        return p;
    }
}

void deallocTreeNode (Address p)
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
{
    free(p);
}
boolean isTreeEmpty (BinTree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
    return (p == NULL);
}
boolean isOneElmt (BinTree p)
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
{
    return (p != NULL && RIGHT(p) == NULL && LEFT(p) == NULL);
}
boolean isUnerLeft (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
{
    return (p != NULL && RIGHT(p) == NULL && LEFT(p) != NULL);
}
boolean isUnerRight (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
{
    return (p != NULL && RIGHT(p) != NULL && LEFT(p) == NULL);
}
boolean isBinary (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
{
    return (p != NULL && RIGHT(p) != NULL && LEFT(p) != NULL);
}
/* ****** Display Tree ***** */
void printPreorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    printf("(");
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}
void printInorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    printf("(");
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}
void printPostorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    printf("(");
    if (!isTreeEmpty(p)) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}


void printTreeLevel(BinTree p, int h, int l) {
    // prosedur tambahan untuk print spasi sebelum root dari level yang sedang diprint
    if (!isTreeEmpty(p)) {
        for (int i = 0; i < h*l; i++) {
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printTreeLevel(LEFT(p), h, l+1);
        printTreeLevel(RIGHT(p), h, l+1);
    }
}
void printTree(BinTree p, int h)
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
{
    printTreeLevel(p, h, 0);
}

boolean isEqual(BinTree p1, BinTree p2)
/* I.S. p1 dan p2 terdefinisi */
/* F.S. Mengirimkan true jika struktur dan nilai node pada p1 dan p2 identik, false jika tidak */
{
    if (isTreeEmpty(p1) && isTreeEmpty(p2)){
        return true;
    }

    if (isOneElmt(p1) && isOneElmt(p2)){
        if (ROOT(p1) == ROOT(p2)){
            return true;
        } else {
            return false;
        }
    }

    if (isUnerLeft(p1) && isUnerLeft(p2)){
        if (ROOT(p1) == ROOT(p2)){
            return true && isEqual(LEFT(p1), LEFT(p2));
        } else {
            return false;
        }
    }
    
    if (isUnerRight(p1) && isUnerRight(p2)){
        if (ROOT(p1) == ROOT(p2)){
            return true && isEqual(RIGHT(p1), RIGHT(p2));
        } else {
            return false;
        }
    }

    if (isBinary(p1) && isBinary(p2)){
        if (ROOT(p1) == ROOT(p2)){
            return true && isEqual(RIGHT(p1), RIGHT(p2)) && isEqual(LEFT(p1), LEFT(p2));
        } else {
            return false;
        }
    }

    return false;
}

int getMaximumDepth(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Mengembalikan kedalaman maksimum pohon biner p */
/* Kedalaman maksimum adalah panjang lintasan dari akar ke simpul daun terjauh */
/* Jika pohon kosong, maka kedalaman = 0 */
{   
    if (isTreeEmpty(p)){
        return 0;
    }

    if (isOneElmt(p)){
        return 1;
    }

    if (isUnerLeft(p)){
        return 1 + getMaximumDepth(LEFT(p));
    }

    if (isUnerRight(p)){
        return 1 + getMaximumDepth(RIGHT(p));
    }

    if (isBinary(p)){
        int right = getMaximumDepth(RIGHT(p));
        int left = getMaximumDepth(LEFT(p));

        int max;
        if (right >= left){
            max = right;
        } else {
            max = left;
        }

        return 1 + max;
    }
}
BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start, ElType end)
/* Mengembalikan pohon biner yang seimbang (balanced) dibangun dari array yang terurut */
/* arr terdefinisi dan tidak kosong, start dan end adalah indeks awal dan akhir array */
/* arr merupakan array berisi ElType yang terurut menaik (ascending) */
/* dipastikan semua elemen pada array unik */
/* Pilih elemen tengah dari array (indeks mid = (start + end) / 2) sebagai akar pohon. */
/* Pohon yang dihasilkan adalah Binary Search Tree(BST), di mana setiap node kiri lebih kecil dari parent node,
   dan setiap node kanan lebih besar dari parent node. */
/* Misalnya, jika array [1, 2, 3, 4, 5], pohon yang dihasilkan adalah:
    3
   / \
  1   4
   \   \
    2    5
*/
{
     if (start > end) {
        return NULL;
    }
    int mid = (start+end)/2;

    BinTree leftSubtree = createBinSearchTreeFromSortedArray(arr, start, mid - 1);
    BinTree rightSubtree = createBinSearchTreeFromSortedArray(arr, mid + 1, end);

    return NewTree(arr[mid], leftSubtree, rightSubtree);
}

int countNodes(BinTree p)
/* p terdefinisi, p adalah pohon biner yang mungkin kosong */
/* Mengembalikan jumlah seluruh node dalam pohon biner p */
/* Contoh:
   Misalkan pohon biner p adalah sebagai berikut:
       1
      / \
     2   3
    / \
   4   5

   Panggilan fungsi: countNodes(p)

   Output: 5
   Penjelasan: Pohon ini memiliki 5 simpul (1, 2, 3, 4, 5)
*/
{
    if (isTreeEmpty(p)){
        return 0;
    }

    if (isOneElmt(p)){
        return 1;
    }

    if (isUnerLeft(p)){
        return 1 + countNodes(LEFT(p));
    }

    if (isUnerRight(p)){
        return 1 + countNodes(RIGHT(p));
    }

    if (isBinary(p)){
        return 1 + countNodes(LEFT(p)) + countNodes(RIGHT(p));
    }
}

boolean findElement(BinTree p, ElType target){
    if (isTreeEmpty(p)){
        return false;
    }

    if (isOneElmt(p)){
        if (ROOT(p) == target){
            return true;
        } else {
            return false;
        }
    }

    if (isUnerLeft(p)){
        if (ROOT(p) == target){
            return true;
        } else {
            return findElement(LEFT(p), target);
        }
    }

    if (isUnerRight(p)){
        if (ROOT(p) == target){
            return true;
        } else {
            return findElement(RIGHT(p), target);
        }
    }

    if (isBinary(p)){
        if (ROOT(p) == target){
            return true;
        } else {
            return findElement(LEFT(p), target) || findElement(RIGHT(p), target);
        }
    }
}

void printPathToElementHelper(BinTree p, ElType target, ElType path[], int *pathIndex) {
    if (p == NULL) {
        return;
    }

    path[*pathIndex] = p->info;
    (*pathIndex)++;

    if (p->info == target) {
        for (int i = 0; i < *pathIndex; i++) {
            if (i > 0) {
                printf(" -> ");
            }
            printf("%d", path[i]);
        }
        printf("\n");
        return;
    }

    printPathToElementHelper(p->left, target, path, pathIndex);
    printPathToElementHelper(p->right, target, path, pathIndex);

    (*pathIndex)--;
}

void printPathToElement(BinTree p, ElType target) {
    ElType path[100]; 
    int pathIndex = 0; 

    printPathToElementHelper(p, target, path, &pathIndex);

    // If the target is not found, print -1
    if (pathIndex == 0) {
        printf("-1\n");
    }
}