#include <stdio.h>
#include <stdlib.h>

char * read_sentence(void)
{
	char letter = getchar(), *word = NULL, *sentence = NULL;
	int size_sen = 0, size_word = 0;
	while (letter != '\n')
	{
		while (letter != '\n' && letter != ' ')
		{
			word = realloc(word, size_word + 1);
			if (!word)
			{
				printf("Error with memory");
				return NULL;
			}
			word[size_word] = letter;
			size_word++;
			letter = getchar();
		}
		sentence = realloc(sentence, size_sen + size_word + 1);
		if (!sentence)
		{
			printf("Error with memory");
			return NULL;
		}
		while(size_word != 0)
		{
			sentence[size_sen] = word[size_word - 1];
			size_sen++;
			size_word--;
		}
		if (letter == ' ')
		{
			sentence[size_sen] = letter;
			size_sen++;
		}
		else
		{
			break;
		}
		letter = getchar();
	}
	sentence[size_sen + 1] = '\0';
	return sentence;
}

int main()
{
	char * sent = read_sentence();
	for (int i = 0; sent[i] != '\0'; i++)
	{
		putchar(sent[i]);
	}
	putchar('\n');
	free(sent);
	return 0;
}