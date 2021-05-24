#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *a = NULL;
    char ch;
    int count = 0;
    do {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {
            for (int i = 0; i < count; i++){
                putchar(a[count - i - 1]);
            }
            putchar(' ');
            free(a);
            a = NULL;
            count = 0;
        } else {
            a = (char*)realloc(a, (count + 1) * sizeof(char));
            a[count] = ch;
            count++;
        }
    } while(ch != '\n');
    free(a);
    putchar('\n');
    return 0;
}
