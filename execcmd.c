#include "shell.h"

void exec_cmd(char *cmd)
{
	char *cmdArgs[2];
	char *envp[] = {NULL};
	cmdArgs[0] = cmd;
	cmdArgs[1] = NULL;

	execve(cmd, cmdArgs, envp);
	perror(cmd);
	exit(EXIT_FAILURE);
}

char *c_e()
{
	char *entry = NULL;
	size_t e_s = 0;
	ssize_t d_r = getline(&entry, &e_s, stdin);

	if(d_r == -1)
	{
		free(entry);
		return NULL;
	}
	if (entry[d_r - 1] == '\n')
	{
		entry[d_r - 1] = '\0';
	}
	return entry;
}
