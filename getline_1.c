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
