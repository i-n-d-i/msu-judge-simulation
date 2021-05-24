#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, i;
	char ch, final = '\n', delimeter = ' ';
	char * word = NULL;
	do {
		ch = getchar();
		n = 0;
		word = NULL;
		while (ch != delimeter && ch != final) {
			word = realloc(word, (n + 1) * sizeof(char));
			word[n] = ch;
			n++;
			ch = getchar();
		}
		if (n > 0) {
			word = realloc(word, (n + 1) * sizeof(char));
			word[n] = '\0';
			for (i = (n - 1); i >= 0; i--) {
				printf("%c", word[i]);
			}
			printf(" ");
		}
		free(word);
	} while (ch != final);
	return 0;
}
