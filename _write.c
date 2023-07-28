#include "shell.h"

/**
 * float_print - function prints a decimal (integer) number (base 10)
 * @data: the data
 * @file_d: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int float_print(int data, int file_d)
{
	int (*__putchar)(char) = my_putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (file_d == STDERR_FILENO)
		__putchar = custom_error_putchar;
	if (data < 0)
	{
		_abs_ = -data;
		__putchar('-');
		count++;
	}
	else
		_abs_ = data;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i); /* Print the digit */
			count++;
		}
		current %= i; /* Update the current value */
	}
	__putchar('0' + current); /* Print the last digit */
	count++;

	return (count);
}

/**
 * my_putchar - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: 1 on success.
 */
int my_putchar(char c)
{
	static int number;
	static char buffer[WR_BSIZE];

	if (c == BFLUSH || number >= WR_BSIZE)
	{
		/* Flush the buffer */
		write(1, buffer, number);
		number = 0;
	}
	/* Store the character in the buffer */
	if (c != BFLUSH)
		buffer[number++] = c;
	return (1);
}

/**
 * custom_error_putchar - this function prints a character to the
 * standard error.
 *
 * @c: The character to be written.
 *
 * Return: 1 on success.
 */
int custom_error_putchar(char c)
{
	static int number;
	static char buf[WR_BSIZE];

	if (c == BFLUSH || number >= WR_BSIZE)
	{
		write(2, buf, number); /* Flush the buffer */
		number = 0;
	}
	/* Store the character in the buffer */
	if (c != BFLUSH)
		buf[number++] = c;
	return (1);
}

/**
 * my_fd - Writes character to a specified file descriptor
 * @c: The character to be written.
 * @fdcr: The file descriptor to write the character to.
 *
 * Return: 1 on success.
 */
int my_fd(char c, int fdcr)
{
	static int j;
	static char buf[WR_BSIZE];

	if (c == BFLUSH || j >= WR_BSIZE)
	{
		write(fdcr, buf, j); /* Flush the buffer to stderr */
		j = 0;
	}
	/* Store the character in the buffer */
	if (c != BFLUSH)
		buf[j++] = c;
	return (1);
}

/**
 * my_putsfd - Writes a string to a specified file descriptor.
 * @string: The string to be written.
 * @fdcr: The file descriptor to write the string to.
 *
 * Return: The number of characters written on success, 0 if @string is NULL.
 */
int my_putsfd(char *string, int fdcr)
{
	int j = 0;

	if (!string)
		return (0);
	while (*string)
	{
		/* Write each character to the specified file descriptor */
		j += my_fd(*string++, fdcr);
	}
	return (j);
}
