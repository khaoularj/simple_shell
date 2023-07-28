#include "shell.h"

/**
 * my_print_string - This function prints a string to standard output
 * @string: The string to be printed
 * Return: void
 */
void my_print_string(char *strings)
{
	int number = 0;

	if (!strings)
		return;
	while (strings[number] != '\0')
	{
		custom_error_putchar(strings[number]);
		number++;
	}
}

/**
 * linkedList_print - This function prints a linked list of strings
 * @pointer_head: Is the pointer to the pointer_head of the linked list
 *
 * Return: The number of nodes in the linked list
 */
size_t linkedList_print(const strl_t *pointer_head)
{
	size_t count = 0;

	while (pointer_head)
	{
		_puts(pointer_head->str ? pointer_head->str : "(nil)");
		_puts("\n");
		pointer_head = pointer_head->next;
		count++;
	}
	return (count);
}

/**
 * print_Linkedlist - This function prints a linked list of structures
 * @pointer_head: Is a pointer to the pointer_head of the linked list
 *
 * Return: The number of nodes in the linked list
 */
size_t print_Linkedlist(const strl_t *pointer_head)
{
	size_t i = 0;

	while (pointer_head)
	{
		_puts(long_strcvrt(pointer_head->num, 10, 0));
		my_putchar(':');
		my_putchar(' ');
		_puts(pointer_head->str ? pointer_head->str : "(nil)");
		_puts("\n");
		pointer_head = pointer_head->next;
		i++;
	}
	return (i);
}

/**
 * _puts - This function prints a string to standard output
 * @str: Is the sting to print
 *
 * Return: void
 */
void _puts(char *string)
{
	int number = 0;

	if (!string)
		return;
	while (string[number] != '\0')
	{
		my_putchar(string[number]);
		number++;
	}
}

