#include <stdio.h>
#include <string.h>

int main() {
    int max, answer = 0, len1, len2;
    char s1[100], s2[100];
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    len1 = strlen(s1) - 1;
    len2 = strlen(s2) - 1;
    if (len1 > len2) {
        max = len1;
    } else {
        max = len2;
    }
    for (int i = 0; i < max; i++) {
        if (s1[i] < s2[i] && (s2[i] - s1[i]) != 'a' - 'A'  || s1[i] == ' ') {
            answer = 1;
            break;
        }
        if (s1[i] > s2[i] && (s1[i] - s2[i]) != 'a' - 'A' || s2[i] == ' ') {
            answer = -1;
            break;
        }
    }
    printf("%d\n", answer);
    return 0;
}
