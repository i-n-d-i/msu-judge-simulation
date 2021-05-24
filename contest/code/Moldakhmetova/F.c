#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void sum(int num1, int den1, int num2, int den2) {
    int sum_of_num, sum_of_den, sum_div;
    if (den1 != den2) {
        sum_of_den = den1 * den2;
        sum_of_num = num1 * den2 + num2 * den1;
    }
    else {
        sum_of_den = den1;
        sum_of_num = num1 + num2;
    }
    sum_div = gcd(sum_of_den, sum_of_num);
    sum_of_den /= sum_div;
    sum_of_num /= sum_div;
    printf("%d/%d ", sum_of_num, sum_of_den);
}

void mul(int num1, int den1, int num2, int den2) {
    int mul_of_num, mul_of_den, mul_div;
    mul_of_num = num1 * num2;
    mul_of_den = den1 * den2;
    mul_div = gcd(mul_of_num, mul_of_den);
    mul_of_num /= mul_div;
    mul_of_den /= mul_div;
    printf("%d/%d", mul_of_num, mul_of_den);
}

int main() {
    int num1, num2, den1, den2;
    scanf("%d/%d %d/%d", &num1, &den1, &num2, &den2);
    sum(num1, den1, num2, den2);
    mul(num1, den1, num2, den2);
    return 0;
}
