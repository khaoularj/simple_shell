#include "shell.h"

/**
 * mystr_twords - Convert a string into an array of theWord using delimiters.
 * @string: The input string to be split into theWord.
 * @delimiters: The delimiters used to split the string into theWord (optional).
 *
 * Return: Array of strings representing the theWord, or NULL if no theWord found
 */

char **mystr_twords(char *string, char *delimiters)
{
	int i, j, k, m, wordsNumber = 0;
	char **theWord;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!delimiters)
		delimiters = " ";
	for (i = 0; string[i] != '\0'; i++) /*Count the number of theWord in string*/
		if (!is_delimeter(string[i], delimiters) &&
			(is_delimeter(string[i + 1], delimiters) ||
			 !string[i + 1]))
			wordsNumber++;

	if (wordsNumber == 0)
		return (NULL);
	theWord = malloc((1 + wordsNumber) * sizeof(char *)); /*Alloc memry for arr*/
	if (!theWord)
		return (NULL);
	for (i = 0, j = 0; j < wordsNumber; j++) /* Split the string into theWord */
	{
		while (is_delimeter(string[i], delimiters)) /* Skip delimiters */
			i++;
		k = 0; /* Count the number of characters in the word */
		while (!is_delimeter(string[i + k], delimiters) && string[i + k])
			k++;
		theWord[j] = malloc((k + 1) * sizeof(char)); /*Alloc memory for word*/
		if (!theWord[j])
		{ /* Free all previously allocated memory */
			for (k = 0; k < j; k++)
				free(theWord[k]);
			free(theWord);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			theWord[j][m] = string[i++]; /* Copy the word into the array */
		theWord[j][m] = 0;
	}
	theWord[j] = NULL; /* Set the last element of the array to NULL */
	return (theWord);
}

/**
 * mybffFree - Free memory allocated for a pointer and set it to NULL
 * @pointer: A pointer to the memory to be freed
 *
 * Return: 1 if memory was freed successfully, 0 otherwise
 */
int mybffFree(void **pointer)
{
	/* Check if pointer is not NULL and points to a valid address */
	if (pointer && *pointer)
	{
		free(*pointer);	 /* Free memory */
		*pointer = NULL; /* Set pointer to NULL after freeing */
		return (1);
	}
	return (0);
}

/**
 * long_strcvrt - Convert a long integer to a string representation.
 * @number: The long integer to be converted.
 * @base: The base for the conversion (e.g., 10 for decimal).
 * @flags: Flags for customizing the conversion behavior.
 *
 * Return: A pointer to the string representation of the long integer.
 */
char *long_strcvrt(long int number, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0; /* Flag for negative numbers */
	char *pointer;
	unsigned long n = (unsigned long)number;

	/* If number is zero, return a string of zero */
	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';
	}
	/* Set the default base to 10 if not specified */
	array = flags & CONVTO_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';

	do {
		*--pointer = array[n % base]; /* Convert the number to string */
		n /= base;				  /* Update the number to be converted */
	} while (n != 0);

	if (sign)
		*--pointer = sign; /* Add the negative sign if necessary */
	return (pointer);
}
