#include <stdio.h>
#include <string.h>

int cmp_str(char * str1, char * str2)
{
	int const lowerlet = 'A' - 'a';
	int i = 0;
	while (i != 100 && str1[i] && str2[i])
	{
		char first = str1[i], second = str2[i];
		if (first >= 'A' && first <= 'Z')
		{
			first -= lowerlet;
		}
		if (second >= 'A' && second <= 'Z')
		{
			second -= lowerlet;
		}
		if ((!first && second) || first < second)
		{
			return 1;
		}
		else if ((first && !second) || first > second)
		{
			return - 1;
		}
		i++;
	}
	return 0;
}

int main()
{
	char str1[102], str2[102];
	fgets(str1, 102, stdin);
	fgets(str2, 102, stdin);
	printf("%d\n", cmp_str(str1, str2));
	return 0;
}