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

/**
 * _envsize - counts the total enviroment variables
 * Return: number of variables found
 */
int _envsize(void)
{
	int size = 0;

	while (environ[size] != NULL)
		size++;
	return (size);
}

/**
 * _setenv - Set a new environ variable, modify an existing one
 * @name: the enviroment variable name
 * @value: the enviroment variable value
 * @overwrite: overwrite flag for existing variables
 * Return: 1 (success) -1 (failed)
 */
int _setenv(char *name, char *value, int overwrite)
{
	int i;
	char *env_var = NULL;
	char *env_copy = NULL;

	if (name == NULL || value == NULL || !overwrite)
	{
		_printerr("Usage: setenv VARIABLE VALUE...\n");
		return (-1);
	}
	env_var = _strdup(name);

	_strcat(_strcat(env_var, "="), value);
	for (i = 0; environ[i] != NULL; i++)
	{
		env_copy = _strdup(environ[i]);
		if (!(_strcmp(_strtok(env_copy, "="), name)))
		{
			if (overwrite)
			{
				free(environ[i]);
				environ[i] = env_var;
				free(env_copy);
				return (1);
			}
			else
			{
				free(env_var);
				free(env_copy);
				return (1);
			}
		}
	}
	free(env_copy);
	return (_modenv(env_var));
}

/**
 * _unsetenv - deletes an environment variable
 * @name: variable name
 * Return: 1 (success) -1 (failed)
 */
int _unsetenv(char *name)
{
	int i;
	char *env_copy;

	if (name == NULL || name[0] == '\0')
	{
		_printerr("Usage: unsetenv NAME...\n");
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		env_copy = _strdup(environ[i]);
		if (!(_strcmp(_strtok(env_copy, "="), name)))
		{
			free(environ[i]);
			for (int j = i; environ[j + 1] != NULL; j++)
				environ[j] = environ[j + 1];
			free(env_copy);
			return (1);
		}
	}
	free(env_copy);
	return (1);
}

/**
 * _modenv - modify an enviroment variable
 * @new_env: the new enviroment variable
 * Return: 1 (success) -1 (failed)
 */
int _modenv(char *new_env)
{
	int i;
	char **new_environ;

	new_environ = malloc((_envsize() + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		free(new_env);
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
		new_environ[i] = _strdup(environ[i]);
	new_environ[_envsize()] = new_env;
	new_environ[_envsize() + 1] = NULL;
	environ = new_environ;
	return (1);
}
