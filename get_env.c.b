#include "shell.h"
/**
 * my_getenv - gets the env_content of the global variable
 * @var_name: name of the global variable
 * Return: string of env_content
 */
char *my_getenv(const char *var_name)
{
	int i, j;
	char *env_content;

	if (!var_name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (var_name[j] == environ[i][j])
		{
			while (var_name[j])
			{
				if (var_name[j] != environ[i][j])
					break;

				j++;
			}
			if (var_name[j] == '\0')
			{
				env_content = (environ[i] + j + 1);
				return (env_content);
			}
		}
	}
	return (0);
}
