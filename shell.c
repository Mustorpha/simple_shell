#include "shell.h"

/**
 * main - shell program main entry
 * Return: 0
 */
int main(void)
{
	while (1)
	{
		_tokenizer(_get_command());
	}
	return (0);
}
