#include "shell.h"
/**
 * char_dup - Creates a duplicate string from a portion of input string
 * @path_txt: Is the input string.
 * @start: Is the starting index of the portion to duplicate
 * @stop: Is the ending index of the portion to duplicate
 *
 * Return: A pointer to the duplicated string
 */
char *char_dup(char *path_txt, int start, int stop)
{
	static char buffer[1024];
	int index1 = 0, index2 = 0;

	for (index2 = 0, index1 = start; index1 < stop; index1++)
		if (path_txt[index1] != ':')
			buffer[index2++] = path_txt[index1];
	buffer[index2] = 0;
	return (buffer);
}

/**
 * findexec_cmd - Finds and executes a command based on the input information.
 * @data: Pointer to the `maindt` structure containing command information.
 */
void findexec_cmd(maindt *data)
{
	char *cmd_path = NULL;
	int number, num_args;

	data->path = data->argv[0];
	/* Increment line count if countline_flag is set */
	if (data->countline_flag == 1)
	{
		data->count_line++;
		data->countline_flag = 0;
	}
	/* Count the number of non-delimiter arguments */
	for (number = 0, num_args = 0; data->arg[number]; number++)
		if (!is_delimeter(data->arg[number], " \t\n"))
			num_args++;
	/* If no arguments, return */
	if (num_args == 0)
		return;
	/* Find the executable path */
	cmd_path = my_findPath(data, environ_getter(data, "PATH="),
						   data->argv[0]);
	if (cmd_path)
	{
		/* If path is found, update the command path and execute */
		data->path = cmd_path;
		my_fork(data);
	}
	else
	{
		/* If path is not found, check if the command is executable */
		if ((is_interactive(data) || environ_getter(data, "PATH=") ||
			 data->argv[0][0] == '/') &&
			check_exec(data, data->argv[0]))
			my_fork(data);
		else if (*(data->arg) != '\n') /* Print error if command not found */
		{
			data->status = 127;
			myPrint_error(data, "not found\n");
		}
	}
}
