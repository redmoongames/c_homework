#include <stdio.h>

main()
{
	int c = getchar();
	printf("\n");

	while (c != EOF)
	{
		printf("'%c'(%d) != EOF\n", c, c);
		c = getchar();
	}
	printf("'%c'(%d) == EOF\n", c, c);
}
