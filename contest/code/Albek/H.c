#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
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
		if (n == 3) {
			word = realloc(word, (n + 1) * sizeof(char));
			word[n] = '\0';
			printf("%s ", word);
		}
		free(word);
	} while (ch != final);
	return 0;
}
