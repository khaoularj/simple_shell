#include "shell.h"
/**
 * display_prompt - the function that display a prompt
 */
char **display_prompt(void)
{

        bool from_terminal = isatty(STDIN_FILENO);
        char *buffer = NULL;
        size_t buffer_size = 0;
        int n_char = 0;
        char *token;
        char **args;
        int i = 0;

            /*Check if input is from a terminal*/
                if (from_terminal)
                /*Print shell prompt*/
                {
                        write(1, "$ ", 2);
                }
                n_char = getline(&buffer, &buffer_size, stdin);

                if (n_char == EOF)
                {
                        exit(EXIT_FAILURE);
                }
                else
                {
                        /*Replace the newline character with a null terminator*/
                        buffer[n_char - 1] = '\0';

                        /*Allocate memory for the array of tokens(arguments)*/
                        args = malloc(sizeof(char *) * _strlen(buffer));

                        /*Tokenize the input using space, tab, and newline as delimiters*/
                        token = strtok(buffer, " \t\n");

                while (token)
                {
                        /*Store each token in the array*/
                        args[i] = token;
                        token = strtok(NULL, " \t\n");
                        i++;
                }
                /*set the last element of the array to NULL to mark the end*/
                args[i] = NULL;

                }
        return(args);
}
