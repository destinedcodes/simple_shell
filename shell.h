#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <limits.h>
#define _INT_MIN (1 << (sizeof(int) * 8 - 1))
typedef struct path
{
	char *dir;
	struct path *next;
} path;

path *initpath(void);
path *printpath(path *head);
char *findpath(void);
int handle_builtin(void);
int arraycpy(char *dest[], char *src[]);
int execute_command(void);
int printarray(char *array[]);
char *_getenv(char *);
void free_array(char **arr);
path *printlist(path *head);
int _fputchar(int fd, char c);
int _fputint(int fd, int num);
int _fputstr(int fd, char *str);
int _fprintf(int fd, const char *format, ...);
char **strtoarr(char *str, char delim);
int print_prompt(char *prompt);
ssize_t _getline(char **line);
ssize_t _getchar(char c);
int exit_stat(char *exit_status);
int _atoi(const char *str);

extern char **environ;
int status;
char *line;
char **command;
int shell_index;
char *shell;

#endif /* SHELL_H */
