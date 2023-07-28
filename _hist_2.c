#include "shell.h"
/**
 * historyRead - is a function to read the file history;
 * @data: is informant of maindt structure;
 *
 * Return: counts of history's file otherwise 0;
 */
int historyRead(maindt *data)
{
	int i, final = 0, counter = 0;
	ssize_t fdc, lents, fsize = 0;
	struct stat st;
	char *bff = NULL, *file_hist = myfl_His(data);

	if (!file_hist)
		return (0);
	fdc = open(file_hist, O_RDONLY);
	free(file_hist);
	if (fdc == -1)
		return (0);
	if (!fstat(fdc, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	bff = malloc(sizeof(char) * (fsize + 1));
	if (!bff)
		return (0);
	lents = read(fdc, bff, fsize);
	bff[fsize] = 0;
	if (lents <= 0)
		return (free(bff), 0);
	close(fdc);
	for (i = 0; i < fsize; i++)
		if (bff[i] == '\n')
		{
			bff[i] = 0;
			entryLs(data, bff + final, counter++);
			final = i + 1;
		}
	if (final != i)
		entryLs(data, bff + final, counter++);
	free(bff);
	data->count_hist = counter;
	while (data->count_hist-- >= MAX_HIST)
		ndIndex_del(&(data->history), 0);
	hiscnt_nmb(data);

	return (data->count_hist);
}

/**
 * entryLs - is a function to add entry of linked list;
 * @data: is a structure informant for maindt struct;
 * @bff: is a bff of string;
 * @counter: history counts from count_hist;
 *
 * Return: value 0 for sucess;
 */
int entryLs(maindt *data, char *bff, int counter)
{
	strl_t *fnode = NULL;

	if (data->history)
		fnode = data->history;

	endmyAddnd(&fnode, bff, counter);

	if (!data->history)
		data->history = fnode;

	return (0);
}

/**
 * hiscnt_nmb - is a func to renumber file history after chages;
 * @data: is a structure informant for maindt struct;
 *
 * Return: history counts from count_hist;
 */
int hiscnt_nmb(maindt *data)
{
	strl_t *fnode = data->history;
	int x = 0;

	while (fnode)
	{
		fnode->num = x++;
		fnode = fnode->next;
	}

	return (data->count_hist = x);
}
