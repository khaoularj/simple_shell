#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*Buffer_macros*/
#define BFLUSH -1
#define WR_BSIZE 1024
#define RD_BSIZE 1024

/*Cmd chaining*/
#define NORM_CMD 0
#define OR_CMD 1
#define AND_CMD 2
#define CHAIN_CMD 3

/*System_getline*/
#define STR_TOK 0
#define GET_LINE 0
#define MAX_HIST 4096
#define FILE_HIST ".simple_shell_history"

/*Case_Conversion*/
#define CONVTO_LOWER 1
#define CONVERT_UNSIGNED 2

/*External Env*/
extern char **environ;

/**
 * struct strlist - function to link the string list
 * @num: the filed number
 * @str: string to handle
 * @next:is a pointer to the next node
 */
typedef struct strlist
{
	int num;
	char *str;
	struct strlist *next;
} strl_t;

/**
 * struct passto - pass the commandline arguments to a function
 * for allowing prototype to uniform structure functions
 * @filename: filename for a program
 * @argc: is number of command line arguments
 * @argv: is an array of strings to be obtained from args with cmd line infoma
 * @arg: is a string containing command line arguments by getline
 * @path: is a path of current command
 * @env: is linked list of copy of all environment from environ
 * @environ:copy of external local env
 * @changed_env: is a changed environment (environ)
 * @history: is node of histry containing histry
 * @alias: is node of alias in local environment
 * @status: is a status to be returned for condition of shell loop by execve
 * @bf_cmd: on chaining as address of pointer of bf_cmd
 * @cmdbf_type: is command type for OR (||), AND (&&), (;)
 * @readfd: is read line input for fdcr
 * @count_line: is a counter for error line
 * @nerror: error number for exit() functions
 * @countline_flag: is flag counter in line command
 * @count_hist: is for counting number of line history
 */
typedef struct passto
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int count_line;
	int nerror;
	int countline_flag;
	char *filename;
	strl_t *env;
	strl_t *history;
	strl_t *alias;
	char **environ;
	int changed_env;
	int status;
	char **bf_cmd;
	int cmdbf_type;
	int readfd;
	int count_hist;
} maindt;

#define INIT_INFORMA \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
/**
 * struct builtins - cointains a functions related to builtins struct;
 * @type: is type of builtin command;
 * @fx: is our function acronmy;
 */
typedef struct builtins
{
	char *type;
	int (*fx)(maindt *);
} built_table;

/* shell.c prototypes */
int main(int ac, char **av);

/* print_1.c */
void my_print_string(char *str);
size_t linkedList_print(const strl_t *head);

/* print_2.c*/
size_t print_Linkedlist(const strl_t *head);
void _puts(char *str);

/* string_1.c */
int _strlen(char *s);
int my_strcopy(char *str1, char *str2);

/* string_2.c*/
char *starts_with(const char *haystack, const char *needle);
char *my_strncat(char *dest, char *src, int bytes);
char *my_strchr(char *str, char c);

/* string_3.c*/
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char *src);

/* string_4.c*/
char *my_strdup(const char *str);
char *my_str(char *dest, char *src, int n);
int replace_str(char **old, char *new);

/* print_3.c*/
int float_print(int input, int file_d);
int my_putchar(char c);

/* print_4.c*/
int custom_error_putchar(char c);
int my_fd(char c, int fdcr);
int my_putsfd(char *str, int fdcr);

/* cmd_1.c */
int my_findCmd(maindt *infoma);
int hsh(maindt *infoma, char **av);
/* cmd_2.c */
char *set_mem(char *s, char b, unsigned int n);
void doubly_free(char **pp);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* cmd_3.c */
void my_fork(maindt *infoma);
int check_exec(maindt *infoma, char *path);

/* cmd_4.c*/
char *char_dup(char *path_txt, int start, int stop);
void findexec_cmd(maindt *infoma);

/* cmd_5.c */
char *my_findPath(maindt *infoma, char *path_txt, char *cmd);
int is_interactive(maindt *infoma);

/* cmd_6.c*/
int is_delimeter(char c, char *delim);
void myPrint_error(maindt *infoma, char *estr);

/* _exit.c */
int quit_shell(maindt *infoma);

/* env_1.c */
int myenvPtr(maindt *infoma);
char *environ_getter(maindt *infoma, const char *name);

/* env_2.c */
int env_pop(maindt *infoma);

/* getline_1.c */
ssize_t prompt_buf(maindt *infoma, char **the_buffer, size_t *length);
ssize_t user_inputGet(maindt *infoma);

/* getline_2.c */
ssize_t bffRead(maindt *infoma, char *the_buffer, size_t *i);
int myown_getline(maindt *infoma, char **ptr, size_t *length);
void intsng_handle(__attribute__((unused)) int sig_num);

/* strtok_1.c */
char **mystr_twords(char *str, char *delimiters);

/* strtok_2.c */
int mybffFree(void **ptr);
char *long_strcvrt(long int num, int base, int flags);

/* _exit_args.c */
int cnvstr_int(char *str);

/* setunset_env_1.c */
int myownSetenv(maindt *infoma);
int myownUnsetenv(maindt *infoma);
char **env_finder(maindt *infoma);

/* setunset_env_2.c */
int UnsetenvCustom(maindt *infoma, char *var);
int setenv_custom(maindt *infoma, char *var, char *value);

/* my_cd.c */
int myCd(maindt *infoma);
int my_help(maindt *infoma);

/* check_cmd.c */
int funIs_chain(maindt *infoma, char *buffer, size_t *pt);
void funCheck(maindt *infoma, char *buffer,
				   size_t *pt, size_t i, size_t len);

/* allias_1.c */
int myAlias_make(maindt *infoma, char *str);
int dontmkmy_alias(maindt *infoma, char *str);

/* allias_2.c */
int replaceAlias(maindt *infoma);
int ptrcmy_alias(strl_t *node);
int my_alias(maindt *infoma);

/* vars_1.c */
int replace_Myvar(maindt *infoma);
void mystrutct_set(maindt *infoma, char **av);

/* vars_2.c */
void myStr_free(maindt *infoma, int yes);
void struct_clear(maindt *infoma);

/* han_comments.c */
void commentRmv(char *buffer);

/* _hist_1.c */
char *myfl_His(maindt *infoma);
int appendHis(maindt *infoma);

/* _hist_2.c */
int historyRead(maindt *infoma);
int entryLs(maindt *infoma, char *buffer, int linecounts);
int hiscnt_nmb(maindt *infoma);

/* ls_1.c */
strl_t *myAddnd(strl_t **head, const char *str, int num);
strl_t *endmyAddnd(strl_t **head, const char *str, int num);

/* ls_2.c*/
int ndIndex_del(strl_t **head, unsigned int index);
void allListnd(strl_t **p_hd);

/* main_his_1.c */
int cmdHis(maindt *infoma);
size_t fdlistLen(const strl_t *h);

/* main_his_2.c */
char **Allstr_ls(strl_t *head);

/* _fnodes.c */
strl_t *ndStart(strl_t *node, char *prefix, char c);
ssize_t numbernd(strl_t *head, strl_t *node);

#endif

