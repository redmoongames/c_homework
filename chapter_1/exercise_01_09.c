#include <stdio.h>

#define TRUE 1
#define FALSE 0

void normolizestring(char original[], char normolized[], int limit);
int countspaces(char string[], int limit);
int counttabs(char string[], int limit);
int countlines(char string[], int limit);

int main()
{
	char string[] = "hello world!\nthis\tis		tab\n";
	int spaces = 0;
	int lines = 0;
	int tabs = 0;
	char normolized[1000];
	
	normolizestring(string, normolized, 100);

	spaces = countspaces(string, 100);
	lines = countlines(string, 100);
	tabs = counttabs(string, 100);
	printf("OROGINAL:\t%s\n", string);
	printf("SPACES  :\t%d\n", spaces);
	printf("LINES   :\t%d\n", lines);
	printf("TABS    :\t%d\n", tabs);
	printf("NORMLZED:\t%s\n", normolized);
	
	return 0;
}

void normolizestring(char original[], char normolized[], int limit)
{
	int j = 0;
	int i = 0;
	int spacebefore = FALSE;

    while (limit - i > 0 && original[i] != '\0')
    {
        if (original[i] == ' ' || original[i] == '\t' || original[i] == '\n')
        {
			if (spacebefore == TRUE)
			{
				j--;
			}

            spacebefore = TRUE;
        }
		else
		{
			spacebefore = FALSE;
		}

		if (original[i] == '\t' || original[i] == '\n')
		{
			normolized[j] = ' ';
		}
		else 
		{
			normolized[j] = original[i];
		}
		i++;
		j++;
    }
}

int countlines(char string[], int limit)
{
    int count = 1;
    int i = 0;
    while (limit - i > 0 && string[i] != '\0')
    {
        i++;
        if (string[i] == '\n')
        {
            count++;
        }
    }
    return count;
}

int counttabs(char string[], int limit)
{
    int count = 0;
    int i = 0;
    while (limit - i > 0 && string[i] != '\0')
    {
        i++;
        if (string[i] == '\t')
        {
            count++;
        }
    }
    return count;
}

int countspaces(char string[], int limit)
{
	int count = 0;
	int i = 0;
	while (limit - i > 0 && string[i] != '\0')
	{
		i++;
		if (string[i] == ' ')
		{
			count++;
		}
	}
	return count;
}
