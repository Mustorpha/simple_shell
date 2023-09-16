#include "shell.h"

/**
 * _execute - execute shell commands
 * @exe: a pointer to the of command
 * Return: 0 (success) 1 (failed)
 */
int _execute(char **exe)
{
	char *buff[2];

	buff[0] = *exe;
	buff[1] = NULL;

	if (execve(exe[0], buff, '\0') == -1)
	{
		perror("Error: \n");
		return (1);
	}
	return (1);
}
