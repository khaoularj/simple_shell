#include "shell.h"
/**
 * cmd_interpreter - the function that interprete the input command
 * Return:0
 */
int cmd_interpreter(void)
{
	int status = 0;
	char *buffer = NULL;
	pid_t pid;

	while (1)
	{
		char **args = display_prompt();

		if (_strcmp(args[0], "exit") == 0)
		{
			exit(EXIT_FAILURE);
		}

		pid = fork();

		if (pid == 0)
		{
			int val = execve(args[0], args, NULL);

			if (val == -1)
			{
				perror("./hsh");
				_exit(EXIT_FAILURE);
			}
		}
		else if (pid == -1)
		{
			perror("fork failed");
		}
		else
		{
			wait(&status);
			free(args);
		}
	}
	free(buffer);
	return (0);
}
