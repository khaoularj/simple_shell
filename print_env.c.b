#include"shell.h"
/**
 * env -function that prints the current env
 * @vector: arguments
 */
void env(char **vector __attribute__ ((unused)))
{

	int j;

	for (j = 0; environ[j]; j++)
	{
		_puts(environ[j]);
		_puts("\n");
	}

}
