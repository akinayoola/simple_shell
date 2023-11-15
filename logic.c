#include "shell.h"
/**
 * handle_logical_operators - hadle operators
 * @cmdards: store variables
 * @logic_operators: operators to be handled
 * @status: status of operators
 * Return: 0
 */
void handle_logical_operators(char *cmdargs[], int logic_operator, int *status)
{
	pid_t pid;
	int result;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		executecommand(cmdargs[0], cmdargs);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &result, 0);

		if ((logic_operator == 0 && result == 0) ||
				(logic_operator == 1 && result != 0))
		{
			*status = 0;
		}
		else
		{
			*status = 1;
		}
	}
}
/**
 * handle_commands - handle commands of input
 * @commands: commands to be handles
 * @status: command status
 */
void handle_commands(char *commands[], int *status)
{
	int i = 0;

	while (commands[i] != NULL)
	{
		char *token;
		char *cmdargs[MAX_ARGS];
		int j = 0;

		for (token = strtok(commands[i], " "); token && j < MAX_ARGS - 1;
				token = strtok(NULL, " "))
		{
			cmdargs[j++] = token;
		}
		cmdargs[j] = NULL;
		if (cmdargs[0] != NULL)
		{
			if (strcmp(cmdargs[0], "exit") == 0)
			{
				exit_shell(cmdargs);
			}
			else if (strcmp(cmdargs[0], "env") == 0)
			{
				print_environment();
			}
			else if (strcmp(cmdargs[0], "setenv") == 0)
			{
				set_env(cmdargs);
			}
			else if (strcmp(cmdargs[0], "unsetenv") == 0)
			{
				unset_env(cmdargs);
			}
			else if (strcmp(cmdargs[0], "cd") == 0)
			{
				change_directory(cmdargs);
			}
			else
			{
				int logic_operator = 0;

				if (strstr(commands[i], "&&"))
				{
					logic_operator = 0;
				}
				else if (strstr(commands[i], "||"))
				{
					logic_operator = 1;
				}
				handle_logical_operators(cmdargs, logic_operator, status);
			}
		}
		i++;
	}
}
