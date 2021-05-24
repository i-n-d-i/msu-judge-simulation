#include <stdio.h>
#include <string.h>

int main() {
	char str1[101], str2[101];
	fgets(str1, 100, stdin);
	fgets(str2, 100, stdin);
	printf("%d", strcmp(str1, str2));
	return 0;
}
