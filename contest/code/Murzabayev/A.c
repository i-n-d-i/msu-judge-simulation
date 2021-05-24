#include <stdio.h>

int main(void) {
    char a[100], b[100], diff = 'A' - 'a';
    int len_a = 0, len_b = 0, flag = 0;
    for (len_a = 0; len_a < 100; len_a++) {
        a[len_a] = getchar();
        if (a[len_a] >= 'A' && a[len_a] <= 'Z') {
            a[len_a] -= diff;
        }
        if (a[len_a] == '\n') {
            break;
        }
    }
    for (len_b = 0; len_b < 100; len_b++) {
        b[len_b] = getchar();
        if (b[len_b] >= 'A' && b[len_b] <= 'Z') {
            b[len_b] -= diff;
        }
        if (b[len_b] == '\n') {
            break;
        }
    }
    for (int i = 0; i < len_a && i < len_b; i++) {
        if (a[i] < b[i]) {
            flag = 1;
            break;
        } else if (a[i] != b[i]) {
            flag = -1;
            break;
        }
    }
    printf("%d\n", flag);
    return 0;
}
