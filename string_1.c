#include "shell.h"

/**
 * _strlen - give the size of a string
 * @string: string to be calculated
 * Return: integer length of string
 */
int _strlen(char *string)
{
        int count = 0;

        if (!string)
                return (0);

        while (*string++)
                count++;
        return (count);
}

/**
 * my_strcopy - function that compares two strings
 * @string: 1st string
 * @str2: 2nd string
 * Return: integer difference between strings
 */
int my_strcopy(char *string1, char *str2)
{
        while (*string1 && *str2)
        {
                if (*string1 != *str2)
                        return (*string1 - *str2);
                string1++;
                str2++;
        }

        if (*string1 == *str2)
                return (0);
        else
                return (*string1 < *str2 ? -1 : 1);
}

