#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	char* a = malloc(sizeof(char));
	char ch;
	int j = 0;
	do 
	{
		if (ch == ' '){
			for (int i = 2; i <= j; i++){
				printf("%c", a[j-i]);
			}
			free(a);
			a = malloc(sizeof(char));
			j = 0;
			printf(" ");
		}
		ch = getchar();
		a = realloc(a, (j + 1) * sizeof(char));
		if (ch != ' ')
			a[j] = ch;
		j++;
	} while(ch != '\n');
	for (int i = 2; i <= j; i++){
			printf("%c", a[j-i]);
		}
	putchar('\n');
	free(a);
	return 0;
}
