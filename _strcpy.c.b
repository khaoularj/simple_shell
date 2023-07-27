#include "shell.h"
/**
 * _strcpy - the function that copies the string
 * @dest: the destination of the array
 * @src: the source of array
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int x;

	if (dest == 0)
		return (dest);

	for (x = 0 ; src[x] != '\0' ; x++)
		dest[x] = src[x];
	return (dest);
}
