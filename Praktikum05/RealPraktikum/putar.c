
#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>


void putarKata(){
    Word res;
    res.Length = currentWord.Length;
    int i;
    int j = 0;
    for (i = currentWord.Length-1; i >= 0; i--){
        res.TabWord[i] = currentWord.TabWord[j];
        j++;
    }

    for (int i = 0; i < res.Length; i++) {
        printf("%c", res.TabWord[i]);
    }
    ADVWORD();
}

int main(){
    STARTWORD();
    int i = 1;
    while(!EndWord){
        if (i % 2 != 0){
            putarKata();
        } else {
            for (int i = 0; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
            ADVWORD();
        }
        i++;
        if (!EndWord) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}

