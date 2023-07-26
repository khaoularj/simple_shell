#include "shell.h"
/**
 * cmd_interpreter - the function that interprete the input command
 * @envp: the environment variables
 * Return:0
 */
int cmd_interpreter(char **envp)
{
	int status = 0;
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
			execve(args[0], args, envp);

			if (args[0][0] != '/' && args[0][0] != '.')
			{
				char *path = getenv("PATH");

				if (path != NULL)
				{
					char *dir = strtok(path, ":");

					while (dir != NULL)
					{
						char *full_path = _get_path(dir, args[0]);

						execve(full_path, args, envp);
						free(full_path);
						dir = strtok(NULL, ":");
					}
				}
			}
			perror(args[0]);
			_exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
			free(args);
		}
	}
	return (0);
}
