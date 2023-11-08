#include "shell.h"

char *_afstrtok(char *str, const char *delim)
{
	static char *current_str = NULL;
	char *token_start;
	int i, j;

	if (str)
	{
		current_str = str;
	}

	if (!current_str || *current_str == '\0')
	{
		return NULL;
	}
	token_start = current_str;
	
	for (i = 0; current_str[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (current_str[i] == delim[j])
			{
				current_str = current_str + i + 1;
				return token_start;
			}
		}
	}
	current_str = NULL;
	return token_start;
}
