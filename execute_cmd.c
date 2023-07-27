#include "shell.h"
/**
 * funexec_cmd - function that execute a command
 * @argv: array of arguments
 */

void funexec_cmd(char **argv)
{

	int d, my_status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(my_getenv("_"));
	}
	if (d == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&my_status);
}
