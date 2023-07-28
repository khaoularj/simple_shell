#include "shell.h"

/**
 * main - This function is the entry point for a simple shell
 * @argc: Is the number of arguments
 * @argv: Is the argument vector (array of strings)
 *
 * Return: 0 on success, 1 on error, or error code
 */
int main(int argc, char **argv)
{
	maindt infoma[] = {INIT_INFORMA};
	int fDes= 2;

	/* This is a hack to get the file descriptor for stderr */
	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fDes)
		: "r"(fDes));

	/* Set up the infoma struct */
	if (argc == 2)
	{
		fDes= open(argv[1], O_RDONLY);
		if (fDes== -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				my_print_string(argv[0]);
				my_print_string(": 0: Can't open ");
				my_print_string(argv[1]);
				custom_error_putchar('\n');
				custom_error_putchar(BFLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		infoma->readfd = fDes;
	}
	env_pop(infoma);
	historyRead(infoma);
	hsh(infoma, argv);
	return (EXIT_SUCCESS);
}
