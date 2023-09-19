#include "shell.h"

/**
 * main - main entry of shell program
 * Return: 0
 */
int main(void)
{
	while (1)
	{
		_print("$ ");
		_tokenizer(_get_command());
	}
	return (0);
}
