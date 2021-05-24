#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char word1[80], word2[80];
    scanf("%s", word1);
    scanf("%s", word2);
    int ans = strcasecmp(word1, word2);
    if (ans < 0) {
        printf("%d\n", 1);
    }
    else if (ans > 0) {
        printf("%d\n", -1);
    }
    else {
        printf("%d\n", ans);
    }
    return 0;
}
