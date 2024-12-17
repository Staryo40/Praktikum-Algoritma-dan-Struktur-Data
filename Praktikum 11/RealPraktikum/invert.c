#include <stdio.h>
#include "bintree.h"

void invertTree(BinTree *p) {
    // IMPLEMENTASI DISINI
    if (isTreeEmpty(*p) ||isOneElmt(*p)){
        return;
    }

    if (isUnerLeft(*p)){
        RIGHT(*p) = LEFT(*p);
        LEFT(*p) = NULL;
        invertTree(&RIGHT(*p));
        return;
    }

    if (isUnerRight(*p)){
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = NULL;
        invertTree(&LEFT(*p));
        return;
    }

    if (isBinary(*p)){
        Address temp = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = temp;

        invertTree(&RIGHT(*p));
        invertTree(&LEFT(*p));
        return;
    }
}