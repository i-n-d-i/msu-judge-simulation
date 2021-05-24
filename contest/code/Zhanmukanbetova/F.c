#include <stdio.h>
#include <stdlib.h>

int gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return gcd(num2, num1 % num2);
}
int main(void){
    int num1, denom1, num2, denom2, divider = 1;
    int mult_num, sum_denom, sum_num, mult_denom;
    scanf("%d/%d %d/%d", &num1, &denom1, &num2, &denom2);
    mult_num = num1 * num2;
    mult_denom = denom1 * denom2;
    sum_num = denom2 * num1 + denom1 * num2;
    sum_denom = denom1 * denom2;
    divider = gcd(sum_num, sum_denom);
    printf("%d/%d ", (int)sum_num / divider, (int)sum_denom / divider);
    divider = gcd(mult_num, mult_denom);
    printf("%d/%d\n", (int)mult_num / divider, (int)mult_denom / divider);
    return 0;
}
