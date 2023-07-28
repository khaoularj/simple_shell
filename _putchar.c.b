#include "shell.h"
/**
 * _putchar - function that writes the character c to stdout
 * @c: The printed char
 * Return: 1 On success
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
