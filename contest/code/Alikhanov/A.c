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
    char str_a[100], str_b[100];
    fgets(str_a, 100, stdin);
    fgets(str_b, 100, stdin);
    char *str_b_low = lower(str_b);
    char *str_a_low = lower(str_a);
    ans = strcmp(str_b_low, str_a_low);
    if (ans > 0) {
        ans = 1;
    } else if (ans < 0) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}
