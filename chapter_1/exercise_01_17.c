#include <stdio.h>

#define ARRAYLIMIT 1000
#define MAXLINESIZE 20

int getlinesize(char output[]);
int getline2(char output[], int limit);

int main()
{
	char output[ARRAYLIMIT];
	int linesize = getline2(output, ARRAYLIMIT);
	while (linesize > 0)
	{
    	if (getlinesize(output) >= MAXLINESIZE)
    	{
			printf("[%d]: %s", linesize, output);
	    }
		
		linesize = getline2(output, ARRAYLIMIT);
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
