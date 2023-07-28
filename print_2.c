#include "shell.h"
/**
 * print_Linkedlist - The function prints a linked list of structs
 * @pointer_head: pointer to the *head of the linked list
 * Return: n of nodes in the linked list
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
 * _puts - function prints a string to standard output
 * @str: printed string
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

