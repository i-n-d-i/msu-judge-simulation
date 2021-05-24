#include <stdio.h>
#include <stdlib.h>

int var;
int *ans;

void print_ans(void) {
    for (int i = 0; i < var; i++) {
        printf("%d ", *(ans + i));
    }
    putchar('\n');
}

void make_sum(int sum, int num, int* ans) {
    if (num == 1) {
        *ans = sum;
        print_ans();
        return;
    }
    for (int i = 1; i <= sum - num + 1; i++) {
        *ans = i;
        make_sum(sum - i, num - 1, ans + 1);
    }
}

int main(void) {
    int in_num;
    scanf("%d %d", &in_num, &var);
    ans = (int*)malloc(var * sizeof(int));
    make_sum(in_num, var, ans);
    free(ans);
    return 0;
}
