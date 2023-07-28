#include "shell.h"

/**
 * myownSetenv - is a function to set environment;
 * @data: is informant structure of maindt struct parameter;
 *  Return: value 0 for all.
 */
int myownSetenv(maindt *data)
{
	if (data->argc != 3)
	{
		/* error message of incorect arguments number */
		my_print_string("incorrect number of arguments\n");

		return (1);
	}
	if (setenv_custom(data, data->argv[1], data->argv[2]))
		return (0);

	return (1);
}

/**
 * myownUnsetenv - is a function to delete environmental variable;
 * @data: is informant structure of maindt struct parameter;
 *
 * Return: value 0 for all.
 */
int myownUnsetenv(maindt *data)
{
	int i;

	if (data->argc == 1)
	{
		/* error message of few arguments */
		my_print_string("too few arguments\n");

		return (1);
	}
	for (i = 1; i <= data->argc; i++)
		UnsetenvCustom(data, data->argv[i]);

	return (0);
}

/**
 * env_finder - is a function to find the external environment;
 * @data: is informant structure of maindt struct parameter;
 *
 * Return: value 0 for all;
 */
char **env_finder(maindt *data)
{
	if (!data->environ || data->changed_env)
	{
		data->environ = Allstr_ls(data->env);
		data->changed_env = 0;
	}

	return (data->environ);
}
