#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"

void geserChar(int geser) {
    char orderLower[] = "abcdefghijklmnopqrstuvwxyz";
    char orderUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int realGeser = geser % 26;
    boolean isLetter;

    for (int i = 0; i < currentWord.Length; i++) {
        isLetter = false;

        for (int j = 0; j < 26; j++) {
            if (currentWord.TabWord[i] == orderLower[j]) {
                printf("%c", orderLower[(j - realGeser + 26) % 26]);
                isLetter = true;
                break;
            }
            if (currentWord.TabWord[i] == orderUpper[j]) {
                printf("%c", orderUpper[(j - realGeser + 26) % 26]);
                isLetter = true;
                break;
            }
        }

        if (!isLetter) {
            printf("%c", currentWord.TabWord[i]);
        }
    }

    ADVWORD();
}

int toInt(Word w) {
    int result = 0;
    for (int i = 0; i < w.Length; i++) {
        result = result * 10 + (w.TabWord[i] - '0');
    }
    return result;
}

int main() {
    STARTWORD();

    int geser = 0;
    if (!EndWord) {
        geser = toInt(currentWord);
        ADVWORD();
    }

    while (!EndWord) {
        geserChar(geser);
        if (!EndWord) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}