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
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;

	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
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
