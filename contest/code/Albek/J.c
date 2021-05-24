#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, n, k = 0;
	int * mass = NULL;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			mass = realloc(mass, (k + 1) * sizeof(int));
			mass[k] = i;
			k++;
		}
	}
	for (i = 0; i < k; i++) {
		printf("%d ", mass[i]);
	}
	return 0;
}
