#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char str_1[100], str_2[100];
    int answer = 0, len1, len2, D[100][100];
    fgets(str_1, 100, stdin);
    fgets(str_2, 100, stdin);
    len1 = strlen(str_1) - 1;
    len2 = strlen(str_2) - 1;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str_1[i] == str_2[j]) {
                D[i + 1][j + 1] = D[i][j] + 1;
            } else {
                D[i + 1][j + 1] = 0;
            }
        }
    }
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            if (answer < D[i][j]) {
                answer = D[i][j];
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
