#include "shell.h"
/**
 * funRealloc - function that reallocates a memory block
 * @pointer: the previous pointer
 * @ptr_Osize: the old size of previous pointer
 * @ptr_Nsize: the new size for the pointer
 * Return: the new Pointer
 */

void *funRealloc(void *pointer, unsigned int ptr_Osize, unsigned int ptr_Nsize)
{
	char *new;
	char *old;

	unsigned int i;

	if (pointer == NULL)
		return (malloc(ptr_Nsize));

	if (ptr_Nsize == ptr_Osize)
		return (pointer);

	if (ptr_Nsize == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}

	new = malloc(ptr_Nsize);
	old = pointer;
	if (new == NULL)
		return (NULL);

	if (ptr_Nsize > ptr_Osize)
	{
		for (i = 0; i < ptr_Osize; i++)
			new[i] = old[i];
		free(pointer);
		for (i = ptr_Osize; i < ptr_Nsize; i++)
			new[i] = '\0';
	}
	if (ptr_Nsize < ptr_Osize)
	{
		for (i = 0; i < ptr_Nsize; i++)
			new[i] = old[i];
		free(pointer);
	}
	return (new);
}
