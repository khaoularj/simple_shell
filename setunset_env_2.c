#include "shell.h"
/**
 * UnsetenvCustom - This function unset an environment variable.
 * @data: Pointer to the shell information struct.
 * @var_unset: The variable to unset.
 *
 * Return: 0 if variable is not found or invalid, otherwise
 * returns the value of `data->changed_env`.
 */
int UnsetenvCustom(maindt *data, char *var_unset)
{
	strl_t *list_node = data->env;
	size_t index = 0;
	char *pointer;

	if (!list_node || !var_unset)
		return (0);

	while (list_node)
	{
		/* Check if the variable starts with the given name */
		pointer = starts_with(list_node->str, var_unset);
		if (pointer && *pointer == '=')
		{
			/* if found Delete the node */
			data->changed_env = ndIndex_del(&(data->env), index);
			index = 0;				 /* Reset index */
			list_node = data->env; /* Reset list_node */
			continue;
		}
		list_node = list_node->next; /* Move to the next node */
		index++;					 /* Increment index */
	}
	return (data->changed_env); /* Return 1 if deleted, 0 otherwise */
}

/**
 * setenv_custom - Set an environment variable.
 * @data: Pointer to the shell information struct.
 * @var_unset: The variable name.
 * @value: The value to assign to the variable.
 *
 * Return: 0 if successful, otherwise returns 1 if memory
 * allocation fails or 0 if invalid input.
 */
int setenv_custom(maindt *data, char *var_unset, char *value)
{
	char *the_buffer = NULL;
	strl_t *avNode;
	char *pointer;

	if (!var_unset || !value)
		return (0);

	the_buffer = malloc(_strlen(var_unset) + _strlen(value) + 2);
	if (!the_buffer)
		return (1);
	my_strcpy(the_buffer, var_unset);
	my_strcat(the_buffer, "=");
	my_strcat(the_buffer, value);
	/* Set avNode to the head of the list */
	avNode = data->env;
	while (avNode)
	{
		pointer = starts_with(avNode->str, var_unset);
		if (pointer && *pointer == '=')
		{
			/* if found replace the node */
			free(avNode->str);
			avNode->str = the_buffer;
			data->changed_env = 1; /* Set changed_env to 1 */
			return (0);
		}
		avNode = avNode->next; /* Move to the next node */
	}
	endmyAddnd(&(data->env), the_buffer, 0); /* Add the new node */
	free(the_buffer);							/* Free the buffer */
	data->changed_env = 1;					/* Set changed_env to 1 */
	return (0);
}
