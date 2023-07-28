#include "shell.h"

/**
 * myAlias_make - is a function to make an alias;
 * @data: is informant of maindt structure's information;
 * @string: is a string of an alias to be set or made;
 *
 * Return: value 0 for success otherwise return 1;
 */
int myAlias_make(maindt *data, char *string)
{
	char *pointer;

	pointer = my_strchr(string, '=');
	if (!pointer)
		return (1);

	if (!*++pointer)
		return (dontmkmy_alias(data, string));

	dontmkmy_alias(data, string);

	return (endmyAddnd(&(data->alias), string, 0) == NULL);
}

/**
 * dontmkmy_alias - is a function to unmake or to delete an alias;
 * @data: is informant of maindt structure's information;
 * @string: is a string of an alias to unset or to be deleted;
 *
 * Return: value 0 for success otherwise return 1.
 */
int dontmkmy_alias(maindt *data, char *string)
{
	char *pointer;
	char c;
	int rval;/* return value */

	pointer = my_strchr(string, '=');
	if (!pointer)
		return (1);

	c = *pointer;
	*pointer = 0;
	/* return value on deletion of a fnode */
	rval = ndIndex_del(&(data->alias),
							   numbernd(data->alias, ndStart(data->alias, string, -1)));
	*pointer = c;
	return (rval);
}

/**
 * replaceAlias - is a function to replace an alias;
 * @data: is informant of maindt structure's information;
 *
 * Return: value 1 for success otherwise 0 for failure.
 */
int replaceAlias(maindt *data)
{
	strl_t *fnode;
	int i;
	char *pt;

	for (i = 0; i < 10; i++)
	{
		fnode = ndStart(data->alias, data->argv[0], '=');
		if (!fnode)
			return (0); /* return 0 if fnode is NULL */

		free(data->argv[0]);
		pt = my_strchr(fnode->str, '=');
		if (!pt)
			return (0); /* return 0 if pt is NULL */

		pt = my_strdup(pt + 1);
		if (!pt)
			return (0); /* return 0 if pt is NULL */

		data->argv[0] = pt;
		free(pt); /* end by freeing pt */
	}

	return (1);
}

/**
 * ptrcmy_alias - is a function to print an alias string;
 * @fnode: is a fnode related to an alias string;
 *
 * Return: value 0 for success otherwise 1 for failure.
 */
int ptrcmy_alias(strl_t *fnode)
{
	char *sta = NULL, *pt = NULL;

	if (fnode)
	{
		pt = my_strchr(fnode->str, '=');
		sta = fnode->str;
		while (sta <= pt)
		{
			my_putchar(*sta);
			sta++;
		}
		my_putchar('\'');
		_puts(pt + 1);
		_puts("'\n");

		return (0);
	}

	return (1);
}

/**
 * my_alias - is a mimicing an alias by manual alias details;
 * @data: is informant of maindt structure's information;
 *
 * Return: value 0 for all.
 */
int my_alias(maindt *data)
{
	strl_t *fnode = NULL;
	char *pt = NULL;
	int i = 0;

	if (data->argc == 1)
	{
		fnode = data->alias;
		while (fnode)
		{
			ptrcmy_alias(fnode);/* for printing an alias at current fnode */
			fnode = fnode->next;
		}
		return (0);
	}

	i = 1;
	while (data->argv[i])
	{
		pt = my_strchr(data->argv[i], '=');
		if (pt)
		{
			myAlias_make(data, data->argv[i]);/* for setting an alias */
		}
		else
		{
			/* for printing an alias at current index */
			ptrcmy_alias(ndStart(data->alias, data->argv[i], '='));
		}
		i++;
	}

	return (0);
}
