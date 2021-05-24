#include <stdio.h>
#include <string.h>

int main(void) {
    char str_1[100], str_2[100];
    int Matrix[100][100];
    int len_1, len_2, prev, max, i, j;
    fgets(str_1, 100, stdin);
    fgets(str_2, 100, stdin);
    len_1 = strlen(str_1);
    len_2 = strlen(str_2);
    for (i = 0; i < len_1; i++) {
        for (j = 0; j < len_2; j++) {
            if (str_1[i] == str_2[j]) {
                prev = 0;
                if (i > 0 && j > 0) {
                    prev = Matrix[i - 1][j - 1];
                }
                Matrix[i][j] = prev + 1;
            }
        }
    }
    max = Matrix[0][0];
    for (i = 0; i < len_1; i++){
        for (j = 0; j < len_2; j++) {
            if (max < Matrix[i][j]) {
                max = Matrix[i][j];
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
