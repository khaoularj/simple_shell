#include "shell.h"
/**
 * myStr_free - is a function to free all maindt struct fields;
 * @data: is informant for into_t structure;
 * @yes: if yes free all files;
 *
 * Return: type is void means nothing to be returned.
 */
void myStr_free(maindt *data, int yes)
{
	doubly_free(data->argv);
	data->argv = NULL;
	data->path = NULL;

	if (yes)
	{
		/* cmd buffer */
		if (!data->bf_cmd)
			free(data->arg);

		/* environment */
		if (data->env)
			allListnd(&(data->env));

		/* history */
		if (data->history)
			allListnd(&(data->history));

		/* alias */
		if (data->alias)
			allListnd(&(data->alias));

		doubly_free(data->environ);
		data->environ = NULL;
		mybffFree((void **)data->bf_cmd);

		if (data->readfd > 2)
			close(data->readfd);

		my_putchar(BFLUSH);
	}
}

/**
 * struct_clear - is a function to initialize maindt struct with NULL;
 * @data: is informant for into_t structure;
 *
 * Return: nothing;
 */
void struct_clear(maindt *data)
{
	data->arg = NULL;

	data->argv = NULL;

	data->path = NULL;

	data->argc = 0;
}
