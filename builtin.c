#include "shell.h"

/**
 * builtin_handler - function that checks for and execute builtin commands
 * @command: points to the input command
 * Return: 1 if successful, and 0 if failed
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
 * _terminate - function that teminates the shell process
 * @process: the shell process ID
 * Return: void
 */
void _terminate(pid_t process)
{
	exit(process);
}

/**
 * _env - prints out the environment variables
 * Return: number of varibles that was read
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
