#include <stdio.h>
#include <string.h>

int main(void) {
    char str_1[100], str_2[100];
    int matrix[100][100];
    int len1, len2, prev, max, i, j;
    fgets(str_1, 100, stdin);
    fgets(str_2, 100, stdin);
    len1 = strlen(str_1);
    len2 = strlen(str_2);
    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (str_1[i] == str_2[j]) {
                prev = 0;
                if (i > 0 && j > 0) {
                    prev = matrix[i - 1][j - 1];
                }
                matrix[i][j] = prev + 1;
            }
        }
    }
    max = matrix[0][0];
    for (i = 0; i < len1; i++){
        for (j = 0; j < len2; j++) {
            if (max < matrix[i][j]) {
                max = matrix[i][j];
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
