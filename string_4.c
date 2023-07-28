#include "shell.h"
/**
 * my_strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *my_strdup(const char *str)
{
	int length = 0;
	char *makeTwo;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	makeTwo = malloc(sizeof(char) * (length + 1));
	if (!makeTwo)
		return (NULL);

	for (length++; length--;)
		makeTwo[length] = *--str;
	return (makeTwo);
}

/**
 * my_str - function that copies up to 'n' characters from src to dest
 * @destination: Is the destination string where 'src' will be copied to.
 * @src: src string to be copied.
 * @n: num of characters to be copied.
 * Return: A pointer to the destination string.
 */
char *my_str(char *destination, char *src, int n)
{
	int i, j;
	char *deststore = destination;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		destination[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (deststore);
}

/**
 * replace_str - Replaces the content of a pointer to a string with a new one
 * @old: Pointer to the old string to be replaced.
 * @new: The new string to replace the old string.
 * Return: 1 on success,on fail, 0
 */
int replace_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

