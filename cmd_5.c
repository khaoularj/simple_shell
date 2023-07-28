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
