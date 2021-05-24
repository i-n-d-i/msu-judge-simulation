#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int init = 0, size, letter = 0;
    char ch;
    char *word;
    do {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {
            if (letter == 3) {
                for (int i = 0; i < 3; i++) {
                    printf("%c", word[i]);
                }
                putchar(' ');
            }
            letter = 0;
            init = 0;
            word = realloc(word, 0);
        } else {
            size = (init + 1) * sizeof(int);
            word = realloc(word, size);
            word[init] = ch;
            init++;
            letter++;
        }
    } while (ch != '\n');
    putchar('\n');
    free(word);
    return 0;
}
