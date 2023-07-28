#include "shell.h"

/**
 * ndStart - is a function to return fnode of string strated with prefix;
 * @fnode: is a pointer to pointer_head of linked list;
 * @prefix: is a string to be matched to;
 * @c: is a next character to the next matched prefix with fnode;
 *
 * Return: matched fnode otherwise NULL;
 */
strl_t *ndStart(strl_t *fnode, char *prefix, char c)
{
	char *pointer = NULL;

	while (fnode != NULL)
	{
		pointer = starts_with(fnode->str, prefix);
		if (pointer && ((c == -1) || (*pointer == c)))
		{
			return (fnode);
		}
		fnode = fnode->next;
	}

	return (NULL);
}

/**
 * numbernd - is a function to return index of a fnode;
 * @pointer_head: is a pointer to a pointer_head of singly linked list;
 * @fnode: is a pointer to a fnode of singly linked list;
 *
 * Return: the index of a fnode in singly linked list otherwise -1.
 */
ssize_t numbernd(strl_t *pointer_head, strl_t *fnode)
{
	size_t x = 0;

	while (pointer_head != NULL)
	{
		if (pointer_head == fnode)
			return (x);

		pointer_head = pointer_head->next;
		x++;
	}

	return (-1);
}
