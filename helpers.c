#include "shell.h"

/**
 * _strlen - analyses the total numbr of characters contained in a string
 * @s: serves as a pointer to the string
 * Return: the number of chracters
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcat - concantenates two strings
 * @dest: this is destination string
 * @src: this is source string
 * Return: this is full string
 */
char *_strcat(char *dest, char *src)
{
	char *original;

	original = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (original);
}

/**
 * _strcmp - function which compares two strings
 * @s1: this is the first string
 * @s2: this is the second string
 * Return: the value after comparism has been done
 */
int _strcmp(char *s1, char *s2)
{
	int val = 0;

	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (s1 != s2)
		val = *s1 - *s2;
	return (val);
}


/**
 * *_strcpy - copies the string which is pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: points to the buffer from wehere the string was copied
 * @src: points to the string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - function that duplicates a string
 * @src: pointer to the source string
 * Return: pointer to the duplicate
 */
char *_strdup(char *src)
{
	char *dest;
	int len;

	if (src == NULL)
		return (NULL);
	len = _strlen(src);
	dest = (char *)malloc(len + 1);

	if (dest == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	_strcpy(dest, src);
	return (dest);
}
