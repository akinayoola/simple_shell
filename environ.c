#include "shell.h"

void print_environment()
{
	char **env;
	
	for (env = environ; *env != NULL; env++)
	{
		PROD(*env);
	}
}

void set_env(char *cmdargs[])
{
	if (cmdargs[1] != NULL && cmdargs[2] != NULL && cmdargs[3] == NULL)
	{
		if (setenv(cmdargs[1], cmdargs[2], 1) != 0)
		{
			perror("setenv");
		}
	}
	else
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	}
}

void unset_env(char *cmdargs[])
{
	if (cmdargs[1] != NULL && cmdargs[2] == NULL)
	{
		if (unsetenv(cmdargs[1]) != 0)
		{
			perror("unsetenv");
		}
	}
	else
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	}
}

void change_directory(char *cmdargs[])
{
	char *path;

	if(cmdargs[1] == NULL)
	{
		path = getenv("HOME");
	}
	else if (strcmp(cmdargs[1], "-") == 0)
	{
		path = getenv("OLDPWD");
	}
	else
	{
		path = cmdargs[1];
	}
	
	if (chdir(path) == -1)
	{
		perror("cd");
	}
	else
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", path, 1);
	}
}
