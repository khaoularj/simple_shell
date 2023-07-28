#include "shell.h"

/**
 * cmdHis - a function to displays list of histry by one cmd per line;
 * @data: is informa or a constant structure for arguments;
 *
 *  Return: value 0 for success;
 */
int cmdHis(maindt *data)
{
	print_Linkedlist(data->history);

	return (0);
}

/**
 * fdlistLen - is  a function for finding the length of linked list;
 * @headptr: is a pointer to head of linked list;
 *
 * Return: the length of singly linked list;
 */
size_t fdlistLen(const strl_t *headptr)
{
	size_t x = 0;

	while (headptr != NULL)
	{
		headptr = headptr->next;
		x++;
	}

	return (x);
}

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
