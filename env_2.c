#include "shell.h"
/**
 * env_pop - Populates the environment variable linked list.
 * @data: Pointer to the `maindt` struct.
 *
 * Return: Always returns 0 to indicate successful execution
 */
int env_pop(maindt *data)
{
	strl_t *node_ls = NULL;
	size_t number;

	/*Add each environment variable to the linked list*/
	for (number = 0; environ[number]; number++)
		endmyAddnd(&node_ls, environ[number], 0);
	data->env = node_ls; /* Set the environment variable linked list */
	return (0);
}
