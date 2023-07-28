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
