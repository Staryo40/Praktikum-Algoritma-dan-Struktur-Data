#include <stdio.h>
#include "mesinkata.h"
// #include "mesinkata.c"
// #include "mesinkarakter.c"
#include "boolean.h"

boolean isKataEqual (Word w1, Word w2){
    int i;
    if (w1.Length != w2.Length){
        return false;
    }

    for (i = 0; i < w1.Length; i++){
        if (w1.TabWord[i] != w2.TabWord[i]){
            return false;
        }
    }
    return true;
}

boolean isNumberWord (Word x){
    Word numberWords[] = {{"nol", 3}, {"satu", 4}, {"dua", 3}, {"tiga", 4}, {"empat", 5}, {"lima", 4}, {"enam", 4}, {"tujuh", 5}, {"delapan", 7}, {"sembilan", 8}, {"sepuluh", 7}, {"sebelas", 7}, {"belas", 5}, {"puluh", 5}, {"seratus", 7}, {"ratus", 5}};
    int i;
    for (i = 0; i < 16; i++){
        if (isKataEqual(x, numberWords[i])){
            return true;
        }
    }
}

int getNumberValue(Word w) {
    if (isKataEqual(w, (Word){"satu", 4})) return 1;
    if (isKataEqual(w, (Word){"dua", 3})) return 2;
    if (isKataEqual(w, (Word){"tiga", 4})) return 3;
    if (isKataEqual(w, (Word){"empat", 5})) return 4;
    if (isKataEqual(w, (Word){"lima", 4})) return 5;
    if (isKataEqual(w, (Word){"enam", 4})) return 6;
    if (isKataEqual(w, (Word){"tujuh", 5})) return 7;
    if (isKataEqual(w, (Word){"delapan", 7})) return 8;
    if (isKataEqual(w, (Word){"sembilan", 8})) return 9;
    if (isKataEqual(w, (Word){"sepuluh", 7})) return 10;
    if (isKataEqual(w, (Word){"sebelas", 7})) return 11;
    return 0;
}

void processToNumber(){
    int number = 0;
    int subNum = 0;
    boolean sepNum = false;
    boolean subNumBool = false;

    while (!EndWord && isNumberWord(currentWord)) {
        if (isKataEqual(currentWord, (Word){"belas", 5})) {
            number += 10;
        } else if (isKataEqual(currentWord, (Word){"puluh", 5})) {
            if (subNumBool){
                subNum *= 10;
                sepNum = false;
            } else {
                number *= 10;
                sepNum = false;
            } 
        } else if (isKataEqual(currentWord, (Word){"ratus", 5})) {
            number *= 100;
            sepNum = false;
            subNumBool = true;
        } else if (isKataEqual(currentWord, (Word){"seratus", 7})) {
            number += 100;
            sepNum = false;
            subNumBool = true;
        } else {
            if (sepNum){
                break;
            }
            if (subNumBool){
                subNum += getNumberValue(currentWord);
                sepNum = true;
            } else {
                number += getNumberValue(currentWord);
                sepNum = true;
            }
        }

        ADVWORD();
    }

    number += subNum;
    printf("%d", number);
}

int main(){
    STARTWORD();

    while (!EndWord){
        if (isNumberWord(currentWord)) {
            processToNumber();
        } else {
            for (int i = 0; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
            ADVWORD();
        }

        if (!EndWord) {
            printf(" ");
        }
    }
    
    printf("\n");
    return 0;
}