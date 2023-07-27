#include "shell.h"
/**
  * my_isatty - verify if it's terminal
  */
void my_isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("$ ");
}
