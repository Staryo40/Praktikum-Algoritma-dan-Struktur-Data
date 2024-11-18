#include <stdio.h>
#include "mesinkata.h"
#include "boolean.h"

#define pemisah '@'

int toInt(Word w) {
    int result = 0;
    for (int i = 0; i < w.Length; i++) {
        result = result * 10 + (w.TabWord[i] - '0');
    }
    return result;
}

boolean isAlay(Word w){
    if (w.Length < 7 || w.Length > 15) return false;

    // making sure all character is a digit or pemisah
    for (int i = 0; i < w.Length; i++){
        if ((w.TabWord[i] < '0' || w.TabWord[i] > '9') && w.TabWord[i] != pemisah){
            return false;
        }
    }

    // memastikan hanya ada 3 '@'
    int pemisahCount = 0;
    for (int i = 0; i < w.Length; i++){
        if (w.TabWord[i] == pemisah){
            pemisahCount++;
        }
    }

    if (pemisahCount != 3){
        return false;
    }

    // parsing oktet
    int oktet[4] = {0};
    Word temp;
    temp.Length = 0;
    int j = 0; // octet index

    for (int i = 0; i < w.Length; i++) {
        if (w.TabWord[i] == pemisah) {
            if (temp.Length == 0 || (temp.Length > 1 && temp.TabWord[0] == '0')) return false;
            
            oktet[j] = toInt(temp);
            if (oktet[j] < 0 || oktet[j] > 255) return false;
            j++;
            temp.Length = 0;
        } else {
            temp.TabWord[temp.Length++] = w.TabWord[i];
        }
    }

    // Parse the last octet 
    if (temp.Length == 0 || j != 3 || (temp.Length > 1 && temp.TabWord[0] == '0')) return false;
    oktet[j] = toInt(temp);
    if (oktet[j] < 0 || oktet[j] > 255) return false;

    return true;
}

int main(){
    STARTWORD();

    while (!EndWord){
        if (isAlay(currentWord)){
            printf("4Lay");
        } else {
            printf("ewh");
        }

        ADVWORD();
        if (!EndWord){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}