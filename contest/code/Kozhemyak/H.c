#include <stdio.h>
#include <stdlib.h>

int main(){
	int p = 0, m = 0;
	char ch = getchar(), *ptr = NULL;
	while (ch != '\n'){
		p = 0;
		m = 0;
		while (ch != ' ' && ch != '\n'){
			p++;
			ptr = realloc(ptr, sizeof(char) * (m + 1));
			ptr[m] = ch;
			m++;
			ch = getchar();
		}
		if (p == 3){
			for (int i = 0; i < 3; i++){
				putchar(ptr[i]);
			}
			putchar(' ');
		}
		if (ch != '\n'){
			ch = getchar();
		}
	}
	free(ptr);
	return 0;
}
