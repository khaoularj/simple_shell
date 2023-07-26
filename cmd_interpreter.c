#include "shell.h"
int cmd_interpreter(void)
{
        int status = 0;
        char *buffer = NULL;
        pid_t pid;
        char *cmd;
        while(1)
        {
                char **args = display_prompt();
                if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
                {
                        /*free(args);*/
                        /*free(buffer);*/
                        exit(EXIT_FAILURE);
                        /*return(0);*/
                }


                pid = fork();
                /*check if it's a child process*/
                if (pid == 0)
                {
                        /*Execute the command using execve*/
                        /*int val = execve(args[0], args, environ);

                        if (val == -1)
                        {
                                perror("./shell");
                                exit(EXIT_FAILURE);
                        }*/
                        setenv("PATH","/bin/",1);
                        cmd = strcat(getenv("PATH"),args[0]);

                        if (execve(cmd, args, environ) == -1)
                        {
                                perror(getenv("_"));
                                _exit(EXIT_FAILURE);
                        }
                }
                /*check if Fork failed*/
                else if (pid == -1)
                {
                        perror("fork failed");
                }
                /*check if it's the Parent process*/
                else
                {
                        /*Wait for the child process to complete*/
                        wait(&status);
                        /*Free the memory allocated for the array*/
                        free(args);
                }
                }
        free(buffer);
        return (0);
}
