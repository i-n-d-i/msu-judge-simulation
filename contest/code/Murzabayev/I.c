#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *word, c;
    int end_flag = 0, i;
    while (1) {
        word = NULL;
        for (i = 0; ; i++) {
            c = getchar();
            if (c == ' ') {
                break;
            }
            if (c == '\n') {
                end_flag = 1;
                break;
            }
            word = realloc(word, (i + 1) * sizeof(char));
            if (!word) {
                printf("ERROR\n");
                return 0;
            }
            word[i] = c;
        }
        for (i--; i >= 0; i--) {
            putchar(word[i]);
        }
        free(word);
        if (end_flag) {
            putchar('\n');
            break;
        } else {
            putchar(' ');
        }
    }
    return 0;
}
