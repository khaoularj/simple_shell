#include "shell.h"
/**
 * funSplit_string - splits a string into words
 * @string: the string to be splited
 * @delim: the delimiter
 * Return: array of pointers to words
 */
char **funSplit_string(char *string, const char *delim)
{
	int i, m;
	char **array;
	char *token;
	char *copy_str;

	copy_str = malloc(_strlen(string) + 1);
	if (copy_str == NULL)
	{
		perror(my_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (string[i])
	{
		copy_str[i] = string[i];
		i++;
	}
	copy_str[i] = '\0';

	token = strtok(copy_str, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	i = 1;
	m = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = funRealloc(array, (sizeof(char *) * (m - 1)), (sizeof(char *) * m));
		array[i] = _strdup(token);
		i++;
		m++;
	}
	free(copy_str);
	return (array);
}
