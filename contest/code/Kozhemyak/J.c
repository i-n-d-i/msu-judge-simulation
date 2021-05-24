#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m = 0, *ptr = NULL;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		if (n % i == 0){
			ptr = realloc(ptr, (m + 1) * sizeof(int));
			ptr[m] = i;
			m++;
		}
	}
	for (int i = 0; i < m; i++){
		printf("%d ", ptr[i]);
	}
	free(ptr);
	return 0;
}
