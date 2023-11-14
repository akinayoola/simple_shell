#include "shell.h"

ssize_t _afgetline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i;
	int c;
	char *new_ptr;
	
	if (lineptr == NULL || n == NULL)
	{
		return -1;
	}

	i = 0;
	
	if (*lineptr == NULL || *n == 0)
	{
		*n = MAX_INPUT;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return -1;
		}
	}

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (i == *n - 1)
		{
			*n *= 2;
			
			new_ptr = (char *)realloc(*lineptr, *n);
			
			if (new_ptr == NULL)
			{
				return -1;
			}
			*lineptr = new_ptr;

		}
		(*lineptr)[i++] = (char)c;
	}
	
	(*lineptr)[i] = '\0';

	return (i > 0) ? (ssize_t)i : -1;
}
