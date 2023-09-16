#include "shell.h"

/**
 * main - shell program main entry
 * Return: 0
 */
int main(void)
{
	_print("Simple Shell (press \"exit\" to quit)\n");
	while (1)
	{
		_tokenizer(_get_command());
	}
	return (0);
}
