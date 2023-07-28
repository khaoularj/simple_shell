#include "shell.h"
/**
 * myfree - function that frees the array of pointers vector
 *@vector: array of pointers
 */

void myfree(char **vector)
{
	int i;

	for (i = 0; vector[i]; i++)
		free(vector[i]);
	free(vector);
}
