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
