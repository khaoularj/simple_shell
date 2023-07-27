#include "shell.h"
/**
 * findPathcmd - function that finds the pathname of a f_name
 * @filename: name of file or command
 * @pointer_head: pointer_head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *findPathcmd(char *filename, all_path *pointer_head)
{
	struct stat ft;
	char *string;

	all_path *temporary = pointer_head;

	while (temporary)
	{

		string = concat_all(temporary->dir, "/", filename);
		if (stat(string, &ft) == 0)
		{
			return (string);
		}
		free(string);
		temporary = temporary->p;
	}

	return (NULL);
}
