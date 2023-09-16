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

char *_get_command();
int _tokenizer(char *str);
int _execute(char **exe);
void _print(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* SHELL HEADER  */

#endif
