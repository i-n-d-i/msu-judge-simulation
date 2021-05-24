#include <stdio.h>

void makesum(int n, int k, int ans[], int t) {
	int i;
	if (k == 0) {
		return;
       	}
	if (k == 1) {
		ans[k] = n;
		for (i = 1; i <= t; i++) {
			printf("%d ", ans[i]);
		}
		puts("");
	}
	for (i = 1; i <= k; i++) {
		ans[k] = i;
		makesum (n - i, k - 1, ans, t);
	}
}

int main() {
	int input_n, input_k, ans[102];
	scanf("%d %d", &input_n, &input_k);
	makesum(input_n, input_k, ans, input_k);
	return 0;
}
