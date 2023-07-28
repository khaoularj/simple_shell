#include "shell.h"

/**
 * hsh - This is the main function for the shell.
 * @infoma: Is a pointer to the maindt structure containing shell information.
 * @av: is an array of strings representing command-line arguments.
 *
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
			_puts("$ ");					 /* Print shell prompt */
		custom_error_putchar(BFLUSH);		 /* Flush error buffer */
		read_result = user_inputGet(infoma); /* Read user input */
		if (read_result != -1)
		{
			mystrutct_set(infoma, av);
			/* Check if the command is a built-in */
			built_in_res = my_findCmd(infoma);
			if (built_in_res == -1)
				findexec_cmd(infoma); /* Search for and execute the command */
		}
		else if (is_interactive(infoma))
			my_putchar('\n'); /* Print a newline for better formatting */
		myStr_free(infoma, 0);
	}
	appendHis(infoma);		/* Write command history to file */
	myStr_free(infoma, 1); /* Free remaining memory allocated for command */
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

/**
 * set_mem - Sets a block of memory with a specified value.
 * @s: Pointer to the memory block to be set.
 * @b: Value to set the memory block with.
 * @n: Number of bytes to set.
 *
 * Return: Pointer to the memory block after setting.
 */
char *set_mem(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b; /* Set each byte to the specified value */
	return (s);
}

/**
 * doubly_free - This function frees a double pointer string array.
 * @pointer: Pointer to the double pointer string array.
 */
void doubly_free(char **pointer)
{
	/* Create a temporary pointer to store the original value */
	char **a = pointer;

	if (!pointer)
		return; /* Return if the double pointer is NULL */
	while (*pointer)
		free(*pointer++); /* Free each string pointer and move to the next */
	free(a);		 /* Free the original double pointer */
}

/**
 * my_realloc - Reallocates memory for a given pointer to a new size.
 * @ptr: Pointer to the memory block to be reallocated.
 * @old_size: Size of the current memory block.
 * @new_size: Size of the desired new memory block.
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure.
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size)); /* Allocate memory if the pointer is NULL */

	/* Free memory and return NULL if new size is 0 */
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr); /* Return original pointer if old and new sizes are the same */

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	/* Determine the smaller size */
	old_size = old_size < new_size ? old_size : new_size;

	/* Copy contents from old pointer to new pointer */
	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];
	free(ptr);		  /* Free the old pointer */
	return (new_ptr); /* Return the new pointer */
}

/**
 * my_findCmd - Finds and executes a built-in command.
 * @infoma: Pointer to maindt structure containing command information
 *
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
			/* Execute the built-in command */
			builtin_res = non_builtin_cmds[i].fx(infoma);
			break;
		}
	}
	return (builtin_res);
}
