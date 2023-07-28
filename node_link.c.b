#include "shell.h"
/**
 * node_linkPath - function that creates a linked list for path dr
 * @path: string of path value
 * Return: a pointer to the created linked list
 */
all_path *node_linkPath(char *path)
{
	all_path *pointer_head = '\0';
	char *var_token;
	char *cpath = _strdup(path);

	var_token = strtok(cpath, ":");
	while (var_token)
	{
		pointer_head = new_Node_add(&pointer_head, var_token);
		var_token = strtok(NULL, ":");
	}

	return (pointer_head);
}
