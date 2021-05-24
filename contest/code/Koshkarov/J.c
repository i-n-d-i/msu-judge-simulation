#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, *div = NULL, size_of_div = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			div = realloc(div, (size_of_div + 1) * sizeof(int));
			if(div == NULL)
			{
				return - 1;
			}
			div[size_of_div] = i;
			size_of_div++;
		}
	}
	for (int i = 0; i < size_of_div; i++)
	{
		printf("%d ", div[i]);
	}
	putchar('\n');
	free(div);
	return 0;
}