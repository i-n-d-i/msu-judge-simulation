#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

void sum_frac(int numerator1, int denominator1, int numerator2, int denominator2)
{
	int numerator = numerator1 * denominator2 + numerator2 * denominator1, denominator = denominator1 * denominator2, div;
	printf("%d %d\n", numerator, denominator);
	if (numerator > denominator)
	{
		div = gcd(numerator, denominator);
	}
	else
	{
		div = gcd(denominator, numerator);
	}
	printf("%d/%d ", numerator / div, denominator / div);
	return;
}

void mul_frac(int numerator1, int denominator1, int numerator2, int denominator2)
{
	int numerator = numerator1 * numerator2, denominator = denominator1 * denominator2, div;
	if (numerator > denominator)
	{
		div = gcd(numerator, denominator);
	}
	else
	{
		div = gcd(denominator, numerator);
	}
	printf("%d/%d\n", numerator / div, denominator / div);
	return;
}
int main()
{
	int numerator1, denominator1, numerator2, denominator2, tempnum = 0;
	char c = getchar();
	while (c != ' ')
	{
		if (c == '/')
		{
			numerator1 = tempnum;
			tempnum = 0;
			c = getchar();
			continue;
		}
		tempnum = tempnum * 10 + (int)(c - '0');
		c = getchar();
	}
	denominator1 = tempnum;
	c = getchar();
	tempnum = 0;
	while (c != '\n')
	{
		if (c == '/')
		{
			numerator2 = tempnum;
			tempnum = 0;
			c = getchar();
			continue;
		}
		tempnum = tempnum * 10 + (int)(c - '0');
		c = getchar();
	}
	denominator2 = tempnum;
	sum_frac(numerator1, denominator1, numerator2, denominator2);
	mul_frac(numerator1, denominator1, numerator2, denominator2);
	return 0;
}