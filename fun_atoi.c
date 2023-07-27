#include"shell.h"
/**
 * fun_atoi - function that converts a string into an integer
 *@string: pointer to a string
 *Return: the integer
 */
int fun_atoi(char *string)
{
	int j, convert_Int, signal = 1;

	j = 0;
	convert_Int = 0;
	while (!((string[j] >= '0') && (string[j] <= '9')) && (string[j] != '\0'))
	{
		if (string[j] == '-')
		{
			signal = signal * (-1);
		}
		j++;
	}
	while ((string[j] >= '0') && (string[j] <= '9'))
	{
		convert_Int = (convert_Int * 10) + (signal * (string[j] - '0'));
		j++;
	}
	return (convert_Int);
}
