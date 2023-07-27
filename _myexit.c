#include"shell.h"
/**
 * _myexit - exits the shell with or without a return of status n
 * @vector: array of words of the entered line
 */
void _myexit(char **vector)
{
	int j, k;

	if (vector[1])
	{
		k = fun_atoi(vector[1]);
		if (k <= -1)
			k = 2;
		myfree(vector);
		exit(k);
	}
	for (j = 0; vector[j]; j++)
		free(vector[j]);
	free(vector);
	exit(0);
}
