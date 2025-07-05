#include "bintree.h"
#include <stdio.h>

int hitungNode(BinTree root){
    if (isOneElmt(root)){
        printf("0 ran\n");
        return 0;
    }

    if (isBinary(root)){
        printf("binary ran\n");
        return hitungNode(LEFT(root)) + hitungNode(RIGHT(root));
    }

    if (isUnerLeft(root)){
        printf("left ran\n");
        return 1 + hitungNode(LEFT(root));
    }

    if (isUnerRight(root)){
        printf("right ran\n");
        return 1 + hitungNode(RIGHT(root));
    }
}

int main(){
    BinTree sright = NewTree(4, NewTree(2, NULL, NULL), NewTree(8, NULL, NULL));
    BinTree fleft = NewTree(2, NULL, sright);
    BinTree p = NewTree(1, fleft, NULL);

    int result = hitungNode(p);
    printf("Result = %d\n", result); 

    return 0;
}