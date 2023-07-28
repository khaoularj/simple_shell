#include "shell.h"
/**
 * Allstr_ls - is a function to return an array of strings;
 * @head: is a pointer to a head of singly linked list;
 *
 * Return: an array of string of singly linked list.
 */
char **Allstr_ls(strl_t *head)
{
	strl_t *node = head;
	size_t x = fdlistLen(head), y;
	char **arg;
	char *str;

	if (!head || !x)
		return (NULL);

	arg = malloc(sizeof(char *) * (x + 1)); /* memmory allocation */
	if (!arg)
		return (NULL);

	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (y = 0; y < x; y++)
				free(arg[y]); /* free every argv's index */

			free(arg);
			return (NULL);
		}

		str = my_strcpy(str, node->str);
		arg[x] = str;
	}
	arg[x] = NULL;
	return (arg);
}
