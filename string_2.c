#include "shell.h"
/**
 * starts_with - function that check if a string starts with a substring
 * @haystack: string to search within
 * @needle: substring to search for
 * Return: pointer to the start of the substring or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 **my_strncat - implementation of strncat
 *@destination: 1st string
 *@src: 2nd string
 *@bytes: n of bytes to concatenate
 *Return: pointer to the memory area
 */
char *my_strncat(char *destination, char *src, int bytes)
{
	int i = 0, j = 0;
	char *s = destination;

	while (destination[i] != '\0')
		i++;

	while (src[j] != '\0' && j < bytes)
	{
		destination[i] = src[j];
		i++;
		j++;
	}

	if (j < bytes)
		destination[i] = '\0';
	return (s);
}

/**
 * my_strchr - Locates the first occurrence of a character in a string.
 * @string: string to be searched.
 * @c: character to be located.
 * Return: Pointer to the first occurrence in string, or NULL if 'c' is not found.
 */
char *my_strchr(char *string, char c)
{
	do {
		if (*string == c)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
