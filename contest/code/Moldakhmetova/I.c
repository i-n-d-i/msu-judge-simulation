#include <stdio.h>
#include <stdlib.h>

char *get_word(char *last_char_ptr) {
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
    for (int i = 0; i < (n / 2); i++) {
      char swap = word[i];
      word[i] = word[n - i - 1];
      word[n - i - 1] = swap;
    }
    *last_char_ptr = ch;
    return word;
}

int main() {
    char last_char = '\0';
    char *word = NULL;
    word = get_word(&last_char);
    while (last_char != '\n') {
        puts(word);
        free(word);
        word = get_word(&last_char);
    }
    puts(word);
    free(word);
    return 0;
}

