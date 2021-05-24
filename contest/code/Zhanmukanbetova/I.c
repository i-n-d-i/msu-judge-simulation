#include <stdio.h>
#include <stdlib.h>

void print_reverse(char *word, int len) {
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
}

int main(void) {
    int init = 0, size, letter = 0;
    char ch;
    char *word;
    do {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {
            print_reverse(word, init);
            putchar(' ');
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
