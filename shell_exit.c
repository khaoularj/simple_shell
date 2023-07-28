#include "shell.h"

/**
 * quit_shell - Handles the exit command of the shell.
 * @data: Pointer to the 'maindt' struct.
 *
 * Return:
 *   -2: Indicates the shell should exit.
 *    1: Indicates an error occurred while converting the argument to an int
 */
int quit_shell(maindt *data)
{
	int myQuit_shell;

	if (data->argv[1])
	{
		/* Convert argument to an integer */
		myQuit_shell = cnvstr_int(data->argv[1]);
		if (myQuit_shell == -1)
		{
			data->status = 2;
			myPrint_error(data, "Illegal number: "); /*Print error message*/
			my_print_string(data->argv[1]);
			custom_error_putchar('\n');
			return (1);
		}
		/* Set nerror value */
		data->nerror = cnvstr_int(data->argv[1]);
		return (-2); /* Return -2 to indicate shell should exit */
	}
	data->nerror = -1; /* Set nerror value to -1 */
	return (-2);		 /* Return -2 to indicate shell should exit */
}
