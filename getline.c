#include "shell.h"

/**
 * _get_command - gets input from the terminal
 * Return: pointer to the input
 */
char *_get_command(void)
{
	char *buff;
	size_t buff_size;
	ssize_t len;

	printf("$ ");
	len = getline(&buff, &buff_size, stdin);

	if (buff[len - 1] == '\n')
	{
		buff[len - 1] = '\0';
	}
	return (buff);
}

/**
 * _tokenizer - spilts the input string into an array of strings
 * @str: pointer to the input string
 * Return: number of extracted string
 */
int _tokenizer(char *str)
{
	char **arg = NULL;
	size_t ind = 0;
	char *token;
	pid_t exe_process;

	token = strtok(str, " ");

	while (token != NULL)
	{
		arg = realloc(arg, (ind + 1) * sizeof(char *));

		if (arg == NULL)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		arg[ind++] = token;
		token = strtok(NULL, " ");
	}
	arg[ind] = NULL;

	if (fork() == 0)
	{
		exe_process = getpid();

		execve(str, arg, NULL);
		_print("No such file or directory exist\n");
		exit(EXIT_FAILURE);
	}
	else
		wait(&exe_process);
	return (0);
}
