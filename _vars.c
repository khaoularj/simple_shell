#include "shell.h"

/**
 * replace_Myvar - is a function for variable replacing;
 * @data: is informant for into_t structure;
 *
 * Return: value 1 if yes otherwise 0 for if not replaced.
 */
int replace_Myvar(maindt *data)
{
	strl_t *ptr_node;
	int j = 0;

	for (j = 0; data->argv[j]; j++)
	{
		if (data->argv[j][0] != '$' || !data->argv[j][1])
			continue; /* if yes continue */

		if (!my_strcopy(data->argv[j], "$?"))
		{
			replace_str(&(data->argv[j]),
							my_strdup(long_strcvrt(data->status, 10, 0)));
			continue; /* if yes continue */
		}

		if (!my_strcopy(data->argv[j], "$$"))
		{
			replace_str(&(data->argv[j]),
							my_strdup(long_strcvrt(getpid(), 10, 0)));
			continue; /* if yes continue */
		}

		ptr_node = ndStart(data->env, &data->argv[j][1], '=');
		if (ptr_node)
		{
			replace_str(&(data->argv[j]),
							my_strdup(my_strchr(ptr_node->str, '=') + 1));
			continue; /* if yes continue */
		}
		replace_str(&data->argv[j], my_strdup(""));
	}

	return (0);
}

/**
 * mystrutct_set - is a function for initialization of maindt structure;
 * @data:  is informant for into_t structure;
 * @av: is arguments vector by informant strucure;
 */
void mystrutct_set(maindt *data, char **av)
{
	int x = 0;

	data->filename = av[0];
	if (data->arg)
	{
		data->argv = mystr_twords(data->arg, " \t");
		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = my_strdup(data->arg);
				data->argv[1] = NULL;
			}
		}

		while (data->argv && data->argv[x])
			x++;

		data->argc = x;

		replaceAlias(data);
		replace_Myvar(data);
	}
}

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
