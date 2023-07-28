#include "shell.h"

/**
 * my_print_string - The function that prints a string to standard output
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
 * linkedList_print - function that prints a linked list of str
 * @pointer_head:pointer to the pointer_head of the linked list
 * Return: n of nodes in the linked list
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
