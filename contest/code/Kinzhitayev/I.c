#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch = '\0', *word = NULL;
    int len = 0;
    while (ch != '\n') {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {
            for (int i = len - 1; i >= 0; i--) {
                putchar(word[i]);
            }
            putchar(' ');
            len = 0;
            free(word);
            word = NULL;
        } else {
            len++;
            word = (char*)realloc(word, sizeof(char) * len);
            word[len - 1] = ch;
        }
    }
    puts("");
    return 0;
}
