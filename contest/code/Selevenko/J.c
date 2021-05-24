#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n;
	scanf("%d", &n);
	int* a = (int*)calloc(0, sizeof(int));
	int j = 0;
	for(int i = 1; i <= n; i++){
		if(n % i == 0){
			a = (int*)realloc(a, i * sizeof(int));
			a[j] = i;
			j++;
		}
	}
	for(int i = 0; i < j; i++){
		printf("%d\n", a[i]);
	}
	free(a);
	return 0;
}