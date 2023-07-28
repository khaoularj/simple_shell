#include "shell.h"

/**
 * main - This function that execute a simple shell
 * @argc: number of arguments
 * @argv: argument vector (array of strings)
 * Return: 0 on success, 1 on error, or error code
 */
int main(int argc, char **argv)
{
	maindt infoma[] = {INIT_INFORMA};
	int fDes= 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fDes)
		: "r"(fDes));

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
