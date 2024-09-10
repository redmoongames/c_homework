#include <stdio.h>

void processinput(char input[], int limit);
void replace(char input[], char output[], int limit);

int main()
{
	char input[1000];
	char output[1000];

	processinput(input, 100);
	replace(input, output, 100);
	printf("%s", output);

	return 0;
}

void replace(char input[], char output[], int limit)
{
	int i = 0;
	int j = 0;

    while (i <= limit - 1 && input[i] != '\0')
    {
		if (input[i] == ' ')
		{
        	output[j] = '_';
		} 
		else if (input[i] == '\t')
		{
			output[j] = '\\';
			j++;
			output[j] = 't';
		}
		else if (input[i] == '\n')
        {
            output[j] = '\\';
            j++;
            output[j] = 'n';
        }
		else
		{
		 output[j] = input[i];
		}
        i++;
		j++;
    }
}

void processinput(char input[], int limit)
{
	printf("Enter input. To finish, enter '~'");
	int c = getchar();
	int i = 0;
	
	while (i <= limit - 1 && c != EOF && c != '~')
	{
		input[i] = c;
		c = getchar();
		i++;
	}

	input[i] = '\0';
}
