#include <stdio.h>
#include <string.h>

#define FALSE	0
#define TRUE	1

void printfull(char original[]);
void printparagraph(char original[], int originalsize, int columns);
int cut(char original[], char output[], int outputsize);
int getfirstspaceindex(char original[], int maxsize);
void trim(char original[], char output[]);
void substring(char original[], char output[], int startindex, int endindex);
int getspaceinstart(char original[]);
int getspaceinend(char original[]);
int getsize(char original[]);
void cleararray(char array[], int size);
int readinputline(char output[], int limit);

int arraylimit = 1000;

int main()
{
	extern int arraylimit;
	char output[arraylimit];

	while (readinputline(output, arraylimit) > 0)
	{
		printf("[ORIG]: ");
	    printfull(output);
    	printf("\n");
		
    	printparagraph(output, arraylimit, 25);
	}
}

void printparagraph(char original[], int originalsize, int columns)
{
	char printablebuffer[originalsize];

	do
	{
		printfull(printablebuffer);
		printf("\n");
		cleararray(printablebuffer, originalsize);
	}
	while (cut(original, printablebuffer, columns) > 0);

}

// cut from original last string with size of outputsize.
// return remaining size of original after cut.
int cut(char original[], char output[], int outputsize)
{
	// TRIM ORIGINAL
	int originalsize = getsize(original);
	char originaltrimed[originalsize];
	cleararray(originaltrimed, originalsize);	
	trim(original, originaltrimed);

	// FIND POINT TO END OUTPUT LINE
	int firstspaceindex = getfirstspaceindex(originaltrimed, outputsize);


	// POPULATE OUTPUT
	int j = 0;
	for (int i = 0; i < firstspaceindex; i++)
	{
		output[j] = originaltrimed[i];
		j++;
	}

	if (getsize(originaltrimed) < outputsize) 
	{
		cleararray(original, originalsize);
		return 0;
	}

	// REWRITE ORIGINAL
	j = 0;
	for (int i = firstspaceindex + 1; i < getsize(originaltrimed); i++)
	{
		original[j] = originaltrimed[i];
		j++;
	}
	original[j] = '\0';

	return getsize(original);
}

int getfirstspaceindex(char original[], int maxsize)
{
	int letterencountered = FALSE;
	
	for (int i = maxsize; letterencountered == FALSE; i--)
	{
		if (original[i] == ' ')
		{
			return i;
		}
	}

	return -1;
}

void trim(char original[], char output[])
{
	int startindex = getspaceinstart(original);
	int endindex = (getsize(original) - getspaceinend(original)) - 1;
	substring(original, output, startindex, endindex);	
}

void substring(char original[], char output[], int startindex, int endindex)
{
	int j = 0;

	for (int i = startindex; i < endindex + 1; i++)
	{
		output[j] = original[i];
		j++;
	}
	output[j] = '\0';
}

int getspaceinstart(char original[])
{   
    int spaces = 0;
    int letterencountered = FALSE;
    
    for (int i = 0; letterencountered == FALSE; i++)
    {   
        if (original[i] == ' ' || original[i] == '\t')
        {   
            spaces++;
        }
        else
        {   
            break;
        }
    }
    
    return spaces;
}

int getspaceinend(char original[])
{
	int spaces = 0;
	int letterencountered = FALSE;

	for (int i = getsize(original) - 1; letterencountered == FALSE; i--)
	{
		if (original[i] == ' ' || original[i] == '\t')
		{
			spaces++;
		}
		else
		{
			break;
		}
	}

	return spaces;
}

int getsize(char original[])
{
	int i = 0;
	while (original[i] != '\0')
	{
		i++;
	}
	return i;
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

	while (i + 1 < limit && character != EOF && character != '\n' && character != '\033')
	{
		output[i] = character;
		i++;
		character = getchar();
	}

	output[i] = '\0';
	return i;
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
