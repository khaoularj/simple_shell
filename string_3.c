#include "shell.h"
/**
 * my_strcat - concatenates two strings
 * @destination: the destination string
 * @src:the source string to be appended
 * Return: Pointer to the concatenated string
 */
char *my_strcat(char *destination, char *src)
{
        char *ret = destination;

        while (*destination)
                destination++;

        while (*src)
                *destination++ = *src++;

        *destination = *src;
        return (ret);
}

/**
 * my_strcpy - copies a string from source to destination.
 * @destination: destination string
 * @src: the source string to be copied.
 * Return: A pointer to the destination string
 */
char *my_strcpy(char *destination, char *src)
{
        int index = 0;

        if (destination == src || src == 0)
                return (destination);

        while (src[index])
        {
                destination[index] = src[index];
                index++;
        }
        destination[index] = 0;
        return (destination);
}

