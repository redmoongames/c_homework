#include <stdio.h>

#define IN_STATE 1
#define OUT_STATE 0

void getinput(char value[], int limit);
void printwords(char content[], int limit);

int main()
{
	char input[1000];
	getinput(input, 1000);
	printwords(input, 1000);
	return 0;
}

void printwords(char content[], int limit)
{
	int i = 0;
	int state = OUT_STATE;
	
	while (limit - i >= 0 && content[i] != '\0')
    {
		if (content[i] != ' ' && content[i] != '\n' && content[i] != '\t')
		{
			printf("%c", content[i]);
            state = IN_STATE;
			i++;
			continue;
		}
	
		if (state == IN_STATE)
		{
			printf("\n");
		}

		state = OUT_STATE;
		i++;
    }
	printf("\n");
}

void getinput(char value[], int limit)
{
	int c = 0;
	int i = 0;
	printf("\nEnter input. Enter '~' + Enter to finish\n");
	while (limit - i >= 0 && (c = getchar()) != EOF && c != '~')
	{
		value[i] = c;
		i++;
	}
	value[i] = '\0';
}
