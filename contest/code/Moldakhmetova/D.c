#include <stdio.h>
#include <stdlib.h>

void print(int *answer, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", answer[i]);
    }
    putchar('\n');
}

void make_sum(int n, int k, int *answer, int i) {
    if (k == 1) {
        answer[i] = n;
        print(answer, i + 1);
        return;
    } 
    for (int j = 1; j <= n - k + 1; j++) {
        answer[i] = j;
        make_sum(n - j, k - 1, answer, i + 1);
    }
}

int main(void) {
    int n, k, *answer;
    scanf("%d %d", &n, &k);
    answer = malloc(k * sizeof(int));
    make_sum(n, k, answer, 0);
    return 0;
}
