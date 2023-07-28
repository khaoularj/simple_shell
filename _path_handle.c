#include "shell.h"

/**
 * my_findPath - This function finds the executable path for a command.
 * @data: Pointer to the `maindt` structure containing command information
 * @search_path: Text containing the colon-separated paths to search.
 * @cmd: The command to find.
 *
 * Return: The executable path if found, otherwise NULL.
 */
char *my_findPath(maindt *data, char *search_path, char *cmd)
{
	int i = 0, this_position = 0;
	char *the_path;

	if (!search_path)
		return (NULL);

	/* Check if the command starts with "./" & is executable in directory */
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (check_exec(data, cmd))
			return (cmd);
	}
	while (1)
	{
		/* Split search_path based on ':' _delim */
		if (!search_path[i] || search_path[i] == ':')
		{
			/* Create path, combining current path segment and the command */
			the_path = char_dup(search_path, this_position, i);
			if (!*the_path)
				my_strcat(the_path, cmd);
			else
			{
				my_strcat(the_path, "/");
				my_strcat(the_path, cmd);
			}
			/* Check if the constructed path is executable */
			if (check_exec(data, the_path))
				return (the_path);
			if (!search_path[i])
				break;
			this_position = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * is_interactive - Checks if the program is running in interactive mode.
 * @data: Pointer to the `maindt` structure containing command information.
 *
 * Return: 1 if running in interactive mode, 0 otherwise.
 */
int is_interactive(maindt *data)
{
	/* Check if stdin is terminal and the read fd is within the range [0,2] */
	return (isatty(STDIN_FILENO) && data->readfd <= 2);
}

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

