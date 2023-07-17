#include "shell.h"

/**
 * _strlen - the function that returns the length of a string
 * @s:string
 * Return: the lenght of string
 */

int _strlen(char *s)
{
	int x;
	int count = 0;

	for (x = 0 ; s[x] != '\0' ; x++)
	{
		count++;
	}
	return (count);
}
