#include "shell.h"

/**
 * myenvPtr - Prints the environment variables.
 * @data: Pointer to the `maindt` struct.
 *
 * Return: 0: Indicates successful execution.
 */
int myenvPtr(maindt *data)
{
	/* Print the linked list of environment variables */
	linkedList_print(data->env);
	return (0);
}

/**
 * mygetenv- Retrieves the value of an environment variable.
 * @data: Pointer to the `maindt` struct.
 * @env_name: env_name of the environment variable to retrieve.
 *
 * Return:
 *   - Pointer to the value of the environment variable if found.
 *   - NULL if the environment variable is not found.
 */
char *environ_getter(maindt *data, const char *env_name)
{
	strl_t *node_ls = data->env;
	char *nodeCheck;

	while (node_ls)
	{
		/*Check if the node's string starts with the given env_name*/
		nodeCheck = starts_with(node_ls->str, env_name);
		/*If nodeCheck is not null and the next character is not null as well*/
		if (nodeCheck && *nodeCheck)
			return (nodeCheck);		 /* Return the pointer */
		node_ls = node_ls->next; /* Move to the next node */
	}
	return (NULL);
}

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
