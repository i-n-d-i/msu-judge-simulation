#include <stdio.h>
#include <stdlib.h>

char *get_word(char *last_char_ptr, int *num_of_digits) {
    char *word = NULL, ch;
    int n = 0, bytes;
    
    ch = getchar();
    while (ch != ' ' && ch != '\n') {
        bytes = (n + 1) * sizeof(char);
        word = realloc(word, bytes);
        word[n] = ch;
        n++;
        ch = getchar();
    }
    bytes = (n + 1) * sizeof(char);
    word = realloc(word, bytes);
    word[n] = '\0';
    *last_char_ptr = ch;
    *num_of_digits = n;
    return word;
}

int main() {
    char last_char = '\0';
    char *word = NULL;
    int num_of_digits = 0;
    word = get_word(&last_char, &num_of_digits);
    while (last_char != '\n') {
        if (num_of_digits == 3) {
            puts(word);
        }
        free(word);
        word = get_word(&last_char, &num_of_digits);
    }
    if(num_of_digits == 3) {
        puts(word);
    }
    free(word);
    return 0;
}
