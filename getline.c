#include "shell.h"

/**
 * wnct - counts the number of words in a string
 * @s: the target string
 * Return: count number
 */
int wcnt(const char *s)
{
	int i = 0;
	int cnt = 0;

	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] != '\0')
			cnt++;
		i++;
	}

	return (++cnt);
}

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

	if (len == -1)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
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
	int cnt;
	pid_t exe_process;

	cnt = wcnt(str);
	token = strtok(str, " ");
	if (!(_strcmp(token, "exit")))
		_terminate(getpid());
	arg = malloc(sizeof(char *) * (cnt + 1));

	if (!arg)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		arg[ind++] = token;
		token = strtok(NULL, " ");
	}
	arg[ind] = NULL;

	if (fork() == 0)
	{
		exe_process = getpid();

		execve(str, arg, NULL);
		_execute_path(str, arg);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&exe_process);
	}
	return (0);
}
