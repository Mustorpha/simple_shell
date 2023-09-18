#ifndef SHELL_H
#define SHELL_H

/* SHELL HEADER  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024

extern char **environ;

char *_get_command();
int _tokenizer(char *str);
void _print(char *str);
void _printerr(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int wcnt(const char *s);
char *_strcpy(char *dest, char *src);
char *_getenv(char *name);
void _execute_path(char *command, char **args);
char *_strdup(char *src);
void _terminate(pid_t process);
int _env(void);
int builtin_handler(char *command);
ssize_t _getline(char **buff, size_t *n, int fd);

/* SHELL HEADER  */

#endif
