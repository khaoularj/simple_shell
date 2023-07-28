#include"shell.h"
/**
 * unset_enviroment - function that remove an env var
 * @vector: entered words
 */
void unset_enviroment(char **vector)
{
	int i, j;

	if (!vector[1])
	{
		perror(my_getenv("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (vector[1][j] == environ[i][j])
		{
			while (vector[1][j])
			{
				if (vector[1][j] != environ[i][j])
					break;

				j++;
			}
			if (vector[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

