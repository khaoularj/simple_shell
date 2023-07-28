#include "shell.h"

/**
 * prompt_buf - Read input from the user into a buffer.
 * @data: Pointer to the `maindt` struct.
 * @bff: Double pointer to the input buffer.
 * @lents: Pointer to the size of the input buffer.
 *
 * Return:
 *   - The number of characters read (r) if successful.
 *   - 0 if the buffer size is not 0.
 */
ssize_t prompt_buf(maindt *data, char **bff, size_t *lents)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*lents)
	{
		free(*bff); /*Free the existing buffer*/
		/*Set bff to NULL to avoid using a dangling pointer*/
		*bff = NULL;
		signal(SIGINT, intsng_handle); /*Set up the SIGINT signal handler*/
#if GET_LINE
		r = getline(bff, &len_p, stdin);
#else
		r = myown_getline(data, bff, &len_p);
#endif
		if (r > 0)
		{
			if ((*bff)[r - 1] == '\n')
			{
				/*Remove the newline character from the input line*/
				(*bff)[r - 1] = '\0';
				r--; /*Decrement the number of characters read*/
			}
			/*Set the countline_flag to indicate a new command line*/
			data->countline_flag = 1;
			commentRmv(*bff); /*Remove comments from the input line*/
			/*Add the command to the history list*/
			entryLs(data, *bff, data->count_hist++);
			/*Renumber the history list*/
			*lents = r;
			data->bf_cmd = bff;
		}
	}
	return (r);
}

/**
 * user_inputGet - Get the input from the user and process it.
 * @data: Pointer to the `maindt` struct.
 *
 * Return:
 *   - The lents of the input if successful.
 *   - -1 if an error occurred during input.
 */
ssize_t user_inputGet(maindt *data)
{
	static char *bff;
	static size_t i, j, lents;
	ssize_t read_char = 0;
	char **the_buffer_p = &(data->arg), *pt;

	my_putchar(BFLUSH); /*Flush the output buffer*/
	/*Read input into a buffer*/
	read_char = prompt_buf(data, &bff, &lents);
	if (read_char == -1)
		return (-1);
	if (lents)
	{
		j = i;
		pt = bff + i;

		/*Check for chained commands and update j accordingly*/
		funCheck(data, bff, &j, i, lents);
		while (j < lents)
		{
			/*Check if a chain operator is found*/
			if (funIs_chain(data, bff, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= lents)
		{
			i = lents = 0; /*Reset the buffer indices and lents*/
			/*Set the command buffer type to normal command*/
			data->cmdbf_type = NORM_CMD;
		}

		/*Update the input buffer pointer in data struct*/
		*the_buffer_p = pt;
		return (_strlen(pt)); /*Return the lents of the input*/
	}

	*the_buffer_p = bff; /*Store the buffer in data->arg*/
	return (read_char);			/*Return the number of characters read*/
}

/**
 * bffRead - Read data into a buffer from a file descriptor.
 * @data: Pointer to the `maindt` struct.
 * @buf: Pointer to the buffer for storing the read data.
 * @i: Pointer to the index of the buffer.
 *
 * Return:
 *   - The number of bytes read (r) if successful.
 *   - 0 if the index i is non-zero.
 *   - -1 if an error occurred during the read operation.
 */
ssize_t bffRead(maindt *data, char *buf, size_t *i)
{
	ssize_t myrByte = 0;

	if (*i)
		return (0);

	/*Read data from the file descriptor into the buffer*/
	myrByte = read(data->readfd, buf, RD_BSIZE);
	if (myrByte >= 0)
		*i = myrByte; /*Update the index of the buffer*/
	return (myrByte);
}

/**
 * myown_getline - Read a line of input from a file descriptor.
 * @data: Pointer to the `maindt` struct.
 * @pointr: Pointer to the buffer for storing the line of input.
 * @lents: Pointer to the lents of the buffer.
 *
 * Return:
 *   - The new lents of the buffer (s) if successful.
 *   - -1 if an error occurred during the read operation.
 */
int myown_getline(maindt *data, char **pointr, size_t *lents)
{
	static char buffs[RD_BSIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *pt = NULL, *new_p = NULL, *char_search;

	pt = *pointr; /*Current buffer*/
	if (pt && lents)
		s = *lents;
	if (i == len)
		i = len = 0; /*If position and lents are equal, reset them*/

	r = bffRead(data, buffs, &len); /*Read data into the buffer*/
	if (r == -1 || (r == 0 && len == 0))
		return (-1); /*Return -1 if an error occurred during the read*/
	/*Search for newline character*/
	char_search = my_strchr(buffs + i, '\n');
	/*Determine lents of the line*/
	k = char_search ? 1 + (unsigned int)(char_search - buffs) : len;
	/* Reallocate buffer for the new line */
	new_p = my_realloc(pt, s, s ? s + k : k + 1);
	if (!new_p)
		return (pt ? free(pt), -1 : -1); /*If reallocation fails, return -1*/
										 /*Copy read data to the new buffer*/
	if (s)
		my_strncat(new_p, buffs + i, k - i);
	else
		my_str(new_p, buffs + i, k - i + 1);

	s += k - i; /*Update the lents and position*/
	i = k;
	pt = new_p;

	if (lents)
		*lents = s; /*Update lents if lents pointer is provided*/
	*pointr = pt;
	return (s); /*Return new lents of the buffer*/
}

/**
 * intsng_handle - Signal handler for SIGINT (Ctrl+C) signal.
 * @mysng_nm: The signal number (unused in the function).
 *
 * Return: Nothing
 */
void intsng_handle(__attribute__((unused)) int mysng_nm)
{
	_puts("\n");
	_puts("$ ");
	my_putchar(BFLUSH);
}

