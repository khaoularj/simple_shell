#include "shell.h"


/**
 * commentRmv - is a function to remove comment
 * by replacing this '#' with '\0';
 * @bff: is a bff of a target string (comment);
 *
 * Return: value 0 for success.
 */
void commentRmv(char *bff)
{
	int j;

	for (j = 0; bff[j] != '\0'; j++)
		if (bff[j] == '#' && (!j || bff[j - 1] == ' '))
		{
			bff[j] = '\0';
			break;
		}
}
