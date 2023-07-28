#include "shell.h"

/**
 * my_help - is a process of changing working directory;
 * @data:is informant structure of maindt struct parameter;
 *
 * Return: value 0 for success.
 */
int my_help(maindt *data)
{
	char **arv;

	arv = data->argv;
	_puts("help call works. Function not yet implemented \n");

	if (0)
		_puts(*arv);

	return (0);
}

/**
 * mymyCd- is a function to change working or current directory;
 * @data: is informant structure of maindt struct parameter;
 *
 * Return: value 0 for all.
 */
int myCd(maindt *data)
{
	int val_r;
	char *my_Dir, *string, buffer[1024];

	string = getcwd(buffer, 1024);
	if (string == NULL)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!data->argv[1])
	{
		my_Dir = environ_getter(data, "HOME=");
		if (my_Dir == NULL)
			val_r = chdir((my_Dir = environ_getter(data, "PWD=")) ? my_Dir : "/");
		else
			val_r = chdir(my_Dir);
	}
	else if (my_strcopy(data->argv[1], "-") == 0)
	{
		if (!environ_getter(data, "OLDPWD="))
		{
			_puts(string);
			my_putchar('\n');
			return (1);
		}
		_puts(environ_getter(data, "OLDPWD=")), my_putchar('\n');
		val_r = chdir((my_Dir = environ_getter(data, "OLDPWD=")) ? my_Dir : "/");
	}
	else
		val_r = chdir(data->argv[1]);
	if (val_r == -1)
	{
		myPrint_error(data, "can't cd to ");
		my_print_string(data->argv[1]), custom_error_putchar('\n');
	}
	else
	{
		setenv_custom(data, "OLDPWD", environ_getter(data, "PWD="));
		setenv_custom(data, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
