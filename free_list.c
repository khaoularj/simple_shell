#include "shell.h"
/**
 * bfree - function that frees a list_t
 *@pointer_head: pointer to the linked list
 */
void bfree(all_path *pointer_head)
{
	all_path *storage;

	while (pointer_head)
	{
		storage = pointer_head->p;
		free(pointer_head->dir);
		free(pointer_head);
		pointer_head = storage;
	}

}
