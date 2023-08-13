#ifndef SHELL_H_
#define SHELL_H_

#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>

extern char **environ;

int _putchar(char c);
void _exec(char **args);
char **split_line(char *line);
char *read_line();
void print_env(void);
int _printf(const char *format, ...);
int _puts(const char *str);
void _printfs(const char *format, ...);
int my_strcmp(const char *str1, const char *str2);
void _execme(char **args);
#endif /*SHELL_H_*/
