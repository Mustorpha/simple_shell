#include "shell.h"

/**
 * _strchr - Function which locates a character in a string.
 * @s: The string to be searched for.
 * @c: The character to be located.
 * Return: If c is found - a pointer to the first occurence.
 */
char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return (NULL);
}

/**
 * _strspn - Fetches the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The prefix to be measured.
 * Return: The number of bytes in s which
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * Return: Positive byte difference
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - Compare two strings.
 * @s1: Points to a string.
 * @s2: Points to a string.
 * @n: The first n bytes of the strings to compare.
 * Return: Less than 0 if s1 is shorter than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
