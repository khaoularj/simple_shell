#include "shell.h"

/**
 * funCheck - is a function for checking
 * continous chaining by on last status;
 * @data: is informant structure of maindt struct parameter;
 * @bff: is a bff to be used;
 * @pointer: is a pointer to the current index of bff to be used;
 * @i: is index at starting point in bff to be used;
 * @len: is a length size of bff to be used;
 *
 * Return: nothing;
 */
void funCheck(maindt *data, char *bff,
				size_t *pointer, size_t i, size_t len)
{
	size_t y = *pointer;

	if (data->cmdbf_type == AND_CMD)
	{
		if (data->status)
		{
			bff[i] = 0;
			y = len;/* equalizing current to the length at last */
		}
	}

	if (data->cmdbf_type == OR_CMD)
	{
		if (!data->status)
		{
			bff[i] = 0;
			y = len;/* equalizing current to the length at last */
		}
	}

	*pointer = y;
}

/**
 * funIs_chain - is a function to check if a char is a chain delim;
 * @data: is informant structure of maindt struct parameter;
 * @bff: is a bff to be used;
 * @pointer: is a pointer to the current index of bff to be used;
 *
 * Return: value 1 if it is chain delimeter otherwise 0 for false.
 */
int funIs_chain(maindt *data, char *bff, size_t *pointer)
{
	size_t y = *pointer;

	if (bff[y] == '|' && bff[y + 1] == '|')
	{
		bff[y] = 0; /* if found at the end of command increement */
		y++;

		data->cmdbf_type = OR_CMD; /* for choosing one of cmd */
	}
	else if (bff[y] == '&' && bff[y + 1] == '&')
	{
		bff[y] = 0; /* if found at the end of command increement */
		y++;

		data->cmdbf_type = AND_CMD; /* for adding new command */
	}
	else if (bff[y] == ';') /* if found at the end of command */
	{
		bff[y] = 0; /* will be replaced by null at cmd line */
		data->cmdbf_type = CHAIN_CMD;
	}
	else
		return (0);
	*pointer = y;

	return (1);
}
