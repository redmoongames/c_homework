#include <stdio.h>

#define MAXSIZE 1000
#define MAXLINESIZE 20

int getlinesize(char output[]);
int getline2(char output[], int limit);

int main()
{
	char output[MAXSIZE];
	int linesize = getline2(output, MAXLINESIZE);
	while (linesize > 0)
	{
		printf("[%d]: %s", linesize, output);
		linesize = getline2(output, MAXLINESIZE);
	}
	printf("\n");	
}

int getlinesize(char output[])
{
	int i = 0;
	while (output[i] != '\0' && output[i] != '\n')
    {
        i++;
    }
	return i;
}

int getline2(char output[], int limit)
{
	int i = 0;
	int character;
	int lastsymbols = 2;
	
	while (i < limit && (character = getchar()) != EOF)
	{ 
		output[i] = character;
		i++;

		if (i + 1 >= limit - lastsymbols || character == '\n')
		{
			output[i] = '\n';
			output[i + 1] = '\0';
            break;
		}
	}
	return i;
}
