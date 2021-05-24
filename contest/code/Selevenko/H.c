#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char a[4];
	char ch;
	while(ch !='\n'){
		for (int i = 0; i < 4; i++){
			ch = getchar();
			a[i] = ch;
		}
		if (ch != ' '){
			while(ch != ' ' && ch != '\n')
				ch = getchar();
		}
		else{
			for(int i = 0; i < 4; i++){
				printf("%c", a[i]);
			}
		}
	}
	for(int i = 0; i < 4; i++){
		printf("%c", a[i]);
	}
	return 0;
}