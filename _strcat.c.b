#include "shell.h"
/**
 * _strcat - concatenates two strings
 *@dest: the destination
 *@src: the source
 * Return: pointer to destination
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
