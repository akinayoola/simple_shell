#include "shell.h"
/**
 * _afstrlen - length of string
 * @str: string
 * Return: 0
 */
size_t _afstrlen(const char *str)
{
	size_t lgth = 0;

	if (str == NULL)
	{
		return (0);
	}

	while (str[lgth] != '\0')
	{
		lgth++;
	}
	return (lgth);
}

/**
 * _afstrcmp - compare strings
 * @s1: string source
 * @s2: string destination
 * Return: 0
 */
int _afstrcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _afstrcat - concatenate strings
 * @dest: string destination
 * @src: string source
 * Return: 0
 */
char *_afstrcat(char *dest, const char *src)
{
	char *temp = dest;

	while (*temp)
	{
		temp++;
	}
	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
	}

	*temp = '\0';

	return (dest);
}

/**
 * af_strdup - duplicate strings
 * @str: string to be duplicated
 * Return: 0
 */

char *af_strdup(const char *str)
{
	size_t length;
	size_t i;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}

	length = _afstrlen(str) + 1;

	duplicate = (char *)malloc(length);

	if (duplicate == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length; i++)

	{
		duplicate[i] = str[i];
	}

	return (duplicate);
}

/**
 * af_strcpy - copy strings
 * @dest: destination of strings
 * @src: source of strings
 * Return: 0
 */
char *af_strcpy(char *dest, const char *src)
{
	char *dest_start;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	dest_start = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (dest_start);
}
