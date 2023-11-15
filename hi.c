#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIASES 10

typedef struct
{
	char name[256];
	char value[256];
} Alias;

Alias aliases[MAX_ALIASES];
int alias_count = 0;

Alias *find_alias(const char *name)
{
	for (int i = 0; i < alias_count; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			return (&aliases[i]);
		}
	}
	return (NULL);
}
/**
 * handle_alias - handle input aliases
 * @cmdargs: store variables
 */
void handle_alias(char *cmdargs[])
{
	if (cmdargs[1] == NULL)
	{
		for (int i = 0; i < alias_count; i++)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
		}
	}
	else if (cmdargs[2] == NULL)
	{
		Alias *alias = find_alias(cmdargs[1]);
		if (alias != NULL)
		{
			printf("%s='%s'\n", alias->name, alias->value);
		}
		else
		{
			fprintf(stderr, "Alias not found: %s\n", cmdargs[1]);
		}
	}
	else if (cmdargs[3] == NULL && strchr(cmdargs[1], '='))
	{
		char *name = strtok(cmdargs[1], "=");
		char *value = strtok(NULL, "=");

		Alias *existing_alias = find_alias(name);
		if (existing_alias != NULL)
		{
			strcpy(existing_alias->value, value);
		}
		else
		{
			if (alias_count < MAX_ALIASES)
			{
				strcpy(aliases[alias_count].name, name);
				strcpy(aliases[alias_count].value, value);
				alias_count++;
			}
			else
			{
				fprintf(stderr, "Maximum number of aliases reached\n");
			}
		}
	}
	else
	{
		fprintf(stderr, "Usage: alias [name[='value'] ...]\n");
	}
}
/**
 * main - main entry
 * Return: 0
 */
int main(void)
{
	char *alias_command1[] = {"alias", "myalias='ls'", NULL};

	handle_alias(alias_command1);

	char *alias_command2[] = {"alias", NULL};

	handle_alias(alias_command2);

	char *alias_command3[] = {"alias", "myalias", NULL};

	handle_alias(alias_command3);

	char *alias_command4[] = {"alias", "myalias='ls -l'", NULL};

	handle_alias(alias_command4);

	char *alias_command5[] = {"alias", NULL};

	handle_alias(alias_command5);

	char *alias_command6[] = {"alias", "newalias='echo Hello'", NULL};

	handle_alias(alias_command6);

	char *alias_command7[] = {"alias", "invalid_syntax", NULL};

	handle_alias(alias_command7);

	return (0);
}

