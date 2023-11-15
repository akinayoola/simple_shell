#include "shell.h"
/**
 * executecommand - excute commnads from input
 * @cmd: command to be executed
 * @cmdargs: command argument
 */
void executecommand(char *cmd, char *cmdargs[])
{
	char *envp[] = {NULL};

	if (strchr(cmd, '/'))
	{
		if (execve(cmd, cmdargs, envp) == -1)
		{
			perror(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char *path = getenv("PATH");
		char *token = strtok(path, ":");

		while (token != NULL)
		{
			char fullpath[256];

			snprintf(fullpath, sizeof(fullpath), "%s/%s", token, cmd);
			if (execve(fullpath, cmdargs, envp) != -1)
			{
				break;
			}
			token = strtok(NULL, ":");
		}
		perror(cmd);
		exit(EXIT_FAILURE);
	}
}

/**
 * c_e - get user entry
 * Return: 0
 */
char *c_e()
{
	char *entry = NULL;
	size_t e_s = 0;
	ssize_t d_r = _afgetline(&entry, &e_s, stdin);

	if (d_r == -1)
	{
		free(entry);
		return (NULL);
	}
	if (entry[d_r - 1] == '\n')
		entry[d_r - 1] = '\0';
	return (entry);
}
/**
 * exit_shell - to exit the present shell
 * @cmdargs: store variables
 */
void exit_shell(char *cmdargs[])
{
	int status = 0;

	if (cmdargs[1] != NULL)
	{
		status = atoi(cmdargs[1]);
	}
	exit(status);
}
