#include "shell.h"

/**
 * wcnt - counts the number of words in a string
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

	len = _getline(&buff, &buff_size, STDIN_FILENO);

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
	token = _strtok(str, " ");
	if (builtin_handler(token))
		return (0);
	arg = malloc(sizeof(char *) * (cnt + 1));

	if (!arg)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		arg[ind++] = token;
		token = _strtok(NULL, " ");
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

/**
 * _getline - gets the user input from the terminal
 * @buff: pointer to the extracted command string
 * @n: size of charaters extracted
 * @fd: file descriptor of the source
 * Return: number of character extracted
 */
ssize_t _getline(char **buff, size_t *n, int fd)
{
	size_t index = 0;
	char c;
	ssize_t result;
	char *buffer;

	*n = 64;
	if (buff == NULL || n == NULL || fd < 0)
		return (-1);
	buffer = (char *)malloc(*n);
	if (buffer == NULL)
		return (-1);
	while (1)
	{
		result = read(fd, &c, 1);
		if (result < 0)
		{
			free(buffer);
			return (-1);
		}
		if (result == 0 || c == '\n')
		{
			buffer[index] = '\0';
			break;
		}
		else
			buffer[index] = c;
		index++;
		if (index >= *n - 1)
		{
			*n *= 2;
			buffer = (char *)realloc(buffer, *n);
			if (buffer == NULL)
			{
				free(buffer);
				return (-1);
			}
		}
	}
	*buff = buffer;
	return (index);
}

/**
 * _strtok - splits a string into parts
 * @str: pointer to the string
 * @delim: preffered delimeter
 * Return: string part in order
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *token;
	char *delimPtr;

	lastToken = NULL;
	if (str != NULL)
		lastToken = str;
	else if (lastToken == NULL)
		return (NULL);
	token = lastToken;

	while (*lastToken)
	{
		delimPtr = (char *)delim;

		while (*delimPtr)
		{
			if (*lastToken == *delimPtr)
			{
				*lastToken = '\0';
				lastToken++;
				return (token);
			}
			delimPtr++;
		}
		lastToken++;
	}
	lastToken = NULL;
	return (token);
}
