#include "shell.h"

/**
 * builtin_handler - checks for and execute builtin commands
 * @command: pointer to input command
 * Return: 1 (success) 0 (failed)
 */
int builtin_handler(char  *command)
{
	if (!(_strcmp(command, "exit")))
	{
		_terminate(getpid());
		return (1);
	}
	if (!(_strcmp(command, "env")))
	{
		return (_env());
	}
	return (0);
}

/**
 * _terminate - teminates the shell process
 * @process: the shell process ID
 * Return: void
 */
void _terminate(pid_t process)
{
	exit(process);
}

/**
 * _env - prints out the enviroment variables
 * Return: number of varibles read
 */
int _env(void)
{
	int ind;

	for (ind  = 0; environ[ind] != NULL; ind++)
	{
		_print(environ[ind]);
		_print("\n");
	}
	return (ind);
}
