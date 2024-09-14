#include <stdio.h>
#include <string.h>

void test2(char value[]);
void test(char value[]);
int string_to_int(char hex[], int number_system);
int hex_to_int(char hex);
char to_lower(char character);
int pow2(int base, int power);

int main() 
{
    test("0");
    test("A");
    test("f");
    test("10");
    test("FF");
	test("159DF");
    test("FD951");
}

void test(char value[])
{
    printf("| %5s | %5d |\n", value, string_to_int(value, 16));
}

int string_to_int(char hex[], int number_system)
{
	int lenght = strlen(hex);
    int return_value = 0;
    int i = 0;
    int tmp = 0;

    while (lenght - i > 0)
    {
        tmp = hex_to_int(hex[lenght - (i + 1)]);

        if (tmp == -1)
        {
            printf("\nERROR: %c is incorrect value\n", hex[i]);
            return -1;
        }

        return_value += tmp * pow2(number_system, i);
        i++;
    }

    return return_value;
}

int hex_to_int(char hex)
{
	if (to_lower(hex) >= 97 && to_lower(hex) <= 102)
	{
		return to_lower(hex) - 87;
	}
	else if (hex >= 48 && hex <= 57)
	{
		return hex - 48;
	}
	
	return -1;
}

char to_lower(char character)
{
	if ((int)character >= 65 && (int)character <= 90)
	{
		return character + 32;
	}
	return character;
}

int pow2(int base, int power)
{
	if (power < 0) 
	{
		printf("ERROR: power can be only positive");
		return -1;
	}

	int return_value = 1;
	
	for (int i = 0; i < power; i++)
	{
		return_value *= base;
	}
	
	return return_value;
}
