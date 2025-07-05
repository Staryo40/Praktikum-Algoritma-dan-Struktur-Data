#include "stack.h"
#include <stdio.h>

int main()
{
    int N, i;
    char ch;
    Stack s;
    CreateEmpty(&s);

    scanf("%d", &N);


    for (i = 0; i < N; i++) {
        scanf(" %c", &ch);
        if (ch == '+') {
            int temp1, temp2, temp3;
            Pop(&s, &temp1);
            Pop(&s, &temp2);
            temp3 = temp1 + temp2;
            Push(&s, temp2);
            Push(&s, temp1);
            Push(&s, temp3);
        }
        else if (ch == 'X') {
            int temp;
            Pop(&s, &temp);
        }
        else if (ch == 'S') {
            int total = 0;
            int temp;
            while(!IsEmpty(s)) {
                Pop(&s, &temp);
                total += temp;
            }
            Push(&s, total);
        }
        else if (ch == 'A') {
            int total = 0;
            int count = 0;
            int temp;
            while(!IsEmpty(s)) {
                Pop(&s, &temp);
                total += temp;
                count++;
            }
            if (count == 0) count = 1;
            Push(&s, total/count);
        }
        else {
            Push(&s, (ch - '0'));
        }
    }

    int total = 0;
    int temp;
    while (!IsEmpty(s)) {
        Pop(&s, &temp);
        total += temp;
    }
    printf("%d\n", total);
    return 0;   
}
