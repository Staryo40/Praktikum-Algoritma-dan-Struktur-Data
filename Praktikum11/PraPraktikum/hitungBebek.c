#include "bintree.h"
#include <stdio.h>

int calculatePathProduct(BinTree root, int n, int sum, int product) {
    // if (isOneElmt(root)) {
    //     return 0;
    // }

    // Update the sum and product along the current path
    sum += ROOT(root);
    product *= ROOT(root);

    // If it's a leaf node, check if the sum equals n
    if (isOneElmt(root)) {
        if (sum == n) {
            return product;  // Return the product if the sum equals n
        }
        return 0;  // Return 0 if the sum is not equal to n
    }

    // Recur for left and right children and accumulate the results
    int leftSum = calculatePathProduct(LEFT(root), n, sum, product);
    int rightSum = calculatePathProduct(RIGHT(root), n, sum, product);

    return leftSum + rightSum;  // Return the sum of products from both subtrees
}

int hitungBebek(BinTree root, int n) {
    return calculatePathProduct(root, n, 0, 1);  // Start with sum = 0, product = 1
}

int main(){
    BinTree sright = NewTree(8, NewTree(13, NULL, NULL), NewTree(4, NewTree(5, NULL, NULL), NewTree(1, NULL, NULL)));
    BinTree fleft = NewTree(4, NewTree(11, NewTree(7, NULL, NULL), NewTree(2, NULL, NULL)), NULL);
    BinTree p = NewTree(5, fleft, sright);

    int result = hitungBebek(p, 22);
    printf("Result = %d\n", result); 

    return 0;
}