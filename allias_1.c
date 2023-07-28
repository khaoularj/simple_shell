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
