#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int input, i, count;
	int *arr = NULL;
	scanf("%d", &input);
	for (i = 1, count = 0; i <= input; i++) {
		if(!(input % i)) {
			arr = (int*)realloc(arr, (count + 1) * sizeof(int));
			arr[count] = i;
			count++;
		}
	}
	for (i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);
	putchar('\n');
	return 0;
}
