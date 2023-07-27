#include "shell.h"
/**
 * display_prompt - the function that display a prompt
 * Return:args
 */
char **display_prompt(void)
{
	bool from_terminal = isatty(STDIN_FILENO);
	char *buffer = NULL;
	size_t buffer_size = 0;
	int n_char = 0;
	char *token;
	char **args;
	int i = 0;

	if (from_terminal)
	{
		write(1, "$ ", 2);
	}

	n_char = getline(&buffer, &buffer_size, stdin);

	if (n_char == EOF)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		buffer[n_char - 1] = '\0';
		args = malloc(sizeof(char *) * _strlen(buffer));

		token = strtok(buffer, " \t\n");
		
		while (token)
		{
			args[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		args[i] = NULL;
	}
	return(args);
}
