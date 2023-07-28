#include "shell.h"

/**
 * my_strcat - concatenates two strings
 * @destination: Is the destination string to which 'src' will be appended
 * @src: Is the source string containing the characters to be appended
 *
 * Return: Pointer to the resulting concatenated string
 */
char *my_strcat(char *destination, char *src)
{
	char *ret = destination;

	/* Find the end of the destination string */
	while (*destination)
		destination++;

	/* Append characters from 'src' to 'destination' */
	while (*src)
		*destination++ = *src++;

	*destination = *src; /* Copy the null terminator */
	return (ret);
}

/**
 * my_strcpy - This function copies a string from source to destination.
 * @destination: Is the destination string where 'src' will be copied to.
 * @src: Is the source string to be copied.
 *
 * Return: A pointer to the destination string
 */
char *my_strcpy(char *destination, char *src)
{
	int index = 0;

	if (destination == src || src == 0)
		return (destination);

	/* Copy characters from 'src' to 'destination' */
	while (src[index])
	{
		destination[index] = src[index];
		index++;
	}
	/* Add null terminator to the destination string */
	destination[index] = 0;
	return (destination);
}

/**
 * my_strdup - duplicates a string
 * @str: the string to makeTwo
 *
 * Return: pointer to the duplicated string
 */
char *my_strdup(const char *str)
{
	int length = 0;
	char *makeTwo;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the string */
	while (*str++)
		length++;

	/* Allocate memory for the makeTwo string */
	makeTwo = malloc(sizeof(char) * (length + 1));
	if (!makeTwo)
		return (NULL);

	/* Copy the string in reverse order to the makeTwo */
	for (length++; length--;)
		makeTwo[length] = *--str;
	return (makeTwo);
}

/**
 * my_str - This fn copies up to 'n' characters from source
 * to destination.
 *
 * @destination: Is the destination string where 'src' will be copied to.
 * @src: Is the source string to be copied.
 * @n: is the maximum number of characters to be copied.
 *
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
 * replace_str - Replaces the content of a pointer to a string
 * with a new string.
 *
 * @old: Pointer to the old string to be replaced.
 * @new: The new string to replace the old string.
 *
 * Return: 1 upon successful replacement, 0 otherwise.
 */
int replace_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

