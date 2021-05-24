#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int nok(int a, int b) {
	return a * b / gcd(a, b);
}

void sum(int a, int b, int c, int d) {
	int sum_a = a * d + c * b;
	int sum_b = b * d;
	int gcd_sum = gcd(sum_a, sum_b);
	printf("%d/%d ", sum_a / gcd_sum, sum_b / gcd_sum);
}

void mul(int a, int b, int c, int d) {
	int mul_a = a * c;
	int mul_b = b * d;
	int gcd_mul = gcd(mul_a, mul_b);
	printf("%d/%d ", mul_a / gcd_mul, mul_b / gcd_mul);
}

int main() {
	int a, b, c, d;
	scanf("%d/%d %d/%d", &a, &b, &c, &d);
	sum(a, b, c, d);
	mul(a, b, c, d);
	return 0;
}	
