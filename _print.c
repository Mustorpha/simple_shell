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
