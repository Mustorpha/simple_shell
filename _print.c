#include "shell.h"

/**
 * _print - prints a string to the standard output
 * @str: the output string
 * Return: void
 */

void _print(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _print - prints a string to the standard error
 * @str: the output error message
 * Return: void
 */

void _printerr(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}
