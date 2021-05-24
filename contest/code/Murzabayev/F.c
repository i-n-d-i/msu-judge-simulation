#include <stdio.h>
#include <stdlib.h>

int gcd(int first, int second) {
    if (second == 0) {
        return first;
    }
    return gcd(second, first % second);
}

void sum(int a_num, int a_den, int b_num, int b_den) {
    int sum_num, sum_den, g;
    sum_num = a_num * b_den + a_den * b_num;
    sum_den = a_den * b_den;
    g = gcd(sum_den, sum_num);
    sum_num /= g;
    sum_den /= g;
    if (sum_den == 1) {
        printf("%d ", sum_num);
    } else {
        printf("%d/%d ", sum_num, sum_den);
    }
}

void times(int a_num, int a_den, int b_num, int b_den) {
    int sum_num, sum_den, g;
    sum_num = a_num * b_num;
    sum_den = a_den * b_den;
    g = gcd(sum_num, sum_den);
    sum_num /= g;
    sum_den /= g;
    if (sum_den == 1) {
        printf("%d ", sum_num);
    } else {
        printf("%d/%d ", sum_num, sum_den);
    }
}

int main(void) {
    int a_num = 0, a_den = 0, b_num = 0, b_den = 0;
    char c = 0;
    c = getchar();
    while (c != '/') {
        a_num *= 10;
        a_num += (int) (c - '0');
        c = getchar();
    }
    c = getchar();
    while (c != '\n' && c != ' ') {
        a_den *= 10;
        a_den += (int) (c - '0');
        c = getchar();
    }
    c = getchar();
    while (c != '/') {
        b_num *= 10;
        b_num += (int) (c - '0');
        c = getchar();
    }
    c = getchar();
    while (c != '\n' && c != ' ') {
        b_den *= 10;
        b_den += (int) (c - '0');
        c = getchar();
    }
    sum(a_num, a_den, b_num, b_den);
    times(a_num, a_den, b_num, b_den);
    printf("\n");
    return 0;
}
