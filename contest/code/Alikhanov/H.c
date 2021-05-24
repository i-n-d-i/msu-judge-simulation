#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char a[4];
    char ch;
    int count;
    do {
        count = 0;
        do {
            ch = getchar();
            a[count] = ch;
            count++;
        } while(count != 4 && ch != ' ' && ch != '\n');
        if (ch != ' ' && ch != '\n') {
            while(ch != ' ' && ch != '\n') {
                ch = getchar();
            }
        } else if (count == 4) {
            for (count = 0; count < 4; count++) {
                putchar(a[count]);
            }
        }
    } while(ch != '\n');
    return 0;
}
