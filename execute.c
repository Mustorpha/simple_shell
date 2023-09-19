#include "shell.h"

/**
 * _execute_path - executes command using path
 * @command: points to command requested command
 * @args: pointer to the array of commands
 * Return: void
 */
void _execute_path(char *command, char **args)
{
	char *path;
	char *path_copy;
	char *token;
	char cmd_path[MAX_INPUT_SIZE];

	path = _getenv("PATH");
	path_copy = _strdup(path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		_strcpy(cmd_path, token);
		strcat(cmd_path, "/");
		strcat(cmd_path, command);
		execve(cmd_path, args, NULL);
		token = strtok(NULL, ":");
	}
	_printerr("No such file or directory\n");
	free(path_copy);
}
