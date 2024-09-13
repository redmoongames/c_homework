#include <stdio.h>
#include <string.h>

void printfull(char original[]);
void printresult(char string[]);
void printwithspaces(char string[]);
void tabstospace(char original[], char output[]);
void cleararray(char array[], int size);
int readinputline(char output[], int limit);

int limit = 1000;

int main()
{
	extern int limit;
	char output[limit];

	while (readinputline(output, limit) > 0)
	{
		printresult(output);
	}
}

void printfull(char original[])
{
	for (int i = 0; original[i] != '\0'; i++)
    {
		if (original[i] == ' ')
		{
			printf("_");
		}
		else if (original[i] == '\t')
		{
            printf("\\t");
        }
        else if (original[i] == '\n')
		{
            printf("\\n");
        }
		else printf("%c", original[i]);
	}
}

void printresult(char original[])
{
	extern int limit;

	printf("[ORIG]: ");
	printfull(original);
	printf("\n");
	
    char notabs[limit];
	cleararray(notabs, limit);
    tabstospace(original, notabs);
    printf("[TB>S]: ");
	printfull(notabs);
	printf("\n");
}

void tabstospace(char original[], char output[])
{
	int j = 0;

	for (int i = 0; original[i] != '\0'; i++)
	{
		if (original[i] != '\t')
		{
			output[j] = original[i];
			j++;
			continue;
		}

		for (int ii = 0; ii < 4; ii++)
		{
			output[j] = ' ';
            j++;
		}
			
	}
}

void cleararray(char array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = '\0';
	}
}

int readinputline(char output[], int limit)
{
	int i = 0;
	char character = getchar();

	while (i + 1 < limit && character != EOF && character != '\n')
	{
		output[i] = character;
		i++;
		character = getchar();
	}

	output[i] = '\0';
	return i;
}
