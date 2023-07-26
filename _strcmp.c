#include "shell.h"
/**
 * _strcmp - function that compares two string
 * @s1: the first string
 * @s2: the second string
 *
 * Return: return zero if s1 == s2, negative if if s1 < s2,and positive if s1 > s2,
 */
int _strcmp(char *s1, char *s2)
{
        while (*s1 && *s2)
        {
                if (*s1 != *s2)
                        return (*s1 - *s2);
                s1++;
                s2++;
        }
        if (*s1 == *s2)
                return (0);
        else
                return (*s1 < *s2 ? -1 : 1);
}
