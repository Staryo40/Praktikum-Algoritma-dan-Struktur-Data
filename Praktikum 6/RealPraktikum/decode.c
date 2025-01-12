#include "stack.h"
#include <stdio.h>

int main()
{
    int N;
    scanf("%d\n", &N);

    Stack s, s2;
    CreateEmpty(&s);
    CreateEmpty(&s2);

    int i;
    char c;
    int ascii;
    for (i = 0; i < N; i++) {
        scanf(" %c", &c);
        if (c == ']') {
            CreateEmpty(&s2);
            Pop(&s, &ascii);
            c = (char) ascii;
            while (c != '[') {
                Push(&s2, c);
                Pop(&s, &ascii);
                c = (char) ascii;
            }
            
            int k = 0;
            int temp;
            int dig = 0;
            while (true) {
                if (IsEmpty(s)) break;

                Pop(&s, &temp);

                if (temp < 48 || temp > 57) {
                    Push(&s, temp);
                    break;
                }

                temp -= 48;
                int i;
                for (i = 0; i < dig; i++) {
                    temp *= 10;
                }
                k += temp;
                dig++;
            }
            
            int j;
            for (j = 0; j < k; j++) {
                int idx;
                for (idx = Top(s2); idx >= 0; idx--) {
                    Push(&s, s2.T[idx]);
                }
            }
        } else {
            Push(&s, c);
        }
    }

    for (i = 0; i < Top(s) + 1; i++) {
        printf("%c", (char) s.T[i]);
    }
    printf("\n");
    return 0;
}