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
#include <dirent.h>

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
void def_fprintf(FILE *stream, const char *format, ...);
int def_vsnprintf(char *buffer, size_t buf_size,
		  const char *format, va_list args);
int def_setenv(const char *variable, const char *value);
int def_unsetenv(const char *variable);
int def_fputs(const char *str, FILE *stream);
void def_current_dir(void);
int is_valid_command(const char *command);
#endif /*SHELL_H_*/
