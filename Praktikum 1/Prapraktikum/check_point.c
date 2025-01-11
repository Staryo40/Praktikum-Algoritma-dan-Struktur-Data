#include <stdio.h>
#include "point.h"
#include "point.c"

int main(){
    POINT point1, point2;
    POINT *px1 = &point1;
    POINT *px2 = &point2;
    CreatePoint(px1, 3, 4);
    CreatePoint(px2, 3, 4);

    Putar(px1, 90);
    printf("Pakai variable lokal\n");
    TulisPOINT(point1);
    printf("\n");

    PutarTest(px2, 90);
    printf("Gak Pakai variable lokal\n");
    TulisPOINT(point2);

    return 0;
}