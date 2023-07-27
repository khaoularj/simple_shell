#include "shell.h"
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
