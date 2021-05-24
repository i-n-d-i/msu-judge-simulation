#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char s1[100], s2[100];
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    for (int i = 0; i < s1len; i++)
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] = s1[i] - 'A' + 'a';
    for (int i = 0; i < s2len; i++)
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            s2[i] = s2[i] - 'A' + 'a';
    if (strcmp(s1, s2) > 0)
        printf("-1\n");
    if (strcmp(s1, s2) == 0)
        printf("0\n");
    if (strcmp(s1, s2) < 0)
        printf("1\n");
    return 0;
}
