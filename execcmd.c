#include "shell.h"

void exec_cmd(char *cmd)
{
	char *cmd_path = get_command_path(cmd);
	char *token;
	char *args[MAX_ARGUMENTS];
	int arg_count;
	
	if (cmd_path == NULL)
	{
		write(STDOUT_FILENO, "Command not found\n", 18);
		_exit(EXIT_FAILURE);
	}
	
	token = _afstrtok(cmd, " ");
	arg_count = 0;

	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;

		if (arg_count >= MAX_ARGUMENTS - 1)
		{
			break;
		}

		token = _afstrtok(NULL, " ");
	}
	
	args[arg_count] = NULL;


	execve(cmd_path, args, environ);
	perror("execve");
	_exit(EXIT_FAILURE);
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

void exit_shell()
{
	_exit(0);
}
