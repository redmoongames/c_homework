#include <stdio.h>

#define FALSE		0
#define TRUE		1
#define ARRAYLIMIT 	1000
#define MAXLINESIZE	80

void printinfoaboutstring(char string[]);
void printfull(char input[]);
void removeblanks(char input[], char output[]);
int getlinesize(char output[]);
int getline2(char output[], int limit);

int main()
{
	char output[ARRAYLIMIT];
	int linesize = getline2(output, ARRAYLIMIT);
	
	while (linesize > 0)
	{
		printinfoaboutstring(output);
		linesize = getline2(output, ARRAYLIMIT);
	}
	
	printf("\n");	
}

void printinfoaboutstring(char string[])
{
	int stringsize = getlinesize(string);
	
	printf("\n##########################\n");
	printf("ORIG[%d]:", stringsize);
	printfull(string);
	printf("\n--------------------------\n");
	char prettystring[stringsize+2];
	removeblanks(string, prettystring);
	printf("PRTY[%d]:", getlinesize(prettystring));
	printfull(prettystring);
	printf("\n##########################\n");
}

void printfull(char input[])
{
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\n') 
		{
			printf("\\n");
		}
		else if (input[i] == '\t') 
        {
            printf("\\t");
        }
        else if (input[i] == ' ')
        {
            printf("_");
        }
		else
		{
			printf("%c", input[i]);
		}
		i++;
	}
	printf("\\0");
}

void removeblanks(char input[], char output[])
{
	int spacebarbefore = TRUE;
	int i = 0;
	int j = 0;
	int inputlenght = getlinesize(input);
    
	while (i < inputlenght)
    {
		if (input[i] == '\0')
		{
			output[j] = '\0';
			return;
		}

		if ((input[i] == '\t') || (input[i] == ' ' && spacebarbefore == TRUE))
		{
			i++;
			continue;
		}
		else
		{
			if (input[i] == ' ')
			{
				spacebarbefore = TRUE;
			}
			else
			{
				spacebarbefore = FALSE;
			}
			output[j] = input[i];
			j++;
		}
		
        i++;
    }
	
	output[j+1] = '\0';
}

int getlinesize(char output[])
{
	int i = 0;
	while (output[i] != '\0')
    {
        i++;
    }
	return i + 1;
}

int getline2(char output[], int limit)
{
	int i = 0;
	int character;
	int lastsymbols = 1;
	
	while (i < limit && (character = getchar()) != EOF)
	{ 
		output[i] = character;

		if (i + 1 >= limit - lastsymbols || character == '\n')
		{
			output[i] = '\0';
            break;
		}

		i++;
	}
	return i;
}
