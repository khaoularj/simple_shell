#include"shell.h"
/**
 * set_enviroment - Initialize a new env var
 * @vector: entered words
 */
void set_enviroment(char **vector)
{
	int i, j, k;

	if (!vector[1] || !vector[2])
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
				k = 0;
				while (vector[2][k])
				{
					environ[i][j + 1 + k] = vector[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = concat_all(vector[1], "=", vector[2]);
		environ[i + 1] = '\0';

	}
}
