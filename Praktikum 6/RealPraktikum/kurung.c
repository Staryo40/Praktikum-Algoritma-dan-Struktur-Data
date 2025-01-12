#include "stack.h"
#include <stdio.h>
#include "boolean.h"

int kurType(char c){
    char open[3] = "([{";
    char close[3] = ")]}";
    int res = -1;
    for (int j = 0; j < 3; j++){
        if (c == open[j]){
            res = j;
        }
        if (c == close[j]){
            res = j;
        }
        if (res != -1){
            break;
        }
    }
    return res;
}

int main(){
    int N;
    scanf("%d", &N);
    char kur[N];
    scanf("%s", &kur);
    

    char open[3] = "([{";
    char close[3] = ")]}";
    int lowongan[3] = {0, 0, 0};

    Stack s;
    CreateEmpty(&s);
    boolean valid = true;
    int i = 0;
    while (valid && i < N){
        for (int j = 0; j < 3; j++){
            if (kur[i] == open[j]){
                Push(&s, kur[i]);
            }
            if (kur[i] == close[j]){
                if (IsEmpty(s)){
                    valid = false;
                    break;
                } else {
                    if (kurType(kur[i]) != kurType(InfoTop(s))){
                        valid = false;
                        break;
                    } else {
                        char dummy;
                        Pop(&s, &dummy);
                    }
                }
            }
        }
        i++;
    }

    if (!IsEmpty(s)){
        valid = false;
    }

    if (valid){
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    
    
    return 0;
}

// TEST CASE
// TC 1
// Input: n = 4, str = '({})'
// Output: Valid
// TC 2
// Input: n = 2, str = '(]' 
// Output: Invalid
// TC 3 (buatan sendiri)
// Input: n = 6, str = '()[]{}'
// Output: Valid
