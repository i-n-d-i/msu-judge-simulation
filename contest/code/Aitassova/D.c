#include <stdio.h>
#include <stdlib.h>

int num;
int *answer;

void print_answer(void) {
	for (int i = 0; i < num; i++) {
		printf("%d ", *(answer + i));
	}
	putchar('\n');
}

void make_sum(int sum, int number, int* answer) {
	if (number == 1) {
		*answer = sum;
		print_answer();
		return;
	}
	for (int i = 1; i <= sum - number + 1; i++) {
		*answer = i;
		make_sum(sum - i, number - 1, answer + 1);
	}
}

int main(void) {
	int n;
	scanf("%d %d", &n, &num);
	answer = (int*)malloc(num * sizeof(int));
	make_sum(n, num, answer);
	free(answer);
	return 0;
}
