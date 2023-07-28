#include"shell.h"
/**
* *checkbuild- checks if the command is a buildin
* @vector: array of arguments
* Return: pointer to function that takes vector and returns void
*/
void(*checkbuild(char **vector))(char **vector)
{
	int i, j;
	mybuild T[] = {
		{"exit", _myexit},
		{"env", env},
		{"setenv", set_enviroment},
		{"unsetenv", unset_enviroment},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == vector[0][j])
		{
			for (j = 0; vector[0][j]; j++)
			{
				if (T[i].name[j] != vector[0][j])
					break;
			}
			if (!vector[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
