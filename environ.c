#include "shell.h"

/**
 * _getenv - searches for an environment to check its existence
 * @name: this is the name of the the environment
 * Return: returns a pointer to the value of environment
 */
char *_getenv(char *name)
{
	int ind = 0;
	char *env_tmp, *entry;

	while (environ[ind])
	{
		env_tmp = environ[ind++];
		entry = strtok(env_tmp, "=");
		if (!(_strcmp(name, entry)))
		{
			return (strtok(NULL, "="));
		}
	}
	return (NULL);
}
