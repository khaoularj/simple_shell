#include "shell.h"

/**
 * _strlen - This function calculates the size of a string
 * @string: is the string to be calculated
 *
 * Return: integer length of string
 */
int _strlen(char *string)
{
	int count = 0;

	if (!string)
		return (0);

	while (*string++)
		count++;
	return (count);
}

/**
 * my_strcopy - This function compares two strings
 * @string: Is the first string
 * @str2: Is the second string
 *
 * Return: integer difference between strings
 */
int my_strcopy(char *string1, char *str2)
{
	while (*string1 && *str2)
	{
		/* Compare characters of 'string1' and 'str2' */
		if (*string1 != *str2)
			return (*string1 - *str2);
		string1++;
		str2++;
	}

	/* Check for equality after the loop */
	if (*string1 == *str2)
		return (0);
	else
		return (*string1 < *str2 ? -1 : 1);
}

/**
 * starts_with - This function check if a string starts with a specific
 * substring
 *
 * @haystack: Is the string to search within
 * @needle: Is the substring to search for
 *
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
 **my_strncat - This function is a custom implementation of strncat
 *@destination: Is the first string
 *@src: Is the second string
 *@bytes: Is the number of bytes to concatenate
 *Return: (s) a pointer to the memory area s
 */
char *my_strncat(char *destination, char *src, int bytes)
{
	int i = 0, j = 0;
	char *s = destination;

	/* Find the length of the destination string */
	while (destination[i] != '\0')
		i++;

	/* Append characters from 'src' to 'destination' until 'bytes' limit */
	while (src[j] != '\0' && j < bytes)
	{
		destination[i] = src[j];
		i++;
		j++;
	}

	/* Add null terminator if the number of appended characters < 'bytes' */
	if (j < bytes)
		destination[i] = '\0';
	return (s);
}

/**
 * my_strchr - Locates the first occurrence of a character in a string.
 * @string: The string to be searched.
 * @c: The character to be located.
 *
 * Return: Pointer to the first occurrence of the character 'c' in the
 *         string 'string', or NULL if the character is not found.
 */
char *my_strchr(char *string, char c)
{
	/* Loop through the string until the end or until character 'c' is found */
	do {
		if (*string == c)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}

