#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int input_n, *output_arr = NULL, i = 1, num = 0;
    scanf("%d", &input_n);
    while (i <= input_n) {
        if (input_n % i == 0) {
            // input_n /= i;
            num++;
            output_arr = (int*)realloc(output_arr, sizeof(int) * num);
            output_arr[num - 1] = i;
        }
        i++;
    }
    for (int j = 0; j < num; j++) {
        printf("%d ", output_arr[j]);
    }
    printf("\n");
    free(output_arr);
    return 0;
}
