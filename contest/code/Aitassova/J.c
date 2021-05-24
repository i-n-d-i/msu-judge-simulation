#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int input, i, count;
	int *dividers = NULL;
	scanf("%d", &input);
	for (i = 1, count = 0; i <= input; i++) {
		if(!(input % i)) {
			dividers = (int*)realloc(dividers, (count + 1) * sizeof(int));
			dividers[count] = i;
			count++;
		}
	}
	for (i = 0; i < count; i++) {
		printf("%d ", dividers[i]);
	}
	free(dividers);
	putchar('\n');
	return 0;
}
