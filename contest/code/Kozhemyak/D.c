#include <stdio.h>
#include <stdlib.h>

void print_array(int * ans, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", ans[i]);
	}
	putchar('\n');
}

void make_sum(int n, int k, int * ans, int i) {
	if (k == 1) {
		ans[i] = n;
		print_array(ans, i + 1);
	} else {
		for (int j = 1; j <= n - k + 1; j++) {
			ans[i] = j;
			make_sum(n - j, k - 1, ans, i + 1);
		}
	}
}

int main(void) {
	int n, k, *ans;
	scanf("%d %d", &n, &k);
	ans = malloc(k * sizeof(int));
	make_sum(n, k, ans, 0);
	free(ans);
	return 0;
}
