#include "shell.h"
/**
 * set_mem - Sets a block of memory with a specified value.
 * @s: Ptr to the memory block
 * @b: Value to set the memory block with.
 * @n: N of bytes to set.
 * Return: Ptr to the memory block
 */
char *set_mem(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * doubly_free - function that frees a double ptr string array.
 * @pointer: Ptr to the double pointer str array.
 */
void doubly_free(char **pointer)
{
	char **a = pointer;

	if (!pointer)
		return; 
	while (*pointer)
		free(*pointer++);
	free(a);
}

/**
 * my_realloc - Reallocates memory for a given pointer to a new size.
 * @ptr: Pointer to the memory block to be reallocated.
 * @old_size: Size of the current memory block.
 * @new_size: Size of the desired new memory block.
 * Return: Pointer to the reallocated memory block, or NULL on failure.
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr); 

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];
	free(ptr);  
	return (new_ptr);
}
