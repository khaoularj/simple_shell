#include "shell.h"
/**
 * float_print - function prints a decimal (base 10)
 * @data: the data
 * @file_d: the filedescriptor
 * Return: n of char printed
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
                        __putchar('0' + current / i);
                        count++;
                }
                current %= i;
        }
        __putchar('0' + current);
        count++;

        return (count);
}

/**
 * my_putchar - Writes a character to the stdout.
 * @c: The character to be written.
 * Return: 1 on success.
 */
int my_putchar(char c)
{
        static int number;
        static char buffer[WR_BSIZE];

        if (c == BFLUSH || number >= WR_BSIZE)
        {
                write(1, buffer, number);
                number = 0;
        }
        if (c != BFLUSH)
                buffer[number++] = c;
        return (1);
}
