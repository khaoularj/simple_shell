#include "shell.h"
/**
 * my_fork - This function forks a child process and executes a command.
 * @data: Pointer to the data structure containing command information.
 */
void my_fork(maindt *data)
{
	pid_t child_process;

	child_process = fork();
	if (child_process == -1)
	{
		/* Print error message if fork fails */
		perror("Error:");
		return;
	}
	if (child_process == 0)
	{
		if (execve(data->path, data->argv, env_finder(data)) == -1)
		{
			myStr_free(data, 1);
			/* Exit with code 126 if execution permission denied */
			if (errno == EACCES)
				exit(126);
			exit(1); /* Exit with code 1 if execve fails */
		}
	}
	else
	{
		/* Wait for the child process to terminate */
		wait(&(data->status));
		if (WIFEXITED(data->status))
		{
			/* Get the exit status of the child process */
			data->status = WEXITSTATUS(data->status);
			/* Print error message if permission denied */
			if (data->status == 126)
				myPrint_error(data, "Permission denied\n");
		}
	}
}

/**
 * check_exec - Checks if a file at the given path is executable.
 * @data: Pointer to the data structure (unused in the function).
 * @path: Path of the file to be checked.
 *
 * Return: 1 if the file is executable, 0 otherwise.
 */
int check_exec(maindt *data, char *path)
{
	struct stat st;

	(void)data; /* Unused parameter */

	if (!path || stat(path, &st)) /* Check if path is null or stat fails */
		return (0);

	if (st.st_mode & S_IFREG) /* Check if the file is a regular file */
	{
		return (1); /* File is executable */
	}

	return (0); /* File is not executable */
}
