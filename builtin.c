#include "shell.h"

/**
 * _terminate - teminates the shell process
 * @process: the shell process ID
 * Return: void
 */
void _terminate(pid_t process)
{
	kill(process, SIGINT);
}
