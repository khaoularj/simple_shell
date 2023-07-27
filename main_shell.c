#include "shell.h"
/**
 * _EOF - function that handles the eof (ctrl + d)
 * @length: return value of getline function
 * @buffer: buffer
 */
void _EOF(int length, char *buffer)
{
	(void)buffer;
	if (length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}

/**
 * sig_handler - function that checks the success of (ctrl+D)
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts("\n$ ");
	}
}

/**
  * my_isatty - verify if it's terminal
  */
void my_isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("$ ");
}
/**
 * main - the main function that execute the Shell
 * Return: 0 on success
 */
int main(void)
{
	ssize_t length = 0;
	char *buffer = NULL, *value, *pathname, **arv;
	size_t size = 0;
	all_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (length != EOF)
	{
		my_isatty();
		length = getline(&buffer, &size, stdin);
		_EOF(length, buffer);
		arv = funSplit_string(buffer, " \n");
		if (!arv || !arv[0])
			funexec_cmd(arv);
		else
		{
			value = my_getenv("PATH");
			head = node_linkPath(value);
			pathname = findPathcmd(arv[0], head);
			f = checkbuild(arv);
			if (f)
			{
				free(buffer);
				f(arv);
			}
			else if (!pathname)
				funexec_cmd(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				funexec_cmd(arv);
			}
		}
	}
	bfree(head);
	myfree(arv);
	free(buffer);
	return (0);
}
