#include "shell.h"
/**
 * _get_path - the function that gives the path of a file
 * @dir: the directory path
 * @fname: the name of the file
 * Return: the path of a file
 */
char *_get_path(char *dir, char *fname)
{
	char *fpath = (char *)malloc(_strlen(dir) + _strlen(fname) + 2);

	if (fpath == NULL)
	{
		exit(EXIT_FAILURE);
	}

	_strcpy(fpath, dir);
	_strcat(fpath, "/");
	_strcat(fpath, fname);
	return (fpath);
}
