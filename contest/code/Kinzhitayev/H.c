#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch = '\0', *word = NULL;
    int len = 0;
    while (ch != '\n') {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {
            if (len == 3) {
                for (int i = 0; i < len; i++) {
                    putchar(word[i]);
                }
                puts("");
            }
            len = 0;
            free(word);
            word = NULL;
        } else {
            len++;
            word = (char*)realloc(word, sizeof(char) * len);
            word[len - 1] = ch;
        }
    }
    return 0;
}
