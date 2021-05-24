#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *lower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
        i++;
    }
    return str;
}

int main(void) {
    int ans;
    char str1[100], str2[100];
    fgets(str1, 100, stdin);
    fgets(str2, 100, stdin);
    char *str2_low = lower(str2);
    char *str1_low = lower(str1);
    ans = strcmp(str2_low, str1_low);
    if (ans > 0) {
        ans = 1;
    }
    else {
        if (ans < 0) {
        	ans = -1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
