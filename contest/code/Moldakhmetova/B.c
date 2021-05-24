#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int len1, len2, answer[100][100] = {};
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    len1 = strlen(s1) - 1;
    len2 = strlen(s2) - 1;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (s1[i] == s2[j] && s1[i - 1] == s2[j - 1]) {
                answer[i][j] = answer[i - 1][j - 1] + 1;
            }
            else {
                if (s1[i] == s2[j]) {
                    if (i == 0 || j == 0 || s1[i - 1] != s2[i - 1]) {
                        answer[i][j]++;
                    }
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (answer[i][j] > max) {
                max = answer[i][j];
            }
        }
    }
    printf("%d\n", max);
    return 0;
}

