#include "shell.h"

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
	return lgth;
}

int _afstrcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char* _afstrcat(char *dest, const char *src)
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

	return dest;
}

char *af_strdup(const char *str)
{
	size_t length;
	size_t i;
	char *duplicate;
	
	if (str == NULL)
	{
		return NULL;
	}

	length = _afstrlen(str) + 1;
	
	duplicate = (char *)malloc(length);

	if (duplicate == NULL)
	{
		return NULL;
	}
	
	for (i = 0; i < length; i++)

	{
		duplicate[i] = str[i];
	}

	return duplicate;
}

char *af_strcpy(char *dest, const char *src)
{
	char *dest_start;
	
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	
	dest_start = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return dest_start;
}
