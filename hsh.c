#include "shell.h"
/**
 * main - the main hsh function
 * @argc:argument count
 * @argv:argument vector
 * @envp:environment
 *Return: 0
 */
int main(int argc, char *argv[], char **envp)
{
	(void)argc;
	(void)argv;
	cmd_interpreter(envp);
	return (0);
}
