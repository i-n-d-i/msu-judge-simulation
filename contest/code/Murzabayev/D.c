#include <stdio.h>
#include <stdlib.h>

void print_array(int *answer, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", answer[i]);
    }
    putchar('\n');
}

void make_sum(int n, int k, int *answer, int i) {
    if (k == 1) {
        answer[i] = n;
        print_array(answer, i + 1);
    } else {
        for (int j = 1; j <= n - k + 1; j++) {
            answer[i] = j;
            make_sum(n - j, k - 1, answer, i + 1);
        }
    }
}

int main(void) {
    int n, k, *answer;
    scanf("%d %d", &n, &k);
    answer = malloc(k * sizeof(int));
    make_sum(n, k, answer, 0);
    free(answer);
    return 0;
}
