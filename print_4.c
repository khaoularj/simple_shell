#include "shell.h"
/**
 * custom_error_putchar - function that prints a character
 * @c: The character to be written.
 * Return: 1 on success.
 */
int custom_error_putchar(char c)
{
	static int number;
	static char buf[WR_BSIZE];

	if (c == BFLUSH || number >= WR_BSIZE)
	{
		write(2, buf, number);
		number = 0;
	}
	if (c != BFLUSH)
		buf[number++] = c;
	return (1);
}

/**
 * my_fd - Writes character to a specified file descriptor
 * @c: The character to be written.
 * @fdcr: The file descriptor
 * Return: 1 on success.
 */
int my_fd(char c, int fdcr)
{
	static int j;
	static char buf[WR_BSIZE];

	if (c == BFLUSH || j >= WR_BSIZE)
	{
		write(fdcr, buf, j);
		j = 0;
	}
	if (c != BFLUSH)
		buf[j++] = c;
	return (1);
}

/**
 * my_putsfd - Writes a string to a specified file descriptor.
 * @string: The string to be written.
 * @fdcr: The file descriptor to write the string to.
 * Return: The n of char written on success, 0 if NULL.
 */
int my_putsfd(char *string, int fdcr)
{
	int j = 0;

	if (!string)
		return (0);
	while (*string)
	{
		j += my_fd(*string++, fdcr);
	}
	return (j);
}
