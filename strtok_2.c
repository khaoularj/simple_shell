#include "shell.h"
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
