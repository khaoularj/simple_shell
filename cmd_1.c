#include "shell.h"
/**
 * my_findCmd - Finds and executes a built-in cmd
 * @infoma: Pointer to maindt struct
 * Return: Return value of the executed built-in command, or -1 if not found
 */
int my_findCmd(maindt *infoma)
{
	int i, builtin_res = -1;
	built_table non_builtin_cmds[] = {
		{"exit", quit_shell},
		{"env", myenvPtr},
		{"help", my_help},
		{"history", cmdHis},
		{"setenv", myownSetenv},
		{"unsetenv", myownUnsetenv},
		{"cd", myCd},
		{"alias", my_alias},
		{NULL, NULL}};

	for (i = 0; non_builtin_cmds[i].type; i++)
	{
		if (my_strcopy(infoma->argv[0], non_builtin_cmds[i].type) == 0)
		{
			infoma->count_line++;
			builtin_res = non_builtin_cmds[i].fx(infoma);
			break;
		}
	}
	return (builtin_res);
}

/**
 * hsh - the main function that execute the shell.
 * @infoma: Is a pointer to the maindt struct
 * @av: array of strings representing command-line arguments.
 * Return: Return value of the last executed command or specified exit value
 */
int hsh(maindt *infoma, char **av)
{
	ssize_t read_result = 0;
	int built_in_res = 0;

	while (read_result != -1 && built_in_res != -2)
	{
		struct_clear(infoma);
		if (is_interactive(infoma))
			_puts("$ ");
		custom_error_putchar(BFLUSH);
		read_result = user_inputGet(infoma);
		if (read_result != -1)
		{
			mystrutct_set(infoma, av);
			built_in_res = my_findCmd(infoma);
			if (built_in_res == -1)
				findexec_cmd(infoma);
		}
		else if (is_interactive(infoma))
			my_putchar('\n');
		myStr_free(infoma, 0);
	}
	appendHis(infoma);
	myStr_free(infoma, 1);
	if (!is_interactive(infoma) && infoma->status)
		exit(infoma->status);
	if (built_in_res == -2)
	{
		if (infoma->nerror == -1)
			exit(infoma->status);
		exit(infoma->nerror);
	}
	return (built_in_res);
}
