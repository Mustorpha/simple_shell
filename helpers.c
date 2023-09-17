#include "shell.h"

/**
 * _strlen - analyse the total numbr of character in a string
 * @s: a pointer to the string
 * Return: the number of chracter
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
 * @dest: the destination string
 * @src: the source string
 * Return: the full string
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
 * _strcmp - function that compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: the value from comparism
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
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
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
 * _strdup - duplicates a string
 * @src: the source string
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
