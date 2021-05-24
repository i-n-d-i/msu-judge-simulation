#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char s1[100], s2[100];
	int a;
	fgets(s1, 100, stdin);
	fgets(s2, 100, stdin);
	for (int i = 0; i < 100; i++){
		a = s1[i];
		s1[i] = tolower(a);
		a = s2[i];
		s2[i] = tolower(a);
	}
	if (strcmp(s1, s2) < 0) {
		printf("%d", 1);
	}
	else if (strcmp(s1, s2) == 0) {
		printf("%d", 0);
	}
	else {
		printf("%d", -1);
	}
	return 0;
}
