#include <stdio.h>
#include <stdlib.h>

int main(){
	int m = 0;
	char ch, *ptr = NULL;
	ch = getchar();
	while (ch != '\n'){
		m = 0;
		while (ch != ' ' && ch != '\n'){
			ptr = realloc(ptr, sizeof(char) * (m + 1));
			ptr[m] = ch;
			m++;
			ch = getchar();
		}
		m--;
		for (int i = m; i >= 0; i--){
			putchar(ptr[i]);
		}
		putchar(' ');
		if (ch != '\n'){
			ch = getchar();
		}
	}
	free(ptr);
	return 0;
}
