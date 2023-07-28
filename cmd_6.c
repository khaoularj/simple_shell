#include "shell.h"
/**
 * is_delimeter - This function is for checking if a character is a _delim.
 * @c: The character to be checked.
 * @_delim: The string containing delimiters.
 *
 * Return: 1 if the character is a _delim, 0 otherwise.
 */
int is_delimeter(char c, char *_delim)
{
	/* Iterate through the _delim string and check it */
	while (*_delim)
		if (*_delim++ == c)
			return (1); /* Return 1 on success */
	return (0);
}

/**
 * myPrint_error - Prints an error message to standard error.
 * @data: Pointer to the 'maindt' struct.
 * @string_err: The error message string to be printed.
 *
 * This function prints an error message with the following format:
 *   <filename>: <line>: <command>: <error message>
 */
void myPrint_error(maindt *data, char *string_err)
{
	my_print_string(data->filename);
	my_print_string(": ");
	float_print(data->count_line, STDERR_FILENO);
	my_print_string(": ");
	my_print_string(data->argv[0]);
	my_print_string(": ");
	my_print_string(string_err);
}
