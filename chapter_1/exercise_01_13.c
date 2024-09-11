#include <stdio.h>

#define MAX_LENGTH	100000

void printsymbols(char symbol, int amount);
void printhistogram(int values[], int lenght, int limit);
void printresult(int letters[], int limit);
void readfromfile(char filename[], char result[], int limit);
void countletters(int letters[], char text[], int limit);

int main()
{
	char filename[] = "example.txt";
	char text[MAX_LENGTH];
	int letters[100];

	readfromfile(filename, text, MAX_LENGTH);
	countletters(letters, text, MAX_LENGTH);
	printresult(letters, 100);
	printsymbols('-', 35);
	printf("\n");
	printhistogram(letters, 35, 100);

	return 0;
}

void printhistogram(int values[], int lenght, int limit)
{
	int maxvalue = 0;
	
	for (int i = 0; i < limit; i++)
	{
		if (values[i] > maxvalue)
		{
			maxvalue = values[i];
		}
	}

	if (maxvalue == 0) return;

	for (int i = 0; i < limit; i++)
    {
        if (values[i] == 0) continue;
        printf("%3d letters: ", i);
		printsymbols('*', ((values[i] * lenght) / maxvalue));
		printf("\n");
    }	
}

void printsymbols(char symbol, int amount)
{
	for (int i = 0; i < amount; i++)
    {
		printf("%c", symbol);
	}
}

void printresult(int letters[], int limit)
{
	for (int i = 0; i <= limit; i++)
	{
		if (letters[i] == 0) continue;
		printf("%3d letters: %3d times\n", i, letters[i]);
	}
}

void countletters(int letters[], char text[], int limit)
{
	int i = 0;
	int lettersincurrentword = 0;

	while (limit - i > 0 && text[i] != '\0')
	{
		if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n' || text[i] == '-')
		{
			if (lettersincurrentword > 0)
			{
				letters[lettersincurrentword]++;
				lettersincurrentword = 0;
			}
		}
		else
		{
			lettersincurrentword++;
		}
		i++;
	}
}

void readfromfile(char filename[], char result[], int limit)
{
	FILE *file = fopen(filename, "r");
	
	if (file == NULL) 
	{
		perror("Error opening file");
		return;
	}
    
	int character;
	int i = 0;
	
	while (limit - i > 0 && (character = fgetc(file)) != EOF) 
	{
		result[i] = character;
		i++;
	}
	result[i] = '\0';
    fclose(file);
}
