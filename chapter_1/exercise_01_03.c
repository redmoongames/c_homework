#include <stdio.h>

void printheader();
void printdash(int lenght, int symbol);
void printtemperature(int from, int to, int step);
float convertfahrenheittocelsius(int fahrenheit);

main()
{
	printheader();
	printtemperature(-100, 100, 25);
	printdash(20,'-');
    printtemperature(25, -25, 5);
    printdash(20,'-');
}

void printtemperature(int from, int to, int step)
{
	if (step == 0)
	{
		printf("ERROR: Step could not be zero");
	}
	
	if (step < 0)
	{
		step *= -1;
	}

	if (from > to)
	{
		from += to;
		to = from - to;
		from -= to;
	}

	for (int i = from; i <= to; i += step)
    {
        printf("%7d | %6.1f\n", i, convertfahrenheittocelsius(i));
	}
}

float convertfahrenheittocelsius(int fahrenheit)
{
	return (fahrenheit - 32)*(5.0/9.0);
}

void printheader()
{
	printf("\n");
    printdash(20, '-');
	printf("FAHRENHT | CELSIUS\n");
    printdash(20, '-');
}

void printdash(int lenght, int symbol)
{
	for (int i = 0; i < lenght; i++)
	{
		printf("%c", symbol);
	}
	printf("\n");
}
