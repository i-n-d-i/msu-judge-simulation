#include <stdio.h>
#include <stdlib.h>

void makesum(int sum, int number, int *answer, int i) {
    if (number == 1) {
        answer[i] = sum;
        for (int j = 0; j < i + 1; j++) {
            printf("%d ", answer[j]);
        }
        puts("");
    } else {
        for (int j = 1; j <= sum - number + 1; j++) {
            answer[i] = j;
            makesum(sum - j, number - 1, answer, i + 1);
        }
    }
}

int main(void) {
    int input_n, input_k, *output;
    scanf("%d %d", &input_n, &input_k);
    output = malloc(input_k * sizeof(int));
    makesum(input_n, input_k, output, 0);
    return 0;
}
