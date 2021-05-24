#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char a[100], b[100];
    int len_a = 0, len_b = 0, matrix[100][100] = {0};
    a[0] = getchar();
    for (len_a = 1; len_a < 100 && a[len_a - 1] != '\n'; len_a++) {
        a[len_a] = getchar();
    }
    b[0] = getchar();
    for (len_b = 1; len_b < 100 && b[len_b - 1] != '\n'; len_b++) {
        b[len_b] = getchar();
    }
    for (int i = 1; i < len_a; i++) {
        for (int j = 1; j < len_b; j++) {
            if (a[i - 1] == b[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                if (matrix[i][j - 1] >= matrix[i - 1][j]) {
                    matrix[i][j] = matrix[i][j - 1];
                } else {
                    matrix[i][j] = matrix[i - 1][j];
                }
            }
        }
    }
    printf("%d\n", matrix[len_a - 1][len_b - 1]);
/*
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
*/
    return 0;
}
