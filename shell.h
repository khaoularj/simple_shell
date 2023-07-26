#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>

char **display_prompt(void);
int cmd_interpreter(void);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
extern char **environ;

#endif
