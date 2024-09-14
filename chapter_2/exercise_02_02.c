#include <stdio.h>

int main() 
{
	char character = getchar();
	int limit = 8;
	int i = 0;

	while (1)
	{
		printf("%c", character);

		if (i >= limit) break;
		if (character == EOF) break;
		if (character == '\n') break;

		character = getchar();
		i++;
	}
	
	printf("\n");
}
