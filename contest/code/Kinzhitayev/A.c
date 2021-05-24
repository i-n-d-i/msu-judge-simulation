#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str_1[100], str_2[100];
    int answer = 0, len;
    fgets(str_1, 100, stdin);
    fgets(str_2, 100, stdin);
    len = strlen(str_1);
    for (int i = 0; i < len; i++) {
        str_1[i] = toupper(str_1[i]);
    }
    len = strlen(str_2);
    for (int i = 0; i < len; i++) {
        str_2[i] = toupper(str_2[i]);
    }
    answer = strcmp(str_2, str_1);
    if (answer == 0) {
        printf("%d\n", answer);
    } else  if (answer > 0) {
        printf("1\n");
    } else {
        printf("-1\n");
    }
    return 0;
}
