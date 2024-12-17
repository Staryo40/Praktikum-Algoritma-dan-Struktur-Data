#include "bintree.h"
#include "boolean.h"
#include <stdio.h>

void maxHartaHelper(BinTree T, int *includeCurrent, int *excludeCurrent) {
    if (T == NULL) {
        *includeCurrent = 0; 
        *excludeCurrent = 0;
        return;
    }

    int leftInclude;
    int leftExclude;
    int rightInclude;
    int rightExclude;

    // Rekursi ke anak kiri dan kanan
    maxHartaHelper(LEFT(T), &leftInclude, &leftExclude);
    maxHartaHelper(RIGHT(T), &rightInclude, &rightExclude);

    *includeCurrent = ROOT(T) + leftExclude + rightExclude;

    *excludeCurrent = (leftInclude > leftExclude ? leftInclude : leftExclude) + 
                      (rightInclude > rightExclude ? rightInclude : rightExclude);
}

int mencurry(BinTree T) {
    int includeRoot, excludeRoot;

    maxHartaHelper(T, &includeRoot, &excludeRoot);

    return (includeRoot > excludeRoot ? includeRoot : excludeRoot);
}