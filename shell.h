#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * struct all_path - Linked list that containing PATH dir
 * @dir: dir in path
 * @p: pointer to next node
 */
typedef struct all_path
{
        char *dir;
        struct all_path *p;
} all_path;


int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);

char **funSplit_string(char *str, const char *delim);
void funexec_cmd(char **argv);
void *funRealloc(void *ptr, unsigned int old_size, unsigned int new_size);

extern char **environ;


char *my_getenv(const char *name);
all_path *new_Node_add(all_path **head, char *str);
all_path *node_linkPath(char *path);
char *findPathcmd(char *filename, all_path *head);

/**
 * struct mybuild - pointer to function
 * @name: buildin command
 * @func: funexec_cmd the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

void(*checkbuild(char **arv))(char **arv);
int fun_atoi(char *s);
void _myexit(char **arv);
void env(char **arv);
void set_enviroment(char **arv);
void unset_enviroment(char **arv);

void myfree(char **arv);
void bfree(all_path *head);

#endif
