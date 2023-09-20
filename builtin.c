#include "shell.h"

/**
 * builtin_handler - function that checks for and execute builtin commands
 * @command: points to the input command
 * Return: 1 if successful, and 0 if failed
 */
int builtin_handler(char  *command)
{
	char *name, *value = NULL;

	if (!(_strcmp(command, "exit")))
	{
		_terminate();
		return (-1);
	}
	if (!(_strcmp(command, "env")))
		return (_env());
	if (!(_strcmp(command, "setenv")))
	{
		name = _strtok(NULL, " ");
		value = _strtok(NULL, " ");

		return (_setenv(name, value, 1));
	}
	if (!(_strcmp(command, "unsetenv")))
		return (_unsetenv(_strtok(NULL, " ")));
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = d = n = f = len = digit =  0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
 * _terminate - function that teminates the shell process
 * Return: void
 */
void _terminate(void)
{
	int status;
	char *stat_value = NULL;

	stat_value = (char *)_strtok(NULL, " \t\n\r");

	if (stat_value)
		status = _atoi(stat_value);
	if (status)
		exit(status);
	else
		exit(EXIT_SUCCESS);
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
