#include <stdio.h>
#include <string.h>

int max_substr(char *word1, char *word2, int pos1, int pos2) {
    int d[pos1][pos2];
    int ans = 0;
    for (int i = 1; i <= pos1; i++) {
        for (int j = 1; j <= pos2; j++) {
            if (word1[i] == word2[j]) {
                if (i == 1 || j == 1) {
                    d[i][j] = 1;
                }
                else {
                    d[i][j] = d[i - 1][j - 1] + 1;
                }
                if (d[i][j] > ans) {
                    ans = d[i][j];
                }
            }
            else {
                d[i][j] = 0;
            }
        }
    }
    return ans;
}
int main(void) {
    int pos1 = 1, pos2 = 1;
    char word1[100], word2[100];
    char ch;
    do {
        ch = getchar();
        word1[pos1] = ch;
        pos1++;
    } while (ch != '\n');
    do {
        ch = getchar();
        word2[pos2] = ch;
        pos2++;
    } while (ch != '\n');
    printf("%d\n", max_substr(word1, word2, pos1, pos2));
    return 0;
}
