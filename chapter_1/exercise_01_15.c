#include <stdio.h>

void convertdatatocelsius(double data[], double outbut[], int limit);
void convertdatatofahrenheit(double data[], double outbut[], int limit);
int populatedata(double data[], double from, double to, int step);
void printheader(char leftstring[], char rightstring[]);
void printtable(double left[], double right[], int limit);
double conversioncelsiustofahrenheit(double celsius);
double conversionfahrenheittocelsius(double fahrenheit);

int main()
{
	double data[100];
	int datasize = populatedata(data, -25.0, 100.0, 10);

	double datatofahrenheit[datasize];
	convertdatatofahrenheit(data, datatofahrenheit, datasize);
	printheader("CELSIUS", "FAHRENT");
    printtable(data, datatofahrenheit, datasize);

	double datatocelsius[datasize];
	convertdatatocelsius(data, datatocelsius, datasize);
	printheader("FAHRENT", "CELSIUS");
	printtable(data, datatocelsius, datasize);
}

void convertdatatocelsius(double data[], double outbut[], int limit)
{
    for (int i = 0; i < limit; i++)
    {
        outbut[i] = conversionfahrenheittocelsius(data[i]);
    }
}

void convertdatatofahrenheit(double data[], double outbut[], int limit)
{
	for (int i = 0; i < limit; i++)
	{
		outbut[i] = conversioncelsiustofahrenheit(data[i]);
	}
}

int populatedata(double data[], double from, double to, int step)
{
	if (step == 0)
	{
		printf("ERROR: Step is out of range");
		return 0;
	}
	else if (step < 0)
	{
		step *= -1;
	}

	int dataamount = 0;

	if (from < to)
	{
		int i = 0;
		while (from <= to)
		{
			data[i] = from;
			from += step;
			i++;
		}
		data[i] = '\0';
		dataamount = i;
	}

	return dataamount;
}

void printheader(char leftstring[], char rightstring[])
{
	printf("|%s|%s|\n", leftstring, rightstring);
}

void printtable(double left[], double right[], int limit)
{
	for (int i = 0; i < limit; i++)
	{
		printf("|%6.1f | %6.1f|\n", left[i], right[i]);
	}
}

double conversioncelsiustofahrenheit(double celsius)
{
	return (celsius * 9.0 / 5.0) + 32.0;
}

double conversionfahrenheittocelsius(double fahrenheit)
{
	return (5.0 / 9.0) * (fahrenheit - 32);
}
