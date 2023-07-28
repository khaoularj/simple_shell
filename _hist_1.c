#include "shell.h"
/**
 * myfl_His - a function to find file history;
 * @data: is informant structure;
 *
 * Return: file's history in form of string.
 */

char *myfl_His(maindt *data)
{
	char *bff, *drect;

	drect = environ_getter(data, "HOME=");
	if (drect == NULL)
		return (NULL);

	bff = malloc(sizeof(char) * (_strlen(drect) + _strlen(FILE_HIST) + 2));
	if (!bff)
		return (NULL);

	bff[0] = 0;
	my_strcpy(bff, drect);
	my_strcat(bff, "/");
	my_strcat(bff, FILE_HIST);

	return (bff);
}

/**
 * appendHis - is a function to create or append history of a file;
 * @data: is informant of inft_t structure;
 *
 * Return: value 1 for success otherwise -1;
 */
int appendHis(maindt *data)
{
	char *file_hist = myfl_His(data);
	ssize_t fdc;
	strl_t *fnode = NULL;

	if (!file_hist)
		return (-1);

	fdc = open(file_hist, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file_hist);
	if (fdc == -1)
		return (-1);

	fnode = data->history;
	while (fnode)
	{
		my_putsfd(fnode->str, fdc);
		my_fd('\n', fdc);
		fnode = fnode->next;
	}
	my_fd(BFLUSH, fdc);
	close(fdc);

	return (1);
}
