#include "shell.h"

/**
 * _getenv - search if an enviroment exist
 * @name: the enviroment name
 * Return: a pointer to the enviroment value
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
