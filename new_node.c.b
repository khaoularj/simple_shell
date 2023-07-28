#include "shell.h"
/**
 * new_Node_add -function that adds a new node at the end of a list_t list
 * @pointer_head: pointer to pointer to linked list
 * @string: pointer to string in previous first node
 * Return: the new adress
 */

all_path *new_Node_add(all_path **pointer_head, char *string)
{

	all_path *temporary;
	all_path *new;

	new = malloc(sizeof(all_path));

	if (!new || !string)
	{
		return (NULL);
	}

	new->dir = string;

	new->p = '\0';
	if (!*pointer_head)
	{
		*pointer_head = new;
	}
	else
	{
		temporary = *pointer_head;

		while (temporary->p)
		{

			temporary = temporary->p;
		}

		temporary->p = new;
	}

	return (*pointer_head);
}
