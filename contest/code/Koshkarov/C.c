#include <stdio.h>

int formula()
{
	char symbol = getchar();
	if (symbol >= '0' && symbol <= '9')
	{
		return (int)(symbol - '0');
	}
	int sum = 0;
	if (symbol == '(')
	{
		sum = formula();
	}
	symbol = getchar();
	if (symbol == '+')
	{
		sum += formula();
	}
	else if (symbol == '-')
	{
		sum -= formula();
	}
	else if (symbol == '*')
	{
		sum *= formula();
	}
	symbol = getchar();
	if (symbol == ')')
	{
		return sum;
	}
	return sum;
}

int main()
{
	printf("%d\n", formula());
	return 0;
}