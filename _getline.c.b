#include "shell.h"
/**
 * _getline - function that read the input
 * Return:
 */

char* _getline(void) 
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index = 0;
	static int n_chars_in_buff = 0;

	char *line = NULL;
	int line_index = 0;
	int read_result = 0;

	while (1) 
	{
		if (buffer_index == n_chars_in_buff)
		n_chars_in_buff = read(0, buffer, BUFFER_SIZE);
		buffer_index = 0;
		
		if (n_chars_in_buff <= 0) 
		{
			if (line_index > 0) 
			{
				line[line_index] = '\0';
			}
			return (line);
		}
	}

	if (line_index % BUFFER_SIZE == 0) 
	{
		line = (char*)realloc(line, (line_index + BUFFER_SIZE) * sizeof(char));
		if (!line) 
		{
			fprintf(stderr, "Memory allocation error.\n");
			exit(EXIT_FAILURE);
		}
	}

	while (buffer_index < n_chars_in_buff) 
	{
		char current_char = buffer[buffer_index++];
		if (current_char == '\n') 
		{
			line[line_index++] = '\0'; // Null-terminate the line
			return (line);
		}
		line[line_index++] = current_char;
	}
}

