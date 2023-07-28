#include "shell.h"
/**
 * cnvstr_int - This function convert strings to int.
 * @string: Is The input string
 * Return: The converted integer value, or -1 if conversion fails.
 */
int cnvstr_int(char *string)
{
	int index = 0;
	unsigned long int final = 0;

	/* check for NULL pointer */
	if (*string == '+')
		string++;

	/*Count the number of words in string*/
	for (index = 0; string[index] != '\0'; index++)
	{
		if (string[index] >= '0' && string[index] <= '9')
		{
			final *= 10;				  /* Multiply the current final by 10 */
			final += (string[index] - '0'); /* Add the digit to the final */
			if (final > INT_MAX)
				return (-1); /* Overflow check */
		}
		else
			return (-1); /* Invalid character found, return -1 */
	}
	return (final);
}
