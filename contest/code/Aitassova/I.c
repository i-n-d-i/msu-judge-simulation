#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *wrd = NULL;
    char ch;
    int count = 0;
    do {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {
            for (int i = 0; i < count; i++) {
                putchar(wrd[count - i - 1]);
            }
            putchar(' ');
            free(wrd);
            wrd = NULL;
            count = 0;
        }
		else {
            wrd = (char*)realloc(wrd, (count + 1) * sizeof(char));
            wrd[count] = ch;
            count++;
        }
    }
	while(ch != '\n');
    free(wrd);
    putchar('\n');
    return 0;
}
