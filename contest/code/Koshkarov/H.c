#include <stdio.h>
#include <stdlib.h>

void read_sentence(void)
{
	char letter = getchar(), word[3];
	int size_word = 0;
	while (letter != '\n')
	{
		while (letter != '\n' && letter != ' ')
		{
			if (size_word < 3)
			{
				word[size_word] = letter;
			}
			size_word++;
			letter = getchar();
		}
		if (size_word == 3)
		{
			int i = 0;
			while (i != 3)
			{
				putchar(word[i]);
				i++;
			}
			if (letter == ' ')
			{
				putchar(' ');
			}
		}
		size_word = 0;
		if (letter == '\n')
		{
			putchar('\n');
			break;
		}
		letter = getchar();
	}
	return;
}

int main()
{
	read_sentence();
	return 0;
}